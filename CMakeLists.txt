cmake_minimum_required(VERSION 2.8)

aux_source_directory(. SRC)

set(CMAKE_CXX_STANDARD 11)

add_executable(lpcppc ${SRC})
