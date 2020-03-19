//
// Created by dawen on 18/03/2020.
//

#ifndef CODE_VISITEUR_H
#define CODE_VISITEUR_H


#include "Personne.h"

class Visiteur : public Personne {
private:
    int _idVisiteur;
    char* _dateArrivee;
public:
    static int current_id;
    int getIdVisiteur() const;
    void setIdVisiteur(int idVisiteur);
    char *getDateArrivee() const;
    void setDateArrivee(char *dateArrivee);
    Visiteur();
    Visiteur( char* nomPersonne, char* prenomPersonne, int agePersonne);
    void affiche() const ;
    ~Visiteur();
};


#endif //CODE_VISITEUR_H
