cmake_minimum_required(VERSION 3.30)
project(RouteOptimizationAPI)

set(CMAKE_CXX_STANDARD 17)

# Define the shared library (only .cpp files)
add_library(RouteOptimizationAPI SHARED src/dist_calculator.cpp)

target_include_directories(RouteOptimizationAPI PUBLIC
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/src
)

# Define an executable for testing
add_executable(TestApp src/main.cpp)

# Link the executable with the shared library
target_link_libraries(TestApp PRIVATE RouteOptimizationAPI)
