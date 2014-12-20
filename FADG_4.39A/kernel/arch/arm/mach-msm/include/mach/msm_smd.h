/* linux/include/asm-arm/arch-msm/msm_smd.h
 *
 * Copyright (C) 2007 Google, Inc.
 * Copyright (c) 2009-2011, Code Aurora Forum. All rights reserved.
 * Author: Brian Swetland <swetland@google.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __ASM_ARCH_MSM_SMD_H
#define __ASM_ARCH_MSM_SMD_H

typedef struct smd_channel smd_channel_t;

#ifdef CONFIG_FIH_FXX

/* FIH, Debbie Sun, 2009/06/18 { */
/* get share memory command address dynamically */
struct smem_oem_info
{
        unsigned int hw_id;
        unsigned int keypad_info;
        unsigned int power_on_cause;
	/* FIH, MichaelKao, 2009/07/16 { */
	/* add for Read modem mode from smem */
        unsigned int network_mode;
	/* FIH, MichaelKao, 2009/07/16 { */
	/* FIH, Debbie modify, 2010/01/06 { */
        /* add for display info about download and sd ram dump */
        unsigned int oemsbl_mode;
        char   flash_name[32];
        char   oem_mod_rev[16];
        unsigned int progress;
        unsigned int msg_counter;
        /* FIH, Debbie modify, 2010/01/06 } */
	/* FIH, Debbie Sun, 2010/05/24 { */
	/* get ram info form share memory */
        unsigned int dram_info;
	/* FIH, Debbie Sun, 2010/05/24 { */
};
/* FIH, Debbie Sun, 2009/06/18 }*/

/* FIH, Debbie, 2009/09/11 { */
/* switch UART for printk log */
struct smem_host_oem_info
{
        unsigned int host_usb_id;
        unsigned int host_log_from_uart;
        unsigned int host_enable_kpd;
        unsigned int host_used4;
};
/* FIH, Debbie, 2009/09/11 } */

/* FIH, MichaelKao, 2009/07/16 { */
/* add for Read modem mode from smem */
typedef enum
{
    FIH_ERROR           = 0,
    FIH_GSM             = 0x0001,
    FIH_WCDMA           = 0x0002, // WCDMA only, e.g. in release 4315, the build id is TSNCJOLY
    FIH_CDMA1X          = 0x0004, // CDMA2000 only
    FIH_WCDMA_CDMA1X    = (FIH_WCDMA | FIH_CDMA1X), // WORLD MODE
    FIH_NETWORK_MODE_MAX
} fih_network_mode_type;
/* FIH, MichaelKao, 2009/07/16 } */

/* FIH, JiaHao, 2010/12/17 { */

/* FIH, JiaHao, 2011/01/26 { */
/* New HWID Mechanism */
/* OrigHWID {
    [31:30] = Reserved
    [29]    = HAC_Support
    [28]    = Headdset_Type
    [27:26] = Reserved
    [25:24] = SIM_ID
    [23:16] = Band_ID
    [15: 8] = Phase_ID
    [ 7: 0] = Product_ID } */
/* FIH, JiaHao, 2011/01/26 } */

typedef enum 
{
    Project_DQE = 0x1,
    Project_DMQ = 0x2,
    Project_DQD = 0x3,
    Project_DPD = 0x4,
    Project_DMP = 0x5,
    Project_DP2 = 0x6,
    Project_FAD = 0x7,
    /* FIH, JiaHao, 2010/12/30 { */
    Project_AI1S = 0x8,
    Project_AI1D = 0x9,
    /* FIH, JiaHao, 2010/12/30 } */
    /* FIH, JiaHao, 2011/01/26 { */
    Project_DMO = 0xA,
    Project_DMT = 0xB,
    /* FIH, JiaHao, 2010/01/26 } */
    /* FIH, JiaHao, 2011/04/21 { */
    Project_IRF = 0xC,
    /* FIH, JiaHao, 2011/04/21 } */
    FIH_PROJECT_MAX
} fih_product_id_type; // [7:0]

