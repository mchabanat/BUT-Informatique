package decopack;

public class DecorerAvecOlives extends DecorateurDePizza {
	// CONSTRUCTEUR
	public DecorerAvecOlives (IComposantPizza composant) {
		super (composant);
	}
	// METHODE A DECORER AVANT et/ou APRES : opération
	public String toString() {
		return(_pizzaDecore.toString() + " - Olives");
	}
}
