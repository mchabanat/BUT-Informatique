package relationSymetrique;
import relationSymetrique.Client;

public class Table {
	//CONSTANTES -non-
	//ATTRIBUTS 
	String _numTable;
	Client _monClient;
	
	//CONSTRUCTEURS 
	public Table(String numTable) {
		_numTable = numTable;
	}
	
	//ENCAPSULATION
	public void setNumTable(String numTable) {
		_numTable = numTable;
	}
	
	public String getNumTable() {
		return _numTable;
	}
	
	public void setMonClient(Client c) {
		_monClient = c;
	}
	
	public Client getMonClient() {
		return _monClient;
	}
	
	//METHODES USUELLES
	public String toString() {
		if(this.getMonClient() == null) {
			return ("Le numéro de table est " + _numTable + ".");
		}
		else
		{
			return ("Le numéro de table est " + _numTable + " et elle appartient au client du nom " + this.getMonClient().getNom() + " ayant pour numéro de téléphone " + this.getMonClient().getTel() + ".");
		}
	}
	
	//METHODES SPECIFIQUES 
	public void lierMonClient(Client c) {
		if(c!=null) {
			this.delierMonClient();
			c.delierMaTable();
			this.setMonClient(c);
			c.setMaTable(this);
		}
	}
	
	public void delierMonClient() {
		if(this._monClient != null) {
			this._monClient.setMaTable(null);
			this.setMonClient(null);
		}
	}
	
}
