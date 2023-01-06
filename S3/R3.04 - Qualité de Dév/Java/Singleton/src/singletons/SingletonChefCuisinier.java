package singletons;

public class SingletonChefCuisinier {
	/// Membres sp�cifiques � la mise en �uvre du m�canisme du design pattern Singleton
	// ATTRIBUT
	// R�f�rence priv�e, et au niveau de la classe, de l'unique instance
	private static SingletonChefCuisinier instance = null;
	
	// CONSTRUCTEUR
	private SingletonChefCuisinier() {} 
	
	// METHODE d'obtention de l'instance qui se charge, d�appeller le constructeur
	public static SingletonChefCuisinier get_instance() {
		if (instance == null) { // Equivaut � : if (Singleton.instance == null)
			instance = new SingletonChefCuisinier(); // Invoque le constructeur avec d��ventuels param�tres
		}
		return instance;
	}
	 
	/// Membres sp�cifiques � la mise en �uvre m�tier de l�unique instance
	// (ils n�ont pas � �tre static, les attributs appartiennent � l�objet)
	// ATTRIBUTS m�tier
	String _nom;
	String _prenom;

	// METHODES m�tier
		//CONSTANTES -non-
		//CONSTRUCTEURS -non-
		//ENCAPSULATION 
	public String get_nom() {
		return _nom;
	}
	
	public void set_nom(String n) {
		_nom = n;
	}
	
	public String get_prenom() {
		return _prenom;
	}
	
	public void set_prenom(String p) {
		_prenom = p;
	}
	
	
		//METHODES USUELLES 
	public String to_string() {
		return ("Ce chef cuisinier s'appelle " + _nom + " " + _prenom + ".");
	}
	
		//METHODES SPECIFIQUES -non-
	

}
