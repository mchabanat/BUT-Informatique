/*
 Programme : 
 But : 
 Date de dernière modification : 
 Auteur : Chabanat M
 Remarques : ca fonctionne 
*/

#include <iostream>
using namespace std;



//Type 
struct UnEtudiant
{
    string nom;
    string prenom;
    float note;
};

// Declaration
 void calculerNbEtudiantMoyenne(const UnEtudiant tab[], unsigned int nbCases,unsigned int& compteurMoyenne,unsigned int& compteurPasMoyenne);
/* BUT : calculer le nombre d'étudiants  qui n'ont pas eu (compteurPasMoyenne) dans un controle donné ( ici tab[]). 
       Il y a nbCases étudiants qui ont passé le controle.
       Les etudiants qui ont la moyenne (compteurMoyenne) seront calulés grace a la soustraction du nbCases par le compteurPasMoyenne*/


int main (void)
{
    // VARIABLES
    // Nombre d'étudiants inscrits en semestre 1 :
    const unsigned int EFFECTIF_S1 = 15;

    // Résultats examen du 15 février :
    UnEtudiant notesExamDu15fevrier[EFFECTIF_S1] = {
    {"Almeras", "Valentin", 15}, {"Gueguen", "Lucie", 8.5},
    {"Pomeroy", "Thibault", 4.5}, {"Souchon", "Elodie", 18},
    {"Besnard", "Emmanuel", 12}, {"Gaudreau", "Lucien", 0},
    {"Duret", "Christelle", 10.5}, {"Laffitte", "Anna", 13},
    {"Barbier", "Remi", 15}, {"Blondeau", "Denise", 7},
    {"Berlioz", "Gabriel", 9.5}, {"Dupont", "Benjamin", 3},
    {"Maret", "Ludovic", 13.5}, {"Boutin", "Alain", 12},
    {"Dubuisson", "Marie", 19}};

    // Compteurs
    unsigned int nbEtudiantsMoyenne;
    unsigned int nbEtudiantsPasMoyenne;

    // TRAITEMENTS
    calculerNbEtudiantMoyenne(notesExamDu15fevrier,EFFECTIF_S1,nbEtudiantsMoyenne,nbEtudiantsPasMoyenne);
    cout << "Nombre d'etudiants ayant la moyenne au controle : " << nbEtudiantsMoyenne << endl;
    cout << "Nombre d'etudiants n ayant pas la moyenne au controle : " << nbEtudiantsPasMoyenne << endl;


    return 0;
}


// Definition
void calculerNbEtudiantMoyenne(const UnEtudiant tab[], unsigned int nbCases,unsigned int& compteurMoyenne,unsigned int& compteurPasMoyenne)
{
    // Iitialisation des compteurs a 0
    compteurMoyenne = 0;
    compteurPasMoyenne = 0;
    
    // Boucle qui calcule le nombre d'etudiants n'ayant pas la moyenne
    for (unsigned int i = 0 ; i <= nbCases -1 ; i++)
    {
        if(tab[i].note < 10)
        {
            compteurPasMoyenne++;
        }
    }

    // Recherche du nombre d'étudiants ayant la moyenne
    compteurMoyenne = nbCases - compteurPasMoyenne;
}