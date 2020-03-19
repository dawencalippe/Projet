//
// Created by dawen on 18/03/2020.
//

#ifndef CODE_ABONNE_H
#define CODE_ABONNE_H

#include "Personne.h"

class Abonne : public Personne {
private:
    int _idAbonne;
    char* _dateAbonnement;
public:
    static int current_id;
    Abonne();
    Abonne(char* nomPersonne, char* prenomPersonne, int agePersonne);
    void affiche() const;
    ~Abonne();
};


#endif //CODE_ABONNE_H
