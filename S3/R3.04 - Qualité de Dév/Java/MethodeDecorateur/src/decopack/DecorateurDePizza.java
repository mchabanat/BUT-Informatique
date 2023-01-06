package decopack;
import decopack.DecorerAvecChampignons;
import decopack.DecorerAvecOlives;

public abstract class DecorateurDePizza implements IComposantPizza {
	//ATTRIBUT composantDécoré, le composant à décorer
	public IComposantPizza _pizzaDecore;
	// CONSTRUCTEUR
	public DecorateurDePizza (IComposantPizza composant) {
		setComposantDécoré (composant);
	}
	
	// METHODES D'ENCAPSULATION : composantDécoré
	public void setComposantDécoré (IComposantPizza composant) {
		this._pizzaDecore = composant;
	}
	
	public IComposantPizza getComposantDécoré () {
		return this._pizzaDecore;
	}
}
