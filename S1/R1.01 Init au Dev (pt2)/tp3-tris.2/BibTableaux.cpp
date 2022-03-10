/**  CORPS MODULE BibTableaux
     ------------------------ */

/* Inclusions
   ---------- */
#include "BibTableaux.h"

/* Types - Variables - Constantes propres au corps
*/

/* Déclarations des sous-programmes utilisés dans ce corps 
*/
void echanger(int& nb1, int& nb2);
/* BUT : Echange le contenu de nb1 et nb2 */

void echanger(Personne& pers1, Personne& pers2);
/* BUT : Echange le contenu de pers1 et pers2 */

void faireMonterLaBulleIci(int tab[],unsigned int bDeb,unsigned int ici);
/* BUT : sous programme du triBulle qui nous permet de trier le tableau tab en faisant
         remonter le plus grand element de l'intervalle [bDeb,ici] à l'indice ici par echanges
         successifs
   Préconditions : ici < lgTab */

void faireMonterLaBulleIci(Personne tab[],unsigned int bDeb,unsigned int ici);
/* BUT : sous programme du triBulle qui nous permet de trier le tableau tab en faisant
         remonter le plus grand element de l'intervalle [bDeb,ici] à l'indice ici par echanges
         successifs
   Préconditions : ici < lgTab */

unsigned int saPlace(const int tab[], unsigned int ici);
// BUT : trouver la place que devrait avoir une valeur pour que le tableau 
//       soit trié croissant (sous programme pour le tri par insertion)

void faireDeLaPlace(int tab[], unsigned int bDeb, unsigned int ici);
// BUT : décaler les valeurs du tableau pour y faire entrer la valeur cherchée

void insertion (int tab[], unsigned int bDeb, unsigned int ici);
// BUT :

/* Corps des sous-programmes déclarés dans l'interface bibTableau.h
*/
// Observateurs
/*
bool estTrieCroissant(const int tab[], unsigned short int lgTab)
{
    return true; // POUR COMPILER
}

bool estTrieDecroissant(const int tab[], unsigned short int lgTab)
{
    return true; // POUR COMPILER
}
*/

// Accesseurs

// Opérateurs binaires

// Opérateurs de comparaison

// Autres primitives

// Primitives d'Entrée / Sortie
void afficher(const int tab[],
              unsigned short int lgTab)
{
    if (lgTab > 0)
    {
        cout << "{";
        for (unsigned short int i = 0; i < lgTab - 1; i++)
        {
            cout << tab[i] << ", ";
        };
        cout << tab[lgTab - 1] << "} " << endl;
    }
    else
    {
        cout << "tableau vide " << endl;
    }
}

void afficher (const Personne tab[],
               unsigned short int lgTab)
{
    if (lgTab > 0)
    {
        cout << "{" << endl;
        for (unsigned short int i = 0; i<lgTab-1; i++)
        {
            afficher(tab[i]) ;
            cout << ", "<< endl ;
        };
        afficher (tab[lgTab-1]);
        cout << endl <<  "} "<< endl;
    }
    else
    {
        cout << "tableau vide " << endl;
    }
}

// Recherches
void recherchePremiereOccDichoEntier(const int tab[],
                                     unsigned int lgTab,
                                     int val,
                                     unsigned int &pos,
                                     unsigned int &nbTour,
                                     bool &trouve)
{
    // VARIABLES
    unsigned int borneInf;
    unsigned int borneSup;
    unsigned int milieu;

    // INITIALISATION
    borneInf = 0;
    borneSup = lgTab - 1;
    trouve = false;
    nbTour = 1;

    // RECHERCHE
    while (borneInf <= borneSup)
    {
        // On verifie si la valeur est plus grande / petite que les valeurs du tableau
        // pour éviter de faire tourner le programme en boucle infini
        if (val > tab[borneInf] || val < tab[borneSup])
        {
            break;
        }

        milieu = (borneInf + borneSup) / 2;

        if (tab[milieu] == val)
        {
            nbTour++;

            trouve = true;
            pos = milieu;
            break;
        }
        else if (tab[milieu] < val)
        {
            borneSup = milieu - 1;
        }
        else
        {
            borneInf = milieu + 1;
        }

        nbTour++;
    }
}

