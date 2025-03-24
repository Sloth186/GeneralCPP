cmake_minimum_required(VERSION 3.30)
project(PigGamePart1)

set(CMAKE_CXX_STANDARD 20)

add_executable(PigGamePart1VsComp
        Die.cpp
        Die.h
        playervscomputer.cpp)

add_executable(PigGamePart1VsPlayer
        Die.cpp
        Die.h
        pvp.cpp)