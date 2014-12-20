LOCAL_PATH:= $(call my-dir)
LOCAL_MODULE:= mke2fs
include $(CLEAR_VARS)

# Make #!/system/bin/mke2fs launchers for each tool.

copy_from := \
	mke2fs \
        e2fsck\
        tune2fs
        

copy_to := $(addprefix $(TARGET_OUT)/bin/,$(copy_from))
copy_from := $(addprefix $(LOCAL_PATH)/,$(copy_from))

$(copy_to) : PRIVATE_MODULE := $(LOCAL_MODULE)
$(copy_to) : $(TARGET_OUT)/% : $(LOCAL_PATH)/% | $(ACP)
	$(transform-prebuilt-to-target)

ALL_PREBUILT += $(copy_to)

