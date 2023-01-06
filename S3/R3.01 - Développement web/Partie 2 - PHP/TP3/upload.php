<?php
    $nbPhotos = $_POST["nbphotos"];
    
    for($i = 0 ; $i < $nbPhotos ; $i++) {
        $nomPhoto = "photo$i";
        $tmp_name = $_FILES["$nomPhoto"]['tmp_name'];
        move_uploaded_file($tmp_name,"images/$nomPhoto");
    }
?>