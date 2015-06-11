LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := opencv_nonfree
LOCAL_SRC_FILES := lib/libnonfree.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE    := opencv_java
LOCAL_SRC_FILES := lib/libopencv_java.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE := freeglut-gles
LOCAL_SRC_FILES := lib/libfreeglut-gles.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/GL
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)

#LOCAL_MODULE := libpng
#LOCAL_SRC_FILES := lib/libpng.so
#FILE_LIST_LIBPNG_C := $(wildcard $(LOCAL_PATH)/libpng/*.c)
#FILE_LIST_LIBPNG_H := $(wildcard $(LOCAL_PATH)/libpng/*.h)
#LOCAL_SRC_FILES := $(FILE_LIST_LIBPNG_C:$(LOCAL_PATH)/%=%)
#LOCAL_C_INCLUDES := $(FILE_LIST_LIBPNG_H:$(LOCAL_PATH)/%=%)
#include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
OPENCV_LIB_TYPE := STATIC
OPENCV_INSTALL_MODULES := on
include /home/thinker/Android/OpenCV-2-4-10/sdk/native/jni/OpenCV.mk

#LOCAL_C_INCLUDES:= /home/thinker/Android/OpenCV-2-4-10/sdk/native/jni/OpenCV.mk
LOCAL_MODULE    := native_openmaka

FILE_LIST := $(wildcard $(LOCAL_PATH)/**/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/*.cpp)

LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)

#LOCAL_STATIC_LIBRARIES := libpng
LOCAL_SHARED_LIBRARIES := opencv_nonfree opencv_java

LOCAL_CFLAGS    := -Werror -O3 -ffast-math -DNDEBUG -DANDROID_NDK -DDISABLE_IMPORTGL -DOPEL_ES_1 -ffast-math
LOCAL_CXXFLAGS  += -fno-exceptions
LOCAL_LDLIBS    += -L$(LOCAL_PATH)/lib -landroid -llog -ldl -lEGL -lGLESv1_CM -lOpenSLES -lGLESv2
LOCAL_DISABLE_FORMAT_STRING_CHECKS := true




include $(BUILD_SHARED_LIBRARY)