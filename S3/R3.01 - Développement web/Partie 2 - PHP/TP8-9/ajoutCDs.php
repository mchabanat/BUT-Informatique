<?php session_start(); ?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <title>CD - Ajouter un CD</title>
</head>
<body>
    <nav>
        <a href="accueil.php"><img id="logoSite" src="images/cd.png" alt="logoSite"></a>
        <a id="boutonAjouterCD" href="ajoutCDs.php">AJOUTER DES CD</a>
        <a href="panier.php"><img id="panier" src="images/panier.png" alt="panier"></a>
    </nav>

    <article class="au-centre">
        <h1>Bienvenue sur HappyMusic !</h1>
            <?php
            // On regarde si l'utilisateur est bien connecté en admin
            if (!isset($_SESSION['login']) && !isset($_SESSION['pwd'])) {
                // Si non, on lui indique qu'il doit se connecter
                echo '<body onLoad="alert(\'Vous devez avoir un accès admin pour accéder à cette page\')">'; 
                // puis on le redirige vers la page d'accueil 
                echo '<meta http-equiv="refresh" content="0;URL=accueil.php">';
            } 

            ?>

            <h2>Saisissez une nouvelle musique !</h2>

            <form action="traitementAjoutCD.php" method="post">
                <label for="titre">Titre :</label>
                <input type="text" id="titre" name="titre"><br>

                <label for="auteur">Auteur :</label>
                <input type="text" id="auteur" name="auteur"><br>

                <label for="genre">Genre :</label>
                <select name="genre" id="genre">
                        <?php

                        include 'configBD.php';

                        $link = getConnection();

                        $nomtable= "CD";

                        $query = "SELECT DISTINCT(genre) FROM $nomtable";
                        $result= mysqli_query($link,$query);

                        while ($donnees=mysqli_fetch_assoc($result)) {
                            $genre=$donnees["genre"];

                            print "<option value=\"$genre\">$genre</option>";
                        }

                        print "<option value=\"autre\">Autre</option>";
                        ?>
                    </select>
                    <div id="genre_autre_container" style="display:none;">
                        <label for="genre_autre">Saisissez votre genre :</label>
                        <input type="text" name="genre_autre" id="genre_autre">
                    </div>
                    <script>
                        document.getElementById("genre").addEventListener("change", function() {
                        if (this.value === "autre") {
                            document.getElementById("genre_autre_container").style.display = "block";
                        } else {
                            document.getElementById("genre_autre_container").style.display = "none";
                        }
                        });
                    </script>
                
                <br>
                <label for="url">URL de la vignette :</label>
                <input type="text" id="url" name="url"><br>
                <label for="prix">Prix :</label>
                <input type="text" id="prix" name="prix"><br>

                <input type="submit" value="Ajouter">
            </form> 
    </article>
    <footer>
        <p>Réalisé par Matis Chabanat !</p>
        <p>2022 - 2023</p>
    </footer>
</body>
</html>