cmake_minimum_required(VERSION 3.10.2)
project(cipher)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-g -Wall -Wextra -Werror -pedantic)

add_subdirectory(src)
add_subdirectory(test)
