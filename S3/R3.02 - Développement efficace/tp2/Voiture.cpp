#include "Voiture.h"

Voiture::Voiture(string marque,string plaque) {
    this->setMarque(marque);
    this->setPlaque(plaque);

    
}

string Voiture::to_string() {
    string message;
    message = "Marque (" + getMarque() + ")";
    message = "Plaque (" + getPlaque() + ")";
    return message;
}

void Voiture::setIndividu(Individu* indiv) {
    this->pilote=indiv;
}

Individu* Voiture::getIndividu() {
    return this->pilote;
}