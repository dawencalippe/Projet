//
// Created by 33629 on 28/03/2020.
//

#ifndef CODE_PLACE_H
#define CODE_PLACE_H

#include <c++/4.8.3/iostream>
#include "Bateau.h"

class Place {
public:
    enum TYPEPLACE{
        PLACENORMAL,
        PLACEGRANDE,
        CORPSMORT,
        INCONNU,
    };
    inline static const char * ToString(TYPEPLACE v)  {
        switch (v)
        {
            case PLACENORMAL:   return "PLACENORMAL";
            case PLACEGRANDE:   return "PLACEGRANDE";
            case CORPSMORT: return "CORPSMORT";
            default:      return "[TYPE_PLACE inconnu]";
        }
    }
    inline static const TYPEPLACE ToType(int v)  {
        switch (v)
        {
            case 0:   return TYPEPLACE::PLACENORMAL;
            case 1:   return TYPEPLACE::PLACEGRANDE;
            case 2: return TYPEPLACE::CORPSMORT;
            default:      return TYPEPLACE::INCONNU;
        }
    }

private :
    int _idPlace;
    float _tailleMax;
    TYPEPLACE _typePlace;
    bool _prise;
    bool _suplemmentElectricite;
    bool _suplementEau;
public :
    static int current_id;
    Place();
    Place(float tailleMax, TYPEPLACE typePlace);
    Place(int id, float tailleMax, TYPEPLACE typePlace, bool prise, bool suplemmentElectricite, bool suplemmentEau);
    virtual ~Place();
    int getIdPlace() const;
    bool isPrise() const;
    void setPrise(bool prise);
    bool isSuplemmentElectricite() const;
    void setSuplemmentElectricite(bool suplemmentElectricite);
    bool isSuplementEau() const;
    void setSuplementEau(bool suplementEau);
    void affichePlace() const;
    void affichePlaceNormale() const;
    void affichePlaceGrande() const;
    void afficheCoprsMort() const;
    float getTailleMax() const;
    void setTailleMax(float tailleMax);
    TYPEPLACE getTypePlace() const;
    void setTypePlace(TYPEPLACE typePlace);
};


#endif //CODE_PLACE_H
