APP_MODULE              := OpemGLSample
APP_OPTIM				:= release
NDK_TOOLCHAIN_VERSION   := 4.8
APP_STL                 := gnustl_static
APP_CFLAGS              := -pthread -frtti -fexceptions -O3 -mfloat-abi=softfp -mfpu=neon -ftemplate-backtrace-limit=0 -w
APP_CPPFLAGS            := -std=c++11
APP_CXXFLAGS            := -std=c++11
APP_ABI                 := armeabi-v7a
APP_PLATFORM            := android-19
LOCAL_ARM_NEON          := true
