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
    Abonne(int idAbonne,char * nomPersonne, char* prenomPersonne, int agePersonne, char * dateAbonnement);
    void affiche() const;
    ~Abonne();
    int getIdAbonne() const;

    void setIdAbonne(int idAbonne);

    char *getDateAbonnement() const;

    void setDateAbonnement(char *dateAbonnement);
};


#endif //CODE_ABONNE_H
