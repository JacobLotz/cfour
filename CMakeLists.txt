cmake_minimum_required(VERSION 2.8.12)
project(cfour LANGUAGES CXX)

# Prohibit in-source builds
if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "In-source builds are prohibited.")
endif ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")

# Default options match the Makefile
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()


#
# Setup the library target
#
add_subdirectory(src)


# Setup the executable
add_executable(cfour-exe src/cfour.cpp)
set_target_properties(cfour-exe PROPERTIES OUTPUT_NAME cfour)
target_link_libraries(cfour-exe cfour ${CMAKE_DL_LIBS})

# Install the executable
#install(TARGETS cfour-exe RUNTIME DESTINATION bin)

