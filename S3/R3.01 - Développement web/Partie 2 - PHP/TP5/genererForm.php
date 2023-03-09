<?php
//Lecture du fichier
$monFichier = fopen("config.ini", 'r');
$monTab = [];

while (!feof($monFichier)) {
    $ligne = fgets($monFichier, 255);
   array_push($monTab, $ligne);
   }

//Récupération des information principal
for($i = 0; $i<count($monTab);$i++){
    if(trim($monTab[$i]) == "[NOMFIC]"){
        $nomFichier = trim($monTab[$i+1]);
    }

    elseif(trim($monTab[$i]) == "[NB]"){
        $nombreQuestion = intval(trim($monTab[$i+1]));
    }

    elseif(trim($monTab[$i]) == "[NOMS]"){
        $indexQuestion =$i+1;
    }
}

//Récupération des questions
$tabQuestion = [];
for($i=$indexQuestion; $i<$indexQuestion + $nombreQuestion;$i++){
    array_push($tabQuestion, $monTab[$i]);
}

print("Nom du fichier = $nomFichier / Nombre de questions : $nombreQuestion");
print_r($tabQuestion);

//Génération de code

//PHP
$fichierPHP = fopen("$nomFichier.php", "w+");
fputs($fichierPHP,'<?php');
for($i=0;$i<count($tabQuestion);$i++){
    //Génération PHP
}

//HTML
$fichierGenere = fopen("$nomFichier.html", "w+");
//Entête de la page
fputs($fichierGenere, "<!DOCTYPE html><html lang=en><head><title>$nomFichier</title></head><body>");

//Corps de la page Formulaire
fputs($fichierGenere, "<form action='$nomFichier.php' method='post'>\n");

for($i=0;$i<count($tabQuestion);$i++){
    fputs($fichierGenere, "<label for='$tabQuestion[$i]'>$tabQuestion[$i]</label>");
    fputs($fichierGenere, "<input type='text' name='$tabQuestion[$i]' placeholder='$tabQuestion[$i]'/> </br>");
}
fputs($fichierGenere, "<input type='submit'>");
fputs($fichierGenere, "</form></body></html>\n");

?>