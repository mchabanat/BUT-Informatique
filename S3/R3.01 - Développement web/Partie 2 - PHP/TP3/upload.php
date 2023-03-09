<?php 
$path = "images";
$nbPhoto = $_POST['nbphotos'];

for($i=0;$i<$nbPhoto;$i++){
    $name = "photo$i";
    $tmpName = $_FILES[$name]['tmp_name'];
    move_uploaded_file($tmpName, "$path/$name.jpg");
}
?>