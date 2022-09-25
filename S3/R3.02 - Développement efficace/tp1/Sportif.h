#ifndef SPORTIF_H
#define SPORTIF_H
#include <iostream>
#include <string>
#include "Outils.h"

class Sportif 
{
private: 
    std::string nom;
    std::string prenom;
    int anneeNaissance;
public:
    // Constructeur
    Sportif(std::string,std::string,int);

    // Destructeur
    virtual ~Sportif();	

    // Encapsulation (get&set)
    std::string getNom() { return nom; }
    std::string getPrenom() { return prenom; }
    int getAnneeNaiss() { return anneeNaissance; }

    void setNom(std::string nvNom) { nom = nvNom; }
    void setPrenom(std::string nvPrenom) { prenom = nvPrenom; }
    void setAnneeNaiss(int nvAnneeNaiss) { anneeNaissance = nvAnneeNaiss; }

    // Methodes usuelles
    virtual std::string toString();

    // Methodes spécifiques
    virtual short int getAge();
protected: // -non-

};

#endif
