/*
 * Gadget Driver for Android
 *
 * Copyright (C) 2008 Google, Inc.
 * Copyright (c) 2009-2010, Code Aurora Forum. All rights reserved.
 * Author: Mike Lockwood <lockwood@android.com>
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

/* #define DEBUG */
/* #define VERBOSE_DEBUG */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

#include <linux/delay.h>
#include <linux/kernel.h>
#include <linux/utsname.h>
#include <linux/platform_device.h>
#include <linux/pm_runtime.h>
#include <linux/debugfs.h>

#include <linux/usb/android_composite.h>
#include <linux/usb/ch9.h>
#include <linux/usb/composite.h>
#include <linux/usb/gadget.h>
///WilsonWHLee 2010/02/23 5110 porting +++++++++++
#include <mach/msm_smd.h>
bool isMoto = 0;
///WilsonWHLee 2010/02/23 5110 porting -----------

#include "gadget_chips.h"
static int switch_port_enable=0;
module_param_named(switch_port_enable, switch_port_enable, int, S_IRUGO| S_IWUSR);
static int boot_usb = 0;
/*
 * Kbuild is not very cooperative with respect to linking separately
 * compiled library objects into one module.  So for now we won't use
 * separate compilation ... ensuring init/exit sections work to shrink
 * the runtime footprint, and giving us at least some parts of what
 * a "gcc --combine ... part1.c part2.c part3.c ... " build would.
 */
#include "usbstring.c"
#include "config.c"
#include "epautoconf.c"
#include "composite.c"

MODULE_AUTHOR("Mike Lockwood");
MODULE_DESCRIPTION("Android Composite USB Driver");
MODULE_LICENSE("GPL");
MODULE_VERSION("1.0");

static const char longname[] = "Gadget Android";

/* Default vendor and product IDs, overridden by platform data */
#define VENDOR_ID		0x18D1
#define PRODUCT_ID		0x0001

struct android_dev {
	struct usb_composite_dev *cdev;
	struct usb_configuration *config;
	int num_products;
	struct android_usb_product *products;
	int num_functions;
	char **functions;

    int vendor_id;
	int product_id;
	int version;
};

static struct android_dev *_android_dev;

/* FIH, WilsonWHLee, 2009/11/19 { */
/* [FXX_CR], add for download tool */
void msm_read_fih_version_from_nvitem(void);
char *fih_version_buf;
#include "../../../arch/arm/mach-msm/proc_comm.h"
#define NV_FIH_VERSION_I 8030
/* }FIH, WilsonWHLee, 2009/11/19 */
#define MAX_STR_LEN		256//16
/* string IDs are assigned dynamically */

static char *usb_functions_rndis_adb[] = {
	"rndis",
	"adb",
};
//WilsonWHLee 7019 porting 2010/11/03++
#if 0
static char *usb_functions_all[] = {
	"rndis",
	"usb_mass_storage",
	"diag",
	"adb",
	"modem",
	"nmea",
	//"rmnet",
};
#endif
//WilsonWHLee 7019 porting 2010/11/03--
//Wilson added ++
static char *usb_functions_custfull[] = {
	"usb_mass_storage",
	"diag",
	"adb",
	"modem",
};
static char *usb_functions_nodiag[] = {
	"usb_mass_storage",
	"adb",
};
#if 0
static char *usb_functions_recovery[] = {
	"diag",
};
#endif
static char *usb_functions_msc[] = {
	"usb_mass_storage",
};
static char *usb_functions_modem[] = {
	"usb_mass_storage",
	"adb",
	"modem",
};
////Wilson added --
static struct android_usb_product usb_products[] = {

//Wilson added ++
//original pid is c000
	{
		.product_id	= 0x2DE6,
		.num_functions	= ARRAY_SIZE(usb_functions_custfull),
		.functions	= usb_functions_custfull,
	},
//original pid is c004
	{
		.product_id	= 0x2DE7,
		.num_functions	= ARRAY_SIZE(usb_functions_msc),
		.functions	= usb_functions_msc,
	},
//original pid is c001
	{
		.product_id	= 0x2DE8,
		.num_functions	= ARRAY_SIZE(usb_functions_nodiag),
		.functions	= usb_functions_nodiag,
	},
//original pid is c008
	{
		.product_id	= 0x2DE9,
		.num_functions	= ARRAY_SIZE(usb_functions_rndis_adb),
		.functions	= usb_functions_rndis_adb,
	},
	{
		.product_id	= 0x2DEA,
		.num_functions	= ARRAY_SIZE(usb_functions_modem),
		.functions	= usb_functions_modem,
	},
//Wilson added --
};

