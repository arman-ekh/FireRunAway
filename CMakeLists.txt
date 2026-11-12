
cmake_minimum_required(VERSION 3.10.0)

project(FireRunAway VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(FireRunAway
    src/main.cpp
    src/enviroment/Cell.h
    src/enviroment/Cell.cpp
    src/enviroment/Floor.h
    src/enviroment/Floor.cpp
    src/enviroment/Building.h
    src/enviroment/Building.cpp
    src/visualization/renderer.h
    src/visualization/renderer.cpp
)

target_include_directories(FireRunAway PRIVATE
    /usr/local/include
)

target_link_directories(FireRunAway PRIVATE
    /usr/local/lib
)

target_link_libraries(FireRunAway PRIVATE
    raylib
    m
    pthread
    dl
    GL
    X11
)
