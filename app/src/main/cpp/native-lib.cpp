#include <jni.h>
#include <string>

//由于 FFmpeg 库是 C 语言实现的，我们这里是c++文件，所以要告诉编译器按照 C 的规则进行编译
extern "C" {
#include "libavformat/version.h"
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_player_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    return env->NewStringUTF(AV_STRINGIFY(LIBAVFORMAT_VERSION));
}