//
// Created by dawen on 12/04/2020.
//

#include <c++/4.8.3/ctime>
#include "Facture.h"
#include "Abonne.h"

Facture::Facture(Personne *personne, Bateau * bateau,Place * place, int nbJour):_place(place),_personne(personne),_bateau(bateau),_nbJour(nbJour) {
    time_t now = time(0);
    char * dateActuelle = ctime(&now);
    std::string temp(dateActuelle);
    _dateFacturation = temp;
}

void Facture::calculFacture(int reduction) {
    int somme =  0;
    if(dynamic_cast<Abonne *>(_personne))   {
        somme = calculAbonne();
    } else{
        somme = calculVisiteur();
    }
    _montant=somme;
}

int Facture::calculAbonne() {
    int somme;
    switch (_bateau->getTypeBateau()){
        case Bateau::TYPEBATEAU ::VOILIER_NH :
            somme = 500;
            break;
        case Bateau::TYPEBATEAU ::VOILIER_1:
            std::cout<<"PASSE"<<std::endl;
            somme=500 + (500*0.3);
            break;
        case Bateau::TYPEBATEAU ::VOILIER_2:
            somme=500+(500*0.6);
            break;
    }
    if(_place->isSuplemmentElectricite()){
        somme = somme + 5*365;
    }
    if(_place->isSuplementEau()){
        somme=somme+5*365;
    }
    if(_place->getTypePlace()==Place::TYPEPLACE::CORPSMORT){
        somme = somme *0.5;
    }
    return somme;
}

int Facture::calculVisiteur() {
    int somme;
    switch (_bateau->getTypeBateau()){
        case Bateau::TYPEBATEAU ::VOILIER_NH :
            somme = 20*_nbJour;
            break;
        case Bateau::TYPEBATEAU ::VOILIER_1:
            somme=20*_nbJour;
            somme = somme + (somme*0.3);
            break;
        case Bateau::TYPEBATEAU ::VOILIER_2:
            somme=20*_nbJour;
            somme = somme + (somme*0.6);
            break;
    }
    if(_place->isSuplemmentElectricite()){
        somme = somme + 5*_nbJour;
    }
    if(_place->isSuplementEau()){
        somme=somme+5*_nbJour;
    }
    if(_place->getTypePlace()==Place::TYPEPLACE::CORPSMORT){
        somme = somme *0.5;
    }
    return somme;
}

Personne *Facture::getPersonne() const {
    return _personne;
}

void Facture::setPersonne(Personne *personne) {
    _personne = personne;
}

Bateau *Facture::getBateau() const {
    return _bateau;
}

void Facture::setBateau(Bateau *bateau) {
    _bateau = bateau;
}

Place *Facture::getPlace() const {
    return _place;
}

void Facture::setPlace(Place *place) {
    _place = place;
}

int Facture::getMontant() const {
    return _montant;
}

void Facture::setMontant(int montant) {
    _montant = montant;
}

int Facture::getNbJour() const {
    return _nbJour;
}

void Facture::setNbJour(int nbJour) {
    _nbJour = nbJour;
}

const std::string &Facture::getDateFacturation() const {
    return _dateFacturation;
}

void Facture::setDateFacturation(const std::string &dateFacturation) {
    _dateFacturation = dateFacturation;
}

bool Facture::isPaye() const {
    return _paye;
}

void Facture::setPaye(bool paye) {
    _paye = paye;
}

void Facture::affichefacture() {
    std::cout<<"La facture concerne monsieur : " << _personne->getNom()<<std::endl;
    std::cout<<"La facture concerne le bateau : " << _bateau->getNom()<<std::endl;
    std::cout<<"La facture a pour montant : " << _montant<<std::endl;
    std::cout<<"La facture est réglé  : " << _paye<<std::endl;
    std::cout<<"Date de facturation  : " <<_dateFacturation<<std::endl;
}
