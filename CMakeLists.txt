cmake_minimum_required(VERSION 3.30)
project(Task2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Task2 main.cpp
        classes/Snake.h
        classes/Point.h
        classes/Field.h
        classes/artifact/Artifact.h
        classes/artifact/Bomb.h
        classes/artifact/Slower.h
        classes/artifact/Invisible.h
        classes/Field.cpp
        classes/Snake.cpp
        classes/Utils.cpp
        classes/Direction.h)
