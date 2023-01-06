<?php
    $nbImg = $_POST["nbImage"];




    print "<FORM ENCTYPE=\"multipart/form-data\" ACTION=\"upload.php\" METHOD=\"POST\">";
    print "<input type=hidden name=nbphotos value=$nbImg>";

    for($i = 0 ; $i < $nbImg ; $i++) {
        $nomPhoto = "photo$i";
        print "<input type=file name=$nomPhoto>";
        print "<br>";
    }
?>
<br>
<br>
<input type=submit value="Télécharger Photos">
</FORM>
