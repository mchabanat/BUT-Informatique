package solidpack;
import solidpack.Date;

public class TraiterDate {
	//Attribut
	private Date _uneDate;
	
	//Constructeur
	public TraiterDate(Date d) {
		this._uneDate = d;
	}
	
	//Methode specifique (hors responsabilité qui était avant dans la classe Date)
	public int toInt() {
		return (10000*_uneDate.getAnnee() + 100*_uneDate.getMois() + _uneDate.getJour());
	}
}
