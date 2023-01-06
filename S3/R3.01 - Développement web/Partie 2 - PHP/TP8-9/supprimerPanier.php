<?php
session_start();

$idASupprimer = $_GET["id"];

//Retirer un CD d'id idAAjouter

if (isset($_SESSION['eltsPanier'])) {
    // On regarde si le tableau est vide
    if (sizeof($_SESSION['eltsPanier']) != 0) {
        // S'il n'est pas vide, on regarde en combien d'exemplaire il existe
        if ($_SESSION['eltsPanier'][$idASupprimer] == 1) {
            // S'il y est en un seul exemplaire alors on le supprime du panier
            unset($_SESSION['eltsPanier'][$idASupprimer]);
        } else {
            // S'il est en plusieurs exemplaires dans le panier, alors on enlève 1 exemplaire
            $_SESSION['eltsPanier'][$idASupprimer]--;
        }
        header("Location: panier.php");
    }
} else {
    echo 'Les variables ne sont pas déclarées.'; 
}

?>