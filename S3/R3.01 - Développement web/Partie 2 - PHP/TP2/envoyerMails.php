<?php
    $fic = fopen("envoyerMails.php","r");
    // Faire la moyenne d'age des donateurs
    $remerciement = "Merci pour votre don jeune entrepreneur !";

    while(!feof($fic)) {
        $ligne = fgets($fic,255);
        $uneLigne = explode(" | ",$ligne);
        
        $nom = $uneLigne[0];
        $age = $uneLigne[1];
        $mail = $uneLigne[2];
        $don = $uneLigne[3];

        $recap = "Voici un recap de votre don \n Nom : $nom,\n Age : $age,|n Valeur du don : $don";

        


        $message = "$remerciement\n $recap\n ";
        mail($mail,"Récapitulatif de votre don",$message);
    } 
    fclose($fic);
?>