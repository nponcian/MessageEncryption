file(GLOB cipher_src_common_cpp
    "*.cpp")

add_library(cipher_src_common ${cipher_src_common_cpp})

add_library(cipher_src_common_FOR_TESTING ${cipher_src_common_cpp})
target_compile_definitions(cipher_src_common_FOR_TESTING PUBLIC DONT_PRINT_TO_SCREEN)
