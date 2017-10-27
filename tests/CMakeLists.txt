
cmake_minimum_required (VERSION 2.8)

#----------------------------------------
#        project name

project(decrypt)

include_directories("../src")
include_directories("${PROJECT_BINARY_DIR}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -static-libgcc -static-libstdc++")

set ( SRC_FILES
    ../src/decrypt.hpp
    ../src/base_decrypter.hpp
    ../src/caesar.hpp
    ../src/affine.hpp
    ../src/vigenere_txt.hpp
)

add_executable( example1 example1.cpp ${SRC_FILES})
add_executable( example2 example2.cpp ${SRC_FILES})
add_executable( example3 example3.cpp ${SRC_FILES})
add_executable( example4 example4.cpp ${SRC_FILES})
