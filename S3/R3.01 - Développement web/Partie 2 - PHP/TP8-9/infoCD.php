<?php session_start(); ?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <!-- Fonts -->
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Dosis:wght@200;300;700&display=swap" rel="stylesheet">

    <!-- Titre onglet -->
    <title>CD - Accueil</title>
</head>
<body id="flou">
    <nav>
        <a href="accueil.php"><img id="logoSite" src="images/cd.png" alt="logoSite"></a>
        <a id="boutonAjouterCD" href="ajoutCDs.php">AJOUTER DES CD</a>
        <a href="panier.php"><img id="panier" src="images/panier.png" alt="panier"></a>
    </nav>
    <article class="au-centre">
        <div id="top">
            <h1>Bienvenue sur HappyMusic !</h1>
            <h2>Tous les CDs</h2>
            <?php 
                print "</div>";

                include 'configBD.php';

                $link = getConnection();

                $nomtable = "CD";

                $idCD = $_GET['id'];

                $query="SELECT * FROM $nomtable WHERE id=$idCD";
                $result=mysqli_query($link,$query);

                $donnees=mysqli_fetch_assoc($result);
                $titre=$donnees["titre"];
                $auteur=$donnees["auteur"];
                $genre=$donnees["genre"];
                $prix=$donnees["prix"];
                $url=$donnees["urlVignette"];

                print "<div class=\"leCDDemande\">";
                print "<img id=\"vignette\" src=\"traitementImage.php?url=$url&width=500&height=500\" alt=\"vignette $titre\">";
                print "<div class=\"infosCD-container\">";
                print "<p id=\"titre-du-cd\">Titre : $titre</p>";
                print "<p id=\"auteur-du-cd\">Auteur : $auteur</p>";
                print "<p id=\"genre-du-cd\">Genre : $genre</p>";
                print "<p id=\"prix-du-cd\">Prix : $prix</p>";
                print "</div>";
                print "</div>";
            ?> 
            </div>
    </article>
    <footer>
        <p>Réalisé par Matis Chabanat !</p>
        <p>2022 - 2023</p>
    </footer>
</body>
</html>