void recherchePremiereOccDichoPersonne(const Personne tab[],
                                       unsigned int lgTab,
                                       Personne personneRecherchee,
                                       unsigned int &pos,
                                       bool &trouve)
{
    // VARIABLES
    unsigned int borneInf;
    unsigned int borneSup;
    unsigned int milieu;

    // INITIALISATION
    borneInf = 0;
    borneSup = lgTab - 1;
    trouve = false;

    // RECHERCHE
    while (borneInf <= borneSup)
    {
        // On verifie si la valeur est plus grande / petite que les valeurs du tableau
        // pour éviter de faire tourner le programme en boucle infini
        if (personneRecherchee.nom > tab[borneInf].nom || personneRecherchee.nom < tab[borneSup].nom)
        {
            break;
        }

        milieu = (borneInf + borneSup) / 2;

        if (tab[milieu].nom == personneRecherchee.nom)
        {
            trouve = true;
            pos = milieu;
            break;
        }
        else if (tab[milieu].nom < personneRecherchee.nom)
        {
            borneSup = milieu - 1;
        }
        else
        {
            borneInf = milieu + 1;
        }
    }
}

void determinerPremierDernier(const int tab[],
                              unsigned int lgTab,
                              int val,
                              unsigned int &posPremier,
                              unsigned int &posDernier,
                              bool &trouve)

{

}

// Tris
void triBulle(int tab[], unsigned int lgTab)
{
    // VARIABLES
    unsigned int ici;
    unsigned int bDeb;
    unsigned int i;

    // INITIALISATION
    ici = lgTab - 1;
    bDeb = 0;

    // TRAITEMENTS
    for(i = lgTab - 1 ; i >= bDeb + 1 ; i--)
    {
        faireMonterLaBulleIci(tab,bDeb,ici);
    }
}

void triBulle(Personne tab[], unsigned int lgTab)
{
    // VARIABLES
    unsigned int ici;
    unsigned int bDeb;
    unsigned int i;

    // INITIALISATION
    ici = lgTab - 1;
    bDeb = 0;

    // TRAITEMENTS
    for(i = lgTab - 1 ; i >= bDeb + 1 ; i--)
    {
        faireMonterLaBulleIci(tab,bDeb,ici);
    }
}

void triParInsertion(int tab[], unsigned int lgTab)
{
    
}


/* Corps des sous-programmes déclarés dans ce corps
*/
void echanger(int& nb1, int& nb2)
{
    // VARIABLES
    int copieNb1;

    // Réalisation de l'échange
    copieNb1 = nb1;
    nb1 = nb2;
    nb2 = copieNb1;
}

void echanger(Personne& pers1, Personne& pers2)
{
    // VARIABLES
    Personne copiePers1;

    // Réalisation de l'échange
    copiePers1 = pers1;
    pers1 = pers2;
    pers2 = copiePers1;
}

void faireMonterLaBulleIci(int tab[],unsigned int bDeb,unsigned int ici)
{
    for (unsigned int i = bDeb ; i <= ici-1 ; i++)
    {
        if (tab[i] > tab[i+1])
        {
            echanger(tab[i],tab[i+1]);
        }
    }
}

void faireMonterLaBulleIci(Personne tab[],unsigned int bDeb,unsigned int ici)
{
    for (unsigned int i = bDeb ; i <= ici-1 ; i++)
    {
        if (tab[i].nom > tab[i+1].nom)
        {
            echanger(tab[i],tab[i+1]);
        }
    }
}

unsigned int saPlace(const int tab[], unsigned int ici)
{
    // INITIALISATION
    unsigned int posCourante = ici - 1;
    unsigned int saPlace = 0;

    // TRAITEMENTS
    while (posCourante > 0)
    {
        if(tab[posCourante] < tab[ici])
        {
            saPlace = posCourante + 1;
            break;
        }

        posCourante++;
    }

    return saPlace;
}

void faireDeLaPlace(int tab[], unsigned int bDeb, unsigned int ici)
{
    // INITIALISATION
    int copieValeurIci;
    unsigned int i;
    unsigned int indiceDebDecalage = saPlace(tab,ici);

    // TRAITEMENTS
    copieValeurIci = tab[ici];

    for (i = ici; i >= indiceDebDecalage+1 ; i--)
    {
        tab[i] = tab[i-1];
    }
}

void insertion (int tab[], unsigned int bDeb, unsigned int ici)
{
    
}