typedef enum 
{
    Phase_PR1 = 0x1,
    Phase_PR2,
    Phase_PR3,
    Phase_PR4,
    Phase_PR5,
    Phase_PR6,
    Phase_PR7,
    Phase_PR8,
    /* FIH, JiaHao, 2011/03/21 { */
    Phase_MP = 0x10,
    /* FIH, JiaHao, 2011/03/21 } */
    FIH_PHASE_MAX,
} fih_phase_id_type; // [15:8]

typedef enum 
{
    GSM_900_1800_CDMA_BC0 = 0x1,
    CDMA_BC0              = 0x2,
    WCDMA_145_band        = 0x6,
    WCDMA_148_band        = 0x7,
    WCDMA_245_band        = 0x8,
    WCDMA_15_band         = 0x9,
    WCDMA_18_band         = 0xA,
    WCDMA_25_band         = 0xB,
    /* FIH, JiaHao, 2010/12/30 { */
    WCDMA_125_band        = 0xC,
    WCDMA_128_band        = 0xD,
    WCDMA_14_band         = 0xE,
    /* FIH, JiaHao, 2010/12/30 } */
    FIH_BAND_MAX,
} fih_band_id_type; // [23:16]

/* FIH, JiaHao, 2011/01/26 { */
typedef enum
{
    SIM_SINGLE = 0x0,
    SIM_DUAL   = 0x1,
} fih_sim_id_type; // [25:24]
/* FIH, JiaHao, 2011/01/26 } */

typedef enum
{
    NO_OMTP = 0x0,
    BE_OMTP = 0x1,
} fih_headset_type; //[28]

typedef enum
{
    NO_HAC = 0x0,
    BE_HAC = 0x1,
} fih_hac_support; // [29]

/* FIH, JiaHao, 2010/12/17 } */

#endif /* CONFIG_FIH_FXX */

/* warning: notify() may be called before open returns */
int smd_open(const char *name, smd_channel_t **ch, void *priv,
	     void (*notify)(void *priv, unsigned event));

#define SMD_EVENT_DATA 1
#define SMD_EVENT_OPEN 2
#define SMD_EVENT_CLOSE 3
#define SMD_EVENT_STATUS 4
#define SMD_EVENT_REOPEN_READY 4

int smd_close(smd_channel_t *ch);

/* passing a null pointer for data reads and discards */
int smd_read(smd_channel_t *ch, void *data, int len);
int smd_read_from_cb(smd_channel_t *ch, void *data, int len);
/* Same as smd_read() but takes a data buffer from userspace
 * The function might sleep.  Only safe to call from user context
 */
int smd_read_user_buffer(smd_channel_t *ch, void *data, int len);

/* Write to stream channels may do a partial write and return
** the length actually written.
** Write to packet channels will never do a partial write --
** it will return the requested length written or an error.
*/
int smd_write(smd_channel_t *ch, const void *data, int len);
/* Same as smd_write() but takes a data buffer from userspace
 * The function might sleep.  Only safe to call from user context
 */
int smd_write_user_buffer(smd_channel_t *ch, const void *data, int len);

int smd_write_avail(smd_channel_t *ch);
int smd_read_avail(smd_channel_t *ch);

/* Returns the total size of the current packet being read.
** Returns 0 if no packets available or a stream channel.
*/
int smd_cur_packet_size(smd_channel_t *ch);


#if 0
/* these are interruptable waits which will block you until the specified
** number of bytes are readable or writable.
*/
int smd_wait_until_readable(smd_channel_t *ch, int bytes);
int smd_wait_until_writable(smd_channel_t *ch, int bytes);
#endif

/* these are used to get and set the IF sigs of a channel.
 * DTR and RTS can be set; DSR, CTS, CD and RI can be read.
 */
int smd_tiocmget(smd_channel_t *ch);
int smd_tiocmset(smd_channel_t *ch, unsigned int set, unsigned int clear);
int smd_tiocmset_from_cb(smd_channel_t *ch, unsigned int set, unsigned int clear);

