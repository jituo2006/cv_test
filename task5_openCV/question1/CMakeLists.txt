cmake_minimum_required(VERSION 3.10)
project(RedExtractor)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(red_extractor main.cpp)
target_link_libraries(red_extractor ${OpenCV_LIBS})