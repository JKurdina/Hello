cmake_minimum_required(VERSION 2.8)
project(hello)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(http_server http_server.cpp)
add_executable(calculator calculator.cpp)
target_link_libraries(http_server Boost::boost)
target_link_libraries(http_server Boost::boost pthread)

