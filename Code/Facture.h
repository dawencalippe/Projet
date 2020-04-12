//
// Created by dawen on 12/04/2020.
//

#ifndef CODE_FACTURE_H
#define CODE_FACTURE_H


#include "Personne.h"

class Facture {
private :
    Personne * _personne;
    int _montant;
    std::string _dateFacturation;
    bool _paye;
public:
    Facture(Personne * personne);
    void calculFacture(int reduction);
};


#endif //CODE_FACTURE_H