#define STRING_MANUFACTURER_IDX		0
#define STRING_PRODUCT_IDX		1
#define STRING_SERIAL_IDX		2
static unsigned short desc_pid;
char serial_number[MAX_STR_LEN];
/* String Table */
static struct usb_string strings_dev[] = {
	/* These dummy values should be overridden by platform data */
	[STRING_MANUFACTURER_IDX].s = "Android",
	[STRING_PRODUCT_IDX].s = "Android",
	[STRING_SERIAL_IDX].s = "0123456789ABCDEF",
	{  }			/* end of list */
};

static struct usb_gadget_strings stringtab_dev = {
	.language	= 0x0409,	/* en-us */
	.strings	= strings_dev,
};

static struct usb_gadget_strings *dev_strings[] = {
	&stringtab_dev,
	NULL,
};

static struct usb_device_descriptor device_desc = {
	.bLength              = sizeof(device_desc),
	.bDescriptorType      = USB_DT_DEVICE,
	.bcdUSB               = __constant_cpu_to_le16(0x0200),
	.bDeviceClass         = USB_CLASS_PER_INTERFACE,
	.idVendor             = __constant_cpu_to_le16(VENDOR_ID),
	.idProduct            = __constant_cpu_to_le16(PRODUCT_ID),
	.bcdDevice            = __constant_cpu_to_le16(0xffff),
	.bNumConfigurations   = 1,
};

static struct usb_otg_descriptor otg_descriptor = {
	.bLength =		sizeof otg_descriptor,
	.bDescriptorType =	USB_DT_OTG,
	.bmAttributes =		USB_OTG_SRP | USB_OTG_HNP,
	.bcdOTG               = __constant_cpu_to_le16(0x0200),
};

static const struct usb_descriptor_header *otg_desc[] = {
	(struct usb_descriptor_header *) &otg_descriptor,
	NULL,
};

static struct list_head _functions = LIST_HEAD_INIT(_functions);
static int _registered_function_count = 0;
/* FIH, WilsonWHLee, 2009/11/19 { */
/* [FXX_CR], add for download tool */
void msm_read_fih_version_from_nvitem(void)
{
	uint32_t smem_proc_comm_oem_cmd1 = PCOM_CUSTOMER_CMD1;
	uint32_t smem_proc_comm_oem_data1 = SMEM_PROC_COMM_OEM_NV_READ;
  	uint32_t smem_proc_comm_oem_data2= NV_FIH_VERSION_I;
  	uint32_t fih_version[32];	
  	//struct usb_info *ui = the_usb_info;

    if(msm_proc_comm_oem(smem_proc_comm_oem_cmd1, &smem_proc_comm_oem_data1, fih_version, &smem_proc_comm_oem_data2) == 0)
    {
      printk(KERN_INFO"%s: [wilson fih_version=%s]\r\n",__func__,(char *) fih_version);
      //fih_printk (msm_hsusb_debug_mask, FIH_DEBUG_ZONE_G0, "%s: [wilson fih_version=%s]\r\n",__func__,(char *) fih_version);
      memcpy(fih_version_buf , fih_version , 128); //WilsonWHLee, 2010/08/12 extend length for pc tool
    }
}
/* }FIH, WilsonWHLee, 2009/11/19 */

static void android_set_default_product(int product_id);

void android_usb_set_connected(int connected)
{
	if (_android_dev && _android_dev->cdev && _android_dev->cdev->gadget) {
		if (connected)
			usb_gadget_connect(_android_dev->cdev->gadget);
		else
			usb_gadget_disconnect(_android_dev->cdev->gadget);
	}
}

static struct android_usb_function *get_function(const char *name)
{
	struct android_usb_function	*f;
	list_for_each_entry(f, &_functions, list) {
		if (!strcmp(name, f->name))
			return f;
	}
	return 0;
}

static void bind_functions(struct android_dev *dev)
{
	struct android_usb_function	*f;
	char **functions = dev->functions;
	int i;

	for (i = 0; i < dev->num_functions; i++) {
		char *name = *functions++;
		f = get_function(name);
		if (f)
			f->bind_config(dev->config);
		else
			pr_err("%s: function %s not found\n", __func__, name);
	}

	/*
	 * set_alt(), or next config->bind(), sets up
	 * ep->driver_data as needed.
	 */
	usb_ep_autoconfig_reset(dev->cdev->gadget);
}

