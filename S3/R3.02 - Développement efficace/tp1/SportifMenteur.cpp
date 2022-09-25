#include "SportifMenteur.h"

// Constructeurs
SportifMenteur::SportifMenteur(std::string nom,std::string prenom,int anneeNaiss,std::string tuteur) :
    Sportif(nom,prenom,anneeNaiss) 
{
    this->setTuteur(tuteur);
}

// Methodes usuelles
std::string SportifMenteur::toString() { // spécialise toString()
    std::string message;
    // invoque le toString() de la super-classe Sportif
    message = this -> Sportif::toString();
    message += "  -  tuteur : " + getTuteur();  // complète le code
    return message;
}

// Methodes spécifiques
short int SportifMenteur::getAge() { // spécialise getAge()
    short int age;
    // invoque le getAge() de la super-classe Sportif
    age = this->Sportif::getAge(); // obtient l'age réel
    return (age<18 ? 18 : age);
}