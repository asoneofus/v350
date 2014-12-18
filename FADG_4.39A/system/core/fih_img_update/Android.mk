LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:=                \
                  fih_imgupd.cpp    \
                  utilcrc.cpp  \
                  tinystr.cpp   \
                  tinyxml.cpp   \
                  tinyxmlerror.cpp  \
                  tinyxmlparser.cpp \
                  nb0parser.cpp \
                  md5.cpp
	
LOCAL_MODULE:= fih_imgupd

LOCAL_FORCE_STATIC_EXECUTABLE := true

LOCAL_C_INCLUDES := $(KERNEL_HEADERS)

#LOCAL_CFLAGS := -I bionic/libstdc++/include

#LOCAL_LDFLAGS:= $(TOOL_LDFLAGS) -lstdc++ -lc

LOCAL_STATIC_LIBRARIES := libcutils libc libstdc++

include $(BUILD_EXECUTABLE)
