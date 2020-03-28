//
// Created by 33629 on 28/03/2020.
//

#ifndef CODE_PLACE_H
#define CODE_PLACE_H

#include "Bateau.h"

class Place {
protected :
    int id;
    float tailleMax;
    float prix;
    Bateau * bateauPtr;

public :
    Place(int id, float tailleMax, Bateau *bateauPtr);

    bool placementPossible();

    virtual ~Place();
};


#endif //CODE_PLACE_H
