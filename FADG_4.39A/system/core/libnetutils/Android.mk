LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
        dhcpclient.c \
        dhcpmsg.c \
        dhcp_utils.c \
        ifc_utils.c \
	packet.c

ifeq ($(findstring gingerbread,$(QCOM_TARGET_BRANCH)),gingerbread)
    LOCAL_SRC_FILES := $(filter-out ifc_utils.c, $(LOCAL_SRC_FILES))
    LOCAL_SRC_FILES += ifc_utils_gingerbread.c
endif

ifeq ($(WPA_SUPPLICANT_VERSION),VER_0_8_X)
ifeq ($(strip $(FIH_WIFI_TYPE)),WIFI_BCM4330_WFD)
    LOCAL_SRC_FILES := $(filter-out dhcp_utils.c, $(LOCAL_SRC_FILES))
    LOCAL_SRC_FILES += dhcp_utils_bcm4330_wfd.c 
    LOCAL_SRC_FILES += dlna_utils.c
endif
ifeq ($(strip $(FIH_WIFI_TYPE)),WAPI_BCM4330)
    LOCAL_SRC_FILES := $(filter-out dhcp_utils.c, $(LOCAL_SRC_FILES))
    LOCAL_SRC_FILES += dhcp_utils_bcm4330_wfd.c 
    LOCAL_SRC_FILES += dlna_utils.c
endif
endif

LOCAL_SHARED_LIBRARIES := \
	libcutils

# need "-lrt" on Linux simulator to pick up clock_gettime
ifeq ($(TARGET_SIMULATOR),true)
	ifeq ($(HOST_OS),linux)
		LOCAL_LDLIBS += -lrt -lpthread
	endif
endif

LOCAL_MODULE:= libnetutils

include $(BUILD_SHARED_LIBRARY)
