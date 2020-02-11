#cmake_minimum_required(VERSION 3.4)
cmake_minimum_required(VERSION 2.8)

project(liblifx)
include(ExternalProject)

set(CMAKE_C_FLAGS_DEBUG "-Wall -Wextra -g -O0 -fno-inline -Wno-unused-parameter")
set(CMAKE_C_FLAGS_RELEASE "-Werror -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -g -O0 -fno-inline") # -Weffc++ ")
set(CMAKE_CXX_FLAGS_RELEASE "-Werror -Wall -Wextra") # -Weffc++")

########################################################
# generates sources using lxcodegen with protocol.yml
set(LIFX_YAML ${CMAKE_CURRENT_BINARY_DIR}/deps/src/lifx_yaml_file/protocol.yml)
set(LIFX_YAML_SRC ${CMAKE_CURRENT_BINARY_DIR}/deps/src/lifx_protocol.c)
add_custom_command(
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/tools/lxcodegen.py -i ${LIFX_YAML} -o ${LIFX_YAML_SRC}
  OUTPUT ${LIFX_YAML_SRC})
########################################################

########################################################
# lifx protocol.yml
# just downloads the protocol.yml from github
ExternalProject_Add(
  lifx_yaml_file
  GIT_REPOSITORY https://github.com/LIFX/public-protocol.git
  INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}
  INSTALL_COMMAND ""
  CONFIGURE_COMMAND ""
  BUILD_IN_SOURCE 1
  PREFIX deps 
  BUILD_COMMAND "")
########################################################

########################################################
# yaml lib
#ExternalProject_Add(
#  yaml
#  GIT_REPOSITORY https://github.com/yaml/libyaml.git
#  GIT_TAG release/0.2.3
#  INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}
#  INSTALL_COMMAND ""
#  PREFIX deps
#  CMAKE_ARGS "${CMAKE_ARGS};-DBUILD_SHARED_LIBS=yes")
#
# ./deps/src/yaml-build/libyaml.so
#set(YAML_INCLUDE_DIR ${CMAKE_CURRENT_BINARY_DIR}/deps/src/yaml/include)
#set(YAML_LIB_DIR ${CMAKE_CURRENT_BINARY_DIR}/deps/src/yaml-build)
#
#file(MAKE_DIRECTORY ${YAML_INCLUDE_DIR})
#file(MAKE_DIRECTORY ${YAML_LIB_DIR})
#
#add_library(libyaml SHARED IMPORTED)
#add_dependencies(libyaml yaml)
#
#set_target_properties(libyaml PROPERTIES
#  IMPORTED_LOCATION ${YAML_LIB_DIR}/libyaml.so
#  INTERFACE_INCLUDE_DIRECTORIES ${YAML_INCLUDE_DIR})
########################################################

########################################################
# lxcodegen 
# writing yaml code generator in c++ is pita
# add_executable(lxcodegen tools/lxcodegen.cpp)
# add_dependencies(lxcodegen lifx_yaml_file)
# add_dependencies(lxcodegen libyaml)
# target_link_libraries(lxcodegen libyaml)
########################################################

########################################################
# liblifx
add_library(
  lifx
  SHARED
  src/lifx.c
  src/lifx_buffer.c
  src/lifx_encoders.c)
include_directories(lifx ${CMAKE_CURRENT_BINARY_DIR}/deps/src)
include_directories(lifx ${CMAKE_CURRENT_SOURCE_DIR}/include)
#add_dependencies(lifx generate_sources)
#add_dependencies(generate_sources lifx_yaml_file)
########################################################

add_executable(findbulbs examples/findbulbs.c)
add_dependencies(findbulbs lifx)
target_link_libraries(findbulbs lifx)