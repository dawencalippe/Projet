//
// Created by 33629 on 28/03/2020.
//

#include "Place.h"

Place::~Place() {

}

Place::Place(int id, float tailleMax, Bateau *bateauPtr) : id(id), tailleMax(tailleMax), bateauPtr(bateauPtr) {}

bool Place::placementPossible() {
    return bateauPtr == nullptr;
}
