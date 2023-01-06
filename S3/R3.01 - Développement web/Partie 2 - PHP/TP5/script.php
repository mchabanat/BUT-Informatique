<?php
    // Ouverture du fichier config.ini
    $iniName = "config.ini";
    $contenuFic = [];

    $monFic = fopen($iniName,"r");

    while (!feof($monFic)){
        $ligne = fgets($monFic,255);
        array_push($contenuFic,trim($ligne));
    }
    fclose($monFic);

    $cases = [];
    
    for($i = 0;$i < count($contenuFic);$i++) {
        switch($contenuFic[$i]){
            case "[NOMFIC]": $newFileName = $contenuFic[$i+1]; break;
            case "[NB]": $nbChamps = $contenuFic[$i+1]; break;
            case "[NOMS]": 
                for($j = $i+1;$j<=$i + $nbChamps;$j++) {
                    array_push($cases,$contenuFic[$j]);
                }
                break;
            default: break;
        }
    }

    //Création du nouveau fichier html a générer
    
    $ficHtml = fopen("$newFileName.html","w");

    fputs($ficHtml,"<!DOCTYPE html><head><title>$newFileName</title></head><body>");
    fputs($ficHtml,"<form action=\"form.php\"method=\"post\">");

    for($i = 0;$i < count($cases);$i++) {
        $id = $cases[$i];
        $ligne="<label for=\"$id\">Entrez votre $id : </label> <input type=\"text\" name=\"$id\" placeholder=\"$id\"> <br>";
        fputs($ficHtml,$ligne);
    }

    fputs($ficHtml,"<input type=\"submit\" value=\"OK\">");
    fputs($ficHtml,"</body></html>");

    fclose($ficHtml);

    

    
?>