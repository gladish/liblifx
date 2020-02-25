#cmake_minimum_required(VERSION 3.4)
cmake_minimum_required(VERSION 2.8)

if (CMAKE_VERSION VERSION_LESS "3.0")
  project(lifxlifx C)
  set(PROJECT_VERSION 0.0.1)
else ()
  cmake_policy(SET CMP0048 NEW)
  project(liblifx VERSION 0.0.01)
endif()

include(ExternalProject)
find_package(Threads)
set(CMAKE_C_FLAGS_DEBUG "-Wall -Wextra -g -O0 -fno-inline -Wno-unused-parameter")
set(CMAKE_C_FLAGS_RELEASE "-Werror -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -g -O0 -fno-inline") # -Weffc++ ")
set(CMAKE_CXX_FLAGS_RELEASE "-Werror -Wall -Wextra") # -Weffc++")
enable_testing()

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  set(MACOSX TRUE)
  add_definitions(-DLIFX_PLATFORM_MACOSX)
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  set(LINUX TRUE)
  add_definitions(-DLIFX_PLATFORM_LINUX)
endif()

if (ENABLE_TIDY)
  set(CMAKE_C_CLANG_TIDY
  clang-tidy;
  -checks=*,-google-readability-braces-around-statements,-hicpp-braces-around-statements,-readability-braces-around-statements;
  -header-filter=.;)
endif()

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
set(lifx_SOURCES)
list(APPEND lifx_SOURCES src/lifx.c)
list(APPEND lifx_SOURCES src/lifx_buffer.c)
list(APPEND lifx_SOURCES src/lifx_encoders.c)
list(APPEND lifx_SOURCES src/lifx_log.c)
list(APPEND lifx_SOURCES src/lifx_requests.c)
list(APPEND lifx_SOURCES src/lifx_session.c)
if ((LINUX) OR (MACOSX))
list(APPEND lifx_SOURCES src/lifx_platform_posix.c)
endif()
# liblifx
add_library(
  lifx
  SHARED
  ${lifx_SOURCES})
configure_file("include/lifx_version.h.in" "${CMAKE_CURRENT_SOURCE_DIR}/include/lifx_version.h")
include_directories(lifx ${CMAKE_CURRENT_BINARY_DIR}/deps/src)
include_directories(lifx ${CMAKE_CURRENT_SOURCE_DIR}/include)
if (LINUX)
  target_link_libraries(lifx ${CMAKE_THREAD_LIBS_INIT} rt)
else()
  target_link_libraries(lifx ${CMAKE_THREAD_LIBS_INIT})
endif()
#add_dependencies(lifx generate_sources)
#add_dependencies(generate_sources lifx_yaml_file)
########################################################

add_executable(findbulbs examples/findbulbs.c)
add_dependencies(findbulbs lifx)
target_link_libraries(findbulbs lifx)

add_executable(sendreq examples/sendreq.c)
add_dependencies(sendreq lifx)
target_link_libraries(sendreq lifx)

add_executable(async examples/async.c)
add_dependencies(async lifx)
target_link_libraries(async lifx)

if (ENABLE_UNIT_TESTS)
  add_subdirectory(tests)
endif()