static int __ref android_bind_config(struct usb_configuration *c)
{
	struct android_dev *dev = _android_dev;

	pr_debug("android_bind_config\n");
	dev->config = c;

	/* bind our functions if they have all registered */
	if (_registered_function_count == dev->num_functions)
		bind_functions(dev);

	return 0;
}

static int android_setup_config(struct usb_configuration *c,
		const struct usb_ctrlrequest *ctrl);

static struct usb_configuration android_config_driver = {
	.label		= "android",
	.bind		= android_bind_config,
	.setup		= android_setup_config,
	.bConfigurationValue = 1,
	.bMaxPower	= 0xFA, /* 500ma */
};

static int android_setup_config(struct usb_configuration *c,
		const struct usb_ctrlrequest *ctrl)
{
	int i;
	int ret = -EOPNOTSUPP;

	for (i = 0; i < android_config_driver.next_interface_id; i++) {
		if (android_config_driver.interface[i]->setup) {
			ret = android_config_driver.interface[i]->setup(
				android_config_driver.interface[i], ctrl);
			if (ret >= 0)
				return ret;
		}
	}
	return ret;
}

static int product_has_function(struct android_usb_product *p,
		struct usb_function *f)
{
	char **functions = p->functions;
	int count = p->num_functions;
	const char *name = f->name;
	int i;

	for (i = 0; i < count; i++) {
		if (!strcmp(name, *functions++))
			return 1;
	}
	return 0;
}

static int product_matches_functions(struct android_usb_product *p)
{
	struct usb_function		*f;
	list_for_each_entry(f, &android_config_driver.functions, list) {
		if (product_has_function(p, f) == !!f->disabled)
			return 0;
	}
	return 1;
}

static int get_vendor_id(struct android_dev *dev)
{
    struct android_usb_product *p = dev->products;
    int count = dev->num_products;
    int i;

    if (p) {
        for (i = 0; i < count; i++, p++) {
            if (p->vendor_id && product_matches_functions(p))
                return p->vendor_id;
        }
    }
    /* use default vendor ID */
    return dev->vendor_id;
}

static int get_product_id(struct android_dev *dev)
{
	struct android_usb_product *p = dev->products;
	int count = dev->num_products;
	int i;

	if (p) {
		for (i = 0; i < count; i++, p++) {
			if (product_matches_functions(p))
				return p->product_id;
		}
	}
	/* use default product ID */
	return dev->product_id;
}

static int __devinit android_bind(struct usb_composite_dev *cdev)
{
	struct android_dev *dev = _android_dev;
	struct usb_gadget	*gadget = cdev->gadget;
	int			gcnum, id, product_id, ret;

	pr_debug("android_bind\n");

	/* Allocate string descriptor numbers ... note that string
	 * contents can be overridden by the composite_dev glue.
	 */
	id = usb_string_id(cdev);
	if (id < 0)
		return id;
	strings_dev[STRING_MANUFACTURER_IDX].id = id;
	device_desc.iManufacturer = id;

	id = usb_string_id(cdev);
	if (id < 0)
		return id;
	strings_dev[STRING_PRODUCT_IDX].id = id;
	device_desc.iProduct = id;

	id = usb_string_id(cdev);
	if (id < 0)
		return id;
	strings_dev[STRING_SERIAL_IDX].id = id;
	printk("desc_pid=0x%x",desc_pid);
	if(desc_pid != 0xc002)
	device_desc.iSerialNumber = id;

	if (gadget_is_otg(cdev->gadget))
		android_config_driver.descriptors = otg_desc;

	if (!usb_gadget_set_selfpowered(gadget))
		android_config_driver.bmAttributes |= USB_CONFIG_ATT_SELFPOWER;

	if (gadget->ops->wakeup)
		android_config_driver.bmAttributes |= USB_CONFIG_ATT_WAKEUP;

	/* register our configuration */
	ret = usb_add_config(cdev, &android_config_driver);
	if (ret) {
		pr_err("%s: usb_add_config failed\n", __func__);
		return ret;
	}

	gcnum = usb_gadget_controller_number(gadget);
	if (gcnum >= 0)
		device_desc.bcdDevice = cpu_to_le16(0x0200 + gcnum);
	else {
		/* gadget zero is so simple (for now, no altsettings) that
		 * it SHOULD NOT have problems with bulk-capable hardware.
		 * so just warn about unrcognized controllers -- don't panic.
		 *
		 * things like configuration and altsetting numbering
		 * can need hardware-specific attention though.
		 */
		pr_warning("%s: controller '%s' not recognized\n",
			longname, gadget->name);
		device_desc.bcdDevice = __constant_cpu_to_le16(0x9999);
	}

	usb_gadget_set_selfpowered(gadget);
	dev->cdev = cdev;
    device_desc.idVendor = __constant_cpu_to_le16(get_vendor_id(dev));
    //device_desc.idProduct = __constant_cpu_to_le16(get_product_id(dev));
#if 1
//wilson added ++    
    if( desc_pid == 0xc002)
	    product_id = 0xc002;
	else if ( desc_pid == 0xc001)
		if(isMoto)
		    product_id = 0x2DE7;
		else
		    product_id = 0xc004;
	else if (desc_pid == 0xc00A)
        if(isMoto)
		    product_id = 0x2DEA;
		else
		    product_id = 0xc000;
	else
#endif
	    product_id = get_product_id(dev);
//wilson added --
	device_desc.idProduct = __constant_cpu_to_le16(product_id);
	cdev->desc.idProduct = device_desc.idProduct;

	return 0;
}

