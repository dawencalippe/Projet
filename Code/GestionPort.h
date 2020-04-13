//
// Created by dawen on 18/03/2020.
//

#ifndef CODE_GESTIONPORT_H
#define CODE_GESTIONPORT_H


#include "Abonne.h"
#include "Visiteur.h"
#include "Ressource/tinyxml2/tinyxml2.h"
#include "Place.h"
#include <list>
#include <string>
#include <c++/4.8.3/map>

class GestionPort {
private:
    std::list <Abonne *> _listeAbonne;
    std::list <Visiteur *> _listeVisiteur;
    std::list <Place *> _listePlace;

public:
    const std::list<Abonne *> &getListeAbonne() const;
    void setListeAbonne(const std::list<Abonne *> &listeAbonne);
    const std::list<Visiteur *> &getListeVisiteur() const;
    void setListeVisiteur(const std::list<Visiteur *> &listeVisiteur);
    const std::list<Place *> &getListePlace() const;
    GestionPort();
    ~GestionPort();
    void afficheVisiteur();
    void addVisiteur(Visiteur * visiteur);
    void removeVisiteur(Visiteur * visiteur);
    void afficheAbonne();
    void addAbonne(Abonne * abonne);
    void addPlace(Place * place);
    void removePlace(Place * place);
    void removeAbonne(Abonne * abonne);
    void afficherPlaceDispo();
    void sauvegarde();
    void sauvegardePersonne(tinyxml2::XMLDocument * document, tinyxml2::XMLElement * root);
    void sauvegardePlace(tinyxml2::XMLDocument * document, tinyxml2::XMLElement * root);
    void import();
    void importPersonne(tinyxml2::XMLDocument * document);
    void importPlace(tinyxml2::XMLDocument *document);

    void importBateaux(tinyxml2::XMLElement *root, Personne *personne);

    Place *getPlace(int idPlace);
};

#endif //CODE_GESTIONPORT_H
