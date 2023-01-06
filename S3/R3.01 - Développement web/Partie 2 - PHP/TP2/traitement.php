<?php
    $name = $_POST["name"];
    $age = $_POST["age"];
    $mail = $_POST["email"];
    $don = $_POST["don"];

    $ligne = "$name | $age | $mail | $don\n";

    $fic = fopen("resultats.txt","a");
    fputs($fic,$ligne);
    fclose($fic);
?>

<p>Voici un récap de vos informations : </p>

<?php
    print("Votre nom : $name"."<br>");
    print("Votre Age : $age"."<br>");
    print("Votre email : $mail"."<br>");
    print("Valeur du don : $don"."<br>");
?>


