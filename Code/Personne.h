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
    char *getNom() const;
    int getAge() const;
    //Constructeur
    Personne();
    Personne(char* nomPersonne, char* prenomPersonne, int agePersonne);
    //Destructeur
    ~Personne();
    virtual void affiche() const;
    void addBateau(Bateau * bateau);
};
#endif //CODE_PERSONNE_H