static struct usb_composite_driver android_usb_driver = {
	.name		= "android_usb",
	.dev		= &device_desc,
	.strings	= dev_strings,
	.bind		= android_bind,
	.enable_function = android_enable_function,
};
#if 0 //not support
static bool is_func_supported(struct android_usb_function *f)
{
	char **functions = _android_dev->functions;
	int count = _android_dev->num_functions;
	const char *name = f->name;
	int i;

	for (i = 0; i < count; i++) {
		if (!strcmp(*functions++, name))
			return true;
	}
	return false;
}

void android_register_function(struct android_usb_function *f)
{
	struct android_dev *dev = _android_dev;

	pr_debug("%s: %s\n", __func__, f->name);

	if (!is_func_supported(f))
		return;

	list_add_tail(&f->list, &_functions);
	_registered_function_count++;

	/* bind our functions if they have all registered
	 * and the main driver has bound.
	 */
	if (dev->config && _registered_function_count == dev->num_functions) {
		bind_functions(dev);
		android_set_default_product(dev->product_id);
	}
}
#else
void android_register_function(struct android_usb_function *f)
{
	struct android_dev *dev = _android_dev;

	printk(KERN_INFO "android_register_function %s\n", f->name);
// Disable usb port in recovery +++
	if (fih_read_usb_id_from_smem() == 0xC002)
    {
        printk("not supported in recovery mode\n");
        return;
    }
// Disable usb port in recovery ---
	#if 1
	if(desc_pid ==0xc002){
	    if(strcmp(f->name, "diag"))
	    {
		    printk("android_register_function this isnt diag\n");
		    return ;
	    }
	}
#endif
	#if 0
    else if(desc_pid ==0xc001){
    	if(strcmp(f->name, "usb_mass_storage"))
	    {
		    printk("android_register_function this isnt ums or adb\n");
		    return ;
	    }
	}
	#endif
	list_add_tail(&f->list, &_functions);
	_registered_function_count++;

	/* bind our functions if they have all registered
	 * and the main driver has bound.
	 */
	//if (dev->config && _registered_function_count == dev->num_functions) {
	if (desc_pid == 0xc002 || (dev->config && _registered_function_count == dev->num_functions)){
		bind_functions(dev);
		android_set_default_product(dev->product_id);
	}
}
#endif
/**
 * android_set_function_mask() - enables functions based on selected pid.
 * @up: selected product id pointer
 *
 * This function enables functions related with selected product id.
 */
