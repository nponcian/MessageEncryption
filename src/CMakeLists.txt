cmake_minimum_required(VERSION 3.10.2)
project(cipher_src)

include_directories(.)

add_subdirectory(Common)

add_subdirectory(Algorithm)
add_subdirectory(File)

file(GLOB cipher_src_cpp
    "*.cpp")

add_executable(cipher_src ${cipher_src_cpp})

target_link_libraries(cipher_src cipher_src_common)
target_link_libraries(cipher_src cipher_src_algorithm)
target_link_libraries(cipher_src cipher_src_file)
