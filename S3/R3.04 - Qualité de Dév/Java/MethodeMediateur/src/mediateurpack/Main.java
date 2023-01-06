package mediateurpack;

public class Main {

	public static void main(String[] args) {
		// Creation du serveur de chat
		ServeurDeChat unServeurDeChat = new ServeurDeChat("PecnoLand");
		
		// Creation des utilisateurs
		Utilisateur userArthur = new Utilisateur(unServeurDeChat, "Arthur");
		Utilisateur userIvan = new Utilisateur(unServeurDeChat, "Ivan");
		Utilisateur userTitou = new Utilisateur(unServeurDeChat, "Titouan");

		// On lie les utilisateurs au serveur de chat
		unServeurDeChat.ajouterUtilisateur(userArthur);
		unServeurDeChat.ajouterUtilisateur(userIvan);
		unServeurDeChat.ajouterUtilisateur(userTitou);
		
		// Et on le fait aussi de l'autre coté vu que ce n'est pas symétrique
		userArthur.setMediateur(unServeurDeChat);
		userIvan.setMediateur(unServeurDeChat);
		userTitou.setMediateur(unServeurDeChat);

		unServeurDeChat.diffuserMessageDe("Bonjour je suis un pecno", userTitou);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
	}

}
