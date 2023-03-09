<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Don Caritatif</title>
</head>
<body>
    <h1> Page d'accueil des dons  </h1>
    <?php 
    if(isset($_GET['success']) && $_GET['success']=true){
        ?>
        <h3>Succès <?php print($_GET["name"]);?> vous avez donnez <?php print($_GET["don"]);?> €</h3><?php
    }
    ?>
    <form action="traitementForm.php" method="post">
        <label for="name">Nom :</label>
        <input type="text" name="nom" placeholder="Nom">
        <br>
        <label for="age">Age :</label>
        <input type="number" name="age">
        <br>
        <label for="mail">Adresse Mail :</label>
        <input type="text" name="mail" placeholder="Mail">
        <br>
        <label for="name">Montant du don :</label>
        <input type="number" name="don">
        <br>
        <input type="submit">
    </form>
    <br>
    <form action="resultatMail.php">
        <input type="submit" value="Envoyer résultats">
    </form>
</body>
</html>