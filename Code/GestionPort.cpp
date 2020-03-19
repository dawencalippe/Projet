//
// Created by dawen on 18/03/2020.
//

#include <iostream>
#include "GestionPort.h"
#include "visiteur.h"

using namespace std;

GestionPort::GestionPort() = default;

GestionPort::~GestionPort() {
    cout << "GestionPort détruit" << endl;
}

const list<Abonne *> &GestionPort::getListeAbonne() const {
    return _listeAbonne;
}

void GestionPort::setListeAbonne(const list<Abonne *> &listeAbonne) {
    _listeAbonne = listeAbonne;
}

const list<Visiteur *> &GestionPort::getListeVisiteur() const {
    return _listeVisiteur;
}

void GestionPort::setListeVisiteur(const list<Visiteur *> &listeVisiteur) {
    _listeVisiteur = listeVisiteur;
}

void GestionPort::addVisiteur(Visiteur *visiteur) {
    _listeVisiteur.push_back(visiteur);
}

void GestionPort::afficheVisiteur() {
    cout<<"Liste des visiteurs :"<<endl;
    for(auto &it : _listeVisiteur){
        it->affiche();
    }
}

void GestionPort::afficheAbonne() {
    cout<<"Liste des abonnes :"<<endl;
    for(auto &it : _listeAbonne){
        it->affiche();
    }
}

void GestionPort::removeVisiteur(Visiteur * visiteur) {
    _listeVisiteur.remove(visiteur);
    delete(visiteur);
}

void GestionPort::addAbonne(Abonne *abonne) {
    _listeAbonne.push_back(abonne);
}

void GestionPort::removeAbonne(Abonne *abonne) {
    _listeAbonne.remove(abonne);
    delete(abonne);
}





