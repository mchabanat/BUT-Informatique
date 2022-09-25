#ifndef SPORTIFMENTEUR_H
#define SPORTIFMENTEUR_H
#include <Sportif.h>


class SportifMenteur : public Sportif
{
private: 
    std::string tuteur;
public:
    // Constructeurs
    SportifMenteur(std::string,std::string,int,std::string);

    // Destructeur
    //~SportifMenteur();

    // Encapsulation (get&set)
    std::string getTuteur() { return tuteur; }

    void setTuteur(std::string t) { tuteur = t; }
    
    // Methodes usuelles
    std::string toString();

    // Methodes spécifiques
    short int getAge();
    
protected: // -non-

};

#endif
