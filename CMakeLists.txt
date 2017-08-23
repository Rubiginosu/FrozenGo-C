cmake_minimum_required(VERSION 3.8)
project(FrozenGo_C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c smgr/start.c smgr/start.h cnf/cnf.c cnf/cnf.h clog/color.c clog/color.h)
add_executable(FrozenGo_C ${SOURCE_FILES})