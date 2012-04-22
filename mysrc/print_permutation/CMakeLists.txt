##
# cussyou@gmail.com
# this may be as my cmake template
##
cmake_minimum_required(VERSION 2.8)
set(CMAKE_VERBOSE_MAKEFILE ON)

project(print_permutaion)


## include path
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
## end inc path

## lib path
link_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}}/lib
)
## end lib path

## src files
set(SRC_LIST
  ${CMAKE_CURRENT_SOURCE_DIR}/src/print_permutation.cpp
)
## end src files

## targets
add_executable(print_permutation 
  ${SRC_LIST}
  
)

## end targets