##
# cussyou@gmail.com
# this may be as my cmake template
##
cmake_minimum_required(VERSION 2.6)

project(gles_test)

set(CMAKE_CROSSCOMPILING 1)

## compiler, system include and lib path
if(${CMAKE_CROSSCOMPILING} EQUAL 1 )
  include(CMakeForceCompiler)
  set (DEVROOT "/home/user/toolchain-arm-karmic.rgs0" CACHE PATH "Location of QNX toolchain")
  set (TOOLSROOT ${DEVROOT})

  set (CMAKE_C_COMPILER ${TOOLSROOT}/bin/arm-none-linux-gnueabi-gcc)
  set (CMAKE_CXX_COMPILER ${TOOLSROOT}/bin/arm-none-linux-gnueabi-g++)

  set (CMAKE_C_FLAGS  CACHE STRING "gcc c flags" FORCE)
  set (CMAKE_CXX_FLAGS CACHE STRING "gcc c++ flags" FORCE)
  set (CMAKE_AR "${TOOLSROOT}/bin/arm-fsl-linux-gnueabi-ar" CACHE PATH "Location of ar" FORCE)
  set(LTIB_PATH /home/user/toolchain-arm-karmic.rgs0)

  include_directories(
    ${LTIB_PATH}/sysroot/usr/include
    ${LTIB_PATH}/sysroot/usr/include/gtk-2.0
    )
  link_directories(
    ${LTIB_PATH}/sysroot/usr/lib
    ${LTIB_PATH}/sysroot/lib
    )

endif(${CMAKE_CROSSCOMPILING} EQUAL 1)
## end

## include path
include_directories(
  ${PROJECT_SOURCE_DIR}/src
)
## end inc path

## lib path
link_directories(
  ${PROJECT_SOURCE_DIR}}/lib
)
## end lib path

## src files
set(SRC_LIST
  ${PROJECT_SOURCE_DIR}/src/gles_test.c
  ${PROJECT_SOURCE_DIR}/src/glesutil.c
  ${PROJECT_SOURCE_DIR}/src/eglutil.c
)
## end src files

## link libraries
set(LIB_LIST
  libegl13X.so libgles11.so
)
## end link

## targets
add_executable(gles_test 
  ${SRC_LIST}
  
)
target_link_libraries(
  gles_test
  ${LIB_LIST}
)

## end targets