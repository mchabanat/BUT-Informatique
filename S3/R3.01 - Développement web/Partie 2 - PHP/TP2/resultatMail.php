<?php
//Création du template
$template = "Merci pour votre don ! \n Voici votre récapitulatif de don :";

//Ouverture Fichier
$fichier = fopen("resultats.txt");

//Boucle
while (!feof($fichier)){
    $ligne = fgets($fichier);
    $tab = explode('|', $ligne);
    $mail = "$template\n Nom : $tab[0]\n Age : $tab[1]\n Mail : $tab[2]\n Montant du don : $tab[3]€\n";
    mail($tab[2], "Récapitulatif don à Arthur", $mail);
}
?>