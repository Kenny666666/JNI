# "#"号在mk文件中代表注释
#Android.mk文件详解：交叉编译器在编译c代码/c++代码的时候依赖的配置文件，他是linux下makefile的语法的子集


   #LOCAL_PATH 获取当前Android.mk的路径
   LOCAL_PATH := $(call my-dir)
   
   include $(CLEAR_VARS)
   LOCAL_CPP_EXTENSION := cc
   LOCAL_MODULE    := Hello
   LOCAL_SRC_FILES := Hello.cpp
   LOCAL_LDLIBS += -llog
   include $(BUILD_SHARED_LIBRARY)

   #别的参数
   #LOCAL_CPP_EXTENSION := cc  //指定c++文件的扩展名
   #指定需要加载一些别的什么库
   #LOCAL_LDLIBS += -llog -lvmsagent -lmpnet -lmpxml -lH264Android