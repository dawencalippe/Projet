#ifndef CODE_MENU_H
#define CODE_MENU_H

#include "GestionPort.h"
#include <iostream>
#include "Bateau.h"

class Menu {
private :
    char _entreeClavier;
    char _entreeClavierS[100];
    int _entreeClavierInt;
    GestionPort _gestionPort;
private:
    std::list <Bateau *> _listeBateaux;

public :
    Menu();
    void choisirPlace(Bateau * bat);
    void afficherPlacesDispo(Bateau * bat, Place * place);
    Menu(GestionPort gestionport);
    virtual ~Menu();
    void afficherMenu();
    void afficherFactures();
    void afficherBateaux();
    void afficherAbonnees();
    void afficherVisiteurs();
    void afficherPlacesDispo();
    void ajouterUnePersonne();
    void supprimerUnePersonne();
    const GestionPort &getGestionPort() const;

};


#endif //CODE_MENU_H
