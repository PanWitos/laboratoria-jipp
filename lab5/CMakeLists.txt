cmake_minimum_required(VERSION 3.0.0)

project(lab5 VERSION 0.1.0)

include_directories( ./include ./src )

add_executable(main ./src/main.cpp  ./src/macierze.cpp)