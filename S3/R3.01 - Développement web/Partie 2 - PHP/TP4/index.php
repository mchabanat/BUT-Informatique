<?php
    $user = "roose";
    $mdp = "roose";

    $bdd = "roose";
    $host= "lakartxela.iutbayonne.univ-pau.fr";

    $link=mysqli_connect($host,$user,$mdp,$bdd) or die( "Impossible de se connecter à la base de données");

    $nomtable="bourse";

    $query = "SELECT ville,SUM(indice) as indice FROM $nomtable GROUP BY ville";
    $result= mysqli_query($link,$query);

    if (mysqli_connect_errno()) {
        echo "Failed to connect to MySQL: " . mysqli_connect_error();
        exit();
    }
       
    

    $link->close();

    // Génération de l'image
    header("Content-type: image/jpeg");

    $taille=500;

    $idImg=ImageCreate($taille, $taille);

    ImageColorAllocate($idImg,0,0,0);

    $blanc=ImageColorAllocate($idImg,255,255,255);
    

    $x=10;
    $y=$taille;
    $largeur=25;
    $ratio=5;
    $i = 0;

    while ($donnees=mysqli_fetch_assoc($result)) {
        $color=ImageColorAllocate($idImg,random_int(0,255),random_int(0,255),random_int(0,255));

        $nomVille=$donnees["ville"];
        $valIndice=$donnees["indice"];

        $indiceCourant=$valIndice[i];
        $hauteurBarre=$indiceCourant*$ratio;


        imagefilledrectangle($idImg, $x, $y, $x+$largeur, $taille-100, $color);
        imageString($idImg, 5, $x, $y, "$nomVille - $valIndice", $blanc);

        // Dessiner la prochaine barre plus loin
        $x+=50;
        $i++;
    }
    
    
    //Return l'image pour l'afficher
    ImageJpeg($idImg);

    // Destruction de l'image
    ImageDestroy($idImg);
       
?>