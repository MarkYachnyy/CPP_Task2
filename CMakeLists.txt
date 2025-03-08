cmake_minimum_required(VERSION 3.30)
project(Task2)

set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(Task2 main.cpp
        classes/game/Snake.h
        classes/geometry/Point.h
        classes/game/Field.h
        classes/artifact/Artifact.h
        classes/artifact/Bomb.h
        classes/artifact/Slower.h
        classes/artifact/Invisible.h
        classes/game/Field.cpp
        classes/game/Snake.cpp
        classes/geometry/Utils.cpp
        classes/geometry/Direction.h
        classes/geometry/Point.cpp
        classes/game/Game.cpp
        classes/game/Game.h
        classes/player/SimpleSurvivorBot.cpp
        classes/player/SimpleSurvivorBot.h
        classes/player/Player.cpp)
