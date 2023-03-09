<?php 
//On démarre la session
session_start();
//On verifie qu'une session est active
if(!isset($_SESSION['user'])){
    header('location: connexion.php');
    exit;
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Bourse d'Anglet</title>
</head>
<body>
    <h1>Bourse d'Anglet</h1>
    <img alt="Histogramme" src="histoGenerate.php"/>
    <a href="deconnexion.php">Déconnexion</a>
</body>
</html>