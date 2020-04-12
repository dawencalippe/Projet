#include <iostream>
#include "Personne.h"
#include "Abonne.h"
#include "Bateau.h"
#include "Visiteur.h"
#include "GestionPort.h"
#include "Menu.h"
#include <string>

int main() {
    std::cout << "Hello, Dawen et Aurore!" << std::endl;
    Bateau * bateau = new Bateau(9, 2, "vaillant", Bateau::VOILIER_1);
    GestionPort port;
    Place * p1 = new Place(36.0, Place::PLACEGRANDE);
    Place * p2 = new Place(36.0, Place::TYPEPLACE::PLACENORMAL);
    Place * p3 = new Place(36.0, Place::TYPEPLACE::CORPSMORT);
    port.addPlace(p1);
    port.addPlace(p2);
    port.addPlace(p3);
    Abonne * abo = new Abonne("Calippe", "Dawen", 21);
    Abonne * abonne = new Abonne("Calippe", "Dawen", 21);
    Abonne * oba = new Abonne("Calippe", "Dawen", 21);
    abo->addBateau(bateau);
    abo->addBateau(bateau);
    abo->addBateau(bateau);
    abonne->addBateau(bateau);
    oba->addBateau(bateau);
    Visiteur * visi = new Visiteur("DAwen", "calippe", 21);
    visi->affiche();
    Visiteur * vi = new Visiteur("Erwan", "calippe", 21);
    vi->affiche();
    Visiteur * v = new Visiteur("Aymeric", "calippe", 21);
    v->affiche();
    visi->addBateau(bateau);
    v->addBateau(bateau);
    vi->addBateau(bateau);
    port.addAbonne(abonne);
    port.addAbonne(abo);
    port.addAbonne(oba);
    port.addVisiteur(vi);
    port.addVisiteur(v);
    port.addVisiteur(visi);
    std::cout<<"-------------"<<std::endl;
    Menu menu(port);/*
    menu.afficherPlacesDispo(bateau, p1);
    menu.choisirPlace(bateau);
    std::cout<<"-------------"<<std::endl;
    menu.afficherPlacesDispo(bateau, p1);
    bateau->affiche();*/
    //menu.enregistrerEntree();
    menu.enregistrerEntree();
    abo->affiche();

}
