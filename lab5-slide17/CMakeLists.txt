cmake_minimum_required(VERSION 3.24)
project(lab5_slide17)

set(CMAKE_CXX_STANDARD 14)

include_directories(lab5-slide17)

add_executable(lab5_slide17
        lab5-slide17/Animal.cpp
        lab5-slide17/Animal.h
        lab5-slide17/Cat.cpp
        lab5-slide17/Cat.h
        lab5-slide17/CMakeLists.txt
        lab5-slide17/Dog.cpp
        lab5-slide17/Dog.h
        lab5-slide17/main.cpp)
