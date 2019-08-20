cmake_minimum_required(VERSION 3.13)
project(testOpencvAruco)

set(CMAKE_CXX_STANDARD 14)

set(OpenCV_DIR "../../../opencv/installation/OpenCV-master/lib/cmake/opencv4")
find_package(OpenCV REQUIRED)

add_executable(testOpencvAruco main.cpp)
target_link_libraries(testOpencvAruco ${OpenCV_LIBS})