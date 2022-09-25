#include "Sportif.h"

// Constructeur
Sportif::Sportif(std::string nom,std::string prenom,int anneeNaiss) {
    this->setNom(nom);
    this->setPrenom(prenom);
    this->setAnneeNaiss(anneeNaiss);
}

// Destructeur
Sportif::~Sportif() {
    std::cout << "Sportif " << this->toString() << " ... meurt !!!!\n";
}	

// Methodes usuelles
std::string Sportif::toString() {
    std::string message;
    message = getNom() + " " + getPrenom();
    return message; 
}

// Methodes spécifiques
short int Sportif::getAge() {
    return (Outils::anneeActuelle()-getAnneeNaiss());
}