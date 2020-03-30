//
// Created by dawen on 18/03/2020.
//

#include <iostream>
#include <msxml.h>
#include "GestionPort.h"
#include "Personne.h"
#include "Abonne.h"
#include "Ressource/tinyxml2/tinyxml2.h"

using namespace std;
using namespace tinyxml2;

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

void GestionPort::sauvegarde() {
    tinyxml2::XMLDocument document;
    document.InsertFirstChild(document.NewDeclaration());
    XMLNode * root = document.NewElement("App");
    document.InsertEndChild( root);
    sauvegardePersonne(&document, dynamic_cast<XMLElement *>(root));
    document.SaveFile("../Ressource/sauvegarde.xml");
}

void GestionPort::sauvegardePersonne(tinyxml2::XMLDocument * document, tinyxml2::XMLElement * root) {
    XMLElement * abonne = document->NewElement("ListeAbonnes");
    root->InsertEndChild(abonne);
    for(auto &it : _listeAbonne){
        XMLElement * abonneAdd = document->NewElement("abonne");
        abonneAdd->SetAttribute("prenom",it->getPrenom());
        abonneAdd->SetAttribute("nom",it->getNom());
        abonneAdd->SetAttribute("age",it->getAge());
        abonneAdd->SetAttribute("idAbonne",it->getIdAbonne());
        abonneAdd->SetAttribute("dateAbonnement",it->getDateAbonnement());
        abonne->InsertEndChild(abonneAdd);
    }
    XMLElement * visiteur = document->NewElement("ListeVisiteurs");
    root->InsertEndChild(visiteur);
    for(auto &it : _listeVisiteur){
        XMLElement * visiteurAdd = document->NewElement("visiteur");
        visiteurAdd->SetAttribute("prenom",it->getPrenom());
        visiteurAdd->SetAttribute("nom",it->getNom());
        visiteurAdd->SetAttribute("age",it->getAge());
        visiteurAdd->SetAttribute("idVisiteur",it->getIdVisiteur());
        visiteurAdd->SetAttribute("dateArrivee",it->getDateArrivee());
        visiteur->InsertEndChild(visiteurAdd);
    }
}

void GestionPort::import() {
    tinyxml2::XMLDocument document;
    tinyxml2::XMLError error = document.LoadFile("../Ressource/sauvegarde.xml");
    if(error == XML_SUCCESS){
        XMLHandle docHandle (&document);
        XMLElement * abonne = docHandle.LastChild().FirstChildElement("ListeAbonnes")
                .FirstChild().ToElement();
        cout<<"----------------------"<<endl;
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
            cout<<"Insertion de l'abonné :" << dateAbonnement << " " << age << endl;
            Abonne * abonneAdd = new Abonne(idAbonnement,nom,prenom ,age , dateAbonnement);
            _listeAbonne.push_back(abonneAdd);
            abonne = abonne->NextSiblingElement();
        }
    }else{
        cout<<"Erreur lors de l'ouverture du fichier : "<< tinyxml2::XMLDocument::ErrorIDToName(error) <<endl;
    }
}








