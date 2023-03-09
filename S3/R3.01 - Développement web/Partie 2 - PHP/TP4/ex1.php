<?php
try{
    $bdd = new PDO('mysql:host=lakartxela.iutbayonne.univ-pau.fr;dbname=roose;charset=utf8', 'roose', 'roose');
}catch(Exception $e){
    die('Erreur'.$e->getMessage());
}

$req = "SELECT ville, SUM(indice) as indice FROM bourse GROUP BY ville";
$req = $bdd->prepare($req);
$req->execute();
$res = $req->fetchAll();
for($i=0;$i<count($res);$i++){
    $ville = $res[$i]['ville'];
    $indice = $res[$i]['indice'];
    echo "Nom de la ville : $ville, indice de la ville : $indice </br>";
}

$bdd = null;
?>