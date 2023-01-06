package singletons;

public class SingletonChefCuisinier {
	/// Membres spécifiques à la mise en œuvre du mécanisme du design pattern Singleton
	// ATTRIBUT
	// Référence privée, et au niveau de la classe, de l'unique instance
	private static SingletonChefCuisinier instance = null;
	
	// CONSTRUCTEUR
	private SingletonChefCuisinier() {} 
	
	// METHODE d'obtention de l'instance qui se charge, d’appeller le constructeur
	public static SingletonChefCuisinier get_instance() {
		if (instance == null) { // Equivaut à : if (Singleton.instance == null)
			instance = new SingletonChefCuisinier(); // Invoque le constructeur avec d’éventuels paramètres
		}
		return instance;
	}
	 
	/// Membres spécifiques à la mise en œuvre métier de l’unique instance
	// (ils n’ont pas à être static, les attributs appartiennent à l’objet)
	// ATTRIBUTS métier
	String _nom;
	String _prenom;

	// METHODES métier
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
