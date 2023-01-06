package cuisine;
import java.util.ArrayList;

public class PreparationComposee extends PreparationDeCuisine {
	
	public PreparationComposee(String lib, int prix) {
		super(lib, prix);
		this.enfants = new ArrayList<PreparationDeCuisine>();
	}
	//Relation
	public Boolean ajouterComposant(PreparationDeCuisine unePrep) {
		return enfants.add(unePrep);
	}
	public Boolean retirerComposant(PreparationDeCuisine unePrep) {
		return enfants.remove(unePrep);
	}
	public Boolean existeComposant(PreparationDeCuisine unePrep) {
		return enfants.contains(unePrep);
	}
	
	//Methode metier
	public int getPrix() {
		int resultat = this.prix;
		
		for(PreparationDeCuisine prep: enfants) {
			resultat += prep.getPrix();
		}
		
		return resultat;
	}
	@Override
	public String toString() {
		// Afficher le prix de la préparation
		
		return null;
	}
}
