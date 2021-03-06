include(ExternalProject)
include(GoogleTest)

find_package(Threads)

ExternalProject_Add(
  gtest
  URL https://github.com/google/googletest/archive/master.zip
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
  INSTALL_COMMAND "")

ExternalProject_Get_Property(gtest source_dir binary_dir)

add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest gtest)
set_target_properties(libgtest PROPERTIES
  "IMPORTED_LOCATION" "${binary_dir}/lib/libgtest.a"
  "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}")

add_library(libgmock IMPORTED STATIC GLOBAL)
add_dependencies(libgmock gtest)
set_target_properties(libgmock PROPERTIES
  "IMPORTED_LOCATION" "${binary_dir}/lib/libgmock.a"
  "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}")

include_directories("${source_dir}/googletest/include" "${source_dir}/googlemock/include")

# someone needs to figure out how to run this stuff under valgrind
add_custom_target(test_memcheck
  COMMAND "${CMAKE_CTEST_COMMAND} --force-new-ctest-process --test-action memcheck"
  COMMAND cat "${CMAKE_BINARY_DIR}/Testing/Temporary/MemoryChecker.*.log")

# testGroup.lifxBuffer
add_executable(testGroup.lifxBuffer lifxBufferTests.cpp main.cpp)
add_executable(testGroup.lifxDeviceId lifxDeviceIdTests.cpp main.cpp)
target_link_libraries(testGroup.lifxBuffer libgtest libgmock lifx ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(testGroup.lifxDeviceId libgtest libgmock lifx ${CMAKE_THREAD_LIBS_INIT})

gtest_discover_tests(testGroup.lifxBuffer)
gtest_discover_tests(testGroup.lifxDeviceId)


