cmake_minimum_required(VERSION 3.10)
project(ChatClient)

set(CMAKE_CXX_STANDARD 17)

add_executable(ChatClient main.cpp Client.cpp Client.h)