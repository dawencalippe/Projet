#include <iostream>
#include "Personne.h"
#include "Abonne.h"
#include "Visiteur.h"
#include "GestionPort.h"
#include "Menu.h"

int main() {
    std::cout << "Hello, Dawen et Aurore!" << std::endl;
    GestionPort port;
    Abonne * abonne = new Abonne("Dawen", "Calippe", 21);
    Bateau * bateau = new Bateau(35, 2,"LeBateau", Bateau::VOILIER_2);
    abonne->addBateau(bateau);
    abonne->addBateau(bateau);
    abonne->addBateau(bateau);
    port.addAbonne(abonne);
    port.addAbonne(abonne);
    port.addAbonne(abonne);
    port.sauvegarde();

    Menu menu;
    menu.ajouterUnePersonne();

}
