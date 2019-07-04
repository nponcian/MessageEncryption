file(GLOB cipher_test_algorithm_cpp
    "*.cpp")

set(parent_cipher_test_algorithm_cpp
    "${parent_cipher_test_algorithm_cpp}"
    "${cipher_test_algorithm_cpp}"
    PARENT_SCOPE)
