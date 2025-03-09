#include "jni_bridge.h"
#include "dist_calculator.h"
#include "utils/JTypeConverter.h"

JNIEXPORT jdouble JNICALL
Java_com_yourname_routeoptimization_MainActivity_calculateDistance(
        JNIEnv* env,
        jobject obj,
        jstring addressStart,
        jstring addressEnd
) {
    std::string addr1 = JTypeConverter::jstringToString(env, addressStart);
    std::string addr2 = JTypeConverter::jstringToString(env, addressEnd);

    // Call the actual C++ function
    return calculate_distance(addr1, addr2);
}
