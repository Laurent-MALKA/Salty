cmake_minimum_required(VERSION 3.8)
project(Salty)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${project_SOURCE_DIR}/cmake")

set(SOURCE_FILES main.cpp Espion.cpp Espion.hpp Rect.cpp Rect.hpp Jeu.cpp Jeu.hpp Joueur.cpp Joueur.hpp IA.cpp IA.hpp Input.cpp Input.hpp Image.cpp Image.hpp Moteur.cpp Moteur.hpp Affichage.cpp Affichage.hpp Direction.cpp Direction.hpp params.hpp Clavier.cpp Clavier.hpp)

set(CMAKE_CXX_FLAGS "-lSDL2")

add_executable(Salty ${SOURCE_FILES})
target_link_libraries(Salty ${SDL2_LIBRARY})