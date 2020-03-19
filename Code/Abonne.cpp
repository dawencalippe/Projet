//
// Created by dawen on 18/03/2020.
//

#include "Abonne.h"
#include <iostream>
#include <ctime>

int Abonne::current_id=0;

Abonne::Abonne():Personne() {
    _idAbonne =current_id;
    time_t now = time(0);
    _dateAbonnement = ctime(&now);
    current_id++;
}

Abonne::Abonne(char* nomPersonne, char* prenomPersonne, int agePersonne)
: Personne(nomPersonne, prenomPersonne, agePersonne)
{
    _idAbonne=current_id;
    time_t now = time(0);
    _dateAbonnement = ctime(&now);
    current_id++;
}

Abonne::~Abonne(){
    _dateAbonnement= nullptr;
    delete [] _dateAbonnement;
    std::cout << "Abonné détruit" << std::endl;
}

void Abonne::affiche() const {
    if(_prenom!= nullptr && _nom != nullptr){
        std::cout << "Abonne " <<_idAbonne <<" s'appelle "  <<  _prenom << " " <<  _nom << " et il a " << _age
        << " et il est inscrit depuis le " << _dateAbonnement << std::endl;
    }else{
        std::cout << "Personne s'appelle ERROR PAS DE NOM DEFINI" << " et il a " << _age << std::endl;
    }
}




