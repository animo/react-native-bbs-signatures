cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)

project(bbs_test)

include_directories(.. ../keys)

file(GLOB LIBRARIES ./libs/*.so)

file(GLOB SOURCES ../keys/* ../bbsSignatures.* ../../Logging.h ./src/bbsTest.cpp)

add_executable(bbs_test ${SOURCES})
target_link_libraries(bbs_test ${LIBRARIES})
