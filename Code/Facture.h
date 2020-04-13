#ifndef CODE_FACTURE_H
#define CODE_FACTURE_H


#include "Personne.h"
#include "Place.h"

class Facture {
private :
public:
    Personne *getPersonne() const;

    void setPersonne(Personne *personne);

    Bateau *getBateau() const;

    void setBateau(Bateau *bateau);

    Place *getPlace() const;

    void setPlace(Place *place);

    int getMontant() const;

    void setMontant(int montant);

    int getNbJour() const;

    void setNbJour(int nbJour);

    const std::string &getDateFacturation() const;

    void setDateFacturation(const std::string &dateFacturation);

    bool isPaye() const;

    void setPaye(bool paye);

private:
    Personne * _personne;
    Bateau * _bateau;
    Place * _place;
    int _montant;
    int _nbJour;
    std::string _dateFacturation;
    bool _paye;
    int _nombreAccomptePaye;
public:
    Facture(Personne * personne, Bateau * bateau,Place *place,  int nbJour);
    void calculFacture(int reduction);

    int calculAbonne();

    int calculVisiteur();
    void affichefacture();
};
#endif //CODE_FACTURE_H
