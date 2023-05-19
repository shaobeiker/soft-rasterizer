cmake_minimum_required(VERSION 3.25)
project(NewProject)

set(CMAKE_CXX_STANDARD 23)

add_executable(NewProject main.cpp utils/transform.cpp utils/transform.h math/vector.cpp math/vector.h math/matrix.cpp math/matrix.h)
