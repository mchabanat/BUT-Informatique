<!-- Ex1 -->
<?php
    print "Hello world";
?>

<br>

<!-- Ex2 -->
<?php
    $IP = $_SERVER['REMOTE_ADDR'];
    print " $IP";
    
    if($IP < 128) {
        print " - Classe A";
    }
    if($IP > 127 && $IP < 193) {
        print " - Classe B";
    }
    if($IP > 192) {
        print " - Classe C";
    }

    
?>

<br>

<!-- Ex3 -->
<?php
    $monFic = fopen("restos.csv","r");

    while (TRUE){
        $ligne = fgets($monFic,255);
        if($ligne == ""){
            break;
        }
        $personne=explode(";",$ligne);?>
        <p> Nom : <?php print"$personne[0]";?> </p>
        <p> Prénom : <?php print"$personne[1]";?> </p>
        <p> Restaurant : <?php print"$personne[2]";?> </p>
        <hr>
        <?php
    }

    fclose($monFic);
?>

<!-- Ex4 -->

