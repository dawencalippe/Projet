//
// Created by dawen on 18/03/2020.
//

#include "Abonne.h"
#include <iostream>
#include <ctime>
#include <c++/4.8.3/cstring>

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
    char * dateActuelle = ctime(&now);
    std::string temp(dateActuelle);
    _dateAbonnement = temp;
    current_id++;
}

Abonne::~Abonne(){
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

int Abonne::getIdAbonne() const {
    return _idAbonne;
}

void Abonne::setIdAbonne(int idAbonne) {
    _idAbonne = idAbonne;
}

std::string Abonne::getDateAbonnement() const {
    return _dateAbonnement;
}

void Abonne::setDateAbonnement(std::string dateAbonnement) {
    _dateAbonnement = dateAbonnement;
}

Abonne::Abonne(int idAbonne, char *nomPersonne, char *prenomPersonne, int agePersonne, std::string dateAbonnement)
: Personne(nomPersonne, prenomPersonne, agePersonne){
    _idAbonne=idAbonne;
    _dateAbonnement=dateAbonnement;
}






