#ifndef SOUSPROGRAMMES_H
#define SOUSPROGRAMMES_H
#include <iostream>

using namespace std;

void calculMoyenneSimple (string nomSysPluvio);
/*
Etant donné un fichier de nombres entiers (hauteurs pluviométriques, en mm), éventuellement vide,
mais NON corrompu, et dont le nom système nomSystemeFournis est fourni en paramètre,
Affichage à l'écran de la moyenne des hauteurs pluviométriques contenues dans le fichier.
*/

void calculMoyenneOuArretEcran (string nomSysPluvio);
/*
Etant donné un fichier de nombres entiers (hauteurs pluviométriques, en mm), éventuellement vide,
éventuellement corrompu, et dont le nom système nomSystemeFournis est fourni en paramètre.
Le programme affiche à l'écran, lorsque le fichier est correct, le nombre de hauteurs pluviométriques contenues dans le fichier et, lorsque cela est possible, leur moyenne.
Lorsque le fichier est corrompu, le programme s'arrête après avoir affiché la raison du non calcul 
(notamment, problème rencontré, endroit dans le fichier où il a été rencontré).
*/


void calculMoyenneOuArretLog (string nomSysPluvio);
/*
Etant donné un fichier de nombres entiers (hauteurs pluviométriques, en mm), éventuellement vide,
éventuellement corrompu, et dont le nom système nomSystemeFournis est fourni en paramètre,
crée un fichier texte, dont le nom système sera fabriqué à partir du nom système du
fichier de relevés pluviométriques, contenant les informations sur le déroulement
du programme, à savoir :
Quand cela est possible, le nombre de hauteurs pluviométriques contenues dans le fichier donné ainsi que leur moyenne.
Quand cela n'est pas possible (fichier corrompu), le programme s'arrête après avoir inscrit dans le rapport la raison du non calcul 
(notamment, problème rencontré, endroit dans le fichier où il a été rencontré)
Le nom système du fichier créé est fabriqué par concaténation de la chaîne _rapportExecution_ suivie du nom système du fichier de données.

*/

/*
Types de problèmes rencontrés :

pbOuverture : problème d'OUVERTURE du fichier des hauteurs pluviométriques. 
Correspond aux exceptions suivantes :
--- erreurDeStatut si le fichier est deja ouvert,  
--- erreurDeNomOuUsage : 
    ...le nom est illegal ou le fichier inexistant," << endl;
    ...OU les protections du fichiers rendent l'operation illegale

pbLecture : problème de LECTURE dans le fichier
Correspond aux exceptions suivantes : 
--- erreurDeMode si le mode d'ouverture interdit la lecture, 
--- erreurInconnue si la lecture s'est mal deroulee,
    ...type d'une valeur non attendu,
    ...OU fichier corrompu

pbLectureEtFermeture : problème de LECTURE et FERMETURE du fichier.
Corresopnd aux exceptions suivantes :
--- erreurDeMode si le mode d'ouverture interdit la lecture,
--- erreurInconnue si la lecture s'est mal deroulee,
    ...type d'une valeur non attendu,
    ...OU fichier corrompu

pb de Fermeture : problème de FERMETURE du fichier
Correspond aux exceptions suivantes :
--- erreurDeStatut si le fichier n'est pas ouvert, 
--- erreurInconnue si la fermeture n'a pu se faire (fichier corrompu...)
*/

#endif


