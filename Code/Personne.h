//
// Created by dawen on 18/03/2020.
//

#ifndef CODE_PERSONNE_H
#define CODE_PERSONNE_H


#include <c++/4.8.3/list>
#include "Bateau.h"
#include <string>

class Personne {

protected:
    char* _prenom;
    char* _nom;
    int _age;
    std::list <Bateau *> _listeBateaux;
public:

    const std::list<Bateau *> &getListeBateaux() const;
    char *getPrenom() const;
    void setPrenom(char *prenom);
    char *getNom() const;
    void setNom(char *nom);
    int getAge() const;
    void setAge(int age);
    //Constructeur
    Personne();
    Personne(char* nomPersonne, char* prenomPersonne, int agePersonne);
    //Destructeur
    ~Personne();
    virtual void affiche() const;
    void addBateau(Bateau * bateau);
    void removeBateau(Bateau * bateau);
};


#endif //CODE_PERSONNE_H
