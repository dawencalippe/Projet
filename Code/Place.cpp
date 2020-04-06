//
// Created by 33629 on 28/03/2020.
//

#include "Place.h"
#include <iostream>

Place::~Place() {

}

Place::Place(int id, float tailleMax, TYPEPLACE typePlace) : _idPlace(id), _tailleMax(tailleMax), _typePlace(typePlace) {}

bool Place::isPrise() const {
    return _prise;
}

void Place::setPrise(bool prise) {
    _prise = prise;
}

bool Place::isSuplemmentElectricite() const {
    return _suplemmentElectricite;
}

void Place::setSuplemmentElectricite(bool suplemmentElectricite) {
    _suplemmentElectricite = suplemmentElectricite;
}

bool Place::isSuplementEau() const {
    return _suplementEau;
}

void Place::setSuplementEau(bool suplementEau) {
    _suplementEau = suplementEau;
}

Place::Place() {

}

void Place::affichePlaces() const {
    std::cout << "id : "<< _idPlace  << ", tailleMax : " << _tailleMax << ", type de place : " << _typePlace << std::endl;
}

void Place::affichePlaceNormale() const {
    if (this->_typePlace == PLACENORMAL){
        std::cout << "id : "<< _idPlace  << ", tailleMax : " << _tailleMax << ", type de place : " << _typePlace << std::endl;
    }
}

void Place::affichePlaceGrande() const {
    if (this->_typePlace == PLACEGRANDE){
        std::cout << "id : "<< _idPlace  << ", tailleMax : " << _tailleMax << ", type de place : " << _typePlace << std::endl;
    }
}

void Place::afficheCoprsMort() const {
    if (this->_typePlace == CORPSMORT){
        std::cout << "id : "<< _idPlace  << ", tailleMax : " << _tailleMax << ", type de place : " << _typePlace << std::endl;
    }
}

int Place::getIdPlace() const {
    return _idPlace;
}

