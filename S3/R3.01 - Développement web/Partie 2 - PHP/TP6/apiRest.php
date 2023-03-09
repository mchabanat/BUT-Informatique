<?php
header('Content-Type: text/xml');
$fic = fopen("pays.xml", 'r');
while (!feof($fic)){
    $ligne = fgets($fic, 255);
    print(trim($ligne));
}
?>