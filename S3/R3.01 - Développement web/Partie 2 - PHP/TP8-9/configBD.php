<?php 

$bdd= "mchabanat_bd"; // Base de données
$host= "lakartxela.iutbayonne.univ-pau.fr";
$user= "mchabanat_bd";  // Utilisateur 
$pass= "mchabanat_bd"; // mp 

function getConnection() {
    global $host, $user, $pass, $bdd;
    $link=mysqli_connect($host,$user,$pass,$bdd) or die("Impossible de se connecter à la base de données");
    return $link;
}

?>