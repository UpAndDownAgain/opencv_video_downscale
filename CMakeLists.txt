cmake_minimum_required(VERSION 3.14)
project(opencv_video_downscale)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)
add_executable(opencv_video_downscale main.cpp VideoDownScaler.cpp VideoDownScaler.h)
target_link_libraries(opencv_video_downscale ${OpenCV_LIBS} )