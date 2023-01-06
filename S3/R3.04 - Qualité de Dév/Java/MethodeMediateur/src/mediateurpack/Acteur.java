package mediateurpack;

public abstract class Acteur {
	// Attributs
	private Mediateur mediateur;
	
	// Constructeur 
	public Acteur(Mediateur m) {
		this.mediateur = m;
	}
	
	// Encapsulation
	public void setMediateur(Mediateur m) {
		this.mediateur = m;
	}
	
	public Mediateur getMediateur() {
		return this.mediateur;
	}
}
