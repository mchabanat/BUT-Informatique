<?php $ip = $_SERVER['REMOTE_ADDR']; ?>
<h4> Adresse IP : <?php echo $ip; ?> </h4>
<h4> Classe de l'ip : 
    <?php 
    if($ip < 128){
        echo "Classe A";}
    else if($ip < 193){
        echo "Classe B";
    }
    else{
        echo "Classe C";
    }
 ?> </h4>