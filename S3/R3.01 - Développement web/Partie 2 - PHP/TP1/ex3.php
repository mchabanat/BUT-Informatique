<?php 
$fichierCSV = fopen("restos.csv", 'r');
while(TRUE){
    $ligne = fgets($fichierCSV);
    
    if($ligne == ""){
        break;
    }
    $tab = explode(';', $ligne);?> 
    <p> Nom : <?php echo $tab[0] ?> </p>
    <p> Prénom : <?php echo $tab[1] ?> </p>
    <p> Restaurant : <?php echo $tab[2] ?> </p> <?php
    ?> <br> <?php
    fclose($fichierCSV);
}
?>
