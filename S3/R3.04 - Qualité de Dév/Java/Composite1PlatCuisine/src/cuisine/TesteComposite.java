package cuisine;
import cuisine.PreparationDeCuisine;
import cuisine.PreparationSimple;
import cuisine.PreparationComposee;

public class TesteComposite {

	public static void main(String[] args) {
		PreparationComposee patesBolo = new PreparationComposee("patesBolo",1);
		PreparationSimple pate = new PreparationSimple("pate",2);
		PreparationComposee sauceBolo = new PreparationComposee("sauceBolo",1);
		PreparationSimple viandeHachee = new PreparationSimple("viandeHachee",3);
		PreparationComposee sauceTomate = new PreparationComposee("sauceTomate",2);
		PreparationSimple tomateCuite = new PreparationSimple("tomateCuite",1);
		PreparationSimple assaisonnement = new PreparationSimple("assaisonnement",2);
		
		//Peuplement des preparations
		sauceTomate.ajouterComposant(tomateCuite);
		sauceTomate.ajouterComposant(assaisonnement);
		sauceBolo.ajouterComposant(viandeHachee);
		sauceBolo.ajouterComposant(sauceTomate);
		patesBolo.ajouterComposant(pate);
		patesBolo.ajouterComposant(sauceBolo);
		
		System.out.println(patesBolo.getPrix());
	}

}