static void android_set_function_mask(struct android_usb_product *up)
{
	int index;//, found = 0;
	struct usb_function *func;

	list_for_each_entry(func, &android_config_driver.functions, list) {
		/* adb function enable/disable handled separetely */
#if 0
		if (!strcmp(func->name, "adb") && !func->disabled)
			continue;

		for (index = 0; index < up->num_functions; index++) {
			if (!strcmp(up->functions[index], func->name)) {
				found = 1;
				break;
			}
		}

		if (found) { /* func is part of product. */
			/* if func is disabled, enable the same. */
			if (func->disabled)
				usb_function_set_enabled(func, 1);
			found = 0;
		} else { /* func is not part if product. */
			/* if func is enabled, disable the same. */
			if (!func->disabled)
				usb_function_set_enabled(func, 0);
		}
	}
#else
	//	if (!strcmp(func->name, "adb")) //we don't need this
	//		continue;
		func->disabled = 1;
		for (index = 0; index < up->num_functions; index++) {
			if (!strcmp(up->functions[index], func->name))
				func->disabled = 0;
		}
		if(desc_pid ==0xc000){
		    		if (strcmp(func->name, "usb_mass_storage") &&
		    			strcmp(func->name, "adb")&&
		    			strcmp(func->name, "diag")&&
		    			strcmp(func->name, "modem"))//open all when pid = c000
		    			func->disabled = 1;
		    		else
		    			func->disabled = 0;
		    		printk("func->name =%s func->disabled=%d\n",func->name,func->disabled);

		}else if(desc_pid ==0xc00A){

		    		if (strcmp(func->name, "usb_mass_storage") &&
		    			strcmp(func->name, "adb")&&
		    			strcmp(func->name, "modem"))//open all when pid = c000
		    			func->disabled = 1;
		    		else
		    			func->disabled = 0;
		    		printk("func->name =%s func->disabled=%d\n",func->name,func->disabled);
        }else if(desc_pid ==0xc001){ 
	    	if(!boot_usb){
	    	    printk("boot_usb=0\n");    	
		    		if (strcmp(func->name, "usb_mass_storage")) //only ums enabled when pid = c001
		    			func->disabled = 1;
		    		else
		    			func->disabled = 0;
		    		printk("func->name =%s func->disabled=%d\n",func->name,func->disabled);

		    }
	    }
	}
	boot_usb = 1;

#endif
}

/**
 * android_set_defaut_product() - selects default product id and enables
 * required functions
 * @product_id: default product id
 *
 * This function selects default product id using pdata information and
 * enables functions for same.
*/
static void android_set_default_product(int pid)
{
	struct android_dev *dev = _android_dev;
	struct android_usb_product *up = dev->products;
	int index;

	for (index = 0; index < dev->num_products; index++, up++) {
		if (pid == up->product_id)
			break;
	}
	android_set_function_mask(up);
}

/**
 * android_config_functions() - selects product id based on function need
 * to be enabled / disabled.
 * @f: usb function
 * @enable : function needs to be enable or disable
 *
 * This function selects first product id having required function.
 * RNDIS/MTP function enable/disable uses this.
*/
#ifdef CONFIG_USB_ANDROID_RNDIS
static void android_config_functions(struct usb_function *f, int enable)
{
	struct android_dev *dev = _android_dev;
	struct android_usb_product *up = dev->products;
	int index;
	//WilsonWHLee porting from 7069 ++
	char **functions;
    //WilsonWHLee porting from 7069 --
	/* Searches for product id having function */
	if (enable) {
		for (index = 0; index < dev->num_products; index++, up++) {
		//WilsonWHLee porting from 7069 ++
			functions = up->functions;
			if (!strcmp(*functions, f->name))
				break;
        	//WilsonWHLee porting from 7069 --	
		}
		android_set_function_mask(up);
	} else
		android_set_default_product(dev->product_id);
}
#endif

