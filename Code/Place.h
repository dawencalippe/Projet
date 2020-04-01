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
    Place(int id, float tailleMax, TYPEPLACE typePlace);
    virtual ~Place();
};


#endif //CODE_PLACE_H
