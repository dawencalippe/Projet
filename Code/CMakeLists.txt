cmake_minimum_required(VERSION 3.15)
project(Code)

set(CMAKE_CXX_STANDARD 14)

add_executable(Code main.cpp Personne.cpp Personne.h Abonne.cpp Abonne.h Visiteur.cpp Visiteur.h GestionPort.cpp GestionPort.h)