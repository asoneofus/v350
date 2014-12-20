#include <linux/proc_fs.h>
#include <linux/module.h>
#include <linux/compiler.h>
/* FIH, JiaHao, 2010/09/06 { */
//#include <asm/gpio.h>
#include <linux/gpio.h>
/* FIH, JiaHao, 2010/09/06 } */
#include <mach/msm_iomap.h>
#include <mach/msm_smd.h>
#include "fih_kernel_version.h" //paul 2011/01/13
//FIH, JamesKCTung, 2009/11/03 +++
/* Add dbgmask partition*/
#ifdef CONFIG_PRINTK
#include <asm/uaccess.h>
#include <mach/msm_iomap.h>
#include <linux/io.h>
/* FIH, Square, 2011/10/26 { */
#include "proc_comm.h"
/* FIH, Square, 2011/10/26 } */

/*FIHTDC, WillChen changes because PLOG address has changed by Tiger { */
//#define DBGMSKBUF (MSM_PLOG_BASE + 0x80000)
#define DBGMSKBUF	(MSM_PLOG_BASE2 + 0XFF000)
/*FIHTDC, WillChen changes because PLOG address has changed by Tiger } */

char * debug_mask = (char *) DBGMSKBUF;
static struct proc_dir_entry *mask_file;
#define	MASKSIZE   	4096
#endif
//FIH, JamesKCTung, 2009/11/03 ---


int JogballExist_pr1,JogballExist_pr2;

#define PLUS_X_GPIO     91
#define NEG_X_GPIO      88
#define PLUS_Y_GPIO     90
#define NEG_Y_GPIO      93

/* } FIH, AudiPCHuang, 2009/06/05 */

static int proc_calc_metrics(char *page, char **start, off_t off,
				 int count, int *eof, int len)
{
	if (len <= off+count) *eof = 1;
	*start = page + off;
	len -= off;
	if (len>count) len = count;
	if (len<0) len = 0;
	return len;
}

/* FIH, Paul, 2011/01/13 { */
static unsigned int bootloader_version;
static int __init setup_bootloader_version(char *p)
{
	bootloader_version = memparse(p, NULL);
	return 0;
}
early_param("androidboot.bootloader", setup_bootloader_version);
/* FIH, Paul, 2011/01/13 } */

static int build_version_read_proc(char *page, char **start, off_t off,
				 int count, int *eof, void *data)
{
	int len;

	len = snprintf(page, PAGE_SIZE, "kernel: %s\nbootloader: %d\n", FIH_KERNEL_VERSION, bootloader_version);
	return proc_calc_metrics(page, start, off, count, eof, len);
}

static int device_model_read_proc(char *page, char **start, off_t off,
				 int count, int *eof, void *data)
{
	int len;
	char ver[24];

	/* FIH, JiaHao, 2010/11/08 { */
	/* New HWID Mechanism */
	switch (fih_read_product_id_from_orighwid())
	{
		case Project_DQE: strcpy(ver, "DQE"); break;
		case Project_DMQ: strcpy(ver, "DMQ"); break;
		case Project_DQD: strcpy(ver, "DQD"); break;
		case Project_DPD: strcpy(ver, "DPD"); break;
		case Project_DMP: strcpy(ver, "DMP"); break;
		case Project_DP2: strcpy(ver, "DP2"); break;
		case Project_FAD: strcpy(ver, "FAD"); break;
		/* FIH, JiaHao, 2010/12/30 { */
		case Project_AI1S: strcpy(ver, "AI1S"); break;
		case Project_AI1D: strcpy(ver, "AI1D"); break;
		/* FIH, JiaHao, 2010/12/30 } */
		/* FIH, JiaHao, 2011/01/26 { */
		case Project_DMO: strcpy(ver, "DMO"); break;
		case Project_DMT: strcpy(ver, "DMT"); break;
		/* FIH, JiaHao, 2011/01/26 } */
		/* FIH, JiaHao, 2011/04/21 { */
		case Project_IRF: strcpy(ver, "IRF"); break;
		/* FIH, JiaHao, 2011/04/21 } */
		default:          strcpy(ver, "Unkonwn Device Model"); break; 
	}
	/* FIH, JiaHao, 2010/11/08 } */

	len = snprintf(page, PAGE_SIZE, "%s\n", ver);

	return proc_calc_metrics(page, start, off, count, eof, len);
}

static int baseband_read_proc(char *page, char **start, off_t off,
				 int count, int *eof, void *data)
{
	int len;
	char ver[24];
	
	/* FIH, JiaHao, 2010/11/08 { */
	/* New HWID Mechanism */
	switch (fih_read_phase_id_from_orighwid())
	{
		case Phase_PR1: strcpy(ver, "PR1"); break;
		case Phase_PR2: strcpy(ver, "PR2"); break;
		case Phase_PR3: strcpy(ver, "PR3"); break;
		case Phase_PR4: strcpy(ver, "PR4"); break;
		case Phase_PR5: strcpy(ver, "PR5"); break;
		case Phase_PR6: strcpy(ver, "PR6"); break;
		case Phase_PR7: strcpy(ver, "PR7"); break;
		case Phase_PR8: strcpy(ver, "PR8"); break;
		/* FIH, JiaHao, 2011/03/21 { */
		case Phase_MP:  strcpy(ver, "MP");  break;
		/* FIH, JiaHao, 2011/03/21 } */
		default:        strcpy(ver, "Unkonwn Baseband version"); break;
	}
	/* FIH, JiaHao, 2010/11/08 } */

	len = snprintf(page, PAGE_SIZE, "%s\n", ver);

	return proc_calc_metrics(page, start, off, count, eof, len);
}

