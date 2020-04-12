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
    void afficherPlacesDispo(Bateau * bat);
    Menu(GestionPort gestionport);
    virtual ~Menu();
    void afficherMenu();
    void afficherBateaux();
    void afficherAbonnees();
    void afficherVisiteurs();
    void afficherPlacesDispo();
    Personne * ajouterUnePersonne();
    void supprimerUnePersonne();
    const GestionPort &getGestionPort() const;
    void enregistrerEntree();
    Personne * recherchePersonne();

    Abonne *rechercheAbonne(char *nom, char *prenom, int age);

    Visiteur *rechercheVisiteur(char *nom, char *prenom, int age);

    Bateau *creationBateau(Personne *personne);

    Bateau * choixBateau(Personne *personne);
};


#endif //CODE_MENU_H
