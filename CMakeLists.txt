cmake_minimum_required(VERSION 3.15)
project(Ba2-labo03)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wconversion -Wall -Wextra -pedantic -std=c++11")

add_executable(Ba2-labo_03_basset_nils_lange_yanik_gallay_david.cpp src/date.cpp src/date.h)

# add_executable(testDiffDate tests/testDiffDate.cpp src/date.cpp src/date.h)
