#include <iostream>
#include "Personne.h"
#include "Abonne.h"
#include "Visiteur.h"
#include "GestionPort.h"

int main() {
    std::cout << "Hello, Dawen et Aurore!" << std::endl;

    /*//test Personne
    Personne personne = Personne();
    personne.affiche();
    Personne personne2 = Personne("Dawen", "Calippe", 21);
    personne2.affiche();
        */
    //test abonné
    Abonne abo = Abonne();
    abo.affiche();
    Abonne * abo2 = new Abonne("Abonne", "Abonne", 21);
    abo2->affiche();

    //test visiteur
    Visiteur * visi2 = new Visiteur( "Dawen", "testVisi", 21);
    Visiteur * visi3 = new Visiteur( "Clément", "testVisi", 21);
    GestionPort port;
    port.addVisiteur(visi2);
    port.addVisiteur(visi2);
    port.addVisiteur(visi3);
    port.removeVisiteur(visi2);
    port.afficheVisiteur();

    port.addAbonne(abo2);
    port.afficheAbonne();
    port.removeAbonne(abo2);
    port.afficheAbonne();

    delete(visi2);

    return 0;
}
