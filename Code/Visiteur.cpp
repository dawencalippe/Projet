//
// Created by dawen on 18/03/2020.
//

#include <c++/4.8.3/ctime>
#include "Visiteur.h"
#include <iostream>
#include <c++/4.8.3/cstring>

int Visiteur::current_id=0;

Visiteur::Visiteur(char *nomPersonne, char *prenomPersonne, int agePersonne, int idVisiteur, std::string dateArrivee)
:Personne(nomPersonne, prenomPersonne, agePersonne),
_idVisiteur(idVisiteur), _dateArrivee(dateArrivee) {}

Visiteur::Visiteur() {
    _idVisiteur=current_id;
    time_t now = time(0);
    char * dateActuelle = ctime(&now);
    std::string temp(dateActuelle);
    _dateArrivee = temp;
    current_id++;
}

Visiteur::Visiteur(char *nomPersonne, char *prenomPersonne, int agePersonne)
:Personne(nomPersonne, prenomPersonne, agePersonne){
    _idVisiteur = current_id;
    time_t now = time(0);
    _dateArrivee = ctime(&now);
    current_id++;
}


Visiteur::~Visiteur() {
    std::cout <<"Visiteur détruit"<< std::endl;
}

void Visiteur::affiche() const {
    if(_prenom!= nullptr && _nom != nullptr){
        std::cout << "Visiteur " <<_idVisiteur <<" s'appelle "  <<  _prenom << " " <<  _nom << " et il a " << _age
                  << " et il est arrivé depuis le " << _dateArrivee<< "avec les bateaux suivants :" <<std::endl;
        for(auto &it : _listeBateaux){
            it->affiche();
        }

    }else{
        std::cout << "Personne s'appelle ERROR PAS DE NOM DEFINI" << " et il a " << _age << std::endl;
    }
}

int Visiteur::getIdVisiteur() const {
    return _idVisiteur;
}

std::string Visiteur::getDateArrivee() const {
    return _dateArrivee;
}


