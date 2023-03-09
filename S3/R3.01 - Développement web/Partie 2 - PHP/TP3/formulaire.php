<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Formulaire</title>
</head>
<body>
    <FORM ENCTYPE="multipart/form-data" ACTION="upload.php" METHOD="POST">
        <?php 
        $nbPhoto = $_POST["nbPhoto"];
        ?>
    <input type=hidden name=nbphotos value=<?php print($nbPhoto); ?>>
    <?php 
    for($i=0;$i < $nbPhoto; $i++){
        $name = "photo$i";
        ?>
        <input type=file name=<?php print($name); ?>>
    <?php
    }
    ?>
    <input type=submit value="Télécharger Photos">
    </FORM>
</body>
</html>