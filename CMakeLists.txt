cmake_minimum_required(VERSION 3.10)

project(arena C)

option(ARENA_SHARED "Use shared library instead of static" OFF)

set(ARENA_LIB_TYPE STATIC)
if(ARENA_SHARED)
  set(ARENA_LIB_TYPE SHARED)
  message(STATUS "Using shared library (.so)")
else()
  message(STATUS "Using static library (.a)")
endif()

add_library(arena ${ARENA_LIB_TYPE} src/arena.c)

target_include_directories(arena PRIVATE include)
