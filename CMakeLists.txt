cmake_minimum_required(VERSION 3.1)

set (CMAKE_CXX_STANDARD 11)

project(embedded-bdi)

include_directories(lib/bdi lib/lib lib/syntax)

file(GLOB COMMON_SOURCES "lib/bdi/*.cpp" "lib/lib/*.cpp" "lib/syntax/*.cpp")
file(GLOB TARGET_SOURCES "src/*.cpp")

add_executable(agent_loop ${COMMON_SOURCES} ${TARGET_SOURCES})