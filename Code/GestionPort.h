//
// Created by dawen on 18/03/2020.
//

#ifndef CODE_GESTIONPORT_H
#define CODE_GESTIONPORT_H


#include "Abonne.h"
#include "Visiteur.h"
#include <list>

class GestionPort {
private:
    std::list <Abonne *> _listeAbonne;
    std::list <Visiteur *> _listeVisiteur;
public:
    const std::list<Abonne *> &getListeAbonne() const;
    void setListeAbonne(const std::list<Abonne *> &listeAbonne);
    const std::list<Visiteur *> &getListeVisiteur() const;
    void setListeVisiteur(const std::list<Visiteur *> &listeVisiteur);
    GestionPort();
    ~GestionPort();
    void afficheVisiteur();
    void addVisiteur(Visiteur * visiteur);
    void removeVisiteur(Visiteur * visiteur);
    void afficheAbonne();
    void addAbonne(Abonne * abonne);
    void removeAbonne(Abonne * abonne);
};

#endif //CODE_GESTIONPORT_H
