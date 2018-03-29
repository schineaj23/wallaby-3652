cmake_minimum_required (VERSION 2.6)
project (wallaby-3652)
 
# configure a header file to pass some of the CMake settings
# to the source code

configure_file (
  "${PROJECT_SOURCE_DIR}/src"
  "${PROJECT_BINARY_DIR}/build"
  )
 
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("/include")
incldue_directories("/kipr")
 
# add the executable
add_executable(build.cxx)