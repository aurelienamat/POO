#include "ability.hpp"
#include <iostream>
#include <string>

using namespace std;

ability::ability() : degat(10), cou(20),nom("Boule de feu") {

}

ability::ability(string choix_nom, int choix_degat, int choix_cou) : degat(choix_degat), cou(choix_cou), nom(choix_nom){

}

void ability::afficher() {
	cout << "Nom : " << nom << endl;
	cout << "Degat : " << degat << endl;
	cout << "Cout mana : " << cou << endl;
}