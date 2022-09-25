#ifndef VOITURE_H
#define VOITURE_H

#include "Individu.h"

#include <iostream>
using namespace std;

class Individu;
class Voiture {
private:
    string marque;
    string plaque;

    Individu *pilote;
public:
    Voiture(string,string);

    string getMarque() { return marque; }
    string getPlaque() { return plaque; }

    void setMarque(string nvMarque) { this->marque = nvMarque; }
    void setPlaque(string nvPlaque) { this->plaque = nvPlaque; }
    
    void setIndividu(Individu*);
    Individu* getIndividu();

    string to_string();
};

#endif