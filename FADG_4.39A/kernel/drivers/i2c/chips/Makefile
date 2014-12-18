#
# Makefile for miscellaneous I2C chip drivers.
#
# Do not add new drivers to this directory! It is DEPRECATED.
#
# Device drivers are better grouped according to the functionality they
# implement rather than to the bus they are connected to. In particular:
# * Hardware monitoring chip drivers go to drivers/hwmon
# * RTC chip drivers go to drivers/rtc
# * I/O expander drivers go to drivers/gpio
#

obj-$(CONFIG_SENSORS_MT9T013)	+= mt9t013.o
#+++ FIH_FXX +++  // Square 20110502
obj-$(CONFIG_SC668) += sc668.o
#--- FIH_FXX ---  // Square 20110502

###+++ChandlerKang[mq4_porting]
obj-$(CONFIG_BACKLIGHT_LED_TPS61160) += tps61160.o
###---ChandlerKang[mq4_porting]

###+++ChandlerKang[porting_rt9365]
obj-$(CONFIG_BACKLIGHT_LED_RT9365) += rt9365.o
###---ChandlerKang[porting_rt9365]
###+FIH_FXX, Charles Huang, 2009/05/18
obj-$(CONFIG_FLASH_DRIVER_IC_AAT1272) += aat1272.o
###-FIH_FXX, Charles Huang, 2009/05/18

ifeq ($(CONFIG_I2C_DEBUG_CHIP),y)
EXTRA_CFLAGS += -DDEBUG
endif

