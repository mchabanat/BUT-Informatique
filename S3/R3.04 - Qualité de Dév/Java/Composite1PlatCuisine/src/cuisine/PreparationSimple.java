package cuisine;

public class PreparationSimple extends PreparationDeCuisine {
	public PreparationSimple(String lib, int prix) {
		super(lib, prix);
	}

	//Methode metier
	public int getPrix() {
		return this.prix;
	}

	@Override
	public String toString() {
		// Afficher le prix de la préparation
		
		return null;
	}
}
