<?php

//Base de données
try{
    $bdd = new PDO('mysql:host=lakartxela.iutbayonne.univ-pau.fr;dbname=roose;charset=utf8', 'roose', 'roose');
}catch(Exception $e){
    die('Erreur'.$e->getMessage());
}

$req = "SELECT ville, SUM(indice) as indice FROM bourse GROUP BY ville";
$req = $bdd->prepare($req);
$req->execute();
$res = $req->fetchAll();


$bdd = null;

//Renseignement du type de l'image
header("Content-type: image/jpeg");
//Création de l'image
$taille = 600;
$image = ImageCreate($taille, $taille);

//Couleur de fond
$bg = ImageColorAllocate($image, 26, 26, 26);

//Element
$ecart = 70;
$x = 0;
$tailleBarre = 20;
$ratio = 3 ;
$white = imagecolorallocate($image, 255, 255, 255);
for($i=0;$i<count($res);$i++){
    $ville = $res[$i]['ville'];
    $indice = $res[$i]['indice'];
    imagestring($image, 5, 10, $x, "$ville - $indice", $white);
    $col = imagecolorallocate($image, random_int(0, 255), random_int(0, 255), random_int(0,255));
    imagefilledrectangle($image, $x+$tailleBarre/2, $taille, $x+$tailleBarre*2 , $taille - $indice*$ratio, $col);
    $x += $ecart;
}


//Return l'image
ImageJpeg($image);  

//Destruction de l'image
ImageDestroy($image);
?>