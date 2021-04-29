cmake_minimum_required(VERSION 3.19)
project(nokiatest)

set(CMAKE_CXX_STANDARD 20)


set(NEW_COMPILE_FLAGS "-static")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${NEW_COMPILE_FLAGS}" )

add_executable(nokiatest main.cpp funcs.cpp funcs.h expression.cpp expression.h parse_func.cpp parse_func.h csv_table.cpp csv_table.h)