//
// Created by dawen on 18/03/2020.
//

#include <c++/4.8.3/cstring>
#include <c++/4.8.3/iostream>
#include "Personne.h"
#include "Bateau.h"

//Constructeur par défaut
Personne::Personne() {
    _age=0;
    _prenom= nullptr;
    _nom= nullptr;
}

Personne::Personne(char *nomPersonne, char *prenomPersonne, int agePersonne) {
    int nomSize =strlen(nomPersonne);
    int prenomSize =strlen(prenomPersonne);
    if(nomSize<20){
        _nom = new char(nomSize+1);
        strcpy(_nom, nomPersonne);
    } else{
        _nom = new char(21);
        strncpy(_nom, nomPersonne, 20);
    }
    if(prenomSize<20){
        _prenom = new char(prenomSize+1);
        strcpy(_prenom, prenomPersonne);
    } else{
        _prenom = new char(21);
        strncpy(_prenom, prenomPersonne, 20);
    }
    _age=agePersonne;
}


Personne::~Personne() {
    _prenom= nullptr;
    _nom= nullptr;
    delete [] _prenom;
    delete [] _nom;
    std::cout <<"Personne détruite"<<std::endl;
}

void Personne::affiche() const {
    if(_prenom!= nullptr && _nom != nullptr){
        std::cout << "Personne s'appelle "  <<  _prenom << " " <<  _nom << " et il a " << _age << std::endl;
    }else{
        std::cout << "Personne s'appelle ERROR PAS DE NOM DEFINI" << " et il a " << _age << std::endl;
    }
}

char *Personne::getPrenom() const {
    return _prenom;
}

void Personne::setPrenom(char *prenom) {
    _prenom = prenom;
}

char *Personne::getNom() const {
    return _nom;
}

void Personne::setNom(char *nom) {
    _nom = nom;
}

int Personne::getAge() const {
    return _age;
}

void Personne::setAge(int age) {
    _age = age;
}

void Personne::addBateau(Bateau * bateau) {
    _listeBateaux.push_back(bateau);
}

void Personne::removeBateau(Bateau * bateau) {
    _listeBateaux.remove(bateau);
    delete(bateau);
}

const std::list<Bateau *> &Personne::getListeBateaux() const {
    return _listeBateaux;
}
