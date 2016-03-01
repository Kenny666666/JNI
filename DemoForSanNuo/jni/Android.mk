LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_LDLIBS += -llog

LOCAL_MODULE := CarRunning

LOCAL_SRC_FILES :=	com_beyondsoft_sannuo_RunningInfo.c \
					car_internal_show_R.c				\

include $(BUILD_SHARED_LIBRARY)



