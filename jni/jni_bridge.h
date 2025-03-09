//
// Created by jf160343d on 3/9/2025.
//

#ifndef JNI_BRIDGE_H
#define JNI_BRIDGE_H

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * JNI function that bridges the Java function to the C++ implementation.
     * This function is called from Java/Kotlin via JNI.
     *
     * @param env Pointer to JNI environment.
     * @param obj Reference to the calling Java object.
     * @param addressStart First address as a jstring.
     * @param addressEnd Second address as a jstring.
     * @return The computed distance as a jdouble.
     */
    JNIEXPORT jdouble JNICALL
    Java_com_yourname_routeoptimization_MainActivity_calculateDistance(
            JNIEnv* env,
            jobject obj,
            jstring addressStart,
            jstring addressEnd
    );

#ifdef __cplusplus
}
#endif

#endif // JNI_BRIDGE_H