int android_enable_function(struct usb_function *f, int enable)
{
	struct android_dev *dev = _android_dev;
	int disable = !enable;
	int product_id;

    desc_pid = (unsigned short)fih_read_usb_id_from_smem();
    printk("%s: desc_pid=0x%x\n",__func__,desc_pid);
	//WilsonWHLee porting from 7069 ++
	if (!!f->disabled != disable) {
		f->disabled = disable;
	//	usb_function_set_enabled(f, !disable);
	//WilsonWHLee porting from 7069 --
#ifdef CONFIG_USB_ANDROID_RNDIS
		if (!strcmp(f->name, "rndis")) {
            struct usb_function		*func; 	//WilsonWHLee porting from 7069 ++
			/* We need to specify the COMM class in the device descriptor
			 * if we are using RNDIS.
			 */
			if (enable) {
#ifdef CONFIG_USB_ANDROID_RNDIS_WCEIS
				dev->cdev->desc.bDeviceClass = USB_CLASS_MISC;
				dev->cdev->desc.bDeviceSubClass      = 0x02;
				dev->cdev->desc.bDeviceProtocol      = 0x01;
#else
				dev->cdev->desc.bDeviceClass = USB_CLASS_COMM;
#endif
			//WilsonWHLee make sure bind functions++
            
            list_for_each_entry(func, &android_config_driver.functions, list) {
		    		if (strcmp(func->name, "rndis") &&
		    			strcmp(func->name, "adb")) 
		    			func->disabled = 1;
		    		else
		    			func->disabled = 0;
		    }
		    //WilsonWHLee make sure bind functions--
			} else {
				dev->cdev->desc.bDeviceClass = USB_CLASS_PER_INTERFACE;
				dev->cdev->desc.bDeviceSubClass      = 0;
				dev->cdev->desc.bDeviceProtocol      = 0;
			}

			android_config_functions(f, enable);
		}else 	//WilsonWHLee porting from 7069 ++
#endif
#if 1        
        //if(desc_pid == 0xc002)
        //	product_id = 0xc000;
        //else
        if(desc_pid ==0xc002){
            struct usb_function		*func;
            list_for_each_entry(func, &android_config_driver.functions, list) {
		    		if (strcmp(func->name, "diag")) //only diag enabled when pid = c002
		    			func->disabled = 1;
		    		else
		    			func->disabled = 0;
		    }
	    }
	    else if(desc_pid ==0xc001){ 
	    	if(switch_port_enable){
	    	    struct usb_function		*func;
	    	    printk("switch_port_enable=1\n");
                list_for_each_entry(func, &android_config_driver.functions, list) {
                	
		    		if (strcmp(func->name, "usb_mass_storage") &&
		    			strcmp(func->name, "adb"))//only ums adb enabled when pid = c001
		    			func->disabled = 1;
		    		else
		    			func->disabled = 0;
		    		printk("func->name =%s func->disabled=%d\n",func->name,func->disabled);
		        }
	        }
	        else{
	    	    struct usb_function		*func;
	    	    printk("switch_port_enable=0\n");
                list_for_each_entry(func, &android_config_driver.functions, list) {
                	//printk("func->name =%s func->disabled=%d\n",func->name,func->disabled);
		    		if (strcmp(func->name, "usb_mass_storage"))//only ums enabled when pid = c004
		    			func->disabled = 1;
		    		else
		    			func->disabled = 0;
		    		printk("func->name =%s func->disabled=%d\n",func->name,func->disabled);
		        }
		    }
	    }else if(desc_pid ==0xc000){
	    	struct usb_function		*func;
            list_for_each_entry(func, &android_config_driver.functions, list) {
		    		if (strcmp(func->name, "usb_mass_storage") &&
		    			strcmp(func->name, "adb")&&
		    			strcmp(func->name, "diag")&&
		    			strcmp(func->name, "modem"))//open all when pid = c000
		    			func->disabled = 1;
		    		else
		    			func->disabled = 0;
		    		printk("func->name =%s func->disabled=%d\n",func->name,func->disabled);
		    }
		}else if(desc_pid ==0xc00A){
	    	struct usb_function		*func;
            list_for_each_entry(func, &android_config_driver.functions, list) {
		    		if (strcmp(func->name, "usb_mass_storage") &&
		    			strcmp(func->name, "adb")&&
		    			strcmp(func->name, "modem"))//open all when pid = c000
		    			func->disabled = 1;
		    		else
		    			func->disabled = 0;
		    		printk("func->name =%s func->disabled=%d\n",func->name,func->disabled);
		    }
	    }
#endif

#ifdef CONFIG_USB_ANDROID_ACCESSORY
        if (!strncmp(f->name, "accessory", 32))
            android_config_functions(f, enable);
#endif

#ifdef CONFIG_USB_ANDROID_CCID
        if (!strncmp(f->name, "ccid", 4))
            android_config_functions(f, enable);
#endif

#ifdef CONFIG_USB_ANDROID_MTP
		if (!strcmp(f->name, "mtp"))
			android_config_functions(f, enable);
#endif

        device_desc.idVendor = __constant_cpu_to_le16(get_vendor_id(dev));
        //device_desc.idProduct = __constant_cpu_to_le16(get_product_id(dev));
		product_id = get_product_id(dev);
		printk("android_enable_function product_id=0x%x\n",product_id);
		device_desc.idProduct = __constant_cpu_to_le16(product_id);
		if (dev->cdev) {
            dev->cdev->desc.idVendor = device_desc.idVendor;
			dev->cdev->desc.idProduct = device_desc.idProduct;
        }
//StevenCPHuang_20110826,disable the unnecessary judgement ++
//		if(isMoto){
//		    if(product_id != 0x2DE7)
		        usb_composite_force_reset(dev->cdev);
//		}
//		else{
//			if(product_id != 0xc004)//0x2DE7)
//		        usb_composite_force_reset(dev->cdev);
//		}
//StevenCPHuang_20110826,disable the unnecessary judgement --
	}
	return 0;
}

