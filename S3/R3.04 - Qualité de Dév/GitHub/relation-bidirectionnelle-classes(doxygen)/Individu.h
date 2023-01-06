/**
 * @file Individu.h
 * @author Lopistéguy
 * @brief Spécifie une classe Individu en relation réciproque avec sa Voiture
 * @details Au dela de représenter une personne par son nom et son prénom, la classe Individu
 * permet également de renseigner la voiture qu'il conduit.
 * 
 * La voiture associée à l'individu est représentée par un pointeur vers un objet de la classe Voiture.
 * @version 0.1
 * @date 12/08/2022
 * @warning A un Individu correspond au plus une Voiture
 */


/*
  Spécifie une classe Individu en relation réciproque avec sa Voiture
  Auteur : Lopistéguy
  Version : 0.1
  Date : 12/08/2022
*/

#ifndef INDIVIDU_H
#define INDIVIDU_H

using namespace std;

#include "Voiture.h" // Utilisée ci-dessous
#include <iostream>

class Voiture; /* Annonce une définition ultérieure de Voiture
                   permet de faire référence aux membres de Voiture dans la classe Individu */



/**
 * @brief Représente un Individu via son nom, son prénom et sa Voiture
 * @deprecated Utiliser à la place la classe Personne qui est plus récente
 * 
 */
class Individu
{
    // ATTRIBUTS
  public:
    /**
     * @brief Le nom de l'Individu
     */
    string nom;         // Le nom de l'individu

    /**
     * @brief Le prénom de l'Individu
     */
    string prenom;      // Le prénom de l'individu

    /**
     * @brief Lien avec la voiture de l'individu
     */
    Voiture *maVoiture; // Lien avec la voiture de l'individu

    // MÉTHODES
  public:
    /**
     * @brief Construit un nouvel objet Individu à partir de son nom et prénom.
     */
    Individu(string = "", string = "");

    /**
     * @brief Détruit un objet Individu
     */
    ~Individu();

    // Méthodes usuelles : toString

    /**
     * @brief Retourne l'identité de l'individu
     * 
     * @return une chaine de caractères sous la forme "nom prénom"
     * @bug Problème de formatage : deux espaces entre le nom et le prénom
     * @todo Ajouter un paramètre pour préciser si on veut un affichage du type nom-prénom ou prénom-nom
     */
    string toString();        // Affiche l'identité de l'individu
    string toStringAndLink(); // Affiche l'identité de l'individu et de sa voiture s'il en a une

    // Méthodes spécifiques
    void majMaVoiture(Voiture* voiture);

    /**
     * @brief Définit la voiture de l'individu
     * 
     * @param pointeur vers l'objet Voiture piloté par l'Individu 
     */
    void setMaVoiture(Voiture* voiture);
    void supprimerLien();
};

#endif // INDIVIDU_H