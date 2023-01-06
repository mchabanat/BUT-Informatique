package relationSymetrique;
import relationSymetrique.Table;

public class Client {
	//CONSTANTES -non-
	//ATTRIBUTS 
	String _nom;
	String _tel;
	Table _maTable;
	
	//CONSTRUCTEURS 
	public Client(String nom,String tel) {
		_nom = nom;
		_tel = tel;
	}
	
	//ENCAPSULATION 
	public void setNom(String nom) {
		_nom = nom;
	}
	
	public String getNom() {
		return _nom;
	}
	
	public void setTel(String tel) {
		_tel = tel;
	}
	
	public String getTel() {
		return _tel;
	}
	
	public void setMaTable(Table t) {
		_maTable = t;
	}
	
	public Table getMaTable() {
		return _maTable;
	}
	
	//METHODES USUELLES 
	public String toString() {
		if(this.getMaTable() == null) {
			return ("Le client s'appelle " + _nom + " et son numéro de téléphone est " + _tel + ".");
		}
		else
		{
			return ("Le client s'appelle " + _nom + " et son numéro de téléphone est " + _tel + ". Il est positionné sur la table " + this.getMaTable().getNumTable() + ".");
		}
		
	}
	
	//METHODES SPECIFIQUES 
	public void lierMaTable(Table t) {
		if(t!=null) {
			this.delierMaTable();
			t.delierMonClient();
			this.setMaTable(t);
			t.setMonClient(this);
		}
	}
	
	public void delierMaTable() {
		if(this._maTable != null) {
			this._maTable.setMonClient(null);
			this.setMaTable(null);
		}
	}
}
