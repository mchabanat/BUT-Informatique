package relationSymetrique;
import relationSymetrique.PlatCuisine;

public class Ingredient {
	//CONSTANTES -non-
	//ATTRIBUTS 
	String _libelle;
	PlatCuisine _monPlat;
	
	//CONSTRUCTEURS 
	public Ingredient(String libelle) {
		_libelle = libelle;
	}
		
	//ENCAPSULATION
	public void setLibelle(String libelle) {
		_libelle = libelle;
	}
		
	public String getLibelle() {
		return _libelle;
	}
		
	public void setMonPlat(PlatCuisine plat) {
		_monPlat = plat;
	}
		
	public PlatCuisine getMonPlat() {
		return _monPlat;
	}
		
	//METHODES USUELLES
	public String toString() {
		return ("Cet ingrédient s'appelle " + _libelle + ".");
	}
		
		
	//METHODES SPECIFIQUES 
	public void lierMonPlat(PlatCuisine p) {
		
	}
		
	public void delierMonPlat() {
		
	}
}
