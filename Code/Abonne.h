#ifndef CODE_ABONNE_H
#define CODE_ABONNE_H

#include "Personne.h"

class Abonne : public Personne {
private:
    int _idAbonne;
    std::string _dateAbonnement;
public:
    static int current_id;
    Abonne();
    Abonne(char* nomPersonne, char* prenomPersonne, int agePersonne);
    Abonne(int idAbonne,char * nomPersonne, char* prenomPersonne, int agePersonne, std::string dateAbonnement);
    void affiche() const;
    ~Abonne();
    int getIdAbonne() const;
    std::string getDateAbonnement() const;
};
#endif //CODE_ABONNE_H
