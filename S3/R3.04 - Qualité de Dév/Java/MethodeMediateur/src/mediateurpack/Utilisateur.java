package mediateurpack;

public class Utilisateur extends Acteur {
	// Attributs 
	private String nom;
	
	// Constructeur	
	public Utilisateur(Mediateur m,String n) {
		super(m);
		this.nom = n;
	}

	// Encapsulation 
	public void setNom(String n) {
		this.nom = n;
	}
	
	public String getNom() {
		return this.nom;
	}
	
	// Methodes
	public void recevoirMessageDe(String message, Utilisateur auteur) {
		System.out.println("L'auteur " + auteur.getNom() + " écrit le message " + message);
	}
	
}