#ifdef CONFIG_DEBUG_FS
static int android_debugfs_open(struct inode *inode, struct file *file)
{
	file->private_data = inode->i_private;
	return 0;
}

static ssize_t android_debugfs_serialno_write(struct file *file, const char
				__user *buf,	size_t count, loff_t *ppos)
{
	char str_buf[MAX_STR_LEN];

	if (count > MAX_STR_LEN)
		return -EFAULT;

	if (copy_from_user(str_buf, buf, count))
		return -EFAULT;

	memcpy(serial_number, str_buf, count);

	if (serial_number[count - 1] == '\n')
		serial_number[count - 1] = '\0';

	strings_dev[STRING_SERIAL_IDX].s = serial_number;

	return count;
}
const struct file_operations android_fops = {
	.open	= android_debugfs_open,
	.write	= android_debugfs_serialno_write,
};

struct dentry *android_debug_root;
struct dentry *android_debug_serialno;

static int android_debugfs_init(struct android_dev *dev)
{
	android_debug_root = debugfs_create_dir("android", NULL);
	if (!android_debug_root)
		return -ENOENT;

	android_debug_serialno = debugfs_create_file("serial_number", 0220,
						android_debug_root, dev,
						&android_fops);
	if (!android_debug_serialno) {
		debugfs_remove(android_debug_root);
		android_debug_root = NULL;
		return -ENOENT;
	}
	return 0;
}

