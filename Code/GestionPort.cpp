//
// Created by dawen on 18/03/2020.
//

#include <iostream>
#include "GestionPort.h"
#include "Personne.h"
#include "Abonne.h"
#include "Place.h"
#include "Visiteur.h"
#include "Ressource/tinyxml2/tinyxml2.h"

using namespace std;
using namespace tinyxml2;

GestionPort::GestionPort() = default;

GestionPort::~GestionPort() {
}

const list<Abonne *> &GestionPort::getListeAbonne() const {
    return _listeAbonne;
}

const list<Visiteur *> &GestionPort::getListeVisiteur() const {
    return _listeVisiteur;
}

const list<Place *> &GestionPort::getListePlace() const {
    return _listePlace;
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

void GestionPort::afficherPlaceDispo() {
    cout <<"Liste des places disponibles :"<<endl;
    for(auto &it : _listePlace){
        if(!it->isPrise()){
            it->affichePlace();
        } else {
            cout << "aucune place dispo"<<endl;
        }
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

void GestionPort::addPlace(Place * place) {
    _listePlace.push_back(place);
}

void GestionPort::removePlace(Place *place) {
    _listePlace.remove(place);
    delete(place);
}

void GestionPort::sauvegarde() {
    tinyxml2::XMLDocument document;
    document.InsertFirstChild(document.NewDeclaration());
    XMLNode * root = document.NewElement("App");
    document.InsertEndChild( root);
    sauvegardePersonne(&document, dynamic_cast<XMLElement *>(root));
    sauvegardePlace(&document, dynamic_cast<XMLElement *>(root));
    document.SaveFile("../Ressource/sauvegarde.xml");
}

void GestionPort::sauvegardePersonne(tinyxml2::XMLDocument * document, tinyxml2::XMLElement * root) {
    XMLElement * abonne = document->NewElement("ListeAbonnes");
    abonne->SetAttribute("currentID",Abonne::current_id);
    root->InsertEndChild(abonne);
    for(auto &it : _listeAbonne){
        XMLElement * abonneAdd = document->NewElement("abonne");
        abonneAdd->SetAttribute("prenom",it->getPrenom());
        abonneAdd->SetAttribute("nom",it->getNom());
        abonneAdd->SetAttribute("age",it->getAge());
        abonneAdd->SetAttribute("idAbonne",it->getIdAbonne());
        abonneAdd->SetAttribute("dateAbonnement",it->getDateAbonnement().c_str());
        abonne->InsertEndChild(abonneAdd);
        for(auto &bateaux : it->getListeBateaux()){
            XMLElement * bateauAdd = document->NewElement("Bateau");
            bateauAdd->SetAttribute("nom",bateaux->getNom());
            bateauAdd->SetAttribute("taille", bateaux->getTaille());
            bateauAdd->SetAttribute("nombreCabine", bateaux->getNbCabines());
            bateauAdd->SetAttribute("typeBateau", bateaux->getTypeBateau());
            bateauAdd->SetAttribute("currentPlace", bateaux->getCurrentPlace());
            abonneAdd->InsertEndChild(bateauAdd);
        }
    }
    XMLElement * visiteur = document->NewElement("ListeVisiteurs");
    visiteur->SetAttribute("currentID",Visiteur::current_id);
    root->InsertEndChild(visiteur);
    for(auto &it : _listeVisiteur){
        XMLElement * visiteurAdd = document->NewElement("visiteur");
        visiteurAdd->SetAttribute("prenom",it->getPrenom());
        visiteurAdd->SetAttribute("nom",it->getNom());
        visiteurAdd->SetAttribute("age",it->getAge());
        visiteurAdd->SetAttribute("idVisiteur",it->getIdVisiteur());
        visiteurAdd->SetAttribute("dateArrivee",it->getDateArrivee().c_str());
        visiteur->InsertEndChild(visiteurAdd);
        for(auto &bateaux : it->getListeBateaux()){
            XMLElement * bateauAdd = document->NewElement("Bateau");
            bateauAdd->SetAttribute("nom", bateaux->getNom());
            bateauAdd->SetAttribute("taille", bateaux->getTaille());
            bateauAdd->SetAttribute("nombreCabine", bateaux->getNbCabines());
            bateauAdd->SetAttribute("typeBateau", bateaux->getTypeBateau());
            bateauAdd->SetAttribute("currentPlace", bateaux->getCurrentPlace());
            visiteurAdd->InsertEndChild(bateauAdd);
        }
    }
}

void GestionPort::sauvegardePlace(tinyxml2::XMLDocument *document, tinyxml2::XMLElement *root) {
    XMLElement * place = document->NewElement("ListePlaces");
    place->SetAttribute("currentID",Place::current_id);
    root->InsertFirstChild(place);
    for(auto &it : _listePlace){
        XMLElement * placeAdd = document->NewElement("place");
        placeAdd->SetAttribute("idPlace", it->getIdPlace());
        placeAdd->SetAttribute("tailleMax", it->getTailleMax());
        placeAdd->SetAttribute("typePlace", it->getTypePlace());
        placeAdd->SetAttribute("prise", it->isPrise());
        placeAdd->SetAttribute("suppElec", it->isSuplemmentElectricite());
        placeAdd->SetAttribute("suppEau", it->isSuplementEau());
        place->InsertEndChild(placeAdd);
    }
}

void GestionPort::import() {
    tinyxml2::XMLDocument document;
    tinyxml2::XMLError error = document.LoadFile("../Ressource/sauvegarde.xml");
    if(error == XML_SUCCESS){
        importPlace(&document);
        importPersonne(&document);
    }else{
        cout<<"Erreur lors de l'ouverture du fichier : "<< tinyxml2::XMLDocument::ErrorIDToName(error) <<endl;
    }
}

void GestionPort::importPersonne(tinyxml2::XMLDocument * document){
    XMLHandle docHandle (document);
    XMLElement * currentID = docHandle.LastChild().FirstChildElement("ListeAbonnes").ToElement();
    currentID->QueryIntAttribute("currentID", &Abonne::current_id);
    XMLElement * abonne = docHandle.LastChild().FirstChildElement("ListeAbonnes")
            .FirstChild().ToElement();
    while(abonne){
        char * nom;
        char *prenom;
        char * dateAbonnement;
        int age, idAbonnement;
        nom = const_cast<char *>(abonne->Attribute("nom"));
        prenom = const_cast<char *>(abonne->Attribute("prenom"));
        dateAbonnement = const_cast<char *>(abonne->Attribute("dateAbonnement"));
        abonne->QueryIntAttribute("age",&age);
        abonne->QueryIntAttribute("idAbonne",&idAbonnement);
        Abonne * abonneAdd = new Abonne(idAbonnement,nom,prenom ,age , dateAbonnement);
        importBateaux(abonne, abonneAdd);
        _listeAbonne.push_back(abonneAdd);
        abonne = abonne->NextSiblingElement();
    }
    XMLElement  * currentIDVisiteur = docHandle.LastChild().LastChildElement("ListeVisiteurs").ToElement();
    currentIDVisiteur->QueryIntAttribute("currentID", &Visiteur::current_id);
    XMLElement * visiteur = docHandle.LastChild().FirstChildElement("ListeVisiteurs")
            .FirstChild().ToElement();
    while(visiteur){
        char * nom;
        char *prenom;
        char * dateArrivee;
        int age, idVisiteur;
        nom = const_cast<char *>(visiteur->Attribute("nom"));
        prenom = const_cast<char *>(visiteur->Attribute("prenom"));
        dateArrivee = const_cast<char *>(visiteur->Attribute("dateArrivee"));
        visiteur->QueryIntAttribute("age",&age);
        visiteur->QueryIntAttribute("idVisiteur",&idVisiteur);
        Visiteur * visiteurAdd = new Visiteur(nom, prenom, age, idVisiteur, dateArrivee);
        importBateaux(visiteur, visiteurAdd);
        _listeVisiteur.push_back(visiteurAdd);
        visiteur = visiteur->NextSiblingElement();
    }
}

void GestionPort::importPlace(tinyxml2::XMLDocument *document) {
    XMLHandle docHandle (document);
    XMLElement * currentID = docHandle.LastChild().FirstChildElement("ListePlaces").ToElement();
    currentID->QueryIntAttribute("currentID", &Place::current_id);
    XMLElement * place = docHandle.LastChild().FirstChildElement("ListePlaces")
            .FirstChild().ToElement();
    while(place){
        Place::TYPEPLACE typeplace;
        float tailleMax;
        int idPlace, type;
        bool prise, suplemmentElec, suplemmentEau;
        place->QueryIntAttribute("idPlace", &idPlace);
        place->QueryFloatAttribute("tailleMax", &tailleMax);
        place->QueryIntAttribute("typePlace", &type);
        typeplace = Place::ToType(type);
        place->QueryBoolAttribute("prise", &prise);
        place->QueryBoolAttribute("suppElec", &suplemmentElec);
        place->QueryBoolAttribute("suppEau", &suplemmentEau);
        Place * placeAdd = new Place(idPlace, tailleMax, typeplace, prise, suplemmentElec, suplemmentEau);
        _listePlace.push_back(placeAdd);
        place = place->NextSiblingElement();
    }
}

void GestionPort::importBateaux(tinyxml2::XMLElement *root, Personne *personne) {
    XMLElement * bateau = root->FirstChild()->ToElement();
    while(bateau){
        char * nom;
        int taille, nbCabine, currentPlace, type;
        Bateau::TYPEBATEAU typeBateau;
        nom = const_cast<char *>(bateau->Attribute("nom"));
        bateau->QueryIntAttribute("taille", &taille);
        bateau->QueryIntAttribute("nombreCabine", &nbCabine);
        bateau->QueryIntAttribute("typeBateau", &type);
        bateau->QueryIntAttribute("currentPlace", &currentPlace);
        Bateau * bateauAdd = new Bateau(taille, nbCabine, nom, Bateau::ToType(type), currentPlace);
        personne->addBateau(bateauAdd);
        bateau = bateau->NextSiblingElement();
    }
}

Place *GestionPort::getPlace(int idPlace) {
    Place * place;
    bool trouve = false;
    _List_const_iterator<Place *> iterator = _listePlace.begin();
    while(iterator!= _listePlace.end() && !trouve){
        if((*iterator)->getIdPlace()==idPlace){
            place = (* iterator);
            trouve = true;
        }else{
            iterator++;
        }
    }
    if(!trouve){
        cout<<"Numéro de la place invalide"<<endl;
    }
    return place;
}