enum {
	SMD_APPS_MODEM = 0,
	SMD_APPS_QDSP,
	SMD_MODEM_QDSP,
	SMD_APPS_DSPS,
	SMD_MODEM_DSPS,
	SMD_QDSP_DSPS,
	SMD_APPS_WCNSS,
	SMD_MODEM_WCNSS,
	SMD_QDSP_WCNSS,
	SMD_DSPS_WCNSS,
	SMD_LOOPBACK_TYPE = 100,

};

int smd_named_open_on_edge(const char *name, uint32_t edge, smd_channel_t **_ch,
			   void *priv, void (*notify)(void *, unsigned));

/* Tells the other end of the smd channel that this end wants to recieve
 * interrupts when the written data is read.  Read interrupts should only
 * enabled when there is no space left in the buffer to write to, thus the
 * interrupt acts as notification that space may be avaliable.  If the
 * other side does not support enabling/disabling interrupts on demand,
 * then this function has no effect if called.
 */
void smd_enable_read_intr(smd_channel_t *ch);

/* Tells the other end of the smd channel that this end does not want
 * interrupts when written data is read.  The interrupts should be
 * disabled by default.  If the other side does not support enabling/
 * disabling interrupts on demand, then this function has no effect if
 * called.
 */
void smd_disable_read_intr(smd_channel_t *ch);

/* Starts a packet transaction.  The size of the packet may exceed the total
 * size of the smd ring buffer.
 *
 * @ch: channel to write the packet to
 * @len: total length of the packet
 *
 * Returns:
 *      0 - success
 *      -ENODEV - invalid smd channel
 *      -EACCES - non-packet channel specified
 *      -EINVAL - invalid length
 *      -EBUSY - transaction already in progress
 *      -EAGAIN - no enough memory in ring buffer to start transaction
 *      -EPERM - unable to sucessfully start transaction due to write error
 */
int smd_write_start(smd_channel_t *ch, int len);

/* Writes a segment of the packet for a packet transaction.
 *
 * @ch: channel to write packet to
 * @data: buffer of data to write
 * @len: length of data buffer
 * @user_buf: (0) - buffer from kernelspace    (1) - buffer from userspace
 *
 * Returns:
 *      number of bytes written
 *      -ENODEV - invalid smd channel
 *      -EINVAL - invalid length
 *      -ENOEXEC - transaction not started
 */
int smd_write_segment(smd_channel_t *ch, void *data, int len, int user_buf);

/* Completes a packet transaction.  Do not call from interrupt context.
 *
 * @ch: channel to complete transaction on
 *
 * Returns:
 *      0 - success
 *      -ENODEV - invalid smd channel
 *      -E2BIG - some ammount of packet is not yet written
 */
int smd_write_end(smd_channel_t *ch);

#ifdef CONFIG_FIH_FXX

/* FIH, Debbie Sun, 2009/06/18 { */
/* get share memory command address dynamically */
void fih_smem_alloc(void);

/* switch UART for printk log */
void fih_smem_alloc_for_host_used(void);

unsigned int fih_read_hwid_from_smem(void);

/* modify new hardware id */
unsigned int fih_read_orig_hwid_from_smem(void);

unsigned int fih_read_mode_from_smem(void);

/* add for Read modem mode from smem */
unsigned int fih_read_network_mode_from_smem(void);
#define POWER_ON_CAUSE_PROC_READ_ENTRY 1
#ifdef POWER_ON_CAUSE_PROC_READ_ENTRY
unsigned int fih_read_power_on_cuase_from_smem(void);
#endif

/* switch UART for printk log */
unsigned int fih_read_uart_switch_from_smem(void);
/* FIH, Debbie Sun, 2009/06/18 }*/

unsigned int fih_read_usb_id_from_smem(void);
unsigned int fih_read_kpd_from_smem(void);
/* FIH, Debbie Sun, 2010/05/24 { */
/* get ram info and device name form share memory */
unsigned int fih_read_dram_info_from_smem(void);
char* fih_read_flash_name_from_smem(void);
/* FIH, Debbie Sun, 2010/05/24 } */

