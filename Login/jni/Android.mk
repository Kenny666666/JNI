# "#"号在mk文件中代表注释
#Android.mk文件详解：交叉编译器在编译c代码/c++代码的时候依赖的配置文件，他是linux下makefile的语法的子集


   #LOCAL_PATH 获取当前Android.mk的路径
   LOCAL_PATH := $(call my-dir)
   
   #变量的初始化操作，但不会重新初始化LOCAL_PATH 变量
   include $(CLEAR_VARS)
   #生成so文件的名字，会生成lib前缀.so后缀的文件。  如：libHello.so,这都是makefile的语法约定
   LOCAL_MODULE    := Hello
   LOCAL_SRC_FILES := Hello.c
   #在c中打印log,引入liblog.so库(引入的语法:-l+库名  例：-llog)，E:\Android\Androidvideo\JNI\jni_day02\ziliao\android-ndk-r7b\platforms\android-8\arch-arm\usr\lib\liblog.so
   LOCAL_LDLIBS += -llog
   include $(BUILD_SHARED_LIBRARY)

   #别的参数
   #LOCAL_CPP_EXTENSION := cc  //指定c++文件的扩展名
   #指定需要加载一些别的什么库
   #LOCAL_LDLIBS += -llog -lvmsagent -lmpnet -lmpxml -lH264Android