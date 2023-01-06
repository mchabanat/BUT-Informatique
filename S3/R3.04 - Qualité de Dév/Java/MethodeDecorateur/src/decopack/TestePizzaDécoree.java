package decopack;
import decopack.DecorateurDePizza;
import decopack.DecorerAvecChampignons;
import decopack.DecorerAvecOlives;
import decopack.IComposantPizza;
import decopack.PizzaDeBase;

public class TestePizzaDécoree {
	public static void main(String[] args) {
		// Création d’un composantDeBase
		IComposantPizza unePizza = new PizzaDeBase();
		System.out.println(unePizza.toString()); // Fait l’opération de base
		
		// ... que l’on dote du comportement de décoration du décorateur A ...
		unePizza = new DecorerAvecOlives(unePizza);
		System.out.println(unePizza.toString()); // Fait l’opération de base décorée par A
		
		// ... et on le transforme en le dotant EN PLUS des décorations du décorateur B
		unePizza = new DecorerAvecChampignons(unePizza);
		System.out.println(unePizza.toString()); // Fait l’opération de base décorée par A et B
	}

}
