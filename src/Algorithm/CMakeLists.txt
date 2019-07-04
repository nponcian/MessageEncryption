file(GLOB cipher_src_algorithm_cpp
    "*.cpp")

add_library(cipher_src_algorithm ${cipher_src_algorithm_cpp})

add_library(cipher_src_algorithm_FOR_TESTING ${cipher_src_algorithm_cpp})
target_compile_definitions(cipher_src_algorithm_FOR_TESTING PUBLIC DONT_PRINT_TO_SCREEN)
