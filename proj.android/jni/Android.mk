LOCAL_PATH := $(call my-dir)
$(call import-add-path,$(LOCAL_PATH)/../)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/MainItem.cpp \
                   ../../Classes/PauseScene.cpp \
                   ../../Classes/ResultScene.cpp \
                   ../../Classes/PlayScene.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes \
                    $(LOCAL_PATH)/../protocols/android    \
                    $(LOCAL_PATH)/../protocols/include
LOCAL_WHOLE_STATIC_LIBRARIES := PluginProtocolStatic

LOCAL_STATIC_LIBRARIES := cocos2dx_static
LOCAL_STATIC_LIBRARIES += PluginProtocolStatic

include $(BUILD_SHARED_LIBRARY)

$(call import-module,./prebuilt-mk)
$(call import-module,protocols/android)