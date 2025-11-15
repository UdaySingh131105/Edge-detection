#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_flamedgeviewer_MainActivity_nativeHello(JNIEnv* env, jobject /* this */) {
    return env->NewStringUTF("EdgeViewer JNI ready");
}
