<?php 
//Récupération du POST
$name = $_POST["nom"];
$age = $_POST["age"];
$mail = $_POST["mail"];
$don = $_POST["don"];

//Ecriture dans le fichier
$ligne = "$name|$age|$mail|$don\n";
$fichier = fopen("resultats.txt", "a");
fputs($fichier, $ligne);
header("Location: form.php?success=true&name=$name&age=$age&mail=$mail&don=$don");
?>