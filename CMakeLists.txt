cmake_minimum_required(VERSION 3.8)
project(FrozenGo_C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c smgr/start.c smgr/start.h cnf/cnf.c cnf/cnf.h clog/color.c clog/color.h smgr/execv.c smgr/execv.h smgr/handler.c smgr/handler.h utils/str_filter.c utils/str_filter.h utils/md5_cmp.c utils/md5_cmp.h utils/md5_sum.c utils/md5_sum.h)
link_libraries(pthread)
link_libraries(crypto)
add_executable(FrozenGo_C ${SOURCE_FILES})