cmake_minimum_required(VERSION 3.15)
project(Code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(./Ressource/tinyxml2/)
add_executable(Code main.cpp Personne.cpp Personne.h Abonne.cpp Abonne.h Visiteur.cpp Visiteur.h GestionPort.cpp GestionPort.h
        ./Ressource/tinyxml2/tinyxml2.cpp ./Ressource/tinyxml2/tinyxml2.h Bateau.cpp Bateau.h
        Place.cpp Place.h)