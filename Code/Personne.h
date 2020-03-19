//
// Created by dawen on 18/03/2020.
//

#ifndef CODE_PERSONNE_H
#define CODE_PERSONNE_H


class Personne {

protected:
    char* _prenom;
    char* _nom;
    int _age;
public:
    char *getPrenom() const;

    void setPrenom(char *prenom);

    char *getNom() const;

    void setNom(char *nom);

    int getAge() const;

    void setAge(int age);
    //Constructeur
    Personne();
    Personne(char* nomPersonne, char* prenomPersonne, int agePersonne);
    //Destructeur
    ~Personne();

    virtual void affiche() const;
};


#endif //CODE_PERSONNE_H
