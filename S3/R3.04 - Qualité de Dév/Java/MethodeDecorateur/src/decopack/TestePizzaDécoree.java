package decopack;
import decopack.DecorateurDePizza;
import decopack.DecorerAvecChampignons;
import decopack.DecorerAvecOlives;
import decopack.IComposantPizza;
import decopack.PizzaDeBase;

public class TestePizzaD�coree {
	public static void main(String[] args) {
		// Cr�ation d�un composantDeBase
		IComposantPizza unePizza = new PizzaDeBase();
		System.out.println(unePizza.toString()); // Fait l�op�ration de base
		
		// ... que l�on dote du comportement de d�coration du d�corateur A ...
		unePizza = new DecorerAvecOlives(unePizza);
		System.out.println(unePizza.toString()); // Fait l�op�ration de base d�cor�e par A
		
		// ... et on le transforme en le dotant EN PLUS des d�corations du d�corateur B
		unePizza = new DecorerAvecChampignons(unePizza);
		System.out.println(unePizza.toString()); // Fait l�op�ration de base d�cor�e par A et B
	}

}
