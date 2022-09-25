/**
 * @file Individu.h
 * @brief
 * @author Lopist�guy
 * @version 0.1
 * @date jj/mm/aaa
 */

#ifndef INDIVIDU_H
#define INDIVIDU_H

#include <iostream>
using namespace std;

/*** Individu ***/
class Individu {
    /// ATTRIBUTS : nom, prenom
    public:    // -non-
    protected: // -non-
    private:
        string nom;
        string prenom;

    /// METHODES
    public:
        // CONSTRUCTEUR
        Individu(string nom="", string prenom="");

        // DESTRUCTEUR          /** Parce qu'il il existe une m�thode sp�cialis�e **/
        virtual ~Individu();    /// cf.    virtual string toString()
                                /// le destructeur DOIT aussi �tre: virtual
        // ENCAPSULATION : nom, prenom
        string getNom() { return nom; }
        void setNom(string val) { nom = val; }

        string getPrenom() { return prenom; }
        void setPrenom(string val) { prenom = val; }

        // METHODES USUELLES : toString
        virtual string toString();    // m�thodes sp�cialis�e, donc : virtual

        // METHODES SPECIFIQUES : -non-
};

#endif // INDIVIDU_H
