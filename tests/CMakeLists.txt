cmake_minimum_required(VERSION 3.10)

include(CTest)
include(CheckCCompilerFlag)

enable_testing()

add_executable(base_test base_test.c)
target_compile_options(base_test PRIVATE -std=c89)
add_test(NAME base.test COMMAND base_test)
