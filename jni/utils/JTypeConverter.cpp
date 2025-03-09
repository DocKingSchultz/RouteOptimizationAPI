//
// Created by jf160343d on 3/9/2025.
//

#include "JTypeConverter.h"

std::string JTypeConverter::jstringToString(JNIEnv *env, jstring jStr) {
    if (!jStr)return "";
    const char *str = env->GetStringUTFChars(jStr, nullptr);
    std::string result = str;
    env->ReleaseStringUTFChars(jStr, str);
    return result;
}

jstring JTypeConverter::stringToJString(JNIEnv *env, const char *str) {
    return env->NewStringUTF((char *)str);
}