/* FIH, JiaHao, 2010/08/04 } */
/* return jogball device is exist or not { (0)=not_exist, (1)=is_exist } */
int fih_read_jogball_exist_from_smem(void);
/* FIH, JiaHao, 2010/08/04 } */

/* FIH, JiaHao, 2010/12/17 { */
/* FIH, JiaHao, 2011/01/26 { */
/* New HWID Mechanism */
/* OrigHWID {
    [31:30] = Reserved
    [29]    = HAC_Support
    [28]    = Headdset_Type
    [27:26] = Reserved
    [25:24] = SIM_ID
    [23:16] = Band_ID
    [15: 8] = Phase_ID
    [ 7: 0] = Product_ID } */
/* FIH, JiaHao, 2011/01/26 } */
bool fih_read_new_hwid_mech_from_orighwid(void);
unsigned int fih_read_product_id_from_orighwid(void);
unsigned int fih_read_phase_id_from_orighwid(void);
unsigned int fih_read_band_id_from_orighwid(void);
unsigned int fih_read_sim_id_from_orighwid(void); /* FIH, JiaHao, 2011/01/26 */
unsigned int fih_read_headset_type_from_orighwid(void);
unsigned int fih_read_hac_support_from_orighwid(void);
/* FIH, JiaHao, 2010/12/17 } */

/* FIH, Paul Huang, 2009/08/04 { */
/* add for QXDM LOG to SD card */
#define SAVE_QXDM_LOG_TO_SD_CARD    1
/* FIH, Paul Huang, 2009/08/04 } */

