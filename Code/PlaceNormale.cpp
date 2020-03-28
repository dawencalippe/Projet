//
// Created by 33629 on 28/03/2020.
//

#include "PlaceNormale.h"

PlaceNormale::~PlaceNormale() {

}

PlaceNormale::PlaceNormale(int id, float tailleMax, Bateau *bateauPtr) : Place(id, tailleMax, bateauPtr) {
    this->tailleMax = 25;
}
