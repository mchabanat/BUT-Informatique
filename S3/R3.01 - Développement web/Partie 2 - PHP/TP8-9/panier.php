<?php session_start(); ?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <title>CD - Panier</title>
</head>
<body>
    <nav>
        <a href="accueil.php"><img id="logoSite" src="images/cd.png" alt="logoSite"></a>
        <a id="boutonAjouterCD" href="ajoutCDs.php">AJOUTER DES CD</a>
        <a href="panier.php"><img id="panier" src="images/panier.png" alt="panier"></a>
    </nav>

    <article id="article-panier">
        <h1>Bienvenue sur HappyMusic !</h1><br><br>
            <h2>Panier</h2>

            <?php
                include 'configBD.php';

                $link = getConnection();

                $nomtable = "CD";

                $prixFinal = 0; // Représente la somme du prix de tous les articles du panier
                $nbItemsDansPanier = 0;
                $tailleTab = sizeof($_SESSION['eltsPanier']);

                // Affichage du panier
                if ($tailleTab == 0) {
                    // S'il est vide, on affiche panier vide
                    print "<div id=\"panier-vide\">";
                    print "<p>Le panier est vide.</p>";
                    print "</div>";
                } else {
                    // Parcours du tableau pour afficher chaque élément
                    foreach ($_SESSION["eltsPanier"] as $idCD => $qte) {
                        // Requete qui récupère les infos du cd selon son id
                        $sql="SELECT * FROM $nomtable WHERE id = $idCD";
                        $result=mysqli_query($link,$sql); 

                        $donnees=mysqli_fetch_assoc($result);

                        $titre=$donnees["titre"];
                        $auteur=$donnees["auteur"];
                        $genre=$donnees["genre"];
                        $prix=$donnees["prix"] * $qte;

                        $prixFinal += $prix;
                        $nbItemsDansPanier += $qte;

                        // Affichage
                        print "<div class=\"unArticlePanier\">";
                        print "<div class=\"infosAlbum\">";
                        print "<p id=\"titre\">$titre</p>";
                        print "<p>$auteur</p>";
                        print "</div>";
                        print "<p>Nb Exemplaires : $qte</p>";
                        print "<p>Prix = €$prix</p>";
                        print "<a href=\"supprimerPanier.php?id=$idCD\">Retirer 1 du panier</a>";
                        print "</div>";
                    }
                    
                    print "<div class=\"infosCommande\">";
                    print "<p>$nbItemsDansPanier article(s)</p>";
                    print "<p>Prix total : €$prixFinal</p>";
                    print "<a href=\"paiement.php\">Commander</a>";
                    print "</div>";
                }
            ?>
    </article>
    <footer>
        <p>Réalisé par Matis Chabanat !</p>
        <p>2022 - 2023</p>
    </footer>
</body>
</html>