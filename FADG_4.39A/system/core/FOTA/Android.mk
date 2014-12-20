# Copyright 2006 The Android Open Source Project

LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_PREBUILT_LIBS := DominQ_arm-eabi-4.4.0_fs.a

include $(BUILD_MULTI_PREBUILT)






include $(CLEAR_VARS)

LOCAL_SRC_FILES:= RB_FSUpdate6.2.c vRM_NewFunc.c

LOCAL_SHARED_LIBRARIES := liblog
LOCAL_STATIC_LIBRARIES := libcutils DominQ_arm-eabi-4.4.0_fs

LOCAL_MODULE:= fota

include $(BUILD_EXECUTABLE)