/* FIH, JiaHao, 2010/12/17 { */
/* New HWID Mechanism */
/* HWID = OrigHWID [16:FFFF][8:Phase_ID][8:Product_ID] */
typedef enum 
{
    /* DQE family */
    CMCS_DQE_PR1 = 0xFFFF0101,
    CMCS_DQE_PR2 = 0xFFFF0201,
    CMCS_DQE_PR3 = 0xFFFF0301,
    CMCS_DQE_PR4 = 0xFFFF0401,
    CMCS_DQE_PR5 = 0xFFFF0501,
    CMCS_DQE_PR6 = 0xFFFF0601,
    CMCS_DQE_PR7 = 0xFFFF0701,
    CMCS_DQE_PR8 = 0xFFFF0801,
    /* FIH, JiaHao, 2011/03/21 { */
    CMCS_DQE_MP  = 0xFFFF1001,
    /* FIH, JiaHao, 2011/03/21 } */

    /* DMQ family */
    CMCS_DMQ_PR1 = 0xFFFF0102,
    CMCS_DMQ_PR2 = 0xFFFF0202,
    CMCS_DMQ_PR3 = 0xFFFF0302,
    CMCS_DMQ_PR4 = 0xFFFF0402,
    CMCS_DMQ_PR5 = 0xFFFF0502,
    CMCS_DMQ_PR6 = 0xFFFF0602,
    CMCS_DMQ_PR7 = 0xFFFF0702,
    CMCS_DMQ_PR8 = 0xFFFF0802,
    /* FIH, JiaHao, 2011/03/21 { */
    CMCS_DMQ_MP  = 0xFFFF1002,
    /* FIH, JiaHao, 2011/03/21 } */

    /* DQD family */
    CMCS_DQD_PR1 = 0xFFFF0103,
    CMCS_DQD_PR2 = 0xFFFF0203,
    CMCS_DQD_PR3 = 0xFFFF0303,
    CMCS_DQD_PR4 = 0xFFFF0403,
    CMCS_DQD_PR5 = 0xFFFF0503,
    CMCS_DQD_PR6 = 0xFFFF0603,
    CMCS_DQD_PR7 = 0xFFFF0703,
    CMCS_DQD_PR8 = 0xFFFF0803,
    /* FIH, JiaHao, 2011/03/21 { */
    CMCS_DQD_MP  = 0xFFFF1003,
    /* FIH, JiaHao, 2011/03/21 } */

    /* DPD family */
    CMCS_DPD_PR1 = 0xFFFF0104,
    CMCS_DPD_PR2 = 0xFFFF0204,
    CMCS_DPD_PR3 = 0xFFFF0304,
    CMCS_DPD_PR4 = 0xFFFF0404,
    CMCS_DPD_PR5 = 0xFFFF0504,
    CMCS_DPD_PR6 = 0xFFFF0604,
    CMCS_DPD_PR7 = 0xFFFF0704,
    CMCS_DPD_PR8 = 0xFFFF0804,
    /* FIH, JiaHao, 2011/03/21 { */
    CMCS_DPD_MP  = 0xFFFF1004,
    /* FIH, JiaHao, 2011/03/21 } */

    /* DMP family */
    CMCS_DMP_PR1 = 0xFFFF0105,
    CMCS_DMP_PR2 = 0xFFFF0205,
    CMCS_DMP_PR3 = 0xFFFF0305,
    CMCS_DMP_PR4 = 0xFFFF0405,
    CMCS_DMP_PR5 = 0xFFFF0505,
    CMCS_DMP_PR6 = 0xFFFF0605,
    CMCS_DMP_PR7 = 0xFFFF0705,
    CMCS_DMP_PR8 = 0xFFFF0805,
    /* FIH, JiaHao, 2011/03/21 { */
    CMCS_DMP_MP  = 0xFFFF1005,
    /* FIH, JiaHao, 2011/03/21 } */

    /* DP2 family */
    CMCS_DP2_PR1 = 0xFFFF0106,
    CMCS_DP2_PR2 = 0xFFFF0206,
    CMCS_DP2_PR3 = 0xFFFF0306,
    CMCS_DP2_PR4 = 0xFFFF0406,
    CMCS_DP2_PR5 = 0xFFFF0506,
    CMCS_DP2_PR6 = 0xFFFF0606,
    CMCS_DP2_PR7 = 0xFFFF0706,
    CMCS_DP2_PR8 = 0xFFFF0806,
    /* FIH, JiaHao, 2011/03/21 { */
    CMCS_DP2_MP  = 0xFFFF1006,
    /* FIH, JiaHao, 2011/03/21 } */

    /* FAD family */
    CMCS_FAD_PR1 = 0xFFFF0107,
    CMCS_FAD_PR2 = 0xFFFF0207,
    CMCS_FAD_PR3 = 0xFFFF0307,
    CMCS_FAD_PR4 = 0xFFFF0407,
    CMCS_FAD_PR5 = 0xFFFF0507,
    CMCS_FAD_PR6 = 0xFFFF0607,
    CMCS_FAD_PR7 = 0xFFFF0707,
    CMCS_FAD_PR8 = 0xFFFF0807,
    /* FIH, JiaHao, 2011/03/21 { */
    CMCS_FAD_MP  = 0xFFFF1007,
    /* FIH, JiaHao, 2011/03/21 } */

    /* FIH, JiaHao, 2010/12/30 { */
    /* AI1S family */
    CMCS_AI1S_PR1 = 0xFFFF0108,
    CMCS_AI1S_PR2 = 0xFFFF0208,
    CMCS_AI1S_PR3 = 0xFFFF0308,
    CMCS_AI1S_PR4 = 0xFFFF0408,
    CMCS_AI1S_PR5 = 0xFFFF0508,
    CMCS_AI1S_PR6 = 0xFFFF0608,
    CMCS_AI1S_PR7 = 0xFFFF0708,
    CMCS_AI1S_PR8 = 0xFFFF0808,
    /* FIH, JiaHao, 2010/12/30 } */
    /* FIH, JiaHao, 2011/03/21 { */
    CMCS_AI1S_MP  = 0xFFFF1008,
    /* FIH, JiaHao, 2011/03/21 } */

    /* FIH, JiaHao, 2010/12/30 { */
    /* AI1D family */
    CMCS_AI1D_PR1 = 0xFFFF0109,
    CMCS_AI1D_PR2 = 0xFFFF0209,
    CMCS_AI1D_PR3 = 0xFFFF0309,
    CMCS_AI1D_PR4 = 0xFFFF0409,
    CMCS_AI1D_PR5 = 0xFFFF0509,
    CMCS_AI1D_PR6 = 0xFFFF0609,
    CMCS_AI1D_PR7 = 0xFFFF0709,
    CMCS_AI1D_PR8 = 0xFFFF0809,
    /* FIH, JiaHao, 2010/12/30 } */
    /* FIH, JiaHao, 2011/03/21 { */
    CMCS_AI1D_MP  = 0xFFFF1009,
    /* FIH, JiaHao, 2011/03/21 } */

    /* FIH, JiaHao, 2011/01/26 { */
    /* DMO family */
    CMCS_DMO_PR1 = 0xFFFF010A,
    CMCS_DMO_PR2 = 0xFFFF020A,
    CMCS_DMO_PR3 = 0xFFFF030A,
    CMCS_DMO_PR4 = 0xFFFF040A,
    CMCS_DMO_PR5 = 0xFFFF050A,
    CMCS_DMO_PR6 = 0xFFFF060A,
    CMCS_DMO_PR7 = 0xFFFF070A,
    CMCS_DMO_PR8 = 0xFFFF080A,
    /* FIH, JiaHao, 2011/01/26 } */
    /* FIH, JiaHao, 2011/03/21 { */
    CMCS_DMO_MP  = 0xFFFF100A,
    /* FIH, JiaHao, 2011/03/21 } */

    /* FIH, JiaHao, 2011/01/26 { */
    /* DMT family */
    CMCS_DMT_PR1 = 0xFFFF010B,
    CMCS_DMT_PR2 = 0xFFFF020B,
    CMCS_DMT_PR3 = 0xFFFF030B,
    CMCS_DMT_PR4 = 0xFFFF040B,
    CMCS_DMT_PR5 = 0xFFFF050B,
    CMCS_DMT_PR6 = 0xFFFF060B,
    CMCS_DMT_PR7 = 0xFFFF070B,
    CMCS_DMT_PR8 = 0xFFFF080B,
    /* FIH, JiaHao, 2011/01/26 } */
    /* FIH, JiaHao, 2011/03/21 { */
    CMCS_DMT_MP  = 0xFFFF100B,
    /* FIH, JiaHao, 2011/03/21 } */

    /* FIH, JiaHao, 2011/04/21 { */
    /* IRF family */
    CMCS_IRF_PR1 = 0xFFFF010C,
    CMCS_IRF_PR2 = 0xFFFF020C,
    CMCS_IRF_PR3 = 0xFFFF030C,
    CMCS_IRF_PR4 = 0xFFFF040C,
    CMCS_IRF_PR5 = 0xFFFF050C,
    CMCS_IRF_PR6 = 0xFFFF060C,
    CMCS_IRF_PR7 = 0xFFFF070C,
    CMCS_IRF_PR8 = 0xFFFF080C,
    CMCS_IRF_MP  = 0xFFFF100C,
    /* FIH, JiaHao, 2011/04/21 } */

    CMCS_HW_VER_MAX
}cmcs_hw_version_type;
/* FIH, JiaHao, 2010/12/17 } */

#ifdef MSM_SHARED_RAM_BASE
/* get share memory command address dynamically */
#define FIH_READ_HWID_FROM_SMEM()  fih_read_hwid_from_smem()

/* modify new hardware id */
#define FIH_READ_ORIG_HWID_FROM_SMEM()  fih_read_orig_hwid_from_smem()

/* add for Read modem mode from smem */
#define FIH_READ_NETWORK_MODE_FROM_SMEM()  fih_read_network_mode_from_smem()
    #ifdef POWER_ON_CAUSE_PROC_READ_ENTRY
    #define FIH_READ_POWER_ON_CAUSE()  fih_read_power_on_cuase_from_smem()
    #endif
#endif
/* FIH, Charles Huang, 2009/05/18 } */

#endif /* CONFIG_FIH_FXX */

#endif
