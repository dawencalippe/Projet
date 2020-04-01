//
// Created by 33629 on 26/03/2020.
//
#include "Bateau.h"


Bateau::Bateau() {
    _taille = 0;
    _nbCabines = 0;
    _currentPlace = 0;
}

Bateau::~Bateau() {}

Bateau::Bateau(int taille, int nbCabines, char *nom, Bateau::TYPEBATEAU typeBateau) {
    _taille=taille;
    _nbCabines=nbCabines;
    _nom = nom;
    _typeBateau=typeBateau;
}

int Bateau::getTaille() const {
    return _taille;
}

void Bateau::setTaille(int taille) {
    _taille = taille;
}

int Bateau::getNbCabines() const {
    return _nbCabines;
}

void Bateau::setNbCabines(int nbCabines) {
    _nbCabines = nbCabines;
}

char *Bateau::getNom() const {
    return _nom;
}

void Bateau::setNom(char *nom) {
    _nom = nom;
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

void Bateau::setTypeBateau(Bateau::TYPEBATEAU typeBateau) {
    _typeBateau = typeBateau;
}





