//
// Created by 33629 on 28/03/2020.
//

#ifndef CODE_PLACENORMALE_H
#define CODE_PLACENORMALE_H

#include "Place.h"

class PlaceNormale : public Place {
public :
    PlaceNormale(int id, float tailleMax, Bateau *bateauPtr);

    ~PlaceNormale();
};


#endif //CODE_PLACENORMALE_H
