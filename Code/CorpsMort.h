//
// Created by 33629 on 28/03/2020.
//

#ifndef CODE_CORPSMORT_H
#define CODE_CORPSMORT_H

#include "Place.h"

class CorpsMort : public Place {
public:
    CorpsMort(int id, float tailleMax, Bateau *bateauPtr);

    ~CorpsMort();
};


#endif //CODE_CORPSMORT_H
