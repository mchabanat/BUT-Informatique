package strategies;


public class ClasseXUtilisantStrategie {
	// Attribut
	IStrategie laStrat;
	
	// Methodes m�tier
	public void operationMetier() {
		System.out.println(laStrat.methodeDeStrategie());
	}
	
	public void setLaStrategie(IStrategie strat) {
		laStrat = strat;
	}
}
