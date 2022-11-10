cmake_minimum_required(VERSION 2.8.3)

PROJECT(server_http)

add_compile_options(-std=c++11)



add_executable(server server.cpp httplib.cpp)
target_link_libraries(server -pthread)

