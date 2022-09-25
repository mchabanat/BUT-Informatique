#ifndef INDIVIDU_H
#define INDIVIDU_H

#include "Voiture.h"

#include <iostream>
using namespace std;

class Voiture;
class Individu {
private:
    string nom;
    string prenom;

    Voiture *voiture;
public: 
    Individu(string,string);

    string getNom() { return nom; }
    string getPrenom() { return prenom; }

    void setNom(string nvNom) { nom = nvNom; }
    void setPrenom(string nvPrenom) { prenom = nvPrenom; }

    void setVoiture(Voiture*);
    Voiture* getVoiture();

    string to_string();
};

#endif
