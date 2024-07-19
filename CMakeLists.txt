cmake_minimum_required(VERSION 3.10)
project(AstroidShooter)

set(CMAKE_CXX_STANDARD 17)

# Path to SFML
set(SFML_DIR "${PROJECT_SOURCE_DIR}/thirdparty/SFML-2.6.0/lib/cmake/SFML")

find_package(SFML 2.6 COMPONENTS system window graphics network audio REQUIRED)


set(SOURCES
    src/main.cpp
    src/Animation.cpp
    src/player.cpp
    src/astroids.cpp
    src/healing.cpp
)

add_executable(AstroidShooter ${SOURCES})

target_link_libraries(AstroidShooter sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

target_link_libraries(AstroidShooter sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
