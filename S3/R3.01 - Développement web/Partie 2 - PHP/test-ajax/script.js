var body = document.querySelector("body"); // QuerySelector récupère l'objet qui est passé en paramètre (fonctionne comme le css)

// Requete ajax
var xhr = new XMLHttpRequest();
xhr.open("GET", "serveurImage.php", true);
xhr.send();

// Dès que xhr recoit la réponse de la requete il appelle une fonction
xhr.onreadystatechange = function() {
    if (xhr.readyState == 4 && xhr.status == 200) { // vérifie qu'il y a bien une réponse
        //Réussite
        body.innerHTML = xhr.response; // On met dans la balise récupérée ligne 1
    }
} 