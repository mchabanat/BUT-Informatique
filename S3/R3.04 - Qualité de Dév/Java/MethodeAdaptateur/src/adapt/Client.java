package adapt;

public class Client {

	public static void main(String[] args) {
		ICible cible = new Adaptateur();
		cible.operation();

	}

}
