//
// Created by 33629 on 28/03/2020.
//

#include "GrandePlace.h"

GrandePlace::~GrandePlace() {

}

GrandePlace::GrandePlace(int id, float tailleMax, Bateau *bateauPtr) : Place(id, tailleMax, bateauPtr) {
    this->tailleMax = 400;
}
