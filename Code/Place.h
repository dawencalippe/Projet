//
// Created by 33629 on 28/03/2020.
//

#ifndef CODE_PLACE_H
#define CODE_PLACE_H

#include "Bateau.h"

class Place {
public:
    enum TYPEPLACE{
        PLACENORMAL,
        PLACEGRANDE,
        CORPSMORT,
    };
private :
    int _idPlace;
    float _tailleMax;
    TYPEPLACE _typePlace;
    bool _prise;
    bool _suplemmentElectricite;
    bool _suplementEau;
public :
    Place();
    Place(int id, float tailleMax, TYPEPLACE typePlace);
    virtual ~Place();

    int getIdPlace() const;

    bool isPrise() const;
    void setPrise(bool prise);
    bool isSuplemmentElectricite() const;
    void setSuplemmentElectricite(bool suplemmentElectricite);
    bool isSuplementEau() const;
    void setSuplementEau(bool suplementEau);
    void affichePlaces() const;
    void affichePlaceNormale() const;
    void affichePlaceGrande() const;
    void afficheCoprsMort() const;

};


#endif //CODE_PLACE_H
