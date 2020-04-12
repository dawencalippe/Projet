//
// Created by 33629 on 28/03/2020.
//

#include "Place.h"
#include <iostream>

int Place::current_id =0;

Place::~Place() {

}

Place::Place() {
    _idPlace = current_id;
    current_id++;
}

Place::Place(float tailleMax, TYPEPLACE typePlace) : _tailleMax(tailleMax), _typePlace(typePlace) {
    _idPlace=current_id;
    _prise=false;
    _suplemmentElectricite=false;
    _suplementEau=false;
    current_id++;
}

Place::Place(int id, float tailleMax, Place::TYPEPLACE typePlace, bool prise, bool suplemmentElectricite,
             bool suplemmentEau)  : _idPlace(id),_tailleMax(tailleMax), _typePlace(typePlace),
             _prise(prise), _suplementEau(suplemmentEau),_suplemmentElectricite(suplemmentElectricite)
             {}

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

void Place::affichePlace() const {
    std::cout << "id : "<< _idPlace  << ", tailleMax : " << _tailleMax << ", type de place : " << ToString(_typePlace) << std::endl;
}

void Place::affichePlaceNormale() const {
    if (this->_typePlace == PLACENORMAL){
        std::cout << "id : "<< _idPlace  << ", tailleMax : " << _tailleMax << ", type de place : " << ToString(_typePlace) << std::endl;
    }
}

void Place::affichePlaceGrande() const {
    if (this->_typePlace == PLACEGRANDE){
        std::cout << "id : "<< _idPlace  << ", tailleMax : " << _tailleMax << ", type de place : " << ToString(_typePlace) << std::endl;
    }
}

void Place::afficheCoprsMort() const {
    if (this->_typePlace == CORPSMORT){
        std::cout << "id : "<< _idPlace  << ", tailleMax : " << _tailleMax << ", type de place : " << ToString(_typePlace) << std::endl;
    }
}

int Place::getIdPlace() const {
    return _idPlace;
}

float Place::getTailleMax() const {
    return _tailleMax;
}

void Place::setTailleMax(float tailleMax) {
    _tailleMax = tailleMax;
}

Place::TYPEPLACE Place::getTypePlace() const {
    return _typePlace;
}

void Place::setTypePlace(Place::TYPEPLACE typePlace) {
    _typePlace = typePlace;
}



