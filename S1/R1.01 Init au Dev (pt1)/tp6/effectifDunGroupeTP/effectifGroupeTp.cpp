/*
 Programme : 
 But : 
 Date de dernière modification : 
 Auteur : Chabanat M
 Remarques : ca fonctionne
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES 
    unsigned int i;
    unsigned short int tp;
    unsigned int compteur = 0;

    struct Etudiant
    {
        string nom;            // nom de l'étudiant
        string prenom;         // prénom de l'étudiant
        unsigned short int td; // numéro de TD de l'étudiant
        unsigned short int tp; // numéro de TP de l'étudiant
    };
    
    // Nombre d'étudiants inscrits en semestre 1
    const unsigned int EFFECTIF_S1 = 15;
    
    // Etudiants inscrits en semestre 1 :
    Etudiant etudiantsS1[EFFECTIF_S1] = {
        {"Almeras", "Valentin", 1, 1}, {"Gueguen", "Lucie", 1, 1},
        {"Pomeroy", "Thibault", 1, 1}, {"Souchon", "Elodie", 1, 2},
        {"Besnard", "Emmanuel", 1, 2}, {"Gaudreau", "Lucien", 2, 3},
        {"Duret", "Christelle", 2, 3}, {"Laffitte", "Anna", 2, 4},
        {"Barbier", "Remi", 2, 4},     {"Blondeau", "Denise", 2, 4},
        {"Berlioz", "Gabriel", 2, 4},  {"Dupont", "Benjamin", 3, 5},
        {"Maret", "Ludovic", 3, 5},    {"Boutin", "Alain", 3, 5},
        {"Dubuisson", "Marie", 3, 5}};

    // TRAITEMENTS
    // Saisie du nb TP
    cout << "Numero TP : ";  
    cin >> tp;

    // Recherche
    for (i = 0 ; i <= EFFECTIF_S1 - 1 ; i++)
    {
        if (etudiantsS1[i].tp == tp)
        {
            compteur++;
        }
    }

    cout << "Il y a " << compteur << " etudiants dans le tp " << tp;
    
    return 0;
}