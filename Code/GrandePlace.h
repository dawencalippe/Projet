//
// Created by 33629 on 28/03/2020.
//

#ifndef CODE_GRANDEPLACE_H
#define CODE_GRANDEPLACE_H

#include "Place.h"

class GrandePlace : public Place {
public :
    GrandePlace(int id, float tailleMax, Bateau *bateauPtr);

    ~GrandePlace();
};


#endif //CODE_GRANDEPLACE_H
