cmake_minimum_required(VERSION 2.6)
project(armory)

set(CMAKE_C_STANDARD 90)

add_library(armory armory.h make_nonblocking.c is_space.c create_dir_if_not_exists.c)
