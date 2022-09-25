#include "Individu.h"

Individu::Individu(string nom,string prenom) {
    this->setNom(nom);
    this->setPrenom(prenom);
}

string Individu::to_string() {
    string message;
    message = "Nom (" + getNom() + ")";
    message = "Prenom (" + getPrenom() + ")";
    return message;
}

void Individu::setVoiture(Voiture* voit) {
    this->voiture=voit;
}

Voiture *Individu::getVoiture() {
    return this->voiture;
}