//
// Created by 33629 on 26/03/2020.
//

#include "VoilierNonHabitable.h"
#include <iostream>
using namespace std;

VoilierNonHabitable::~VoilierNonHabitable() {
}

VoilierNonHabitable::VoilierNonHabitable(float taille, int nbCabines) {
    if (taille < 10){
        this->taille = taille;
    } else {
        cout <<"Ce bateau n'est pas un Voilier non habitable si la taille est superieur a 10m."<<endl;
    }
    if (nbCabines == 0){
        this->nbCabines = nbCabines;
    } else {
        cout << "Ce bateau n'est pas un voilier non habitable si le nombre de cabines est superieur a 0."<<endl;
    }
}

