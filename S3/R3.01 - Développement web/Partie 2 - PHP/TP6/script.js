//Récupération de l'input
var inputPays = document.querySelector('#inputPays');

//Évènement
urlApi = "http://lakartxela.iutbayonne.univ-pau.fr/~almenn/PHP/TP6/apiRest.php"


inputPays.addEventListener('input', function(){
    console.log(inputPays.value);
    fetch(urlApi)
    .then(function(res) {
        if (res.ok) {
        return res.json();
        }
    })
    .then(function(value) {
        console.log(value)
    })
})

//Requête

function ajax(){
    var xhr=null;
    if (window.XMLHttpRequest){ 
        xhr = new XMLHttpRequest();
    }
    else if (window.ActiveXObject){
        xhr = new ActiveXObject("Microsoft.XMLHTTP");
    }
    xhr.onreadystatechange = function() { alert_ajax(xhr); };
    xhr.open("GET", "http://iparla.iutbayonne.univ-pau.fr/~roose/ajax/attente.php", true);
    xhr.send(null);
    console.log(xhr.responseXML());
}