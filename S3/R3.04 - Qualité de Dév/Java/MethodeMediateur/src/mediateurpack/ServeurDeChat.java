package mediateurpack;

import java.util.ArrayList;

public class ServeurDeChat extends Mediateur {
	// Attributs 
	private String nom;
	protected ArrayList<Utilisateur> lesUtilisateurs;
	
	// Constructeur
	public ServeurDeChat(String n) {
		this.nom = n;
		this.lesUtilisateurs = new ArrayList<Utilisateur>();
	}
	
	// Encapsulation
	public void setNom(String n) {
		this.nom = n;
	}
	
	public String getNom() {
		return this.nom;
	}
	
	// Methodes
	public Boolean ajouterUtilisateur(Utilisateur user) {
		return this.lesUtilisateurs.add(user);
	}
	public Boolean retirerUtilisateur(Utilisateur user) {
		return this.lesUtilisateurs.remove(user);
	}
	public Boolean existeUtilisateur(Utilisateur user) {
		return this.lesUtilisateurs.contains(user);
	}
	
	public void diffuserMessageDe(String message, Utilisateur auteur) {
		System.out.println(getNom() + " diffuse " + message + " de " + auteur.getNom());
		
		for (Utilisateur destinataire: lesUtilisateurs) {
			if (auteur != destinataire) {
				destinataire.recevoirMessageDe(message, auteur);
			}
		}
	}
}
