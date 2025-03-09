# 🚀 RouteOptimizationAPI

RouteOptimizationAPI is a C++ library designed to compute optimal routes from a starting location to multiple destinations while optimizing for the fastest and/or cheapest routes. The library integrates with the **TomTom API** to fetch real-time distances and provide smart route-planning capabilities. This library is built to be **modular** and **cross-platform**.

---

## 📦 Requirements

### **General Requirements**
- **CMake** (Version **3.22+**)
- **Android NDK** (Installed via **Android Studio SDK Manager**)
- **Ninja Build System** (Install via Chocolatey: `choco install ninja -y`)
- **CLion** (or another CMake-compatible IDE)

---

## ⚙️ **Setup & Build Instructions**

### **1️⃣ Clone the Repository**
```sh
git clone https://github.com/DocKingSchultz/RouteOptimizationAPI.git
cd RouteOptimizationAPI
```

### **2️⃣ Remove Previous Build Files (if any)**
Run the following command to delete old build files before starting a fresh build:

```sh
Remove-Item -Recurse -Force cmake-build-android  # Windows PowerShell
```

### **3️⃣ Configure CMake for Android**
Use CMake to configure the build for Android (arm64-v8a):

```sh
cmake -B cmake-build-android -G "Ninja" \
    -DCMAKE_TOOLCHAIN_FILE="$ANDROID_NDK/build/cmake/android.toolchain.cmake" \
    -DANDROID_ABI=arm64-v8a \
    -DANDROID_PLATFORM=android-21 .
```

🔹 **Note:** Replace `$ANDROID_NDK` with your actual NDK path, e.g.:
```sh
C:/Users/YOUR_USER/AppData/Local/Android/Sdk/ndk/29.0.13113456
```

### **4️⃣ Build the Library**
Once configured, run the following command to build the shared library:
```sh
cmake --build cmake-build-android
```

### **5️⃣ Locate the Generated .so File**
After a successful build, locate the shared library file:
```sh
ls cmake-build-android/**/*.so
```
Expected output:
```sh
cmake-build-android/arm64-v8a/libRouteOptimizationAPI.so
```

---

## 📲 **Integrating the .so Library in Android Studio**

### **6️⃣ Copy .so File to Android Project**
Create a JNI Directory in your Android project:
```sh
mkdir -p app/src/main/jniLibs/arm64-v8a/
```
Move the generated `.so` file inside this folder:
```sh
mv cmake-build-android/arm64-v8a/libRouteOptimizationAPI.so \
   app/src/main/jniLibs/arm64-v8a/
```

### **7️⃣ Load the Library in Your Kotlin Code**
Modify `MainActivity.kt`:
```kotlin
class MainActivity : AppCompatActivity() {

    companion object {
        init {
            System.loadLibrary("RouteOptimizationAPI")  // Name without `lib` and `.so`
        }
    }

    // Declare external C++ function
    external fun calculateDistance(address1: String, address2: String): Double

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val result = calculateDistance("New York", "Los Angeles")
        Log.d("RouteOptimization", "Calculated Distance: $result")
    }
}
```

### **8️⃣ Define the JNI Function in C++**
Modify `dist_calculator.h`:
```cpp
#ifndef DIST_CALCULATOR_H
#define DIST_CALCULATOR_H

#include <jni.h>
#include <string>

extern "C" JNIEXPORT jdouble JNICALL
Java_com_yourname_routeoptimization_MainActivity_calculateDistance(
        JNIEnv *env,
        jobject obj,
        jstring address1,
        jstring address2);

#endif //DIST_CALCULATOR_H
```
Modify `dist_calculator.cpp`:
```cpp
#include "dist_calculator.h"

extern "C" JNIEXPORT jdouble JNICALL
Java_com_yourname_routeoptimization_MainActivity_calculateDistance(
        JNIEnv *env,
        jobject obj,
        jstring address1,
        jstring address2) {
    return 42.0;  // Placeholder implementation
}
```

### **9️⃣ Update CMakeLists.txt in Android Studio**
Modify `app/CMakeLists.txt` to link the library:
```cmake
cmake_minimum_required(VERSION 3.18)
project(RouteOptimizationAPI)

set(CMAKE_CXX_STANDARD 17)

add_library(RouteOptimizationAPI SHARED IMPORTED)
set_target_properties(RouteOptimizationAPI PROPERTIES IMPORTED_LOCATION
    ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libRouteOptimizationAPI.so)

target_link_libraries(RouteOptimizationAPI log)
```

### **🔄 10️⃣ Clean & Rebuild the Android Project**
Run these commands:
```sh
./gradlew clean
./gradlew build
```

---

## ✅ **Final Test**
Run the app on an Android device.
Check the logs for:
```yaml
Calculated Distance: 42.0
```

---

## 🏁 **Conclusion**
This guide provides end-to-end steps to:
- Build a C++ library (.so file)
- Integrate it into an Android Studio project
- Call the function from Kotlin using JNI

🔹 **Happy Coding! 🚀**

