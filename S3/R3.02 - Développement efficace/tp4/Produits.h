#ifndef PRODUITS_H
#define PRODUITS_H

#include <iostream>
using namespace std;

class Produits {
public:
    string reference;
    string libelle;
    int prix;

    Produits(string,string,int);

    string toString();
};

#endif