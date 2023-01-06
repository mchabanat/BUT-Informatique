package cuisine;

import java.util.ArrayList;

public abstract class PreparationDeCuisine {
	//Attributs
	public String libelle;
	public int prix;
	protected ArrayList<PreparationDeCuisine> enfants;
	
	//Constructeur
	public PreparationDeCuisine(String lib,int prix) {
		this.libelle=lib;
		this.prix=prix;
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
	public abstract int getPrix();
	public abstract String toString();
}