static void android_debugfs_cleanup(void)
{
       debugfs_remove(android_debug_serialno);
       debugfs_remove(android_debug_root);
}
#endif
static int __init android_probe(struct platform_device *pdev)
{
	struct android_usb_platform_data *pdata = pdev->dev.platform_data;
	struct android_dev *dev = _android_dev;
	int result;

///WilsonWHLee 2010/02/23 5110 porting +++++++++++
    unsigned short pid = 0;

//WilsonWHLee is Moto ? ++
/*Product name
DOMINO Q

XT316 = Domino Q W //DMQ 0x2

XT312 = Domino Q CT //DQE 0x1

XT315 = Domino Q Dual SIM //DQD 0x3

 

DOMINO +

XT530 = Domino + W //DMP 0x5

XT532 = Domino + Dual SIM //DP2 0x6

XT533 = Domino + CT //DPD 0x4

*/
    char product_str[21]; //the length is related to board file
    char manufacturer_str[21];
    if ( fih_read_new_hwid_mech_from_orighwid() ) // NEW-HWID
	{
			switch ( fih_read_product_id_from_orighwid() ) {
				case Project_DMQ:
					snprintf(product_str , 6 ,"XT316");
				    isMoto = true;
					break;
				case Project_DQE:
					snprintf(product_str , 6 ,"XT312");
				    isMoto = true;
					break;
				case Project_DQD:
					snprintf(product_str , 6 ,"XT315");
				    isMoto = true;
					break;
				case Project_DMP:
					snprintf(product_str , 6 ,"XT530");
				    isMoto = true;
					break;
				case Project_DP2:
					snprintf(product_str , 6 ,"XT532");
					isMoto = true;
					break;
				case Project_DPD:
					snprintf(product_str , 6 ,"XT533");
				    isMoto = true;
					break;
				case Project_AI1D:
				case Project_AI1S:							
				case Project_FAD:
				default:
					isMoto = false;
					break;
			}
	}
	else
		isMoto = false;
    pid = (unsigned short)fih_read_usb_id_from_smem(); //get pid value from share memory
	desc_pid = pid;
	printk("android_probe USB PID = 0x%x",pid);
    if(pid == 0)
	    pid = 0xC000;
	printk("%s: isMoto = %d\n", __func__, isMoto);
	if (isMoto && pid != 0xc002){
		snprintf(manufacturer_str , 9 ,"Motorola");
		memcpy(pdata->manufacturer_name , manufacturer_str , 21);
		memcpy(pdata->product_name , product_str , 21);
		pdata->vendor_id = 0x22b8;
		if( desc_pid == 0xc000)
            pdata->product_id= 0x2de6;
		else if( desc_pid == 0xc00a)
		    pdata->product_id= 0x2dea;
		pdata->num_products = ARRAY_SIZE(usb_products);
	    pdata->products = usb_products;
	}
//WilsonWHLee is Moto ? --

///WilsonWHLee 2010/02/23 5110 porting ------------
//@CP_DP2_20110701_add & test for solving unknown device show on windows when device in recovery mode ++
    // Disable diag port in recovery +++
	if(pid == 0xc002)
    {
        printk("android_probe: not supporting in recovery mode"); 
        return -ENODEV;
    }
    // Disable diag port in recovery ---
//@CP_DP2_20110701_add & test for solving unknown device show on windows when device in recovery mode --
	printk(KERN_INFO "android_probe pdata: %p\n", pdata);

	pm_runtime_set_active(&pdev->dev);
	pm_runtime_enable(&pdev->dev);

	result = pm_runtime_get(&pdev->dev);
	if (result < 0) {
		dev_err(&pdev->dev,
			"Runtime PM: Unable to wake up the device, rc = %d\n",
			result);
		return result;
	}

	if (pdata) {
		dev->products = pdata->products;
		dev->num_products = pdata->num_products;
		dev->functions = pdata->functions;
		dev->num_functions = pdata->num_functions;
		if (pdata->vendor_id) {
            dev->vendor_id = pdata->vendor_id;
			device_desc.idVendor =
				__constant_cpu_to_le16(pdata->vendor_id);
        }
		if (pdata->product_id) {
#if 1
//Wilson added
		    if( pid == 0xc002) 
			    pdata->product_id = 0xc002;
			else if( pid == 0xc001){
				    if(isMoto)
				        pdata->product_id = 0x2DE8;           
					else
						pdata->product_id = 0xc001;           
            }
#endif
			dev->product_id = pdata->product_id;
//Wilson added
			device_desc.idProduct =
				__constant_cpu_to_le16(pdata->product_id);
		}
		if (pdata->version)
			dev->version = pdata->version;
        if (pdata->fih_version)
			fih_version_buf=pdata->fih_version;
		if (pdata->product_name)
			strings_dev[STRING_PRODUCT_IDX].s = pdata->product_name;
		if (pdata->manufacturer_name)
			strings_dev[STRING_MANUFACTURER_IDX].s =
					pdata->manufacturer_name;
		if (pdata->serial_number)
			if(desc_pid != 0xc002)
			strings_dev[STRING_SERIAL_IDX].s = pdata->serial_number;
	}
#ifdef CONFIG_DEBUG_FS
	result = android_debugfs_init(dev);
	if (result)
		pr_debug("%s: android_debugfs_init failed\n", __func__);
#endif
	return usb_composite_register(&android_usb_driver);
}

static int andr_runtime_suspend(struct device *dev)
{
	dev_dbg(dev, "pm_runtime: suspending...\n");
	return 0;
}

static int andr_runtime_resume(struct device *dev)
{
	dev_dbg(dev, "pm_runtime: resuming...\n");
	return 0;
}

static struct dev_pm_ops andr_dev_pm_ops = {
	.runtime_suspend = andr_runtime_suspend,
	.runtime_resume = andr_runtime_resume,
};

static struct platform_driver android_platform_driver = {
	.driver = { .name = "android_usb", .pm = &andr_dev_pm_ops},
};

static int __init init(void)
{
	struct android_dev *dev;

	pr_debug("android init\n");
	dev = kzalloc(sizeof(*dev), GFP_KERNEL);
	if (!dev)
		return -ENOMEM;

	/* set default values, which should be overridden by platform data */
	dev->product_id = PRODUCT_ID;
	_android_dev = dev;

	return platform_driver_probe(&android_platform_driver, android_probe);
}
module_init(init);

static void __exit cleanup(void)
{
#ifdef CONFIG_DEBUG_FS
	android_debugfs_cleanup();
#endif
	usb_composite_unregister(&android_usb_driver);
	platform_driver_unregister(&android_platform_driver);
	kfree(_android_dev);
	_android_dev = NULL;
}
module_exit(cleanup);
