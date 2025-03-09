//
// Created by jf160343d on 3/9/2025.
//

#ifndef TYPECONVERTER_H
#define TYPECONVERTER_H
#include <jni.h>
#include <string>


class JTypeConverter {
public:
    static std::string  jstringToString(JNIEnv *env, jstring obj);

    static jstring stringToJString(JNIEnv *env, const char *str);
};



#endif //TYPECONVERTER_H
