package decopack;

public class DecorerAvecChampignons extends DecorateurDePizza {
	// CONSTRUCTEUR
	public DecorerAvecChampignons (IComposantPizza composant) {
		super (composant);
	}
	// METHODE A DECORER AVANT et/ou APRES : opération
	public String toString() {
		return(_pizzaDecore.toString() + " - Champignons");
	}
}