/* FIH, JiaHao, 2010/12/17 { */
/* support FQC can read HWID */
static int device_OrigHWID_read_proc(char *page, char **start, off_t off,
				 int count, int *eof, void *data)
{
	int len;
	len = snprintf(page, PAGE_SIZE, "0x%08X\n", FIH_READ_ORIG_HWID_FROM_SMEM());
	return proc_calc_metrics(page, start, off, count, eof, len);
}
/* FIH, JiaHao, 2010/12/17 } */

#ifdef POWER_ON_CAUSE_PROC_READ_ENTRY
static int proc_read_power_on_cause(char *page, char **start, off_t off,
				 int count, int *eof, void *data)
{
	int len;
	uint32_t poc = FIH_READ_POWER_ON_CAUSE();

	len = snprintf(page, PAGE_SIZE, "0x%x\n", poc);

	return proc_calc_metrics(page, start, off, count, eof, len);	
}
#endif

/* FIH, JamesKCTung, 2009/11/03 { */
/* Add dbgmask partition*/
#ifdef CONFIG_PRINTK
static int proc_read_debug_mask(char *page, char **start, off_t off,
				 int count, int *eof, void *data)
{

	int i,j;
	
	for (i=0,j=0; i<MASKSIZE; i++,j=j+2)
		sprintf((page+j),"%02x",debug_mask[i]);
	
	return MASKSIZE;
}
static int proc_write_debug_mask(struct file *file, const char *buffer, 
				 unsigned long count, void *data)
{
	//char mask[16];
	/*FIHTDC, WillChen add for debug mask { */
	printk("proc_write_debug_mask()\n");
	//if ( copy_from_user(debug_mask,buffer,count))
	//	return -EFAULT;
	if (buffer)
		memcpy(debug_mask,buffer,count);

	return count;
	/*FIHTDC, WillChen add for debug mask } */
}
#endif
/* FIH, JamesKCTung, 2009/11/03 } */

/* FIH, Square, 2011/10/26 { */
static int proc_read_product_id(char *page, char **start, off_t off, int count, int *eof, void *data)
{
    int len = 0;	
	int iRetVal = 0;
	unsigned int product_id[32];
	
	memset(product_id, 0, 32 * sizeof(unsigned int));
	
	iRetVal = proc_comm_read_product_id(product_id);

    if(iRetVal == 0)
    {
	    len = snprintf(page, PAGE_SIZE, "%s\n", (char *)product_id);
	}

	return proc_calc_metrics(page, start, off, count, eof, len);	
}
/* FIH, Square, 2011/10/26 } */


static struct {
		char *name;
		int (*read_proc)(char*,char**,off_t,int,int*,void*);
} *p, adq_info[] = {
	{"bspversion", build_version_read_proc},
	{"devmodel", device_model_read_proc},
	{"baseband", baseband_read_proc},
	/* FIH, JiaHao, 2010/10/28 { */
	{"orighwid", device_OrigHWID_read_proc},
	/* FIH, JiaHao, 2010/10/28 } */
	#ifdef POWER_ON_CAUSE_PROC_READ_ENTRY
	{"poweroncause", proc_read_power_on_cause},
	#endif
	/* FIH, Square, 2011/10/26 { */
	{"productid", proc_read_product_id},
	/* FIH, Square, 2011/10/26 } */
	{NULL,},
};

void adq_info_init(void)
{	
	for (p = adq_info; p->name; p++)
		create_proc_read_entry(p->name, 0, NULL, p->read_proc, NULL);
		
	//FIH, JamesKCTung, 2009/11/03 +++
	/* Add dbgmask partition*/
	#ifdef CONFIG_PRINTK
	mask_file = create_proc_entry("debug_mask",0777,NULL);
	mask_file->read_proc = proc_read_debug_mask;
	mask_file->write_proc = proc_write_debug_mask;
	/* FIH, JiaHao, 2010/08/20 { */
	/* ./android/kernel/include/linux/proc_fs.h no define owner at 6030cs */
	//mask_file->owner = THIS_MODULE;
	/* FIH, JiaHao, 2010/08/20 } */
	#endif
	//FIH, JamesKCTung, 2009/11/03 ---
}
EXPORT_SYMBOL(adq_info_init);

void adq_info_remove(void)
{
	for (p = adq_info; p->name; p++)
		remove_proc_entry(p->name, NULL);
}
EXPORT_SYMBOL(adq_info_remove);
