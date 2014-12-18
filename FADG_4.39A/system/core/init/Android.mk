# Copyright 2005 The Android Open Source Project

LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	builtins.c \
	init.c \
	devices.c \
	property_service.c \
	runit.c \
	util.c \
	parser.c \
	mlog.c \
	logo.c \
	keychords.c \
	signal_handler.c \
	init_parser.c \
	ueventd.c \
	ueventd_parser.c \
	fih_prop_serv.c

ifeq ($(strip $(INIT_BOOTCHART)),true)
LOCAL_SRC_FILES += bootchart.c
LOCAL_CFLAGS    += -DBOOTCHART=1
endif

#WeiChihChen@20110309@Support ext3 format of emmc data partion BEGIN
ifeq ($(QCOM_TARGET_PRODUCT),msm7630_surf)
    LOCAL_CFLAGS += -DEMMC_DATA_FORMAT
endif
#WeiChihChen@20110309@Support ext3 format of emmc data partion END

ifeq ($(BOARD_HAS_BCM_CHIP), true)

ifeq ($(SF8_WLAN), true)
LOCAL_CFLAGS    += -DBROADCOM_WLAN
endif

ifeq ($(SF8_BLUETOOTH), true)
LOCAL_CFLAGS    += -DBROADCOM_BT
endif

endif

LOCAL_MODULE:= init

LOCAL_FORCE_STATIC_EXECUTABLE := true
LOCAL_MODULE_PATH := $(TARGET_ROOT_OUT)
LOCAL_UNSTRIPPED_PATH := $(TARGET_ROOT_OUT_UNSTRIPPED)

LOCAL_STATIC_LIBRARIES := libcutils libc

include $(BUILD_EXECUTABLE)

# Make a symlink from /sbin/ueventd to /init
SYMLINKS := $(TARGET_ROOT_OUT)/sbin/ueventd
$(SYMLINKS): INIT_BINARY := $(LOCAL_MODULE)
$(SYMLINKS): $(LOCAL_INSTALLED_MODULE) $(LOCAL_PATH)/Android.mk
	@echo "Symlink: $@ -> ../$(INIT_BINARY)"
	@mkdir -p $(dir $@)
	@rm -rf $@
	$(hide) ln -sf ../$(INIT_BINARY) $@

ALL_DEFAULT_INSTALLED_MODULES += $(SYMLINKS)

# We need this so that the installed files could be picked up based on the
# local module name
ALL_MODULES.$(LOCAL_MODULE).INSTALLED := \
    $(ALL_MODULES.$(LOCAL_MODULE).INSTALLED) $(SYMLINKS)
