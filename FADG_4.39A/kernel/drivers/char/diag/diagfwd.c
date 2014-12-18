/* Copyright (c) 2008-2011, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 */

#include <linux/slab.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/err.h>
#include <linux/platform_device.h>
#include <linux/sched.h>
#include <linux/workqueue.h>
#include <linux/pm_runtime.h>
#include <linux/diagchar.h>
#include <linux/delay.h>
#include <linux/reboot.h>
#include <linux/smp_lock.h>
#ifdef CONFIG_DIAG_OVER_USB
#include <mach/usbdiag.h>
#endif
#include <mach/msm_smd.h>
#include <mach/socinfo.h>
#include <mach/restart.h>
#include "diagmem.h"
#include "diagchar.h"
#include "diagfwd.h"
#include "diagchar_hdlc.h"
#ifdef CONFIG_DIAG_SDIO_PIPE
#include "diagfwd_sdio.h"
#endif

#include <linux/pm_runtime.h>
#ifdef CONFIG_FIH_FXX
#define SAVE_MODEM_EFS_LOG  1
#ifdef SAVE_QXDM_LOG_TO_SD_CARD
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/rtc.h>
#endif
#if defined(SAVE_QXDM_LOG_TO_SD_CARD) || defined(SAVE_MODEM_EFS_LOG)
#include <linux/cmdbgapi.h>
#endif
#define WRITE_NV_4719_TO_ENTER_RECOVERY 1
#ifdef WRITE_NV_4719_TO_ENTER_RECOVERY
#include "../../../arch/arm/mach-msm/proc_comm.h"
#define NV_FTM_MODE_BOOT_COUNT_I    4719
#endif
#endif
MODULE_DESCRIPTION("Diag Char Driver");
MODULE_LICENSE("GPL v2");
MODULE_VERSION("1.0");

int diag_debug_buf_idx;
unsigned char diag_debug_buf[1024];
static unsigned int buf_tbl_size = 8; /*Number of entries in table of buffers */

struct diag_send_desc_type send = { NULL, NULL, DIAG_STATE_START, 0 };
struct diag_hdlc_dest_type enc = { NULL, NULL, 0 };

#define ENCODE_RSP_AND_SEND(buf_length)				\
do {									\
	send.state = DIAG_STATE_START;					\
	send.pkt = driver->apps_rsp_buf;				\
	send.last = (void *)(driver->apps_rsp_buf + buf_length);	\
	send.terminate = 1;						\
	if (!driver->in_busy_1) {					\
		enc.dest = driver->buf_in_1;				\
		enc.dest_last = (void *)(driver->buf_in_1 + 499);	\
		diag_hdlc_encode(&send, &enc);				\
		driver->write_ptr_1->buf = driver->buf_in_1;		\
		driver->write_ptr_1->length = (int)(enc.dest - \
						(void *)(driver->buf_in_1)); \
		usb_diag_write(driver->legacy_ch, driver->write_ptr_1);	\
		memset(driver->apps_rsp_buf, '\0', 500);		\
	}								\
} while (0)

#define CHK_OVERFLOW(bufStart, start, end, length) \
((bufStart <= start) && (end - start >= length)) ? 1 : 0

// FIH +++
#ifdef CONFIG_FIH_FXX
#define DIAG_READ_RETRY_COUNT    100  //100 * 5 ms = 500ms

#if SAVE_MODEM_EFS_LOG
enum 
{
EFS_ERR_NONE,
EFS_EPERM,
EFS_ENOENT,
EFS_EEXIST        =6, 
EFS_EBADF         =9,
EFS_ENOMEM        =12,
EFS_EACCES        =13,
EFS_EBUSY         =16,
EFS_EXDEV         =18,
EFS_ENODEV        =19,
EFS_ENOTDIR       =20,
EFS_EISDIR        =21,
EFS_EINVAL        =22,
EFS_EMFILE        =24,
EFS_ETXTBSY       =26,
EFS_ENOSPC        =28,
EFS_ESPIPE        =29,
EFS_FS_ERANGE     =34,
EFS_ENAMETOOLONG  =36,
EFS_ENOTEMPTY     =39,
EFS_ELOOP         =40,
EFS_ESTALE        =116,
EFS_EDQUOT        =122,
EFS_ENOCARD       =301,
EFS_EBADFMT       =302,
EFS_ENOTITM       =303,
EFS_EROLLBACK     =304,
EFS_ERR_UNKNOWN       =999,
};
enum
{
EFS_DIAG_TRANSACTION_OK = 0,
EFS_DIAG_TRANSACTION_NO_DATA,
EFS_DIAG_TRANSACTION_WRONG_DATA,
EFS_DIAG_TRANSACTION_NO_FILE_DIR,
EFS_DIAG_TRANSACTION_CMD_ERROR,
EFS_DIAG_TRANSACTION_ABORT,
};
#define READ_FILE_SIZE  0x200
#define EFS_BUFFER_SIZE (2*READ_FILE_SIZE)
#define FILE_NAME_LENGTH    128
#define EFS2_DIAG_OPENDIR_RES_SIZE  12  // Response 12 bytes
#define EFS2_DIAG_READDIR_RES_SIZE  (40 + 64)  // Response 40 bytes + variable string
#define EFS2_DIAG_OPEN_RES_SIZE  12     // Response 12 bytes
#define EFS2_DIAG_READ_RES_SIZE  20     // Response 20 bytes + variable data
#define EFS2_DIAG_CLOSE_RES_SIZE  8     // Response 8 bytes
#define EFS2_DIAG_CLOSEDIR_RES_SIZE  8  // Response 8 bytes

static char * efs_log_dir_path[] = {"/data/efslog/OEMDBG_LOG/", "/data/efslog/err/"};
//static char * efs_log_dir_path[] = {"/sdcard/", "/data/efslog/err/"};
static char efs_file_path[FILE_NAME_LENGTH];
static struct file *efs_file_filp = NULL;
static DEFINE_MUTEX(efslog_mutex);

#define EFSLOG_STATUS_FAIL_TO_OPEN_MODEM_FILE  -4
#define EFSLOG_STATUS_DIAG_PORT_INVALID        -3
#define EFSLOG_STATUS_CREATE_FILE_FAIL         -2
#define EFSLOG_STATUS_MEMORY_ALLOCATION_FAIL   -1
#define EFSLOG_STATUS_DEFAULT                  0
#define EFSLOG_STATUS_SUCCESS                  1
static int efslog_result=0;
module_param_named(efslog_result, efslog_result, int, S_IRUGO);
#endif

// QXDM to SD
    #if SAVE_QXDM_LOG_TO_SD_CARD
    #define MAX_W_BUF_SIZE 65535
    #define SAFE_W_BUF_SIZE 32768
    static DECLARE_WAIT_QUEUE_HEAD(diag_wait_queue);

    static unsigned char *pBuf = NULL;
    static unsigned char *pBuf_Curr = NULL;
    static unsigned char *r_buf = NULL;  //paul
    static unsigned char *log_write_buf = NULL;  //paul
    static int gBuf_Size = 0;

    static struct file *gLog_filp = NULL;
    static struct file *gFilter_filp = NULL;
    static struct file *gLogWriteThreadFilter_filp = NULL;    //paul
    static struct task_struct *kLogTsk;
    static struct task_struct *kLoadFilterTsk;

    static char gPath[] = "/sdcard/log/";
    static char gLogFilePath[64];
    static char gFilterFileName[] = "filter.bin";

    static int bCaptureFilter = 0;
    static int bLogStart = 0;
    static int gTotalWrite = 0;
    static int bWriteSD = 0;
    static int bGetRespNow = 0;

    static void diag_start_log(void);
    static void diag_stop_log(void);
    static int open_qxdm_filter_file(void);
    static int close_qxdm_filter_file(void);
#define QXDMLOG_STATUS_CREATE_THREAD_FAIL       -3
#define QXDMLOG_STATUS_CREATE_FILE_FAIL         -2
#define QXDMLOG_STATUS_MEMORY_ALLOCATION_FAIL   -1
#define QXDMLOG_STATUS_DEFAULT                  0
#define QXDMLOG_STATUS_SUCCESS                  1
static int qxdmlog_launch_result=0;
module_param_named(qxdmlog_status, qxdmlog_launch_result, int, S_IRUGO);
    #endif
