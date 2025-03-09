# RouteOptimizationAPI
RouteOptimizationAPI is a C++ library designed to compute optimal routes from a starting location to multiple destinations while optimizing for fastest and/or cheapest routes. The library will integrate with TomTom API to fetch real-time distances and provide smart route-planning capabilities. This library is built to be modular and cross-platform.

## 📦 Requirements
- **CMake** (`>= 3.30`)
- **MinGW-w64** (for Windows)
- **Git** (for version control)

## ⚙️ Setup & Build Instructions
### **1️⃣ Clone the Repository**
```sh
git clone https://github.com/DocKingSchultz/RouteOptimizationAPI.git
cd RouteOptimizationAPI
cmake -B cmake-build-debug-mingw .
mingw32-make -C cmake-build-debug-mingw
./cmake-build-debug-mingw/TestApp.exe  # Windows


