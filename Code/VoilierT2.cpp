//
// Created by 33629 on 27/03/2020.
//

#include "VoilierT2.h"
#include <iostream>
using namespace std;

VoilierT2::~VoilierT2() {

}

VoilierT2::VoilierT2(float taille, int nbCabines) {
    if(taille>25){
        this->taille=taille;
    } else {
        cout << "Ce bateau n'est pas un Voilier de type2 si la taille est inférieur a 25m."<<endl;
    }
    if(nbCabines>=1){
        this->nbCabines = nbCabines;
    } else {
        cout << "Ce bateau n'est pas un Voilier de type2 si le nombre des cabine est inferieur a 1."<<endl;
    }
}
