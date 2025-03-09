cmake_minimum_required(VERSION 3.18)
project(RouteOptimizationAPI)

set(CMAKE_CXX_STANDARD 17)

# Set Android NDK path
set(ANDROID_NDK "C:/Users/jf160343d/AppData/Local/Android/Sdk/ndk/29.0.13113456")

# Include directories for JNI and project headers
include_directories(
        ${ANDROID_NDK}/toolchains/llvm/prebuilt/windows-x86_64/sysroot/usr/include
        ${CMAKE_SOURCE_DIR}/include
)

# Add library
add_library(RouteOptimizationAPI SHARED
        src/dist_calculator.cpp
        jni/utils/JTypeConverter.cpp
        jni/utils/JTypeConverter.h
        jni/jni_bridge.cpp
        jni/jni_bridge.h
)

target_link_libraries(RouteOptimizationAPI
        android
        log
)
