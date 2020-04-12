#include "Menu.h"
#include <iostream>
using namespace std;

void Menu::afficherMenu() {
    cout << "Bonjour, bienvenue dans notre Port, que souhaitez vous faire ? \n"
            "1) Enregistrer une nouvelle arrivée\n"
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
            enregistrerEntree();
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
            supprimerUnePersonne();
            break;
        default :
            cout<<"Erreur de saisie. Veuillez rentrer le nombre qui correspond à ce que vous souhaitez faire :"<<endl;
            afficherMenu();
            break;
    }

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

Personne * Menu::ajouterUnePersonne() {
    cout << "Quel est le nom de la personne ? :" <<endl;
    cin >> _entreeClavierS;
    char * nomPersonne = _entreeClavierS;
    cout <<"Quel est le prenom de la personne ? :"<<endl;
    cin >> _entreeClavierS;
    char * prenomPersonne = _entreeClavierS;
    cout << "Quel est l'age de la personne ? :"<<endl;
    cin >> _entreeClavierInt;
    int age = _entreeClavierInt;
    cout << "La personne est-elle un abonne ou un visiteur ? [a/v]" << endl;
    cin >> _entreeClavier;
    while(_entreeClavier != 'a' && _entreeClavier !='A' && _entreeClavier != 'v' && _entreeClavier !='V'){
        cout<<"Veuillez entrer y ou n :"<<endl;
        cin >> _entreeClavier;
    }
    if(_entreeClavier == 'a' || _entreeClavier =='A'){
        Abonne* abo = new Abonne(nomPersonne, prenomPersonne, age);
        _gestionPort.addAbonne(abo);
    }else{
        Visiteur * visit = new Visiteur(nomPersonne, prenomPersonne, age);
        _gestionPort.addVisiteur(visit);
    }
}

