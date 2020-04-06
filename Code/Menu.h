#ifndef CODE_MENU_H
#define CODE_MENU_H

#include "GestionPort.h"
#include <iostream>
#include "Bateau.h"

class Menu {
private :
    char _entreeClavier;
    char _entreeClavierS[100];
    int _entreClavierInt;
    GestionPort gestionPort;
    std::list <Bateau *> _listeBateaux;

    void afficherPlacesDispo(Bateau bat, Place place);
    void choisirPlace(Bateau bat);

public :
    Menu();
    virtual ~Menu();
    void afficherMenu();
    void afficherFactures();
    void afficherBateaux();
    void afficherAbonnees();
    void afficherVisiteurs();
    void afficherPlacesDispo();
    void ajouterUnePersonne();
    void supprimerUnePersonne();

};


#endif //CODE_MENU_H