#endif
// FIH ---
#ifdef CONFIG_FIH_FXX
/* +++ FIH, Paul Huang, 2010/01/04 { */
// G0: General and critical
#define DIAG_DBG_MSG_G0(fmt, ...) \
        fih_printk(diag_char_debug_mask, FIH_DEBUG_ZONE_G0, fmt, ##__VA_ARGS__);
// G1: QXDM LOG TO SD
#define DIAG_DBG_MSG_G1(fmt, ...) \
        fih_printk(diag_char_debug_mask, FIH_DEBUG_ZONE_G1, fmt, ##__VA_ARGS__);
// G2: QXDM LOG TO SD filter.bin error
#define DIAG_DBG_MSG_G2(fmt, ...) \
        fih_printk(diag_char_debug_mask, FIH_DEBUG_ZONE_G2, fmt, ##__VA_ARGS__);

#define DIAG_DBG_MSG_G3(fmt, ...) \
        fih_printk(diag_char_debug_mask, FIH_DEBUG_ZONE_G3, fmt, ##__VA_ARGS__);

#define DIAG_DBG_MSG_G4(fmt, ...) \
        fih_printk(diag_char_debug_mask, FIH_DEBUG_ZONE_G4, fmt, ##__VA_ARGS__);

#define DIAG_DBG_MSG_G5(fmt, ...) \
        fih_printk(diag_char_debug_mask, FIH_DEBUG_ZONE_G5, fmt, ##__VA_ARGS__);
/* --- FIH, Paul Huang, 2010/01/04 } */

/* FIH, JiaHao, 2011/09/30 { */ /* fver */
// G6: save BSP/fver into /data/fver
#define DIAG_DBG_MSG_G6(fmt, ...) \
        fih_printk(diag_char_debug_mask, FIH_DEBUG_ZONE_G6, fmt, ##__VA_ARGS__);
/* FIH, JiaHao, 2011/09/30 } */ /* fver */

uint32_t diag_char_debug_mask =0;
module_param_named(
    debug_mask, diag_char_debug_mask, uint, S_IRUGO | S_IWUSR | S_IWGRP
);
    #if SAVE_QXDM_LOG_TO_SD_CARD || SAVE_MODEM_EFS_LOG
    static DEFINE_SPINLOCK(diag_smd_lock);
    #endif
#endif

#if SAVE_QXDM_LOG_TO_SD_CARD
static ssize_t qxdm2sd_run(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	unsigned LogRun;
	
	sscanf(buf, "%1d\n", &LogRun);
	
	dev_dbg(dev, "%s: %d %d\n", __func__, count, LogRun);

	if (LogRun == 1)
	{
		// Open log file and start capture
		diag_start_log();
	}
	else if (LogRun == 0)
	{
		// Close log file and stop capture
		diag_stop_log();
	}
	else if (LogRun == 2)
	{
		open_qxdm_filter_file();
	}
	else if (LogRun == 3)
	{
		close_qxdm_filter_file();
	}
	return count;
}
DEVICE_ATTR(qxdm2sd, 0644, NULL, qxdm2sd_run);

static void diag_log_smd_read(void)
{
	int sz;
	void *buf = NULL;
	unsigned long flags;

    if ((buf = kzalloc(IN_BUF_SIZE, GFP_KERNEL)) == NULL) {
	    DIAG_DBG_MSG_G1(KERN_ERR "diag_log_smd_read kzalloc buf fail!\n");
        return;
	}
	for (;;) {
		sz = smd_cur_packet_size(driver->ch);
		if (sz == 0)
			break;
		if (sz > smd_read_avail(driver->ch)) {
			DIAG_DBG_MSG_G0(KERN_INFO "[diagfwd.c][WARNING] sz > smd_read_avail(), sz = %d\n", sz);
			break;
		}
		if (sz > USB_MAX_OUT_BUF) {
			DIAG_DBG_MSG_G0(KERN_INFO "[diagfwd.c][ERROR] sz > USB_MAX_OUT_BUF, sz = %d\n", sz);
			smd_read(driver->ch, 0, sz);
			continue;
		}
		
		if (!buf) {
			DIAG_DBG_MSG_G0(KERN_INFO "Out of diagmem for a9\n");
			break;
		}
        spin_lock_irqsave(&diag_smd_lock, flags);
		if (smd_read(driver->ch, buf, sz) != sz) {
			DIAG_DBG_MSG_G0(KERN_INFO "[diagfwd.c][WARNING] not enough data?!\n");
            spin_unlock_irqrestore(&diag_smd_lock, flags);
			continue;
		}
		spin_unlock_irqrestore(&diag_smd_lock, flags);

        if ((pBuf_Curr + sz) >= (pBuf + MAX_W_BUF_SIZE))
        {
            pBuf_Curr = pBuf;   //Index is over the allocated buffer size. Move the index to the beginning of buffer.
        }
		spin_lock_irqsave(&diag_smd_lock, flags);
		memcpy(pBuf_Curr, buf, sz);
		pBuf_Curr += sz;
		gBuf_Size += sz;
		spin_unlock_irqrestore(&diag_smd_lock, flags);
		
		if ((gBuf_Size >= SAFE_W_BUF_SIZE) || bGetRespNow) {
			wake_up_interruptible(&diag_wait_queue);
		}
		
		gTotalWrite += sz;
	}
    kfree(buf);
}

#endif
int chk_config_get_id()
{
	/* For all Fusion targets, Modem will always be present */
	if (machine_is_msm8x60_charm_surf() || machine_is_msm8x60_charm_ffa())
		return 0;

	switch (socinfo_get_id()) {
	case APQ8060_MACHINE_ID:
		return APQ8060_TOOLS_ID;
	case AO8960_MACHINE_ID:
		return AO8960_TOOLS_ID;
	default:
		return 0;
	}
}

void __diag_smd_send_req(void)
{
	void *buf = NULL;
	int *in_busy_ptr = NULL;
	struct diag_request *write_ptr_modem = NULL;

	if (!driver->in_busy_1) {
		buf = driver->buf_in_1;
		write_ptr_modem = driver->write_ptr_1;
		in_busy_ptr = &(driver->in_busy_1);
	} else if (!driver->in_busy_2) {
		buf = driver->buf_in_2;
		write_ptr_modem = driver->write_ptr_2;
		in_busy_ptr = &(driver->in_busy_2);
	}

	if (driver->ch && buf) {
		int r = smd_read_avail(driver->ch);

		if (r > IN_BUF_SIZE) {
			if (r < MAX_IN_BUF_SIZE) {
				printk(KERN_ALERT "\n diag: SMD sending in "
						   "packets upto %d bytes", r);
				buf = krealloc(buf, r, GFP_KERNEL);
			} else {
				printk(KERN_ALERT "\n diag: SMD sending in "
				"packets more than %d bytes", MAX_IN_BUF_SIZE);
				return;
			}
		}
		if (r > 0) {
			if (!buf)
				pr_info("Out of diagmem for Modem\n");
			else {
				APPEND_DEBUG('i');
				smd_read(driver->ch, buf, r);
				APPEND_DEBUG('j');
				write_ptr_modem->length = r;
				*in_busy_ptr = 1;
				diag_device_write(buf, MODEM_DATA,
							 write_ptr_modem);
			}
		}
	}
}

int diag_device_write(void *buf, int proc_num, struct diag_request *write_ptr)
{
	int i, err = 0;

	if (driver->logging_mode == MEMORY_DEVICE_MODE) {
		if (proc_num == APPS_DATA) {
			for (i = 0; i < driver->poolsize_write_struct; i++)
				if (driver->buf_tbl[i].length == 0) {
					driver->buf_tbl[i].buf = buf;
					driver->buf_tbl[i].length =
								 driver->used;
#ifdef DIAG_DEBUG
					printk(KERN_INFO "\n ENQUEUE buf ptr"
						   " and length is %x , %d\n",
						   (unsigned int)(driver->buf_
				tbl[i].buf), driver->buf_tbl[i].length);
#endif
					break;
				}
		}
		for (i = 0; i < driver->num_clients; i++)
			if (driver->client_map[i].pid ==
						 driver->logging_process_id)
				break;
		if (i < driver->num_clients) {
			driver->data_ready[i] |= MEMORY_DEVICE_LOG_TYPE;
			wake_up_interruptible(&driver->wait_q);
		} else
			return -EINVAL;
	} else if (driver->logging_mode == NO_LOGGING_MODE) {
		if (proc_num == MODEM_DATA) {
			driver->in_busy_1 = 0;
			driver->in_busy_2 = 0;
			queue_work(driver->diag_wq, &(driver->
							diag_read_smd_work));
		} else if (proc_num == QDSP_DATA) {
			driver->in_busy_qdsp_1 = 0;
			driver->in_busy_qdsp_2 = 0;
			queue_work(driver->diag_wq, &(driver->
						diag_read_smd_qdsp_work));
		}
#ifdef CONFIG_DIAG_SDIO_PIPE
        else if (proc_num == SDIO_DATA) {
            driver->in_busy_sdio = 0;
            queue_work(driver->diag_sdio_wq,
                &(driver->diag_read_sdio_work));
        }
#endif
		err = -1;
	}
#ifdef CONFIG_DIAG_OVER_USB
	else if (driver->logging_mode == USB_MODE) {
		if (proc_num == APPS_DATA) {
			driver->write_ptr_svc = (struct diag_request *)
			(diagmem_alloc(driver, sizeof(struct diag_request),
				 POOL_TYPE_WRITE_STRUCT));
			if (driver->write_ptr_svc) {
				driver->write_ptr_svc->length = driver->used;
				driver->write_ptr_svc->buf = buf;
				err = usb_diag_write(driver->legacy_ch,
						driver->write_ptr_svc);
			} else
				err = -1;
		} else if (proc_num == MODEM_DATA) {
			write_ptr->buf = buf;
#ifdef DIAG_DEBUG
			printk(KERN_INFO "writing data to USB,"
				"pkt length %d\n", write_ptr->length);
			print_hex_dump(KERN_DEBUG, "Written Packet Data to"
					   " USB: ", 16, 1, DUMP_PREFIX_ADDRESS,
					    buf, write_ptr->length, 1);
#endif /* DIAG DEBUG */
			err = usb_diag_write(driver->legacy_ch, write_ptr);
		} else if (proc_num == QDSP_DATA) {
			write_ptr->buf = buf;
			err = usb_diag_write(driver->legacy_ch, write_ptr);
		}
#ifdef CONFIG_DIAG_SDIO_PIPE
		else if (proc_num == SDIO_DATA) {
			if (machine_is_msm8x60_charm_surf() ||
					machine_is_msm8x60_charm_ffa()) {
				write_ptr->buf = buf;
				err = usb_diag_write(driver->mdm_ch, write_ptr);
			} else
				pr_err("diag: Incorrect data while USB write");
		}
#endif
		APPEND_DEBUG('d');
	}
#endif /* DIAG OVER USB */
    return err;
}

void __diag_smd_qdsp_send_req(void)
{
	void *buf = NULL;
	int *in_busy_qdsp_ptr = NULL;
	struct diag_request *write_ptr_qdsp = NULL;

	if (!driver->in_busy_qdsp_1) {
		buf = driver->buf_in_qdsp_1;
		write_ptr_qdsp = driver->write_ptr_qdsp_1;
		in_busy_qdsp_ptr = &(driver->in_busy_qdsp_1);
	} else if (!driver->in_busy_qdsp_2) {
		buf = driver->buf_in_qdsp_2;
		write_ptr_qdsp = driver->write_ptr_qdsp_2;
		in_busy_qdsp_ptr = &(driver->in_busy_qdsp_2);
	}

	if (driver->chqdsp && buf) {
		int r = smd_read_avail(driver->chqdsp);

		if (r > IN_BUF_SIZE) {
			if (r < MAX_IN_BUF_SIZE) {
				printk(KERN_ALERT "\n diag: SMD sending in "
						   "packets upto %d bytes", r);
				buf = krealloc(buf, r, GFP_KERNEL);
			} else {
				printk(KERN_ALERT "\n diag: SMD sending in "
				"packets more than %d bytes", MAX_IN_BUF_SIZE);
				return;
			}
		}
		if (r > 0) {
			if (!buf)
				printk(KERN_INFO "Out of diagmem for QDSP\n");
			else {
				APPEND_DEBUG('i');
				smd_read(driver->chqdsp, buf, r);
				APPEND_DEBUG('j');
				write_ptr_qdsp->length = r;
				*in_busy_qdsp_ptr = 1;
				diag_device_write(buf, QDSP_DATA,
							 write_ptr_qdsp);
			}
		}
	}
}

static void diag_print_mask_table(void)
{
/* Enable this to print mask table when updated */
#ifdef MASK_DEBUG
	int first;
	int last;
	uint8_t *ptr = driver->msg_masks;
	int i = 0;

	while (*(uint32_t *)(ptr + 4)) {
		first = *(uint32_t *)ptr;
		ptr += 4;
		last = *(uint32_t *)ptr;
		ptr += 4;
		printk(KERN_INFO "SSID %d - %d\n", first, last);
		for (i = 0 ; i <= last - first ; i++)
			printk(KERN_INFO "MASK:%x\n", *((uint32_t *)ptr + i));
		ptr += ((last - first) + 1)*4;

	}
#endif
}

static void diag_update_msg_mask(int start, int end , uint8_t *buf)
{
	int found = 0;
	int first;
	int last;
	uint8_t *ptr = driver->msg_masks;
	uint8_t *ptr_buffer_start = &(*(driver->msg_masks));
	uint8_t *ptr_buffer_end = &(*(driver->msg_masks)) + MSG_MASK_SIZE;

	mutex_lock(&driver->diagchar_mutex);
	/* First SSID can be zero : So check that last is non-zero */

	while (*(uint32_t *)(ptr + 4)) {
		first = *(uint32_t *)ptr;
		ptr += 4;
		last = *(uint32_t *)ptr;
		ptr += 4;
		if (start >= first && start <= last) {
			ptr += (start - first)*4;
			if (end <= last)
				if (CHK_OVERFLOW(ptr_buffer_start, ptr,
						  ptr_buffer_end,
						  (((end - start)+1)*4)))
					memcpy(ptr, buf , ((end - start)+1)*4);
				else
					printk(KERN_CRIT "Not enough"
							 " buffer space for"
							 " MSG_MASK\n");
			else
				printk(KERN_INFO "Unable to copy"
						 " mask change\n");

			found = 1;
			break;
		} else {
			ptr += ((last - first) + 1)*4;
		}
	}
	/* Entry was not found - add new table */
	if (!found) {
		if (CHK_OVERFLOW(ptr_buffer_start, ptr, ptr_buffer_end,
				  8 + ((end - start) + 1)*4)) {
			memcpy(ptr, &(start) , 4);
			ptr += 4;
			memcpy(ptr, &(end), 4);
			ptr += 4;
			memcpy(ptr, buf , ((end - start) + 1)*4);
		} else
			printk(KERN_CRIT " Not enough buffer"
					 " space for MSG_MASK\n");
	}
	mutex_unlock(&driver->diagchar_mutex);
	diag_print_mask_table();

}

static void diag_update_event_mask(uint8_t *buf, int toggle, int num_bits)
{
	uint8_t *ptr = driver->event_masks;
	uint8_t *temp = buf + 2;

	mutex_lock(&driver->diagchar_mutex);
	if (!toggle)
		memset(ptr, 0 , EVENT_MASK_SIZE);
	else
		if (CHK_OVERFLOW(ptr, ptr,
				 ptr+EVENT_MASK_SIZE,
				  num_bits/8 + 1))
			memcpy(ptr, temp , num_bits/8 + 1);
		else
			printk(KERN_CRIT "Not enough buffer space "
					 "for EVENT_MASK\n");
	mutex_unlock(&driver->diagchar_mutex);
}

static void diag_update_log_mask(int equip_id, uint8_t *buf, int num_items)
{
	uint8_t *temp = buf;
	struct mask_info {
		int equip_id;
		int index;
	};
	int i = 0;
	unsigned char *ptr_data;
	int offset = 8*MAX_EQUIP_ID;
	struct mask_info *ptr = (struct mask_info *)driver->log_masks;

	mutex_lock(&driver->diagchar_mutex);
	/* Check if we already know index of this equipment ID */
	for (i = 0; i < MAX_EQUIP_ID; i++) {
		if ((ptr->equip_id == equip_id) && (ptr->index != 0)) {
			offset = ptr->index;
			break;
		}
		if ((ptr->equip_id == 0) && (ptr->index == 0)) {
			/*Reached a null entry */
			ptr->equip_id = equip_id;
			ptr->index = driver->log_masks_length;
			offset = driver->log_masks_length;
			driver->log_masks_length += ((num_items+7)/8);
			break;
		}
		ptr++;
	}
	ptr_data = driver->log_masks + offset;
	if (CHK_OVERFLOW(driver->log_masks, ptr_data, driver->log_masks
					 + LOG_MASK_SIZE, (num_items+7)/8))
		memcpy(ptr_data, temp , (num_items+7)/8);
	else
		printk(KERN_CRIT " Not enough buffer space for LOG_MASK\n");
	mutex_unlock(&driver->diagchar_mutex);
}

static void diag_update_pkt_buffer(unsigned char *buf)
{
	unsigned char *ptr = driver->pkt_buf;
	unsigned char *temp = buf;

	mutex_lock(&driver->diagchar_mutex);
	if (CHK_OVERFLOW(ptr, ptr, ptr + PKT_SIZE, driver->pkt_length))
		memcpy(ptr, temp , driver->pkt_length);
	else
		printk(KERN_CRIT " Not enough buffer space for PKT_RESP\n");
	mutex_unlock(&driver->diagchar_mutex);
}

void diag_update_userspace_clients(unsigned int type)
{
	int i;

	mutex_lock(&driver->diagchar_mutex);
	for (i = 0; i < driver->num_clients; i++)
		if (driver->client_map[i].pid != 0)
			driver->data_ready[i] |= type;
	wake_up_interruptible(&driver->wait_q);
	mutex_unlock(&driver->diagchar_mutex);
}

void diag_update_sleeping_process(int process_id)
{
	int i;

	mutex_lock(&driver->diagchar_mutex);
	for (i = 0; i < driver->num_clients; i++)
		if (driver->client_map[i].pid == process_id) {
			driver->data_ready[i] |= PKT_TYPE;
			break;
		}
	wake_up_interruptible(&driver->wait_q);
	mutex_unlock(&driver->diagchar_mutex);
}

static int diag_process_apps_pkt(unsigned char *buf, int len)
{
	uint16_t subsys_cmd_code;
	int subsys_id, ssid_first, ssid_last, ssid_range;
	int packet_type = 1, i, cmd_code;
	unsigned char *temp = buf;
#if defined(CONFIG_DIAG_OVER_USB)
	int payload_length;
	unsigned char *ptr;
#endif

	/* set event mask */
	if (*buf == 0x82) {
		buf += 4;
		diag_update_event_mask(buf, 1, *(uint16_t *)buf);
		diag_update_userspace_clients(EVENT_MASKS_TYPE);
	}
	/* event mask change */
	else if ((*buf == 0x60) && (*(buf+1) == 0x0)) {
		diag_update_event_mask(buf+1, 0, 0);
		diag_update_userspace_clients(EVENT_MASKS_TYPE);
#if defined(CONFIG_DIAG_OVER_USB)
		/* Check for Apps Only 8960 */
		if (!(driver->ch) && (chk_config_get_id() == AO8960_TOOLS_ID)) {
			/* echo response back for apps only DIAG */
			driver->apps_rsp_buf[0] = 0x60;
			driver->apps_rsp_buf[1] = 0x0;
			driver->apps_rsp_buf[2] = 0x0;
			ENCODE_RSP_AND_SEND(2);
			return 0;
		}
#endif
	}
	/* Set log masks */
	else if (*buf == 0x73 && *(int *)(buf+4) == 3) {
		buf += 8;
		/* Read Equip ID and pass as first param below*/
		diag_update_log_mask(*(int *)buf, buf+8, *(int *)(buf+4));
		diag_update_userspace_clients(LOG_MASKS_TYPE);
#if defined(CONFIG_DIAG_OVER_USB)
		/* Check for Apps Only 8960 */
		if (!(driver->ch) && (chk_config_get_id() == AO8960_TOOLS_ID)) {
			/* echo response back for Apps only DIAG */
			driver->apps_rsp_buf[0] = 0x73;
			*(int *)(driver->apps_rsp_buf + 4) = 0x3; /* op. ID */
			*(int *)(driver->apps_rsp_buf + 8) = 0x0; /* success */
			payload_length = 8 + ((*(int *)(buf + 4)) + 7)/8;
			for (i = 0; i < payload_length; i++)
				*(int *)(driver->apps_rsp_buf+12+i) =
								 *(buf+8+i);
			ENCODE_RSP_AND_SEND(12 + payload_length - 1);
			return 0;
		}
#endif
	}
	/* Check for set message mask  */
	else if ((*buf == 0x7d) && (*(buf+1) == 0x4)) {
		ssid_first = *(uint16_t *)(buf + 2);
		ssid_last = *(uint16_t *)(buf + 4);
		ssid_range = 4 * (ssid_last - ssid_first + 1);
		diag_update_msg_mask(ssid_first, ssid_last , buf + 8);
		diag_update_userspace_clients(MSG_MASKS_TYPE);
#if defined(CONFIG_DIAG_OVER_USB)
		if (!(driver->ch) && (chk_config_get_id() == AO8960_TOOLS_ID)) {
			/* echo response back for apps only DIAG */
			for (i = 0; i < 8 + ssid_range; i++)
				*(driver->apps_rsp_buf + i) = *(buf+i);
			ENCODE_RSP_AND_SEND(8 + ssid_range - 1);
			return 0;
		}
#endif
	}
#if defined(CONFIG_DIAG_OVER_USB)
	/* Check for Apps Only 8960 & get event mask request */
	else if (!(driver->ch) && (chk_config_get_id() == AO8960_TOOLS_ID)
			  && *buf == 0x81) {
		driver->apps_rsp_buf[0] = 0x81;
		driver->apps_rsp_buf[1] = 0x0;
		*(uint16_t *)(driver->apps_rsp_buf + 2) = 0x0;
		*(uint16_t *)(driver->apps_rsp_buf + 4) = EVENT_LAST_ID + 1;
		for (i = 0; i < EVENT_LAST_ID/8 + 1; i++)
			*(unsigned char *)(driver->apps_rsp_buf + 6 + i) = 0x0;
		ENCODE_RSP_AND_SEND(6 + EVENT_LAST_ID/8);
		return 0;
	}
	/* Get log ID range & Check for Apps Only 8960 */
	else if (!(driver->ch) && (chk_config_get_id() == AO8960_TOOLS_ID)
			  && (*buf == 0x73) && *(int *)(buf+4) == 1) {
		driver->apps_rsp_buf[0] = 0x73;
		*(int *)(driver->apps_rsp_buf + 4) = 0x1; /* operation ID */
		*(int *)(driver->apps_rsp_buf + 8) = 0x0; /* success code */
		*(int *)(driver->apps_rsp_buf + 12) = LOG_GET_ITEM_NUM(LOG_0);
		*(int *)(driver->apps_rsp_buf + 16) = LOG_GET_ITEM_NUM(LOG_1);
		*(int *)(driver->apps_rsp_buf + 20) = LOG_GET_ITEM_NUM(LOG_2);
		*(int *)(driver->apps_rsp_buf + 24) = LOG_GET_ITEM_NUM(LOG_3);
		*(int *)(driver->apps_rsp_buf + 28) = LOG_GET_ITEM_NUM(LOG_4);
		*(int *)(driver->apps_rsp_buf + 32) = LOG_GET_ITEM_NUM(LOG_5);
		*(int *)(driver->apps_rsp_buf + 36) = LOG_GET_ITEM_NUM(LOG_6);
		*(int *)(driver->apps_rsp_buf + 40) = LOG_GET_ITEM_NUM(LOG_7);
		*(int *)(driver->apps_rsp_buf + 44) = LOG_GET_ITEM_NUM(LOG_8);
		*(int *)(driver->apps_rsp_buf + 48) = LOG_GET_ITEM_NUM(LOG_9);
		*(int *)(driver->apps_rsp_buf + 52) = LOG_GET_ITEM_NUM(LOG_10);
		*(int *)(driver->apps_rsp_buf + 56) = LOG_GET_ITEM_NUM(LOG_11);
		*(int *)(driver->apps_rsp_buf + 60) = LOG_GET_ITEM_NUM(LOG_12);
		*(int *)(driver->apps_rsp_buf + 64) = LOG_GET_ITEM_NUM(LOG_13);
		*(int *)(driver->apps_rsp_buf + 68) = LOG_GET_ITEM_NUM(LOG_14);
		*(int *)(driver->apps_rsp_buf + 72) = LOG_GET_ITEM_NUM(LOG_15);
		ENCODE_RSP_AND_SEND(75);
		return 0;
	}
	/* Respond to Get SSID Range request message */
	else if (!(driver->ch) && (chk_config_get_id() == AO8960_TOOLS_ID)
			 && (*buf == 0x7d) && (*(buf+1) == 0x1)) {
		driver->apps_rsp_buf[0] = 0x7d;
		driver->apps_rsp_buf[1] = 0x1;
		driver->apps_rsp_buf[2] = 0x1;
		driver->apps_rsp_buf[3] = 0x0;
		*(int *)(driver->apps_rsp_buf + 4) = MSG_MASK_TBL_CNT;
		*(uint16_t *)(driver->apps_rsp_buf + 8) = MSG_SSID_0;
		*(uint16_t *)(driver->apps_rsp_buf + 10) = MSG_SSID_0_LAST;
		*(uint16_t *)(driver->apps_rsp_buf + 12) = MSG_SSID_1;
		*(uint16_t *)(driver->apps_rsp_buf + 14) = MSG_SSID_1_LAST;
		*(uint16_t *)(driver->apps_rsp_buf + 16) = MSG_SSID_2;
		*(uint16_t *)(driver->apps_rsp_buf + 18) = MSG_SSID_2_LAST;
		*(uint16_t *)(driver->apps_rsp_buf + 20) = MSG_SSID_3;
		*(uint16_t *)(driver->apps_rsp_buf + 22) = MSG_SSID_3_LAST;
		*(uint16_t *)(driver->apps_rsp_buf + 24) = MSG_SSID_4;
		*(uint16_t *)(driver->apps_rsp_buf + 26) = MSG_SSID_4_LAST;
		*(uint16_t *)(driver->apps_rsp_buf + 28) = MSG_SSID_5;
		*(uint16_t *)(driver->apps_rsp_buf + 30) = MSG_SSID_5_LAST;
		*(uint16_t *)(driver->apps_rsp_buf + 32) = MSG_SSID_6;
		*(uint16_t *)(driver->apps_rsp_buf + 34) = MSG_SSID_6_LAST;
		*(uint16_t *)(driver->apps_rsp_buf + 36) = MSG_SSID_7;
		*(uint16_t *)(driver->apps_rsp_buf + 38) = MSG_SSID_7_LAST;
		*(uint16_t *)(driver->apps_rsp_buf + 40) = MSG_SSID_8;
		*(uint16_t *)(driver->apps_rsp_buf + 42) = MSG_SSID_8_LAST;
		*(uint16_t *)(driver->apps_rsp_buf + 44) = MSG_SSID_9;
		*(uint16_t *)(driver->apps_rsp_buf + 46) = MSG_SSID_9_LAST;
		*(uint16_t *)(driver->apps_rsp_buf + 48) = MSG_SSID_10;
		*(uint16_t *)(driver->apps_rsp_buf + 50) = MSG_SSID_10_LAST;
		*(uint16_t *)(driver->apps_rsp_buf + 52) = MSG_SSID_11;
		*(uint16_t *)(driver->apps_rsp_buf + 54) = MSG_SSID_11_LAST;
		*(uint16_t *)(driver->apps_rsp_buf + 56) = MSG_SSID_12;
		*(uint16_t *)(driver->apps_rsp_buf + 58) = MSG_SSID_12_LAST;
		*(uint16_t *)(driver->apps_rsp_buf + 60) = MSG_SSID_13;
		*(uint16_t *)(driver->apps_rsp_buf + 62) = MSG_SSID_13_LAST;
		*(uint16_t *)(driver->apps_rsp_buf + 64) = MSG_SSID_14;
		*(uint16_t *)(driver->apps_rsp_buf + 66) = MSG_SSID_14_LAST;
		*(uint16_t *)(driver->apps_rsp_buf + 68) = MSG_SSID_15;
		*(uint16_t *)(driver->apps_rsp_buf + 70) = MSG_SSID_15_LAST;
		*(uint16_t *)(driver->apps_rsp_buf + 72) = MSG_SSID_16;
		*(uint16_t *)(driver->apps_rsp_buf + 74) = MSG_SSID_16_LAST;
		*(uint16_t *)(driver->apps_rsp_buf + 76) = MSG_SSID_17;
		*(uint16_t *)(driver->apps_rsp_buf + 78) = MSG_SSID_17_LAST;
		*(uint16_t *)(driver->apps_rsp_buf + 80) = MSG_SSID_18;
		*(uint16_t *)(driver->apps_rsp_buf + 82) = MSG_SSID_18_LAST;
		ENCODE_RSP_AND_SEND(83);
		return 0;
	}
	/* Check for AO8960 Respond to Get Subsys Build mask */
	else if (!(driver->ch) && (chk_config_get_id() == AO8960_TOOLS_ID)
			 && (*buf == 0x7d) && (*(buf+1) == 0x2)) {
		ssid_first = *(uint16_t *)(buf + 2);
		ssid_last = *(uint16_t *)(buf + 4);
		ssid_range = 4 * (ssid_last - ssid_first + 1);
		/* frame response */
		driver->apps_rsp_buf[0] = 0x7d;
		driver->apps_rsp_buf[1] = 0x2;
		*(uint16_t *)(driver->apps_rsp_buf + 2) = ssid_first;
		*(uint16_t *)(driver->apps_rsp_buf + 4) = ssid_last;
		driver->apps_rsp_buf[6] = 0x1;
		driver->apps_rsp_buf[7] = 0x0;
		ptr = driver->apps_rsp_buf + 8;
		/* bld time masks */
		switch (ssid_first) {
		case MSG_SSID_0:
			for (i = 0; i < ssid_range; i += 4)
				*(int *)(ptr + i) = msg_bld_masks_0[i/4];
			break;
		case MSG_SSID_1:
			for (i = 0; i < ssid_range; i += 4)
				*(int *)(ptr + i) = msg_bld_masks_1[i/4];
			break;
		case MSG_SSID_2:
			for (i = 0; i < ssid_range; i += 4)
				*(int *)(ptr + i) = msg_bld_masks_2[i/4];
			break;
		case MSG_SSID_3:
			for (i = 0; i < ssid_range; i += 4)
				*(int *)(ptr + i) = msg_bld_masks_3[i/4];
			break;
		case MSG_SSID_4:
			for (i = 0; i < ssid_range; i += 4)
				*(int *)(ptr + i) = msg_bld_masks_4[i/4];
			break;
		case MSG_SSID_5:
			for (i = 0; i < ssid_range; i += 4)
				*(int *)(ptr + i) = msg_bld_masks_5[i/4];
			break;
		case MSG_SSID_6:
			for (i = 0; i < ssid_range; i += 4)
				*(int *)(ptr + i) = msg_bld_masks_6[i/4];
			break;
		case MSG_SSID_7:
			for (i = 0; i < ssid_range; i += 4)
				*(int *)(ptr + i) = msg_bld_masks_7[i/4];
			break;
		case MSG_SSID_8:
			for (i = 0; i < ssid_range; i += 4)
				*(int *)(ptr + i) = msg_bld_masks_8[i/4];
			break;
		case MSG_SSID_9:
			for (i = 0; i < ssid_range; i += 4)
				*(int *)(ptr + i) = msg_bld_masks_9[i/4];
			break;
		case MSG_SSID_10:
			for (i = 0; i < ssid_range; i += 4)
				*(int *)(ptr + i) = msg_bld_masks_10[i/4];
			break;
		case MSG_SSID_11:
			for (i = 0; i < ssid_range; i += 4)
				*(int *)(ptr + i) = msg_bld_masks_11[i/4];
			break;
		case MSG_SSID_12:
			for (i = 0; i < ssid_range; i += 4)
				*(int *)(ptr + i) = msg_bld_masks_12[i/4];
			break;
		case MSG_SSID_13:
			for (i = 0; i < ssid_range; i += 4)
				*(int *)(ptr + i) = msg_bld_masks_13[i/4];
			break;
		case MSG_SSID_14:
			for (i = 0; i < ssid_range; i += 4)
				*(int *)(ptr + i) = msg_bld_masks_14[i/4];
			break;
		case MSG_SSID_15:
			for (i = 0; i < ssid_range; i += 4)
				*(int *)(ptr + i) = msg_bld_masks_15[i/4];
			break;
		case MSG_SSID_16:
			for (i = 0; i < ssid_range; i += 4)
				*(int *)(ptr + i) = msg_bld_masks_16[i/4];
			break;
		case MSG_SSID_17:
			for (i = 0; i < ssid_range; i += 4)
				*(int *)(ptr + i) = msg_bld_masks_17[i/4];
			break;
		case MSG_SSID_18:
			for (i = 0; i < ssid_range; i += 4)
				*(int *)(ptr + i) = msg_bld_masks_18[i/4];
			break;
		}
		ENCODE_RSP_AND_SEND(8 + ssid_range - 1);
		return 0;
	}
	/* Check for download command */
	else if (cpu_is_msm8x60() && (*buf == 0x3A)) {
		/* send response back */
		driver->apps_rsp_buf[0] = *buf;
		ENCODE_RSP_AND_SEND(0);
		msleep(5000);
		/* call download API */
		msm_set_restart_mode(RESTART_DLOAD);
		printk(KERN_CRIT "diag: download mode set, Rebooting SoC..\n");
		lock_kernel();
		kernel_restart(NULL);
		unlock_kernel();
		/* Not required, represents that command isnt sent to modem */
		return 0;
	}
	 /* Check for ID for NO MODEM present */
	else if (!(driver->ch) && chk_config_get_id()) {
		/* Respond to polling for Apps only DIAG */
		if ((*buf == 0x4b) && (*(buf+1) == 0x32) &&
							 (*(buf+2) == 0x03)) {
			for (i = 0; i < 3; i++)
				driver->apps_rsp_buf[i] = *(buf+i);
			for (i = 0; i < 13; i++)
				driver->apps_rsp_buf[i+3] = 0;

			ENCODE_RSP_AND_SEND(15);
			return 0;
		}
		/* respond to 0x0 command */
		else if (*buf == 0x00) {
			for (i = 0; i < 55; i++)
				driver->apps_rsp_buf[i] = 0;

			ENCODE_RSP_AND_SEND(54);
			return 0;
		}
		/* respond to 0x7c command */
		else if (*buf == 0x7c) {
			driver->apps_rsp_buf[0] = 0x7c;
			for (i = 1; i < 8; i++)
				driver->apps_rsp_buf[i] = 0;
			/* Tools ID for APQ 8060 */
			*(int *)(driver->apps_rsp_buf + 8) =
							 chk_config_get_id();
			*(unsigned char *)(driver->apps_rsp_buf + 12) = '\0';
			*(unsigned char *)(driver->apps_rsp_buf + 13) = '\0';
			ENCODE_RSP_AND_SEND(13);
			return 0;
		}
	}
#endif
	/* Check for registered clients and forward packet to user-space */
	cmd_code = (int)(*(char *)buf);
	temp++;
	subsys_id = (int)(*(char *)temp);
	temp++;
	subsys_cmd_code = *(uint16_t *)temp;
	temp += 2;

	for (i = 0; i < diag_max_registration; i++) {
		if (driver->table[i].process_id != 0) {
			if (driver->table[i].cmd_code ==
				 cmd_code && driver->table[i].subsys_id ==
				 subsys_id &&
				driver->table[i].cmd_code_lo <=
				 subsys_cmd_code &&
				  driver->table[i].cmd_code_hi >=
				 subsys_cmd_code){
				driver->pkt_length = len;
				diag_update_pkt_buffer(buf);
				diag_update_sleeping_process(
					driver->table[i].process_id);
					return 0;
				} /* end of if */
			else if (driver->table[i].cmd_code == 255
				  && cmd_code == 75) {
				if (driver->table[i].subsys_id ==
					subsys_id &&
				   driver->table[i].cmd_code_lo <=
					subsys_cmd_code &&
					 driver->table[i].cmd_code_hi >=
					subsys_cmd_code){
					driver->pkt_length = len;
					diag_update_pkt_buffer(buf);
					diag_update_sleeping_process(
						driver->table[i].
						process_id);
					return 0;
				}
			} /* end of else-if */
			else if (driver->table[i].cmd_code == 255 &&
				  driver->table[i].subsys_id == 255) {
				if (driver->table[i].cmd_code_lo <=
						 cmd_code &&
						 driver->table[i].
						cmd_code_hi >= cmd_code){
					driver->pkt_length = len;
					diag_update_pkt_buffer(buf);
					diag_update_sleeping_process
						(driver->table[i].
						 process_id);
					return 0;
				}
			} /* end of else-if */
		} /* if(driver->table[i].process_id != 0) */
	}  /* for (i = 0; i < diag_max_registration; i++) */
	return packet_type;
}

void diag_process_hdlc(void *data, unsigned len)
{
	struct diag_hdlc_decode_type hdlc;
	int ret, type = 0;
#if defined(DIAG_DEBUG) || defined(CONFIG_DIAG_OVER_USB)
	int i;
	pr_debug("\n HDLC decode function, len of data  %d\n", len);
#endif
	hdlc.dest_ptr = driver->hdlc_buf;
	hdlc.dest_size = USB_MAX_OUT_BUF;
	hdlc.src_ptr = data;
	hdlc.src_size = len;
	hdlc.src_idx = 0;
	hdlc.dest_idx = 0;
	hdlc.escaping = 0;

	ret = diag_hdlc_decode(&hdlc);

	if (ret)
		type = diag_process_apps_pkt(driver->hdlc_buf,
							  hdlc.dest_idx - 3);
	else if (driver->debug_flag) {
		printk(KERN_ERR "Packet dropped due to bad HDLC coding/CRC"
				" errors or partial packet received, packet"
				" length = %d\n", len);
		print_hex_dump(KERN_DEBUG, "Dropped Packet Data: ", 16, 1,
					   DUMP_PREFIX_ADDRESS, data, len, 1);
		driver->debug_flag = 0;
	}
	/* implies this packet is NOT meant for apps */
	if (!(driver->ch) && type == 1 && chk_config_get_id()) {
		if (chk_config_get_id() == AO8960_TOOLS_ID) {
#if defined(CONFIG_DIAG_OVER_USB)
			driver->apps_rsp_buf[0] = 0x13;
			for (i = 0; i < hdlc.dest_idx; i++)
				driver->apps_rsp_buf[i+1] =
							 *(driver->hdlc_buf+i);
			ENCODE_RSP_AND_SEND(hdlc.dest_idx - 3);
#endif
		} else { /* APQ 8060, Let Q6 respond */
			if (driver->chqdsp)
				smd_write(driver->chqdsp, driver->hdlc_buf,
						  hdlc.dest_idx - 3);
		}
		type = 0;
	}

#ifdef DIAG_DEBUG
	printk(KERN_INFO "\n hdlc.dest_idx = %d", hdlc.dest_idx);
	for (i = 0; i < hdlc.dest_idx; i++)
		printk(KERN_DEBUG "\t%x", *(((unsigned char *)
							driver->hdlc_buf)+i));
#endif /* DIAG DEBUG */
	/* ignore 2 bytes for CRC, one for 7E and send */
	if ((driver->ch) && (ret) && (type) && (hdlc.dest_idx > 3)) {
		APPEND_DEBUG('g');
		smd_write(driver->ch, driver->hdlc_buf, hdlc.dest_idx - 3);
		APPEND_DEBUG('h');
#ifdef DIAG_DEBUG
		printk(KERN_INFO "writing data to SMD, pkt length %d\n", len);
		print_hex_dump(KERN_DEBUG, "Written Packet Data to SMD: ", 16,
			       1, DUMP_PREFIX_ADDRESS, data, len, 1);
#endif /* DIAG DEBUG */
	}
}

#ifdef CONFIG_DIAG_OVER_USB
#define N_LEGACY_WRITE	(driver->poolsize + 5) /* 2+1 for modem ; 2 for q6 */
#define N_LEGACY_READ	1

int diagfwd_connect(void)
{
	int err;

	printk(KERN_DEBUG "diag: USB connected\n");
	err = usb_diag_alloc_req(driver->legacy_ch, N_LEGACY_WRITE,
			N_LEGACY_READ);
	if (err)
		printk(KERN_ERR "diag: unable to alloc USB req on legacy ch");

	driver->usb_connected = 1;
	driver->in_busy_1 = 0;
	driver->in_busy_2 = 0;
	driver->in_busy_qdsp_1 = 0;
	driver->in_busy_qdsp_2 = 0;

	/* Poll SMD channels to check for data*/
	queue_work(driver->diag_wq, &(driver->diag_read_smd_work));
	queue_work(driver->diag_wq, &(driver->diag_read_smd_qdsp_work));
	/* Poll USB channel to check for data*/
	queue_work(driver->diag_wq, &(driver->diag_read_work));
#ifdef CONFIG_DIAG_SDIO_PIPE
	if (machine_is_msm8x60_charm_surf() || machine_is_msm8x60_charm_ffa()) {
		if (driver->mdm_ch && !IS_ERR(driver->mdm_ch))
			diagfwd_connect_sdio();
		else
			printk(KERN_INFO "diag: No USB MDM ch");
	}
#endif
	return 0;
}

int diagfwd_disconnect(void)
{
	printk(KERN_DEBUG "diag: USB disconnected\n");
	driver->usb_connected = 0;
	driver->in_busy_1 = 1;
	driver->in_busy_2 = 1;
	driver->in_busy_qdsp_1 = 1;
	driver->in_busy_qdsp_2 = 1;
	driver->debug_flag = 1;
	usb_diag_free_req(driver->legacy_ch);
#ifdef CONFIG_DIAG_SDIO_PIPE
	if (machine_is_msm8x60_charm_surf() || machine_is_msm8x60_charm_ffa())
		if (driver->mdm_ch && !IS_ERR(driver->mdm_ch))
			diagfwd_disconnect_sdio();
#endif
	/* TBD - notify and flow control SMD */
	return 0;
}

int diagfwd_write_complete(struct diag_request *diag_write_ptr)
{
	unsigned char *buf = diag_write_ptr->buf;
	/*Determine if the write complete is for data from modem/apps/q6 */
	/* Need a context variable here instead */
	if (buf == (void *)driver->buf_in_1) {
		driver->in_busy_1 = 0;
		APPEND_DEBUG('o');
		queue_work(driver->diag_wq, &(driver->diag_read_smd_work));
	} else if (buf == (void *)driver->buf_in_2) {
		driver->in_busy_2 = 0;
		APPEND_DEBUG('O');
		queue_work(driver->diag_wq, &(driver->diag_read_smd_work));
	} else if (buf == (void *)driver->buf_in_qdsp_1) {
		driver->in_busy_qdsp_1 = 0;
		APPEND_DEBUG('p');
		queue_work(driver->diag_wq, &(driver->diag_read_smd_qdsp_work));
	} else if (buf == (void *)driver->buf_in_qdsp_2) {
		driver->in_busy_qdsp_2 = 0;
		APPEND_DEBUG('P');
		queue_work(driver->diag_wq, &(driver->diag_read_smd_qdsp_work));
	}
#ifdef CONFIG_DIAG_SDIO_PIPE
	else if (buf == (void *)driver->buf_in_sdio)
		if (machine_is_msm8x60_charm_surf() ||
					 machine_is_msm8x60_charm_ffa())
			diagfwd_write_complete_sdio();
		else
			pr_err("diag: Incorrect buffer pointer while WRITE");
#endif
	else {
		diagmem_free(driver, (unsigned char *)buf, POOL_TYPE_HDLC);
		diagmem_free(driver, (unsigned char *)diag_write_ptr,
						 POOL_TYPE_WRITE_STRUCT);
		APPEND_DEBUG('q');
	}
	return 0;
}

int diagfwd_read_complete(struct diag_request *diag_read_ptr)
{
	int status = diag_read_ptr->status;
	unsigned char *buf = diag_read_ptr->buf;

	/* Determine if the read complete is for data on legacy/mdm ch */
	if (buf == (void *)driver->usb_buf_out) {
		driver->read_len_legacy = diag_read_ptr->actual;
		APPEND_DEBUG('s');
#ifdef DIAG_DEBUG
		printk(KERN_INFO "read data from USB, pkt length %d",
		    diag_read_ptr->actual);
		print_hex_dump(KERN_DEBUG, "Read Packet Data from USB: ", 16, 1,
		       DUMP_PREFIX_ADDRESS, diag_read_ptr->buf,
		       diag_read_ptr->actual, 1);
#endif /* DIAG DEBUG */
		if (driver->logging_mode == USB_MODE) {
			if (status != -ECONNRESET && status != -ESHUTDOWN)
				queue_work(driver->diag_wq,
					&(driver->diag_proc_hdlc_work));
			else
				queue_work(driver->diag_wq,
						 &(driver->diag_read_work));
		}
	}
#ifdef CONFIG_DIAG_SDIO_PIPE
	else if (buf == (void *)driver->usb_buf_mdm_out) {
		if (machine_is_msm8x60_charm_surf() ||
					 machine_is_msm8x60_charm_ffa()) {
			driver->read_len_mdm = diag_read_ptr->actual;
			diagfwd_read_complete_sdio();
		} else
			pr_err("diag: Incorrect buffer pointer while READ");
	}
#endif
	else
		printk(KERN_ERR "diag: Unknown buffer ptr from USB");

	return 0;
}
//EricCHWang add for SD download
#define SD_CARD_DOWNLOAD	1
#if SD_CARD_DOWNLOAD
int diag_read_from_smd(uint8_t * res_buf, int16_t* res_size)
{
	unsigned long flags;
	//int ret = 0;//, type = 0;
    int sz;
    int gg = 0;
    int retry = 0;
    int rc = -1;

    DIAG_DBG_MSG_G4("[diagfwd]diag_read_from_smd start\n");
	for(retry = 0; retry < DIAG_READ_RETRY_COUNT; )
	{
        sz = smd_cur_packet_size(driver->ch);
        DIAG_DBG_MSG_G4(KERN_INFO "[wilson][WARNING]sz = %d\n", sz);
		if (sz == 0)
        {
            msleep(5);
            retry++;
			continue;
        }
		gg = smd_read_avail(driver->ch);
		DIAG_DBG_MSG_G4(KERN_INFO "[wilson]smd_read_avail()= %d\n", gg);
		if (sz > gg)
		{
			DIAG_DBG_MSG_G4(KERN_INFO "[wilson][WARNING] smd_read_avail()= %d\n", gg);
			continue;
		}
		//if (sz > 535) {
		//	smd_read(driver->ch, 0, sz);
		//	continue;
		//}

		spin_lock_irqsave(&diag_smd_lock, flags);//mutex_lock(&nmea_rx_buf_lock);
		if (smd_read(driver->ch, res_buf, sz) == sz) {
			spin_unlock_irqrestore(&diag_smd_lock, flags);//mutex_unlock(&nmea_rx_buf_lock);
			DIAG_DBG_MSG_G4(KERN_ERR "diag_read_from_smd: not enough data?!\n");
			break;
		}
		//nmea_devp->bytes_read = sz;
		spin_unlock_irqrestore(&diag_smd_lock, flags);//mutex_unlock(&nmea_rx_buf_lock);
	 }
    *res_size = sz;
    if (retry >= DIAG_READ_RETRY_COUNT)
    {
        rc = -2;
        goto lbExit;
    }
    rc = 0;
	//print_hex_dump(KERN_DEBUG, "", DUMP_PREFIX_OFFSET,
	//			16, 1, res_buf, sz, 0);
lbExit:
    DIAG_DBG_MSG_G4("[diagfwd]diag_read_from_smd end read %d bytes, rc=%d\n", sz, rc);    
    return rc;
}
EXPORT_SYMBOL(diag_read_from_smd);

void diag_write_to_smd(uint8_t * cmd_buf, int cmd_size)
{
	unsigned long flags;
	int need;
	//paul// need = sizeof(cmd_buf);
	need = cmd_size;
	DIAG_DBG_MSG_G4("[diagfwd]diag_write_to_smd start\n");
	spin_lock_irqsave(&diag_smd_lock, flags);
	while (smd_write_avail(driver->ch) < need) {
		spin_unlock_irqrestore(&diag_smd_lock, flags);
		msleep(10);
		spin_lock_irqsave(&diag_smd_lock, flags);
	}
    smd_write(driver->ch, cmd_buf, cmd_size);
    spin_unlock_irqrestore(&diag_smd_lock, flags);
    DIAG_DBG_MSG_G4("[diagfwd]diag_write_to_smd end\n");
	//print_hex_dump(KERN_DEBUG, "", DUMP_PREFIX_OFFSET,
	//			16, 1, cmd_buf, cmd_size, 0);
}
EXPORT_SYMBOL(diag_write_to_smd);
// --- To back up NV for image update, paul ---
#endif
#ifdef CONFIG_FIH_FXX
#if SAVE_MODEM_EFS_LOG
static void efs_send_req(unsigned char * cmd_buf ,int cmd_size)
{
	unsigned long flags;
	int need;
	//paul// need = sizeof(cmd_buf);
	need = cmd_size;
	DIAG_DBG_MSG_G4("[diagfwd]efs_send_req +++\n");
	spin_lock_irqsave(&diag_smd_lock, flags);
	while (smd_write_avail(driver->ch) < need) {
		spin_unlock_irqrestore(&diag_smd_lock, flags);
		msleep(250);
		spin_lock_irqsave(&diag_smd_lock, flags);
	}
    	smd_write(driver->ch, cmd_buf, cmd_size);
    	spin_unlock_irqrestore(&diag_smd_lock, flags);
    	DIAG_DBG_MSG_G4("[diagfwd]efs_send_req ---\n");
	//print_hex_dump(KERN_DEBUG, "", DUMP_PREFIX_OFFSET, 16, 1, cmd_buf, cmd_size, 0);
}
static int efs_recv_res(unsigned char * res_buf ,int res_size)
{
	unsigned long flags;
	//int need;
	static unsigned char responseBuf_temp[EFS_BUFFER_SIZE]; //Declaired as static to avoid compiler(gcc-4.4.0)'s warning
	struct diag_hdlc_decode_type hdlc;
	int ret = 0;//, type = 0;
    	int sz;
    	int gg = 0;
    	int retry = 0;
    	int rc = -EFS_DIAG_TRANSACTION_NO_DATA;
	hdlc.dest_ptr = res_buf;//driver->hdlc_buf;
	hdlc.dest_size = res_size;//USB_MAX_OUT_BUF;
	hdlc.src_ptr = responseBuf_temp;//data;
	//hdlc.src_size = res_size;//len;
	hdlc.src_size = sizeof(responseBuf_temp);//len;
	hdlc.src_idx = 0;
	hdlc.dest_idx = 0;
	hdlc.escaping = 0;
    	#if 0
    	need = sizeof(res_buf);
    	spin_lock_irqsave(&smd_lock, flags);
    	while (smd_read_avail(driver->ch) < need) {
		spin_unlock_irqrestore(&smd_lock, flags);
		msleep(250);
		spin_lock_irqsave(&smd_lock, flags);
	}

	//	do{
    	//spin_lock_irqsave(&smd_lock, flags);
     	smd_read(driver->ch, responseBuf_temp, res_size);
	 
	spin_unlock_irqrestore(&smd_lock, flags);
	#endif
	DIAG_DBG_MSG_G4("[diagfwd]efs_recv_res +++\n");
     	memset(responseBuf_temp, 0, sizeof(responseBuf_temp));
	for(retry = 0 ; retry<DIAG_READ_RETRY_COUNT ;)
	{
        		sz = smd_cur_packet_size(driver->ch);
        		//printk(KERN_INFO "[wilson][WARNING]sz = %d\n", sz);
		if (sz == 0)
       		{
            		retry++;
            		msleep(5);
			continue;
        		}
		gg = smd_read_avail(driver->ch);
		DIAG_DBG_MSG_G4(KERN_INFO "[wilson]smd_read_avail()= %d\n", gg);
		if (sz > gg)
		{
			DIAG_DBG_MSG_G4(KERN_INFO "[wilson][WARNING] smd_read_avail()= %d\n", gg);
			continue;
		}
		//if (sz > 535) {
		//	smd_read(driver->ch, 0, sz);
		//	continue;
		//}
		// sz should not be so large. So we take it as an abnormal case.
		if (sz >= sizeof(responseBuf_temp))
        		{
            		DIAG_DBG_MSG_G4(KERN_INFO "sz=%d, larger than our buffer!\n", sz);      
            		goto lbExit;
        		}
		spin_lock_irqsave(&diag_smd_lock, flags);//mutex_lock(&nmea_rx_buf_lock);
		if (smd_read(driver->ch, responseBuf_temp, sz) == sz) {
			spin_unlock_irqrestore(&diag_smd_lock, flags);//mutex_unlock(&nmea_rx_buf_lock);
			DIAG_DBG_MSG_G4(KERN_ERR "efs: not enough data?!\n");
			break;
		}
		//nmea_devp->bytes_read = sz;
		spin_unlock_irqrestore(&diag_smd_lock, flags);//mutex_unlock(&nmea_rx_buf_lock);
	}
     	if (retry >= DIAG_READ_RETRY_COUNT)
        		goto lbExit;

	ret = diag_hdlc_decode(&hdlc); //decode hdlc protocol

     	rc = EFS_DIAG_TRANSACTION_OK;
lbExit:
    
	DIAG_DBG_MSG_G4("[diagfwd]efs_recv_res ---\n");

    	//print_hex_dump(KERN_DEBUG, "", DUMP_PREFIX_OFFSET, 16, 1, res_buf, res_size, 0);

    	return rc;
}

static int efs_diag_transaction(unsigned char * TxBuf, int TxBufSize, unsigned char * RxBuf, int RxBufSize)
{
    	int retry = 5;
    	int rc = -1;
    	int error_code = EFS_ERR_NONE;
    
    	do
    	{
        		#ifdef SAVE_QXDM_LOG_TO_SD_CARD
        		if (bLogStart || driver->usb_connected)
        		#else
        		if (driver->usb_connected)
        		#endif
        		{
            		rc = -EFS_DIAG_TRANSACTION_ABORT;
            		break;
        		}
        		efs_send_req(TxBuf, TxBufSize);
lbReadDataAgain:
        		rc = efs_recv_res(RxBuf, RxBufSize);

        		if (rc < 0)
        		{
            		DIAG_DBG_MSG_G4("Didn't get enough data! \n", retry);
            		if (retry-- < 0)
                			break;
           		else
                			continue;
        		}
        		if (TxBuf[0] != RxBuf[0] || TxBuf[1] != RxBuf[1] || TxBuf[2] != RxBuf[2])
        		{
            		rc = -EFS_DIAG_TRANSACTION_WRONG_DATA;
            		DIAG_DBG_MSG_G4("response not match. Read data again!\n");
            		print_hex_dump(KERN_DEBUG, "", DUMP_PREFIX_OFFSET, 16, 1, RxBuf, RxBufSize, 0);
            		if (retry-- < 0)
                			break;
            		else
                			goto lbReadDataAgain;
        		}
        		else
        		{
            		if (RxBuf[0] == 0x4b && RxBuf[1] == 0x13)
            		{
                			switch (RxBuf[2])
                			{
                    			case 0x0d:  //Close dir
                    			case 0x03:  //Close file
                        				error_code = *(uint32_t *)&RxBuf[4];
                        				break;
                    			case 0x0c:  //Read dir
                        				error_code = *(uint32_t *)&RxBuf[12];
                        				break;
                    			case 0x0b:  //Open dir
                    			case 0x02:  //Open file
                        				error_code = *(uint32_t *)&RxBuf[8];
                        				break;
                    			case 0x04:  //Read file
                        				error_code = *(uint32_t *)&RxBuf[16];
                        				break;
                    			default:
                        				error_code = EFS_ERR_UNKNOWN;
                        				break;
                			}
            		}
            		if (error_code)
            		{
                			if (error_code == EFS_ENOENT)
                			{
                    			DIAG_DBG_MSG_G4("No such file or directory," "Cmd:0x%x Error:0x%x\n", *(uint32_t *)&RxBuf[0], error_code);
                    			rc = -EFS_DIAG_TRANSACTION_NO_FILE_DIR;
                    			break;
               			}
                			else
                			{
                    			DIAG_DBG_MSG_G4("Cmd:0x%x Error:0x%x\n", *(uint32_t *)&RxBuf[0], error_code);
                    			rc = -EFS_DIAG_TRANSACTION_CMD_ERROR;
                			}
            		}
        		}
    	}while(rc < 0 && retry-- > 0);

    	return rc;
}

static ssize_t save_efs2sd(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
    	int mutex_rc;
    	int rc = EFSLOG_STATUS_DEFAULT;
	unsigned char * efs_req_buf = NULL;
	unsigned char * efs_read_file_buf = NULL;
	unsigned char * responseBuf = NULL;
	unsigned char *write_p = NULL;
	int efs_file_name_length = 0;
	int dirp = 0;
	int req_size = 0;
	unsigned int efs_read_res_size = 0;
	mm_segment_t oldfs = get_fs();

	int i=0;
	int fd = 0;
	int bEOF = 0;
	uint32_t read_offset = 0;
	#if 1
	//char start[1]={0x0c};
	//char check[4]={0x4b, 0x04, 0x0e, 00,};
	//char EFS_hello_req[44]={0x4b ,0x13 ,00 ,00 , 00 ,00 ,00 ,00  ,00 ,00 ,00 ,00  ,00 ,00 ,00 ,00,  
    	//                       00 ,00 ,00 ,00 , 00 ,00 ,00 ,00  ,00 ,00 ,00 ,00  ,00 ,00 ,00 ,00,  
    	//                       00 ,00 ,00 ,00 , 00 ,00 ,00 ,00  ,00 ,00 ,00 ,00};
    	//char EFS_opendir_root_req[6]={0x4b, 0x13, 0x0b ,00  ,0x2f, 00 }; //open root

    	char * efs_dir[2] = {"OEMDBG_LOG", "err"};
    	char deliminator = '/';
    	int dir_index = 0;
    	unsigned char EFS_opendir_req[] = {0x4b, 0x13, 0x0b, 0x00};
    	unsigned char EFS_readdir_req[12] = {0x4b ,0x13, 0x0c, 0x00 , 0x01,//req[4]:Directory pointer
    	                        0x00 , 0x00, 0x00 , 0x01 ,0x00 ,0x00 ,0x00};                 
    	unsigned char EFS_openfile_req[] = {0x4b, 0x13, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x01, 0x00, 0x00};
   	unsigned char EFS_readfile_req[16] = {0x4b, 0x13, 0x04, 00, 00, 00, 00, 00, 00, 02, 00, 00, 00, 00, 00, 00};
    	unsigned char EFS_closedir_req[8] = {0x4b, 0x13, 0x0d, 00, 0x01, 00 ,00 ,00};
	unsigned char EFS_closefile_req[8] = {0x4b, 0x13, 03, 00, 00, 00, 00, 00};
	#endif
    	int readdir_i;

    	mutex_rc = mutex_lock_interruptible(&efslog_mutex);

    	efslog_result = 0;

    	// Don't get the efs logs if QXDM log is enabled. Because the diag port is occupied.
    	#ifdef SAVE_QXDM_LOG_TO_SD_CARD
    	if (bLogStart || driver->usb_connected)
    	#else
    	if (driver->usb_connected)
    	#endif
    	{
        		rc = EFSLOG_STATUS_DIAG_PORT_INVALID;
        		goto lbExit;
    	}

    	// read and write OEMDBG_LOG/files  +++++++++++++++++++++++  
    	efs_read_file_buf = kzalloc(EFS_BUFFER_SIZE, GFP_KERNEL);  //allocate buffer for reading file
    	DIAG_DBG_MSG_G4("efs_read_file_buf:0x%p\n", efs_read_file_buf);
    	if ( efs_read_file_buf == NULL)
    	{
        		DIAG_DBG_MSG_G4(KERN_ERR "kzalloc efs_read_file_buf_size fail!\n");
        		rc = EFSLOG_STATUS_MEMORY_ALLOCATION_FAIL;
	    	goto lbExit;
    	}
    	efs_req_buf = kzalloc(EFS_BUFFER_SIZE, GFP_KERNEL);
    	DIAG_DBG_MSG_G4("efs_req_buf:0x%p\n", efs_req_buf);
    	if ( efs_req_buf == NULL)
    	{
        		DIAG_DBG_MSG_G4(KERN_ERR "kzalloc efs_req_buf fail!\n");
        		rc = EFSLOG_STATUS_MEMORY_ALLOCATION_FAIL;
	    	goto lbExit;
    	}
    	responseBuf = kzalloc(EFS_BUFFER_SIZE, GFP_KERNEL);
    	DIAG_DBG_MSG_G4("responseBuf:0x%p\n", responseBuf);
    	if ( responseBuf == NULL)
    	{
        		DIAG_DBG_MSG_G4(KERN_ERR "kzalloc efs_req_buf fail!\n");
        		rc = EFSLOG_STATUS_MEMORY_ALLOCATION_FAIL;
	    	goto lbExit;
    	}

    	// Just read the "OEMDBG_LOG" and "err" directories.
    	for (dir_index = 0; dir_index<2; dir_index++)
    	{
        		EFS_readdir_req[8] = 1;
        		readdir_i = 2;

        		DIAG_DBG_MSG_G4("open dir %s\n", efs_dir[dir_index]);
        		memcpy(efs_req_buf, EFS_opendir_req, sizeof(EFS_opendir_req));
        		req_size = sizeof(EFS_opendir_req) + strlen(efs_dir[dir_index]) + 1; //The NULL ended character must be included
        		memcpy((efs_req_buf + sizeof(EFS_opendir_req)), (uint8_t *)efs_dir[dir_index], (req_size - sizeof(EFS_opendir_req)));
        		DIAG_DBG_MSG_G4("req_size=%d, efs_req_buf:\n",req_size);
    		//print_hex_dump(KERN_DEBUG, "", DUMP_PREFIX_OFFSET, 16, 1, efs_req_buf, req_size, 0);
        		rc = efs_diag_transaction(efs_req_buf, req_size, responseBuf, EFS2_DIAG_OPENDIR_RES_SIZE);
        		if (rc < 0)
        		{
            		DIAG_DBG_MSG_G4("open dir %s failed\n", efs_dir[dir_index]);
            		break;
        		}

        		dirp = responseBuf[4];
        		DIAG_DBG_MSG_G4("the dirp=0x%x\n",responseBuf[4]);
        		if (diag_char_debug_mask & FIH_DEBUG_ZONE_G4)
        		{
            		print_hex_dump(KERN_DEBUG, "", DUMP_PREFIX_OFFSET,
    				16, 1, responseBuf, 7, 0);
        		}
    		while(1){
            		EFS_readdir_req[4] = dirp;

            		DIAG_DBG_MSG_G4("read dir\n");
            		rc = efs_diag_transaction(EFS_readdir_req, sizeof(EFS_readdir_req), responseBuf, EFS2_DIAG_READDIR_RES_SIZE);
            		if (rc < 0)
            		{
                			DIAG_DBG_MSG_G4("read OEMDBG_LOG dir failed\n");
                			break;
            		}

      			EFS_readdir_req[8] = readdir_i++; //Sequence number of directory entry to read
        			DIAG_DBG_MSG_G4("read %s dir\n", efs_dir[dir_index]);
        			DIAG_DBG_MSG_G4("file name: %s\n",&responseBuf[40]);

        			if(responseBuf[40] == 0x00) //the file name is null
        				break;

            		i = snprintf(efs_file_path, sizeof(efs_file_path), "%s%s", efs_log_dir_path[dir_index], &responseBuf[40]);
         		if (i >= sizeof(efs_file_path))
                			efs_file_path[FILE_NAME_LENGTH - 1] = '\0';
         		DIAG_DBG_MSG_G4("efs_file_path: %s\n", efs_file_path);

         		efs_file_name_length = strlen(&responseBuf[40]) + 1;    //Include the NULL ended character
    			DIAG_DBG_MSG_G4("efs_file_name_length=%d\n", efs_file_name_length);
         		req_size = sizeof(EFS_openfile_req) + strlen(efs_dir[dir_index]) + 1 + efs_file_name_length; 
    			i = strlen(efs_dir[dir_index]);
    			memcpy(efs_req_buf, EFS_openfile_req, sizeof(EFS_openfile_req));
      			memcpy((efs_req_buf + sizeof(EFS_openfile_req)), efs_dir[dir_index], i);
         		memcpy((efs_req_buf + sizeof(EFS_openfile_req) + i), &deliminator, 1);
    			memcpy((efs_req_buf + sizeof(EFS_openfile_req) + i + 1), &responseBuf[40], efs_file_name_length);

    	    		DIAG_DBG_MSG_G4("open file in dir req_size=%d, efs_req_buf:\n", req_size);
    	    		//print_hex_dump(KERN_DEBUG, "", DUMP_PREFIX_OFFSET, 16, 1, efs_req_buf, req_size, 0);
            		rc = efs_diag_transaction(efs_req_buf, req_size, responseBuf, EFS2_DIAG_OPEN_RES_SIZE);
            		if (rc < 0)
           		{
                			DIAG_DBG_MSG_G4("open file failed\n");
                			break;
            		}

    			fd = responseBuf[4];
    			DIAG_DBG_MSG_G4("open file\n");
    			EFS_readfile_req[4] = fd;

    			bEOF = 0;
    			read_offset = 0;

            		set_fs(KERNEL_DS);
          		efs_file_filp = filp_open(efs_file_path, O_CREAT|O_WRONLY|O_LARGEFILE, 0666);
            		if (IS_ERR(efs_file_filp))
        			{
        				efs_file_filp = NULL;
        				DIAG_DBG_MSG_G1(KERN_ERR "Open %s error!\n", efs_file_path);
                			rc = EFSLOG_STATUS_CREATE_FILE_FAIL;
        				goto lbExit;
        			}
    			while(!bEOF) //write file until EOF
    	    		{
                			int writesize = 0;
    	        			*(uint32_t *) &EFS_readfile_req[12] = read_offset;

                			DIAG_DBG_MSG_G4("Read file req, offset:0x%x size:0x%x\n", *(uint32_t *)&EFS_readfile_req[12], *(uint32_t *)&EFS_readfile_req[8]);
                			rc = efs_diag_transaction(EFS_readfile_req, sizeof(EFS_readfile_req), efs_read_file_buf, EFS_BUFFER_SIZE);
                			if (rc < 0)
                			{
                    			DIAG_DBG_MSG_G4("read file failed\n");
                    			break;
                			}

        				read_offset += READ_FILE_SIZE;

        				write_p = &efs_read_file_buf[20];
        				efs_read_res_size = (efs_read_file_buf[13] << 8) + efs_read_file_buf[12] ; 
        				//DIAG_DBG_MSG_G4("read file size: %d bytes efs_read_file_buf:0x%x write_p:0x%x\n", efs_read_res_size, efs_read_file_buf, write_p);

        				if(efs_read_res_size == 0)
        					bEOF = 1;
        				else if(efs_read_res_size < READ_FILE_SIZE)
        				{
        		    			if (efs_file_filp)
                   			{
            		    			writesize = efs_file_filp->f_op->write(efs_file_filp,(unsigned char __user *)(write_p), efs_read_res_size ,&efs_file_filp->f_pos);
                        				if (writesize != efs_read_res_size)
                        				{
                            				DIAG_DBG_MSG_G4("write file failed write size=0x%x expected:0x%x\n", writesize, efs_read_res_size);
                            				break;
                        				}
                   			}
        		    			bEOF = 1;
        				}
        				else
                			{
                    			if (efs_file_filp)
                    			{
                        				writesize = efs_file_filp->f_op->write(efs_file_filp,(unsigned char __user *)(write_p), efs_read_res_size ,&efs_file_filp->f_pos);
                        				if (writesize != efs_read_res_size)
                       				{
                            				DIAG_DBG_MSG_G4("write file failed write size=0x%x expected:0x%x\n", writesize, efs_read_res_size);
                            				break;
                        				}
                   			}
                			}
           		}
            		if (efs_file_filp)
            		{
                			vfs_fsync(efs_file_filp, 1);
                			filp_close(efs_file_filp, NULL);
                			efs_file_filp = NULL;
            		}
            		DIAG_DBG_MSG_G4("close file\n");
            		rc = efs_diag_transaction(EFS_closefile_req, sizeof(EFS_closefile_req), responseBuf, EFS2_DIAG_CLOSE_RES_SIZE);
            		if (rc < 0)
            		{
                			DIAG_DBG_MSG_G4("close file failed\n");
                			break;
            		}
        		};//while(1) read content until the pathname is null

        		DIAG_DBG_MSG_G4("close dir\n");
        		rc = efs_diag_transaction(EFS_closedir_req, sizeof(EFS_closedir_req), responseBuf, EFS2_DIAG_CLOSEDIR_RES_SIZE);
        		if (rc < 0)
        		{
           	 	DIAG_DBG_MSG_G4("close dir failed\n");
            		break;
        		}
    	}

    	DIAG_DBG_MSG_G4("rc=%d\n",rc);
    	if (rc == -EFS_DIAG_TRANSACTION_NO_DATA 
     	|| rc == -EFS_DIAG_TRANSACTION_WRONG_DATA
    	|| rc == -EFS_DIAG_TRANSACTION_ABORT)
    	{
        		rc = EFSLOG_STATUS_DIAG_PORT_INVALID;
    	}
    	else if (rc == -EFS_DIAG_TRANSACTION_CMD_ERROR)
    	{
        		rc = EFSLOG_STATUS_FAIL_TO_OPEN_MODEM_FILE;
    	}
    	else
        		rc = EFSLOG_STATUS_SUCCESS;
lbExit:

    	efslog_result = rc;
    	if (efs_read_file_buf)
        		kfree(efs_read_file_buf);
    	if (efs_req_buf)
        		kfree(efs_req_buf);
    	if (responseBuf)
        		kfree(responseBuf);

    	if (efs_file_filp)
    	{
        		filp_close(efs_file_filp, NULL);
        		efs_file_filp = NULL;
    	}

    	set_fs(oldfs);
    	mutex_unlock(&efslog_mutex);

	return count;
}

DEVICE_ATTR(efs2sd, 0777, NULL, save_efs2sd);
#endif
#endif  // End of #ifdef CONFIG_FIH_FXX

/* FIH, JiaHao, 2011/09/30 { */ /* fver */
// efs_page = the index of page in fver which want to read
// efs_buf  = store the read back page of BSP/fver 
int read_efsfver(int efs_page, char *efs_buf)
{
	char src[] = "BSP/fver";

	char req_cmd[256];
	int  req_size;
	char res_dat[544];
	int  res_size;

	int rc;
	int fd;
	int offset;
	int bEOF;
	char *chr = NULL;
	int len;
	int total;

	char CMD_OpenFile[]  = {0x4b, 0x13, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x01, 0x00, 0x00};
	char CMD_CloseFile[] = {0x4b, 0x13, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00};
	char CMD_ReadFile[]  = {0x4b, 0x13, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

	if (NULL == efs_buf) {
		DIAG_DBG_MSG_G6(KERN_ERR "read_efsfver: [WARNING] efs_buf is NULL\n");
		DIAG_DBG_MSG_G6(KERN_ERR "read_efsfver: [INFO] return the all byte(s) of %s\n", src);
	}
	DIAG_DBG_MSG_G6("read_efsfver: [INFO] efs_page = %d\n", efs_page);

	// open BSP/fver file
	DIAG_DBG_MSG_G6(KERN_ERR "read_efsfver: [INFO] Open %s (src)\n", src);
	memcpy(req_cmd, CMD_OpenFile, sizeof(CMD_OpenFile));
	memcpy((req_cmd + sizeof(CMD_OpenFile)), src, sizeof(src));
	req_size = sizeof(CMD_OpenFile) + sizeof(src) + 1; // +1 for null end of string
	memset(res_dat, sizeof(res_dat), 0);
	res_size = EFS2_DIAG_OPEN_RES_SIZE;

	rc = efs_diag_transaction(req_cmd, req_size, res_dat, res_size);
	if (rc < 0) {
		DIAG_DBG_MSG_G6(KERN_ERR "read_efsfver: [ERRPR] Open %s Failed #(-1)\n", src);
		total = (-1);
		return total;
	}
	fd = res_dat[4];
	offset = PAGE_SIZE * efs_page;
	DIAG_DBG_MSG_G6("read_efsfver: [INFO] offset = %d\n", offset);
	bEOF = 0;
	total = 0;

	// read BSP/fver file
	while (!bEOF)
	{
		memset(req_cmd, sizeof(req_cmd), 0);
		memcpy(req_cmd, CMD_ReadFile, sizeof(CMD_ReadFile));
		req_cmd[4] = fd;
		*(uint32_t *) &req_cmd[12] = offset;
		req_size = sizeof(CMD_ReadFile);
		memset(res_dat, sizeof(res_dat), 0);
		res_size = 544;

		rc = efs_diag_transaction(req_cmd, req_size, res_dat, res_size);
		if (rc < 0) {
			DIAG_DBG_MSG_G6(KERN_ERR "read_efsfver: [ERROR] Read %s Failed #(-2)\n", src);
			total = (-2);
			break;
		}

		offset += READ_FILE_SIZE;
		chr = &res_dat[20];
		len = (res_dat[13] << 8) + res_dat[12];
		DIAG_DBG_MSG_G6("read_efsfver: [INFO] len = %d\n", len);
		total += len;

		// write BSP/fver into efs_buf
		if (0 == len)
		{
			bEOF = 1;
		}
		else if (len < READ_FILE_SIZE)
		{
			bEOF = 1;
			if ((NULL != efs_buf)&&(total <= PAGE_SIZE)) {
				memcpy((efs_buf+(total-len)), chr, len);
			}
		}
		else
		{
			if ((NULL != efs_buf)&&(total <= PAGE_SIZE)) {
				memcpy((efs_buf+(total-len)), chr, len);
			}
		}

		if ((PAGE_SIZE <= total)&&(NULL != efs_buf)) {
			bEOF = 1;
		}
	} // while (!bEOF)

	// close BSP/fver file
	DIAG_DBG_MSG_G6("read_efsfver: [INFO] Close %s\n", src);
	memset(req_cmd, sizeof(req_cmd), 0);
	memcpy(req_cmd, CMD_CloseFile, sizeof(CMD_CloseFile));
	req_size = sizeof(CMD_CloseFile);
	memset(res_dat, sizeof(res_dat), 0);
	res_size = EFS2_DIAG_CLOSE_RES_SIZE;

	rc = efs_diag_transaction(req_cmd, req_size, res_dat, res_size);
	if (rc < 0) {
		DIAG_DBG_MSG_G6("read_efsfver: [ERROR] Close %s Failed\n", src);
	}

	DIAG_DBG_MSG_G6("read_efsfver: [INFO] total = %d\n", total);
	return total;
}
/* FIH, JiaHao, 2011/09/30 } */ /* fver */

void diag_read_work_fn(struct work_struct *work)
{
#if SAVE_QXDM_LOG_TO_SD_CARD
	unsigned char *head = NULL;
#endif
	APPEND_DEBUG('d');
	driver->usb_read_ptr->buf = driver->usb_buf_out;
	driver->usb_read_ptr->length = USB_MAX_OUT_BUF;
	usb_diag_read(driver->legacy_ch, driver->usb_read_ptr);
	APPEND_DEBUG('e');
#if SAVE_QXDM_LOG_TO_SD_CARD
	if (bCaptureFilter)
	{
		if (gFilter_filp != NULL)
		{
			head = driver->usb_read_ptr->buf;

			if (head[0] != 0x4b && head[1] != 0x04)
			{
				gFilter_filp->f_op->write(gFilter_filp, (unsigned char __user *)driver->usb_buf_out, driver->read_len_legacy, &gFilter_filp->f_pos);

				DIAG_DBG_MSG_G1(KERN_INFO "Filter string capture (%d).\n", driver->read_len_legacy);
			}
			
		}
	}
#endif
}

void diag_process_hdlc_fn(struct work_struct *work)
{
	APPEND_DEBUG('D');
	diag_process_hdlc(driver->usb_buf_out, driver->read_len_legacy);
	diag_read_work_fn(work);
	APPEND_DEBUG('E');
}

void diag_usb_legacy_notifier(void *priv, unsigned event,
			struct diag_request *d_req)
{
	switch (event) {
	case USB_DIAG_CONNECT:
		diagfwd_connect();
		break;
	case USB_DIAG_DISCONNECT:
		diagfwd_disconnect();
		break;
	case USB_DIAG_READ_DONE:
		diagfwd_read_complete(d_req);
		break;
	case USB_DIAG_WRITE_DONE:
		diagfwd_write_complete(d_req);
		break;
	default:
		printk(KERN_ERR "Unknown event from USB diag\n");
		break;
	}
}

#endif /* DIAG OVER USB */

static void diag_smd_notify(void *ctxt, unsigned event)
{
#ifdef SAVE_QXDM_LOG_TO_SD_CARD
	if (bLogStart) {
		if (event != SMD_EVENT_DATA)
			return;
		diag_log_smd_read();
	}else {
		queue_work(driver->diag_wq, &(driver->diag_read_smd_work));
	}
#else
	queue_work(driver->diag_wq, &(driver->diag_read_smd_work));
#endif
}

#if defined(CONFIG_MSM_N_WAY_SMD)
static void diag_smd_qdsp_notify(void *ctxt, unsigned event)
{
	queue_work(driver->diag_wq, &(driver->diag_read_smd_qdsp_work));
}
#endif

static int diag_smd_probe(struct platform_device *pdev)
{
	int r = 0;

	if (pdev->id == 0)
		r = smd_open("DIAG", &driver->ch, driver, diag_smd_notify);
#if defined(CONFIG_MSM_N_WAY_SMD)
	if (pdev->id == 1)
		r = smd_named_open_on_edge("DIAG", SMD_APPS_QDSP
			, &driver->chqdsp, driver, diag_smd_qdsp_notify);
#endif
	pm_runtime_set_active(&pdev->dev);
	pm_runtime_enable(&pdev->dev);
	pr_debug("diag: opened SMD port ; r = %d\n", r);
#if SAVE_QXDM_LOG_TO_SD_CARD
	r = device_create_file(&pdev->dev, &dev_attr_qxdm2sd);

	if (r < 0)
	{
		dev_err(&pdev->dev, "%s: Create qxdm2sd attribute \"qxdm2sd\" failed!! <%d>", __func__, r);
		goto err;
	}
#endif
#if SAVE_MODEM_EFS_LOG
	r = device_create_file(&pdev->dev, &dev_attr_efs2sd);

	if (r < 0)
	{
		dev_err(&pdev->dev, "%s: Create efs2sd attribute \"efs2sd\" failed!! <%d>", __func__, r);
		goto err;
	}
    	else
    	{
        		mutex_init(&efslog_mutex);
    	}
#endif
err:
	return 0;
}

static int diagfwd_runtime_suspend(struct device *dev)
{
	dev_dbg(dev, "pm_runtime: suspending...\n");
	return 0;
}

static int diagfwd_runtime_resume(struct device *dev)
{
	dev_dbg(dev, "pm_runtime: resuming...\n");
	return 0;
}

static const struct dev_pm_ops diagfwd_dev_pm_ops = {
	.runtime_suspend = diagfwd_runtime_suspend,
	.runtime_resume = diagfwd_runtime_resume,
};

static struct platform_driver msm_smd_ch1_driver = {

	.probe = diag_smd_probe,
	.driver = {
		   .name = "DIAG",
		   .owner = THIS_MODULE,
		   .pm   = &diagfwd_dev_pm_ops,
		   },
};

#ifdef SAVE_QXDM_LOG_TO_SD_CARD
void diag_close_log_file_fn(void)
{
	unsigned char buf1[] = {0x60,0x00,0x12,0x6a,0x7e};
	unsigned char buf2[] = {0x73,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xda,0x81,0x7e};
	unsigned char buf3[] = {0x7d,0x5d,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x74,0x41,0x7e};
	
	diag_process_hdlc(buf1, 5);
	diag_process_hdlc(buf2, 11);
	diag_process_hdlc(buf3, 12);
	
	if (gLog_filp != NULL)
	{
		vfs_fsync(gLog_filp, 1);
		filp_close(gLog_filp, NULL);
		gLog_filp = NULL;
		
		if (pBuf)
        		{      
    			kfree(pBuf);
            		pBuf = NULL;
        		}
		DIAG_DBG_MSG_G1(KERN_INFO "[diagfwd.c][DEBUG] Log file %s (%d) is closed.\n", gLogFilePath, gTotalWrite);
	}
	
	if (gFilter_filp != NULL)
	{
		// Close filter file
		vfs_fsync(gFilter_filp, 1);
		filp_close(gFilter_filp, NULL);
		gFilter_filp = NULL;
		
		DIAG_DBG_MSG_G1(KERN_INFO "Filter file %s closed.\n", gFilterFileName);
	}
    
    if (gLogWriteThreadFilter_filp != NULL)
	{
		// Close filter file
		vfs_fsync(gLogWriteThreadFilter_filp,  1);
		filp_close(gLogWriteThreadFilter_filp, NULL);
		gLogWriteThreadFilter_filp = NULL;
		
		DIAG_DBG_MSG_G1(KERN_INFO "gLogWriteThreadFilter_filp %s closed.\n", gFilterFileName);
	}
}

static int diag_check_response(unsigned char *str1, unsigned char *str2, int len1, int len2)
{
	int i = 0;
	int bPass = 0;
	unsigned char *buf1 = str1;
	unsigned char *buf2 = str2;
	unsigned char *buf3 = NULL;

	unsigned char *pos = NULL;

	if (*buf1 == 0x7d)
	{
		buf3 = kzalloc(7, GFP_KERNEL);
		memcpy(buf3, buf1, 7);
		
		for (i=0;i<len2;i++)
		{
			if (*buf2 == 0x7d)
			{
				if (memcmp(buf2, buf3, 7) == 0)
				{
					if (*(buf2+7) == 0x01)
					{
						DIAG_DBG_MSG_G2(KERN_INFO "[diagfwd.c][DEBUG] Set filter SUCCESS!\n");
						bPass = 1;
						break;
					}
					else
					{
						DIAG_DBG_MSG_G2(KERN_INFO "[diagfwd.c][DEBUG] Set filter FAIL!\n");
						bPass = 0;
						// +++ Debug +++
						pos = buf1;
						DIAG_DBG_MSG_G2(KERN_INFO "==============================> Send\n");
						while(1) {
							DIAG_DBG_MSG_G2(KERN_INFO "%.2x ", *pos);
							if (*pos == 0x7e) break;
							pos++;
						}
						DIAG_DBG_MSG_G2(KERN_INFO "\n");
						
						pos = buf2;
						DIAG_DBG_MSG_G2(KERN_INFO "==============================> Return\n");
						while(1) {
							DIAG_DBG_MSG_G2(KERN_INFO "%.2x ", *pos);
							if (*pos == 0x7e) break;
							pos++;
						}
						DIAG_DBG_MSG_G2(KERN_INFO "\n");
						// --- Debug ---
						break;
					}
				}
			}
			
			buf2++;
		}
		
		kfree(buf3);
	}
	
	if (*buf1 == 0x73)
	{
		buf3 = kzalloc(5, GFP_KERNEL);
		memcpy(buf3, buf1, 5);

		for (i=0;i<len2;i++)
		{
			if (*buf2 == 0x73)
			{
				if (memcmp(buf2, buf3, 5) == 0)
				{
					if (*(buf2+5) == 0 && *(buf2+6) == 0 && *(buf2+7) == 0 && *(buf2+8) == 0)
					{
						DIAG_DBG_MSG_G2(KERN_INFO "[diagfwd.c][DEBUG] Set filter SUCCESS!\n");
						bPass = 1;
						break;
					}
					else
					{
						DIAG_DBG_MSG_G2(KERN_INFO "[diagfwd.c][DEBUG] Set filter FAIL!\n");
						bPass = 0;
						// +++ Debug +++
						pos = buf1;
						DIAG_DBG_MSG_G2(KERN_INFO "==============================> Send\n");
						while(1) {
							DIAG_DBG_MSG_G2(KERN_INFO "%.2x ", *pos);
							if (*pos == 0x7e) break;
							pos++;
						}
						DIAG_DBG_MSG_G2(KERN_INFO "\n");
						
						pos = buf2;
						DIAG_DBG_MSG_G2(KERN_INFO "==============================> Return\n");
						while(1) {
							DIAG_DBG_MSG_G2(KERN_INFO "%.2x ", *pos);
							if (*pos == 0x7e) break;
							pos++;
						}
						DIAG_DBG_MSG_G2(KERN_INFO "\n");
						// --- Debug ---
						break;
					}
				}
			}
			
			buf2++;
		}
		
		kfree(buf3);
	}
	
	if (*buf1 == 0x82)
	{
		buf3 = kzalloc(4, GFP_KERNEL);
		memcpy(buf3, (buf1+2), 4);

		for (i=0;i<len2;i++)
		{
			if (*buf2 == 0x82)
			{
				if (memcmp((buf2+2), buf3, 4) == 0)
				{
					if (*(buf2+1) == 0)
					{
						DIAG_DBG_MSG_G2(KERN_INFO "[diagfwd.c][DEBUG] Set filter SUCCESS!\n");
						bPass = 1;
						break;
					}
					else
					{
						DIAG_DBG_MSG_G2(KERN_INFO "[diagfwd.c][DEBUG] Set filter FAIL!\n");
						bPass = 0;
						// +++ Debug +++
						pos = buf1;
						DIAG_DBG_MSG_G2(KERN_INFO "==============================> Send\n");
						while(1) {
							DIAG_DBG_MSG_G2(KERN_INFO "%.2x ", *pos);
							if (*pos == 0x7e) break;
							pos++;
						}
						DIAG_DBG_MSG_G2(KERN_INFO "\n");
						
						pos = buf2;
						DIAG_DBG_MSG_G2(KERN_INFO "==============================> Return\n");
						while(1) {
							DIAG_DBG_MSG_G2(KERN_INFO "%.2x ", *pos);
							if (*pos == 0x7e) break;
							pos++;
						}
						DIAG_DBG_MSG_G2(KERN_INFO "\n");
						// --- Debug ---
						break;
					}
				}
			}
			
			buf2++;
		}
		
		kfree(buf3);
	}
	
	return bPass;
}

static int diag_write_filter_thread(void *__unused)
{
	unsigned long flags;
	unsigned char w_buf[512];
	unsigned char *p = NULL;
	int nRead = 0;
	int w_size = 0;
	int r_size = 0;
	int bEOF = 0;
	int bSuccess = 0;
	int rt = 0;

	bGetRespNow = 1;

	// Read filter.bin

	p = kmalloc(1, GFP_KERNEL);

	//while(!kthread_should_stop())
	for(;;)
    	{
		w_size = 0;
		memset(w_buf, 0 , 512);
		do{
            		if (!bLogStart) // Abort right away if user stop the qxdmlog
                			goto lbForceExit;

			if (IS_ERR(gLogWriteThreadFilter_filp) || gLogWriteThreadFilter_filp == NULL)
	        		{
		        		gLogWriteThreadFilter_filp = NULL;
		        		DIAG_DBG_MSG_G1(KERN_ERR "[diagfwd.c][ERROR] Missing filter file!\n");
        				goto lbForceExit;
        			}
            		else
            		{   
                			nRead = gLogWriteThreadFilter_filp->f_op->read(gLogWriteThreadFilter_filp, (unsigned char __user *)p, 1, &gLogWriteThreadFilter_filp->f_pos);
           		}
			if (nRead != 1) {
				bEOF = 1;
				break;
			}
			w_buf[w_size++] = *p;
		}while (*p != 0x7e);
		
		if (bEOF) break;
		
		// Ignore filter except MSG, LOG, EVENT
		if (w_buf[0] != 0x7d  && w_buf[0] != 0x73 && w_buf[0] != 0x82) {
			continue;
		}
		
		bSuccess = 0;
		rt = 5;
		
		switch (w_buf[0])
		{
			case 0x7d:
						DIAG_DBG_MSG_G1(KERN_INFO "[diagfwd.c][DEBUG] Set MSG filter string (%d).\n", w_size);
						break;
			case 0x73:
						DIAG_DBG_MSG_G1(KERN_INFO "[diagfwd.c][DEBUG] Set LOG filter string (%d).\n", w_size);
						break;
			case 0x82:
						DIAG_DBG_MSG_G1(KERN_INFO "[diagfwd.c][DEBUG] Set EVENT filter string (%d).\n", w_size);
						break;
		}

		while (!bSuccess && rt--)
		{
		    	if (!bLogStart) // Abort right away if user stop the qxdmlog
                		goto lbForceExit;
			diag_process_hdlc(w_buf, w_size);
			wait_event_interruptible(diag_wait_queue, gBuf_Size && !bWriteSD);
			spin_lock_irqsave(&diag_smd_lock, flags);
			r_size = gBuf_Size;
            		if (r_buf && pBuf)
            		{
			    	memcpy(r_buf, pBuf, MAX_W_BUF_SIZE);
			    	gBuf_Size = 0;
			    	pBuf_Curr = pBuf;
            		}
			spin_unlock_irqrestore(&diag_smd_lock, flags);
            		if (r_buf)
           	 	{
			    	bSuccess = diag_check_response(w_buf, r_buf, w_size, r_size);
            		}
            		else
            		{
                			if (bLogStart == 0)
                			{
                    			DIAG_DBG_MSG_G1("Force Exit filter\n");
                    			goto lbForceExit;
                			}
            		}
			if (!bSuccess) {
				DIAG_DBG_MSG_G1(KERN_INFO "[diagfwd.c][DEBUG] Try again.\n");
				msleep(100);
			}
		}
		if (rt <= 0) {
			DIAG_DBG_MSG_G1(KERN_INFO "[diagfwd.c][DEBUG] Set filter FAIL!\n");
		}
	}

lbForceExit:
    
	// Close filter.bin
	if (r_buf)
    	{
        		kfree(r_buf);
        		r_buf = NULL;
   	}
	kfree(p);
    	if (gLogWriteThreadFilter_filp)
    	{
        		filp_close(gLogWriteThreadFilter_filp, NULL);
        		gLogWriteThreadFilter_filp = NULL;
    	}
	bGetRespNow = 0;
	bWriteSD = 1;
	DIAG_DBG_MSG_G1(KERN_INFO "[diagfwd.c][DEBUG] Load filter.bin is finished.\n");
	return 0;
}

static int diag_log_write_thread(void *__unused)
{
	unsigned long flags;
	int buf_size = 0;

	while (!kthread_should_stop())
	{
		wait_event_interruptible(diag_wait_queue, (gBuf_Size && bWriteSD) || kthread_should_stop());
		
		spin_lock_irqsave(&diag_smd_lock, flags);

//		printk(KERN_INFO "[diagfwd.c][DEBUG] Buffer write to SD %d\n", gBuf_Size);

		buf_size = gBuf_Size;
		if (pBuf && log_write_buf)   //Paul Huang, 2009/12/29, Avoid exception
		    memcpy(log_write_buf, pBuf, MAX_W_BUF_SIZE);
		gBuf_Size = 0;
		pBuf_Curr = pBuf;
		spin_unlock_irqrestore(&diag_smd_lock, flags);
        		if (gLog_filp)  //Paul Huang, 2009/12/29, Avoid exception
			gLog_filp->f_op->write(gLog_filp, (unsigned char __user *)log_write_buf, buf_size, &gLog_filp->f_pos);
	}
	if (log_write_buf)
    	{   
	    	kfree(log_write_buf);
        		log_write_buf = 0;
    	}
	return 0;
}

int diag_open_log_file_fn(void)
{
	struct timespec ts;
	struct rtc_time tm;
    	int rc = 0;
	// Create log file
	if (gLog_filp == NULL)
	{
		getnstimeofday(&ts);
		rtc_time_to_tm(ts.tv_sec, &tm);

		sprintf(gLogFilePath,
		"%sQXDM-%d-%02d-%02d-%02d-%02d-%02d.bin",
			gPath,
			tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
			tm.tm_hour, tm.tm_min, tm.tm_sec);

		gLog_filp = filp_open(gLogFilePath, O_CREAT|O_WRONLY|O_LARGEFILE, 0);
		
		if (IS_ERR(gLog_filp))
		{
			gLog_filp = NULL;
			DIAG_DBG_MSG_G1(KERN_ERR "[diagfwd.c][ERROR] Create log file %s error!\n", gLogFilePath);
           	 	rc = -1;
			goto err;
		}
	    	DIAG_DBG_MSG_G1(KERN_INFO "[diagfwd.c][DEBUG] Log file %s is created.\n", gLogFilePath);
    	}
	
err:
	return rc;
}
int diag_open_filter_file(void)
{
   	int rc = 0;
    	char FilterFile[64];
	// Create log file
	if (gLogWriteThreadFilter_filp == NULL)
	{
    		// Open filter.bin
    		memset(FilterFile, 0, sizeof(FilterFile));
    		sprintf(FilterFile, "%s%s", gPath, gFilterFileName);
    		gLogWriteThreadFilter_filp = filp_open(FilterFile, O_RDONLY|O_LARGEFILE, 0);
    		if (IS_ERR(gLogWriteThreadFilter_filp))
    		{
    			gLogWriteThreadFilter_filp = NULL;
    			DIAG_DBG_MSG_G1(KERN_ERR "[diagfwd.c][ERROR] Open filter file %s error!\n", FilterFile);
            		rc = -1;
    			goto err;
    		}
	}
err:
	return rc;
}
static void diag_start_log(void)
{
	if (bLogStart)
        return;

	// Allocate write buffer
	if ((pBuf = kzalloc(MAX_W_BUF_SIZE, GFP_KERNEL)) == NULL) {
	    DIAG_DBG_MSG_G1(KERN_ERR "[diagfwd.c][ERROR] kzalloc pBuf fail!\n");
        qxdmlog_launch_result = QXDMLOG_STATUS_MEMORY_ALLOCATION_FAIL;
	    goto err;
	}
	if ((r_buf = kzalloc(MAX_W_BUF_SIZE, GFP_KERNEL)) == NULL) {
	    DIAG_DBG_MSG_G1(KERN_ERR "[diagfwd.c][ERROR] kzalloc r_buf fail!\n");
        qxdmlog_launch_result = QXDMLOG_STATUS_MEMORY_ALLOCATION_FAIL;
	    goto err;
	}
    	if ((log_write_buf = kzalloc(MAX_W_BUF_SIZE, GFP_KERNEL)) == NULL) {
	    DIAG_DBG_MSG_G1(KERN_ERR "[diagfwd.c][ERROR] kzalloc log_write_buf fail!\n");
        		qxdmlog_launch_result = QXDMLOG_STATUS_MEMORY_ALLOCATION_FAIL;
	    	goto err;
	}

	if (diag_open_log_file_fn() || diag_open_filter_file())
    	{
        		qxdmlog_launch_result = QXDMLOG_STATUS_CREATE_FILE_FAIL;
        		goto err;
    	}
	
	pBuf_Curr = pBuf;
	gBuf_Size = 0;
	gTotalWrite = 0;
	bLogStart = 1;
	bWriteSD = 0;

	// Load filter
	kLoadFilterTsk = kthread_create(diag_write_filter_thread, NULL, "Load filter");

	if (!IS_ERR(kLoadFilterTsk)) {
		wake_up_process(kLoadFilterTsk);
	}else {
		DIAG_DBG_MSG_G1(KERN_ERR "[diagfwd.c][ERROR] Start load filter thread error.\n");
        		qxdmlog_launch_result = QXDMLOG_STATUS_CREATE_FILE_FAIL;
		goto err;
	}

	// Start thread for write log to SD
	kLogTsk = kthread_create(diag_log_write_thread, NULL, "Write QXDM Log To File");
	
	if (!IS_ERR(kLogTsk)) {
		wake_up_process(kLogTsk);
	}else {
		DIAG_DBG_MSG_G1(KERN_ERR "[diagfwd.c][ERROR] Start write log thread error.\n");
        		qxdmlog_launch_result = QXDMLOG_STATUS_CREATE_FILE_FAIL;
		goto err;
	}

    	qxdmlog_launch_result = QXDMLOG_STATUS_SUCCESS;
    	return;

err:
    	bLogStart = 0;

    	if (pBuf)
    	{
        		kfree(pBuf);
        		pBuf = NULL;
    	}
    	if (r_buf)
    	{
        		kfree(r_buf);
        		r_buf = NULL;
    	}
    	if (log_write_buf)
    	{
        		kfree(log_write_buf);
        		log_write_buf = NULL;
    	}
    	diag_close_log_file_fn();
	return;
}

static void diag_stop_log(void)
{
	if (bLogStart)
	{
		// Stop thread
	    	kthread_stop(kLogTsk);
		// Clear flag
		bLogStart = 0;
		if (r_buf)
        		{
            		kfree(r_buf);
            		r_buf = NULL;
        		}
        		if (log_write_buf)
        		{
            		kfree(log_write_buf);
            		log_write_buf = NULL;
        		}
		// Close file
		diag_close_log_file_fn();
        		qxdmlog_launch_result = QXDMLOG_STATUS_DEFAULT;
	}
}

static int open_qxdm_filter_file(void)
{
	char FilterFilePath[64];
	
	if (gFilter_filp == NULL)
	{
		sprintf(FilterFilePath, "%s%s", gPath, gFilterFileName);
		
		gFilter_filp = filp_open(FilterFilePath, O_CREAT|O_WRONLY|O_LARGEFILE, 0);
		
		if (IS_ERR(gFilter_filp))
		{
			gFilter_filp = NULL;
			DIAG_DBG_MSG_G1(KERN_ERR "Create filter file %s error.\n", FilterFilePath);
			goto err;
		}

		bCaptureFilter = 1;

		DIAG_DBG_MSG_G1(KERN_INFO "Create filter file %s success.\n", FilterFilePath);
	}

err:
	return 0;
}

static int close_qxdm_filter_file(void)
{
	if (bCaptureFilter)
	{
		bCaptureFilter = 0;
        		diag_close_log_file_fn();
	}

	return 0;
}
#endif
void diagfwd_init(void)
{
	diag_debug_buf_idx = 0;
	driver->read_len_legacy = 0;
	if (driver->buf_in_1 == NULL)
		driver->buf_in_1 = kzalloc(IN_BUF_SIZE, GFP_KERNEL);
		if (driver->buf_in_1 == NULL)
			goto err;
	if (driver->buf_in_2 == NULL)
		driver->buf_in_2 = kzalloc(IN_BUF_SIZE, GFP_KERNEL);
		if (driver->buf_in_2 == NULL)
			goto err;
	if (driver->buf_in_qdsp_1 == NULL)
		driver->buf_in_qdsp_1 = kzalloc(IN_BUF_SIZE, GFP_KERNEL);
		if (driver->buf_in_qdsp_1 == NULL)
			goto err;
	if (driver->buf_in_qdsp_2 == NULL)
		driver->buf_in_qdsp_2 = kzalloc(IN_BUF_SIZE, GFP_KERNEL);
		if (driver->buf_in_qdsp_2 == NULL)
			goto err;
	if (driver->usb_buf_out  == NULL &&
	     (driver->usb_buf_out = kzalloc(USB_MAX_OUT_BUF,
					 GFP_KERNEL)) == NULL)
		goto err;
	if (driver->hdlc_buf == NULL
	    && (driver->hdlc_buf = kzalloc(HDLC_MAX, GFP_KERNEL)) == NULL)
		goto err;
    if (driver->user_space_data == NULL)
        driver->user_space_data = kzalloc(USER_SPACE_DATA, GFP_KERNEL);
        if (driver->user_space_data == NULL)
            goto err;
	if (driver->msg_masks == NULL
	    && (driver->msg_masks = kzalloc(MSG_MASK_SIZE,
					     GFP_KERNEL)) == NULL)
		goto err;
	if (driver->log_masks == NULL &&
	    (driver->log_masks = kzalloc(LOG_MASK_SIZE, GFP_KERNEL)) == NULL)
		goto err;
	driver->log_masks_length = 8*MAX_EQUIP_ID;
	if (driver->event_masks == NULL &&
	    (driver->event_masks = kzalloc(EVENT_MASK_SIZE,
					    GFP_KERNEL)) == NULL)
		goto err;
	if (driver->client_map == NULL &&
	    (driver->client_map = kzalloc
	     ((driver->num_clients) * sizeof(struct diag_client_map),
		   GFP_KERNEL)) == NULL)
		goto err;
	if (driver->buf_tbl == NULL)
			driver->buf_tbl = kzalloc(buf_tbl_size *
			  sizeof(struct diag_write_device), GFP_KERNEL);
	if (driver->buf_tbl == NULL)
		goto err;
	if (driver->data_ready == NULL &&
	     (driver->data_ready = kzalloc(driver->num_clients * sizeof(int)
							, GFP_KERNEL)) == NULL)
		goto err;
	if (driver->table == NULL &&
	     (driver->table = kzalloc(diag_max_registration*
		      sizeof(struct diag_master_table),
		       GFP_KERNEL)) == NULL)
		goto err;
	if (driver->write_ptr_1 == NULL)
		driver->write_ptr_1 = kzalloc(
			sizeof(struct diag_request), GFP_KERNEL);
		if (driver->write_ptr_1 == NULL)
			goto err;
	if (driver->write_ptr_2 == NULL)
		driver->write_ptr_2 = kzalloc(
			sizeof(struct diag_request), GFP_KERNEL);
		if (driver->write_ptr_2 == NULL)
			goto err;
	if (driver->write_ptr_qdsp_1 == NULL)
		driver->write_ptr_qdsp_1 = kzalloc(
			sizeof(struct diag_request), GFP_KERNEL);
		if (driver->write_ptr_qdsp_1 == NULL)
			goto err;
	if (driver->write_ptr_qdsp_2 == NULL)
		driver->write_ptr_qdsp_2 = kzalloc(
			sizeof(struct diag_request), GFP_KERNEL);
		if (driver->write_ptr_qdsp_2 == NULL)
			goto err;
	if (driver->usb_read_ptr == NULL)
		driver->usb_read_ptr = kzalloc(
			sizeof(struct diag_request), GFP_KERNEL);
		if (driver->usb_read_ptr == NULL)
			goto err;
	if (driver->pkt_buf == NULL &&
	     (driver->pkt_buf = kzalloc(PKT_SIZE,
			 GFP_KERNEL)) == NULL)
		goto err;
	if (driver->apps_rsp_buf == NULL)
			driver->apps_rsp_buf = kzalloc(500, GFP_KERNEL);
		if (driver->apps_rsp_buf == NULL)
			goto err;
	driver->diag_wq = create_singlethread_workqueue("diag_wq");
#ifdef CONFIG_DIAG_OVER_USB
	INIT_WORK(&(driver->diag_proc_hdlc_work), diag_process_hdlc_fn);
	INIT_WORK(&(driver->diag_read_work), diag_read_work_fn);
	driver->legacy_ch = usb_diag_open(DIAG_LEGACY, driver,
			diag_usb_legacy_notifier);
	if (IS_ERR(driver->legacy_ch)) {
		printk(KERN_ERR "Unable to open USB diag legacy channel\n");
		goto err;
	}
#ifdef CONFIG_DIAG_SDIO_PIPE
	if (machine_is_msm8x60_charm_surf() || machine_is_msm8x60_charm_ffa())
		diagfwd_sdio_init();
#endif
#endif
	platform_driver_register(&msm_smd_ch1_driver);

	return;
err:
		printk(KERN_INFO "\n Could not initialize diag buffers\n");
		kfree(driver->buf_in_1);
		kfree(driver->buf_in_2);
		kfree(driver->buf_in_qdsp_1);
		kfree(driver->buf_in_qdsp_2);
		kfree(driver->usb_buf_out);
		kfree(driver->hdlc_buf);
		kfree(driver->msg_masks);
		kfree(driver->log_masks);
		kfree(driver->event_masks);
		kfree(driver->client_map);
		kfree(driver->buf_tbl);
		kfree(driver->data_ready);
		kfree(driver->table);
		kfree(driver->pkt_buf);
		kfree(driver->write_ptr_1);
		kfree(driver->write_ptr_2);
		kfree(driver->write_ptr_qdsp_1);
		kfree(driver->write_ptr_qdsp_2);
		kfree(driver->usb_read_ptr);
		kfree(driver->apps_rsp_buf);
		if (driver->diag_wq)
			destroy_workqueue(driver->diag_wq);
}

void diagfwd_exit(void)
{
	smd_close(driver->ch);
	smd_close(driver->chqdsp);
	driver->ch = 0;		/* SMD can make this NULL */
	driver->chqdsp = 0;
#ifdef CONFIG_DIAG_OVER_USB
	if (driver->usb_connected)
		usb_diag_free_req(driver->legacy_ch);
#endif
	platform_driver_unregister(&msm_smd_ch1_driver);
#ifdef CONFIG_DIAG_OVER_USB
	usb_diag_close(driver->legacy_ch);
#endif

	kfree(driver->buf_in_1);
	kfree(driver->buf_in_2);
	kfree(driver->buf_in_qdsp_1);
	kfree(driver->buf_in_qdsp_2);
	kfree(driver->usb_buf_out);
	kfree(driver->hdlc_buf);
	kfree(driver->msg_masks);
	kfree(driver->log_masks);
	kfree(driver->event_masks);
	kfree(driver->client_map);
	kfree(driver->buf_tbl);
	kfree(driver->data_ready);
	kfree(driver->table);
	kfree(driver->pkt_buf);
	kfree(driver->write_ptr_1);
	kfree(driver->write_ptr_2);
	kfree(driver->write_ptr_qdsp_1);
	kfree(driver->write_ptr_qdsp_2);
	kfree(driver->usb_read_ptr);
	kfree(driver->apps_rsp_buf);
	destroy_workqueue(driver->diag_wq);
}