void Menu::afficherPlacesDispo(Bateau * bat) {
    bool suppEau =false;
    bool suppElec = false;
    cout<<"La personne souhaite-t-elle avoir acces a l'eau ? [y/n]"<<endl;
    cin >> _entreeClavier;
    while(_entreeClavier != 'y' && _entreeClavier !='Y' && _entreeClavier != 'n' && _entreeClavier !='N'){
        cout<<"Veuillez entrer y ou n :"<<endl;
        cin >> _entreeClavier;
    }
    if(_entreeClavier == 'y' || _entreeClavier =='Y'){
        suppEau =true;
    }
    cout<<"La personne souhaite-t-elle avoir acces a l'electricite ? [y/n]"<<endl;
    cin >> _entreeClavier;
    while(_entreeClavier != 'y' && _entreeClavier !='Y' && _entreeClavier != 'n' && _entreeClavier !='N'){
        cout<<"Veuillez entrer y ou n :"<<endl;
        cin >> _entreeClavier;
    }
    if(_entreeClavier == 'y' || _entreeClavier =='Y'){
        suppElec =true;
    }
    cout << "Voici la liste des places dispo pour ce bateau :" << endl;
    if ((bat->getTypeBateau()==Bateau::VOILIER_NH || bat->getTypeBateau()==Bateau::VOILIER_1) &&
        (!suppEau && !suppElec)){
        for(auto &it : _gestionPort.getListePlace()){
            if(!it->isPrise()){
                it->afficheCoprsMort();
                it->affichePlaceNormale();
            } else {
                cout << "aucune place dispo pour ce type de bateau"<<endl;
            }
        }
    } else if (bat->getTypeBateau()==Bateau::VOILIER_1 && suppElec || suppEau) {
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
        choisirPlace(bat);
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

void Menu::enregistrerEntree() {
    cout<<"Le nouvel arrivant est-il déjà venu dans notre port ? [y/n]"<<endl;
    cin >> _entreeClavier;
    while(_entreeClavier != 'y' && _entreeClavier !='Y' && _entreeClavier != 'n' && _entreeClavier !='N'){
        cout<<"Veuillez entrer y ou n :"<<endl;
        cin >> _entreeClavier;
    }
    if(_entreeClavier == 'y' || _entreeClavier =='Y'){
        Personne * personne = recherchePersonne();
        personne->affiche();
        Bateau * bateau = choixBateau(personne);
        bateau->affiche();
        afficherPlacesDispo(bateau);
        choisirPlace(bateau);
    }else{
        cout<<"Voulez-vous l'enregistrer comme nouveau client ? [y/n]"<<endl;
        cin >> _entreeClavier;
        while(_entreeClavier != 'y' && _entreeClavier !='Y' && _entreeClavier != 'n' && _entreeClavier !='N'){
            cout<<"Veuillez entrer y ou n :"<<endl;
            cin >> _entreeClavier;
        }
        if(_entreeClavier == 'y' || _entreeClavier =='Y'){
            cout<<"Ajout de la personne"<<endl;

        }else{
            cout<<"Non ajout de la personne"<<endl;
        }
    }
}

Personne * Menu::recherchePersonne() {
    Personne * personne = nullptr;
    int age;
    char *nomPersonne ;
    char *prenomPersonne;
    cout<<"Entrez le nom de la personne :"<<endl;
    cin >> _entreeClavierS;
    nomPersonne =_entreeClavierS;
    cout<<"Entrez le prénom de la personne :"<<endl;
    cin >> _entreeClavierS;
    prenomPersonne =_entreeClavierS;
    cout<<"Entrez l'âge de la personne :"<<endl;
    cin >> _entreeClavierInt;
    age = _entreeClavierInt;
    cout<<"Abonner ou visiteur ? [a/v]:"<<endl;
    cin >> _entreeClavier;
    while(_entreeClavier != 'a' && _entreeClavier !='A' && _entreeClavier != 'v' && _entreeClavier !='V'){
        cout<<"Veuillez entrer a ou V :"<<endl;
        cin >> _entreeClavier;
    }
    if(_entreeClavier == 'a' || _entreeClavier =='A'){
        Abonne * abonne = rechercheAbonne(nomPersonne, prenomPersonne, age);
        personne = abonne;
    }else{
        Visiteur * visiteur = rechercheVisiteur(nomPersonne,prenomPersonne, age);
        personne = visiteur;
    }
    return personne;
}

Abonne *Menu::rechercheAbonne(char *nom, char *prenom, int age) {
    for(auto &it : _gestionPort.getListeAbonne()){
        if((strcmp(it->getPrenom(), prenom) == 0) && (it->getAge()==age) && (strcmp(it->getNom(),prenom)) ){
            return it;
        }
    }
    return nullptr;
}

Visiteur *Menu::rechercheVisiteur(char *nom, char *prenom, int age) {
    for(auto &it : _gestionPort.getListeVisiteur()){
        if((strcmp(it->getPrenom(), prenom) == 0) && (it->getAge()==age) && (strcmp(it->getNom(),prenom)) ){
            return it;
        }
    }
    return nullptr;
}

Bateau *Menu::creationBateau(Personne *personne) {
    Bateau * bateau;
    cout << "Quel est la taille du bateau ?"<<endl;
    cin >> _entreeClavierInt;
    int taille = _entreeClavierInt;
    cout << "Quel est le nom du bateau ? "<< endl;
    cin >> _entreeClavierS;
    char * nomBateau = _entreeClavierS;
    if (taille<10){
        bateau = new  Bateau(taille, 0, nomBateau, Bateau::VOILIER_NH);
    } else {
        cout << "Combien de cabines le bateau comporte-t-il ?" << endl;
        cin >> _entreeClavierInt;
        int nbCabines = _entreeClavierInt;
        if (taille >= 10 && taille <= 25) {
            bateau = new Bateau(taille, nbCabines, nomBateau, Bateau::VOILIER_1);
        } else {
            bateau = new Bateau(taille, nbCabines, nomBateau, Bateau::VOILIER_2);
        }
    }
    personne->addBateau(bateau);
    return bateau;
}

Bateau * Menu::choixBateau(Personne *personne) {
    Bateau * bateau;
    if(personne->getListeBateaux().size() ==0){
        cout<<"la personne n'a aucun bateau de connu. Merci de rentrez les informations du bateau"<<endl;
        bateau = creationBateau(personne);
    }
    if(personne->getListeBateaux().size()==1){
        return personne->getListeBateaux().front();
    }else{
        personne->getListeBateaux().front()->affiche();
        cout<<"il s'agit bien de ce bateau ?[y/n]";
        cin>> _entreeClavier;
        while(_entreeClavier != 'y' && _entreeClavier !='Y' && _entreeClavier != 'n' && _entreeClavier !='N'){
            cout<<"Veuillez entrer y ou n :"<<endl;
            cin >> _entreeClavier;
        }
        if(_entreeClavier == 'y' || _entreeClavier =='Y'){
            bateau = personne->getListeBateaux().front();
        }else{
            for(auto &it : personne->getListeBateaux()){
                it->affiche();
            }
            cout<<"Entrez le nom du bateau voulu : "<<endl;
            cin>>_entreeClavierS;
            bool trouve = false;
            _List_const_iterator<Bateau *> iterator = personne->getListeBateaux().begin();
            while(iterator != personne->getListeBateaux().end() && !trouve){
                if(strcmp(_entreeClavierS, (* iterator)->getNom())==0){
                    bateau = (* iterator);
                    trouve = true;
                }else{
                    iterator++;
                }
            }
            if(!trouve){
                bateau = creationBateau(personne);
            }
        }
    }
    return bateau;
}











