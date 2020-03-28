cmake_minimum_required(VERSION 3.15)
project(Code)

set(CMAKE_CXX_STANDARD 14)

add_executable(Code main.cpp Personne.cpp Personne.h Abonne.cpp Abonne.h Visiteur.cpp Visiteur.h
        GestionPort.cpp GestionPort.h
        Bateau.cpp Bateau.h VoilierNonHabitable.cpp VoilierNonHabitable.h VoilierT1.cpp VoilierT1.h VoilierT2.cpp VoilierT2.h
        Place.cpp Place.h PlaceNormale.cpp PlaceNormale.h GrandePlace.cpp GrandePlace.h CorpsMort.cpp CorpsMort.h)