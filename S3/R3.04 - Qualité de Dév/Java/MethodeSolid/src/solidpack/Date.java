package solidpack;

public class Date {
	//Attributs
	private int _annee;
	private int _mois;
	private int _jour;
	
	//Constructeur
	public Date(int annee, int mois, int jour) {
		this._annee = annee;
		this._mois = mois;
		this._jour = jour;
	}
	
	//Encapsulation
	public int getAnnee() {
		return this._annee;
	}
	public int getMois() {
		return this._mois;
	}
	public int getJour() {
		return this._jour;
	}
	
	public void setAnnee(int annee) {
		this._annee = annee;
	}
	public void setMois(int mois) {
		this._mois = mois;
	}
	public void setJour(int jour) {
		this._jour = jour;
	}
	
	//Methode usuelle
	public String toString() {
		String message = "Nous sommes le ";
		message = message + this._jour + "/";
		message = message + this._mois + "/";
		message = message + this._annee + ".";
		
		return message;
	}
}
