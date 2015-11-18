cmake_minimum_required(VERSION 3.3)
project(sarace)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c GridUtils.c GridUtils.h DictionaryUtils.c DictionaryUtils.h Parametres.h Tree.c Tree.h)
add_executable(sarace ${SOURCE_FILES})