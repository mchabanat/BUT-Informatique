package strategies;

public class TesterStrategie {

	public static void main(String[] args) {
		ClasseXUtilisantStrategie objetX;
		objetX = new ClasseXUtilisantStrategie();
		
		IStrategie uneStrat�gie;
		
		uneStrat�gie = new StrategieConcrete1();
		objetX.setLaStrategie(uneStrat�gie);
		objetX.operationMetier(); // Comportement 1
		
		uneStrat�gie = new StrategieConcrete2();
		objetX.setLaStrategie(uneStrat�gie);
		objetX.operationMetier();// Comportement 2
	}

}
