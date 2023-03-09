<?php 
$fichierCompteur = fopen("compteur.txt", "r+");
$compteur = fgets($fichierCompteur, 255);
$compteur += 1;
fseek($fichierCompteur, 0);
//rewind($fichierCompteur);
fwrite($fichierCompteur, $compteur);
fclose($fichierCompteur);
print($compteur);
?>