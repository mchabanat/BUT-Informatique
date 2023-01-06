package singletons;

import singletons.SingletonChefCuisinier;

public class TesterSingleton {

	public static void main(String[] args) {
		SingletonChefCuisinier leChef,leCuisinier;
		
		leCuisinier = SingletonChefCuisinier.get_instance();
		leCuisinier.set_nom("Navarro");
		
		leChef = SingletonChefCuisinier.get_instance();
		
		System.out.println(leChef.to_string());
	}

}
