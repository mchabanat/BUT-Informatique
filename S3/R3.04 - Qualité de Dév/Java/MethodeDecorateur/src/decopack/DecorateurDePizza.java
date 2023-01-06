package decopack;
import decopack.DecorerAvecChampignons;
import decopack.DecorerAvecOlives;

public abstract class DecorateurDePizza implements IComposantPizza {
	//ATTRIBUT composantD�cor�, le composant � d�corer
	public IComposantPizza _pizzaDecore;
	// CONSTRUCTEUR
	public DecorateurDePizza (IComposantPizza composant) {
		setComposantD�cor� (composant);
	}
	
	// METHODES D'ENCAPSULATION : composantD�cor�
	public void setComposantD�cor� (IComposantPizza composant) {
		this._pizzaDecore = composant;
	}
	
	public IComposantPizza getComposantD�cor� () {
		return this._pizzaDecore;
	}
}
