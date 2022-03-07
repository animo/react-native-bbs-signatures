cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 11)

project(bbs_test)

include_directories(..)

file(GLOB LIBRARIES ./libs/*.dylib)

file(GLOB SOURCES ../keys/* ../bbs-signatures.* ../Logging.h ./src/bbs_test.cpp)

add_executable(bbs_test ${SOURCES})
target_link_libraries(bbs_test ${LIBRARIES})
