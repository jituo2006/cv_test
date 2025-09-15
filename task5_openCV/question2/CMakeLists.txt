cmake_minimum_required(VERSION 3.10)
project(CircleDetector)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(circle_detector cv_2.cpp)
target_link_libraries(circle_detector ${OpenCV_LIBS})