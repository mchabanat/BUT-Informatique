package relationSymetrique;
import relationSymetrique.Ingredient;

public class PlatCuisine {
	//CONSTANTES -non-
	//ATTRIBUTS 
	String _libelle;
	ArrayList<Ingredient> lesIngredients;
		
	//CONSTRUCTEURS 
	public PlatCuisine(String libelle) {
		_libelle = libelle;
	}
			
	//ENCAPSULATION
	public void setLibelle(String libelle) {
		_libelle = libelle;
	}
			
	public String getLibelle() {
		return _libelle;
	}
			
	//METHODES USUELLES
	public String toString() {
		return ("Cet ingrédient s'appelle " + _libelle + ".");
	}
			
			
	//METHODES SPECIFIQUES 
	public boolean contientIngredient(Ingredient i) {
		
	}
	
	public boolean ajouterUnIngredient(Ingredient i) {
		
	}
	
	public boolean retirerUnIngredient(Ingredient i) {
		
	}
			
	public boolean lierUnIngredient(Ingredient i) {
		
	}	
	
	public boolean delierUnIngredient() {
		
	}	
}
