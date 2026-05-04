cmake_minimum_required(VERSION 3.26)
project(BugsProjectCa)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(BugsProject
        main.cpp
        src/Bug.cpp
        src/Direction.cpp
        src/Crawler.cpp
        src/Hopper.cpp
        src/Teleporter.cpp
        src/Board.cpp
)