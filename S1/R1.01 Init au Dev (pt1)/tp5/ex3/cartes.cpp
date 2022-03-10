/*
 Programme : cartes
 But : determiner la carte la plus forte entre 2 cartes saisies par l'utilisateur
 Date de dernière modification : 08/10/21
 Auteur : Chabanat M
 Remarques : fonctionne
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    enum NumCarte {deux = 2, trois, quatre, cinq, six, sept, huit, neuf, dix, valet, dame, roi, as};
    enum SigneCarte {pique, coeur, carreau, trefle};

    struct UneCarte
    {
        NumCarte numero; // représente le numero d'une carte
        SigneCarte signe; // représente le signe d'une carte
    };

    bool egalite = false;

    UneCarte carte1;
    UneCarte carte2;
    UneCarte gagnante;

    int numeroCarte;
    int signeCarte;

    // TRAITEMENTS


    cout << "Premiere carte : " << endl;
    cout << "Saisissez le numero de la carte (11 pour le valet, 12 pour la dame, 13 pour le roi et 14 pour l as ) : " ;
    cin >> numeroCarte;
    cout << "Saisissez le signe de la carte (1 pour Pique, 2 pour coeur, 3 pour Carreau et 4 pour trefle) : " ;
    cin >> signeCarte;
    cout << " " << endl;
 
    switch (numeroCarte)
    {
    case 2:
        carte1.numero = deux;
        break;
    
    case 3:
        carte1.numero = trois;
        break;
    
    case 4:
        carte1.numero = quatre;
        break;
    
    case 5:
        carte1.numero = cinq;
        break;
    
    case 6:
        carte1.numero = six;
        break;
    
    case 7:
        carte1.numero = sept;
        break;
    
    case 8:
        carte1.numero = huit;
        break;
    
    case 9:
        carte1.numero = neuf;
        break;
    
    case 10:
        carte1.numero = dix;
        break;
    
    case 11:
        carte1.numero = valet;
        break;
    
    case 12:
        carte1.numero = dame;
        break;
    
    case 13:
        carte1.numero = roi;
        break;
    
    case 14:
        carte1.numero = as;
        break;
    }

    switch (signeCarte)
    {
    case 1:
        carte1.signe = pique;
        break;
    
    case 2:
        carte1.signe = coeur;
        break;
    
    case 3:
        carte1.signe = carreau;
        break;
    
    case 4:
        carte1.signe = trefle;
        break;
    }


    cout << "Deuxieme carte : " << endl;
    cout << "Saisissez le numero de la carte (11 pour le valet, 12 pour la dame, 13 pour le roi et 14 pour l as ) : " ;
    cin >> numeroCarte;
    cout << "Saisissez le signe de la carte (1 pour Pique, 2 pour coeur, 3 pour Carreau et 4 pour trefle) : " ;
    cin >> signeCarte;
    cout << " " << endl;

    switch (numeroCarte)
    {
    case 2:
        carte2.numero = deux;
        break;
    
    case 3:
        carte2.numero = trois;
        break;
    
    case 4:
        carte2.numero = quatre;
        break;
    
    case 5:
        carte2.numero = cinq;
        break;
    
    case 6:
        carte2.numero = six;
        break;
    
    case 7:
        carte2.numero = sept;
        break;
    
    case 8:
        carte2.numero = huit;
        break;
    
    case 9:
        carte2.numero = neuf;
        break;
    
    case 10:
        carte2.numero = dix;
        break;
    
    case 11:
        carte2.numero = valet;
        break;
    
    case 12:
        carte2.numero = dame;
        break;
    
    case 13:
        carte2.numero = roi;
        break;
    
    case 14:
        carte2.numero = as;
        break;
    }

    switch (signeCarte)
    {
    case 1:
        carte2.signe = pique;
        break;
    
    case 2:
        carte2.signe = coeur;
        break;
    
    case 3:
        carte2.signe = carreau;
        break;
    
    case 4:
        carte2.signe = trefle;
        break;
    }

    // Comparaison
    if (carte1.numero > carte2.numero)
    {
        gagnante = carte1;
    }
    else if (carte1.numero < carte2.numero)
    {
        gagnante = carte2;
    }
    else
    {
        egalite = true;
    }

    // AFFICHAGE du resultat
    if (egalite == true)
    {
        cout << "Les 2 cartes sont de meme force.";
    }
    else 
    {
        // Affichage du numero
        switch (gagnante.numero)
        {
        case valet:
            cout << "Valet";
            break;

        case dame:
            cout << "Dame";
            break;
        
        case roi:
            cout << "Roi";
            break;

        case as:
            cout << "As";
            break;
        
        default:
            cout << gagnante.numero;
            break;
        }

        // Affichage du signe
        switch (gagnante.signe)
        {
        case pique:
            cout << " de pique est la carte la plus forte.";
            break;
        
        case coeur:
            cout << " de coeur est la carte la plus forte.";
            break;
        
        case carreau:
            cout << " de carreau est la carte la plus forte.";
            break;
        
        case trefle:
            cout << " de trefle est la carte la plus forte.";
            break;
    
        }

    }

    return 0;
}