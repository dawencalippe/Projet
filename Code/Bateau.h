#ifndef CODE_BATEAU_H
#define CODE_BATEAU_H

#include <string>

class Bateau {
public:
    enum TYPEBATEAU{
        VOILIER_1,
        VOILIER_2,
        VOILIER_NH,
        INCONNU
    };
    inline static const char * ToString(TYPEBATEAU v)  {
        switch (v)
        {
            case VOILIER_1:   return "VOILIER_T1";
            case VOILIER_2:   return "VOILIER_T2";
            case VOILIER_NH: return "VOILIER_NH";
            default:      return "[TYPE_BATEAU inconnu]";
        }
    }
    inline static const TYPEBATEAU ToType(int v)  {
        switch (v)
        {
            case 0:   return TYPEBATEAU::VOILIER_1;
            case 1:   return TYPEBATEAU::VOILIER_2;
            case 2: return TYPEBATEAU::VOILIER_NH;
            default:      return TYPEBATEAU::VOILIER_1;
        }
    }
private:
    int _taille;
    int _nbCabines;
    char * _nom;
    int _currentPlace;
    TYPEBATEAU _typeBateau;

public :
    Bateau();
    Bateau(int taille, int nbCabines, char * nom, TYPEBATEAU typeBateau);
    Bateau(int taille, int nbCabines, char * nom, TYPEBATEAU typeBateau, int currentPlace);
    virtual ~Bateau();
    int getTaille() const;
    int getNbCabines() const;
    char * getNom() const;
    int getCurrentPlace() const;
    void setCurrentPlace(int currentPlace);
    TYPEBATEAU getTypeBateau() const;
    void affiche() const;
};
#endif //CODE_BATEAU_H
