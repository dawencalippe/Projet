//
// Created by 33629 on 26/03/2020.
//

#ifndef CODE_BATEAU_H
#define CODE_BATEAU_H


class Bateau {
public:
    enum TYPEBATEAU{
        VOILIER_1,
        VOILIER_2,
        VOILIER_NH
    };
private:
    int _taille;
    int _nbCabines;
    char * _nom;
    int _currentPlace;
    TYPEBATEAU _typeBateau;
public :
    Bateau();
    Bateau(int taille, int nbCabines, char * nom, TYPEBATEAU typeBateau);
    virtual ~Bateau();
    int getTaille() const;

    void setTaille(int taille);
    int getNbCabines() const;
    void setNbCabines(int nbCabines);
    char *getNom() const;
    void setNom(char *nom);
    int getCurrentPlace() const;
    void setCurrentPlace(int currentPlace);
    TYPEBATEAU getTypeBateau() const;
    void setTypeBateau(TYPEBATEAU typeBateau);
    void affiche() const;
};


#endif //CODE_BATEAU_H
