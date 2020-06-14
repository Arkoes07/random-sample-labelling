# CMakeList.txt : CMake project for RandomSampleLabelling, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# set everything up for c++ 17 features
set(CMAKE_CXX_STANDARD 17)

project ("RandomSampleLabelling")

find_package(OpenCV REQUIRED)
find_package(dlib REQUIRED)

# Add source to this project's executable.
add_executable (RandomSampleLabelling "RandomSampleLabelling.cpp" )

# TODO: Add tests and install targets if needed.
target_link_libraries (RandomSampleLabelling ${OpenCV_LIBS} dlib::dlib)