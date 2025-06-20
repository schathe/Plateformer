cmake_minimum_required(VERSION 3.28)
project(Platformer LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# SFML uniquement
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

# Fichiers source (tout sauf le main)
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp src/*.hpp)

# Ajout du main à la racine
set(MAIN_FILE ${CMAKE_SOURCE_DIR}/main.cpp)

add_executable(Platformer ${MAIN_FILE} ${SRC_FILES})
target_include_directories(Platformer PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(Platformer PRIVATE SFML::Graphics SFML::Window SFML::System)
