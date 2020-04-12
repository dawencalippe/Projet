#include "Menu.h"
#include <iostream>
using namespace std;

void Menu::afficherMenu() {
    cout << "Bonjour, bienvenue dans notre Port, que souhaitez vous faire ? \n"
            "1) Consulter la liste des factures payees et non payees.\n"
            "2) Afficher la liste des bateaux inscrits dans le port.\n"
            "3) Afficher la liste des abonnes.\n"
            "4) Afficher la liste des visiteurs en cours.\n"
            "5) Afficher la liste des places disponibles.\n"
            "6) Ajouter une personne.\n"
            "7) Supprimer une personne.\n"
            "\nVeuillez rentrer le nombre qui correspond à ce que vous souhaitez faire :" <<endl;
    cin >> _entreeClavier;

    switch (_entreeClavier) {
        case '1':
            //TODO
            afficherFactures();
            break;
        case '2':
            afficherBateaux();
            break;
        case '3':
            afficherAbonnees();
            break;
        case '4':
            afficherVisiteurs();
            break;
        case '5':
            afficherPlacesDispo();
            break;
        case '6':
            ajouterUnePersonne();
            break;
        case '7':
            //TODO
            supprimerUnePersonne();
            break;
        default :
            cout<<"Erreur de saisie. Veuillez rentrer le nombre qui correspond à ce que vous souhaitez faire :"<<endl;
            afficherMenu();
            break;
    }

}
void Menu::afficherFactures() {
    //TODO
}

void Menu::afficherBateaux() {
    cout<<"Liste des bateaux :"<<endl;
    for(auto &it : _listeBateaux){
        it->affiche();
    }
}

void Menu::afficherAbonnees() {
    _gestionPort.afficheAbonne();
}

void Menu::afficherVisiteurs() {
    _gestionPort.afficheVisiteur();
}

void Menu::afficherPlacesDispo() {
    _gestionPort.afficherPlaceDispo();
}

void Menu::ajouterUnePersonne() {
    cout << "Quel est le nom de la personne ? :" <<endl;
    cin >> _entreeClavierS;
    char * nomPersonne = _entreeClavierS;
    cout <<"Quel est le prenom de la personne ? :"<<endl;
    cin >> _entreeClavierS;
    char * prenomPersonne = _entreeClavierS;
    cout << "Quel est l'age de la personne ? :"<<endl;
    cin >> _entreeClavierInt;
    int age = _entreeClavierInt;
    cout << "Quel est la taille du bateau ?"<<endl;
    cin >> _entreeClavierInt;
    int taille = _entreeClavierInt;
    cout << "Quel est le nom du bateau ? "<< endl;
    cin >> _entreeClavierS;
    char * nomBateau = _entreeClavierS;
    Bateau bat;
    Place place;
    if (taille<10){
        bat = Bateau(taille, 0, nomBateau, Bateau::VOILIER_NH);
        place.setSuplementEau(false);
        place.setSuplemmentElectricite(false);
        //afficherPlacesDispo(bat, place);
        //choisirPlace(bat);
    } else {
        cout << "Combien de cabines le bateau comporte-t-il ?" <<endl;
        cin >> _entreeClavierInt;
        int nbCabines = _entreeClavierInt;
        if (taille>=10 && taille <=25){
            bat = Bateau(taille, nbCabines, nomBateau, Bateau::VOILIER_1);
        } else {
            bat = Bateau(taille, nbCabines, nomBateau, Bateau::VOILIER_2);
        }
        cout << "La personne souhaite-t-elle avoir acces a l'eau ? [y/n]" <<endl;
        cin >> _entreeClavier;
        char eau = _entreeClavier;
        if (eau == 'y' || eau == 'Y'){
            place.setSuplementEau(true);
        } else {
            place.setSuplementEau(false);
        }
        cout << "La personne souhaite-t-elle avoir acces a l'electricite ? [y/n]" <<endl;
        cin >> _entreeClavier;
        char elect = _entreeClavier;
        if (elect == 'y'|| elect == 'Y'){
            place.setSuplemmentElectricite(true);
        } else {
            place.setSuplemmentElectricite(false);
        }
        //afficherPlacesDispo(bat, place);
        //choisirPlace(bat);
    }
    cout << "La personne est-elle un abonne ou un visiteur ? [a/v]" << endl;
    cin >> _entreeClavier;
    //while (_entreeClavier != 'a' || _entreeClavier != 'v'){
        if(_entreeClavier == 'a'){
            Abonne abo = Abonne(nomPersonne, prenomPersonne, age);
            abo.addBateau(&bat);
            _gestionPort.addAbonne(&abo);
        } else if (_entreeClavier == 'v'){
            Visiteur visit = Visiteur(nomPersonne, prenomPersonne, age);
            visit.addBateau(&bat);
            _gestionPort.addVisiteur(&visit);

            cout << "Combien de jours la personne souhaite-t-elle rester ?" <<endl;
            cin >> _entreeClavierInt;
            //TODO pour faire le calcul de la facture.
        } else {
            cout << "Vous devez rentrer 'a' ou 'v'."<<endl;
        }
    //}
}

void Menu::afficherPlacesDispo(Bateau * bat, Place * place) {
    cout << "Voici la liste des places dispo pour ce bateau :" << endl;
    if ((bat->getTypeBateau()==Bateau::VOILIER_NH || bat->getTypeBateau()==Bateau::VOILIER_1) &&
        (!place->isSuplementEau() && !place->isSuplemmentElectricite())){
        for(auto &it : _gestionPort.getListePlace()){
            if(!it->isPrise()){
                it->afficheCoprsMort();
                it->affichePlaceNormale();
            } else {
                cout << "aucune place dispo pour ce type de bateau"<<endl;
            }
        }
    } else if (bat->getTypeBateau()==Bateau::VOILIER_1 && place->isSuplemmentElectricite() || place->isSuplementEau()) {
        for(auto &it : _gestionPort.getListePlace()){
            if(!it->isPrise()){
                it->affichePlaceNormale();
            } else {
                cout << "aucune place dispo pour ce type de bateau"<<endl;
            }
        }
    } else if (bat->getTypeBateau() == Bateau::VOILIER_2) {
        for(auto &it : _gestionPort.getListePlace()){
            if(!it->isPrise()){
                it->affichePlaceGrande();
            } else {
                cout << "aucune place dispo pour ce type de bateau"<<endl;
            }
        }
    }
}

void Menu::choisirPlace(Bateau * bat) {
    bool trouve = false;
    cout << "Veuillez choisir une place parmis les places ci-dessus (entrez l'id de la place)"<<endl;
    cin >> _entreeClavierInt;
    int idPlace = _entreeClavierInt;
    _List_const_iterator<Place *> iterator = _gestionPort.getListePlace().begin();
    while(iterator!= _gestionPort.getListePlace().end() && !trouve){
        if((*iterator)->getIdPlace()==idPlace){
            (*iterator)->setPrise(true);
            bat->setCurrentPlace(idPlace);
            trouve = true;
        }else{
            iterator++;
        }
    }
    if(!trouve){
        cout<<"Numéro de la place invalide"<<endl;
        //TODO : Afficher de nouveau les places disponibles
    }
}

Menu::Menu() {}

Menu::~Menu() {

}

void Menu::supprimerUnePersonne() {
    //TODO
}

const GestionPort &Menu::getGestionPort() const {
    return _gestionPort;
}

Menu::Menu(GestionPort gestionPort) :_gestionPort(gestionPort){}








