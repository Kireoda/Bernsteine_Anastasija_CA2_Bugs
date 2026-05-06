cmake_minimum_required(VERSION 3.26)
project(BugsProjectCa)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")

add_executable(BugsProject
        main.cpp
        src/Bug.cpp
        src/Direction.cpp
        src/Crawler.cpp
        src/Hopper.cpp
        src/Teleporter.cpp
        src/Board.cpp
)