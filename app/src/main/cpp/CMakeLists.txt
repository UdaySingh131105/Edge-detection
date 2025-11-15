cmake_minimum_required(VERSION 3.22.1)
project(flamedgeviewer)

add_library(flamedgeviewer SHARED native-lib.cpp)

find_library(log-lib log)
target_link_libraries(flamedgeviewer ${log-lib})
