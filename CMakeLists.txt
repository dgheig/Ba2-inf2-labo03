cmake_minimum_required(VERSION 3.15)
project(Ba2-labo03)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wconversion -Wall -Wextra -pedantic -std=c++11")


file(MAKE_DIRECTORY builds)
# https://cmake.org/cmake/help/latest/variable/CMAKE_SOURCE_DIR.html#variable:CMAKE_SOURCE_DIR
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(
    labo_03_basset_nils_lange_yanik_gallay_david
    labo_03_basset_nils_lange_yanik_gallay_david.cpp
    src/utilities.cpp src/utilities.h
    src/rotor.cpp src/rotor.h
    src/enigma_machine.cpp src/enigma_machine.h
)

# add_executable(testDiffDate tests/testDiffDate.cpp src/date.cpp src/date.h)
