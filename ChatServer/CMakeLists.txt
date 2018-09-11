cmake_minimum_required(VERSION 3.10)
project(Chat)

set(CMAKE_CXX_STANDARD 17)

add_executable(Chat Server.cpp Server.h main.cpp)