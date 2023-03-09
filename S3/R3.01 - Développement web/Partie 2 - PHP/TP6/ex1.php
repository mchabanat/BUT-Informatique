<!-- Exercice 1 --> 
<h2>EXERCICE 1</h2>
<?php 
//Lecture du fichier XML
$xml = simplexml_load_file("pays.xml");

//Parcours du tableau récupéré
//print_r($xml->europe->pays[0]);

print("<h2> 1/ Liste des pays global : </h2></br>");
foreach($xml->children() as $continents){
    for($i = 0; $i < count($continents->pays); $i++){
        print($continents->pays[$i]);
        print("</br>");
    }
}

print("<h2> 2/ Liste des pays européen : </h2></br>");
for($i = 0; $i < count($xml->europe->pays); $i++){
    print($xml->europe->pays[$i]);
    print("</br>");
}
?>

<!-- Exercice 2 --> 
<h2>EXERCICE 2</h2>
<script src="script.js" defer></script>
<form>
    <label for="search">Recherche : </label>
    <input id="inputPays" name="search" type="text" placeholder="tapez un pays">
</form>

<?php 

?>


