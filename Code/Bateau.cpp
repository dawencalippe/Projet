//
// Created by 33629 on 26/03/2020.
//
#include "Bateau.h"
#include <iostream>
#include <c++/4.8.3/cstring>

Bateau::Bateau() {
    _taille = 0;
    _nbCabines = 0;
    _currentPlace = 0;
}

Bateau::~Bateau() {}

Bateau::Bateau(int taille, int nbCabines, char * nom, Bateau::TYPEBATEAU typeBateau) {
    _taille=taille;
    _nbCabines=nbCabines;
    int sizeNom = strlen(nom);
    _nom = new char(sizeNom+1);
    strcpy(_nom, nom);
    _typeBateau=typeBateau;
}

Bateau::Bateau(int taille, int nbCabines, char * nom, Bateau::TYPEBATEAU typeBateau, int currentPlace) {
    _taille=taille;
    _nbCabines=nbCabines;
    int sizeNom = strlen(nom);
    _nom = new char(sizeNom+1);
    strcpy(_nom, nom);
    _typeBateau=typeBateau;
    _currentPlace=currentPlace;
}


int Bateau::getTaille() const {
    return _taille;
}

int Bateau::getNbCabines() const {
    return _nbCabines;
}

char * Bateau::getNom() const {
    return _nom;
}

int Bateau::getCurrentPlace() const {
    return _currentPlace;
}

void Bateau::setCurrentPlace(int currentPlace) {
    _currentPlace = currentPlace;
}

Bateau::TYPEBATEAU Bateau::getTypeBateau() const {
    return _typeBateau;
}

void Bateau::affiche() const{
    std::cout << "  Nom du Bateau : " << _nom <<", taille : " <<_taille <<", nombre de cabine : " << _nbCabines
    << ", place du bateau : " << _currentPlace << ", type de bateau :" <<ToString(_typeBateau) << std::endl;
}






