cmake_minimum_required(VERSION 3.6)
project(Voxel)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Cam.cpp
        Cam.h
        Game.cpp
        Game.h
        Main.cpp
        NoiseGen.cpp
        NoiseGen.h
        Shapes.cpp
        Shapes.h
        Terrain.cpp
        Terrain.h
        Vector.cpp
        Vector.h)

add_executable(Voxel ${SOURCE_FILES})

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(GLEW REQUIRED glew)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${GLEW_LIBRARIES})


