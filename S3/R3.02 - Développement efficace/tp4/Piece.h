#ifndef PIECE_H
#define PIECE_H

#include <iostream>
using namespace std;

class Piece {
public:
    string reference;
    string libelle;
    int prix;
    int poids;

    Piece(string,string,int,int);

    int getPrix();
    void setPrix(int);

    int getPoids();
    void setPoids(int);

    string toString();
};

#endif