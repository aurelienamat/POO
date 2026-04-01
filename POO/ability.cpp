#include "ability.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ability::ability() : degat(10), cou(20),nom("Boule de feu") {

}

ability::ability(string choix_nom, int choix_degat, int choix_cou, vector<ability*>& listeAbility) : degat(choix_degat), cou(choix_cou), nom(choix_nom){
	listeAbility.push_back(this);
}

void ability::afficher() {
	cout << "Nom : " << nom << " | Degat : " << degat << " | Cout mana : " << cou << endl;
}