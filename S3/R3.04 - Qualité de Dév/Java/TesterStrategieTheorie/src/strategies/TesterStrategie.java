package strategies;

public class TesterStrategie {

	public static void main(String[] args) {
		ClasseXUtilisantStrategie objetX;
		objetX = new ClasseXUtilisantStrategie();
		
		IStrategie uneStratégie;
		
		uneStratégie = new StrategieConcrete1();
		objetX.setLaStrategie(uneStratégie);
		objetX.operationMetier(); // Comportement 1
		
		uneStratégie = new StrategieConcrete2();
		objetX.setLaStrategie(uneStratégie);
		objetX.operationMetier();// Comportement 2
	}

}
