#include "ability.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<ability*> ability::ListeAbilityStatic;

ability::ability() : degat(10), cou(20),nom("Boule de feu") {
	for (int i = 0; i < ListeAbilityStatic.size(); i++) {
		if (ListeAbilityStatic[i]->nom == "Boule de feu") {
			return;
		}
	}
	ListeAbilityStatic.push_back(this);
}

ability::ability(string choix_nom, int choix_degat, int choix_cou) : degat(choix_degat), cou(choix_cou), nom(choix_nom){
	ListeAbilityStatic.push_back(this);
}

void ability::afficher() {
	cout << "Nom : " << nom << " | Degat : " << degat << " | Cout mana : " << cou << endl;
}

void ability::afficherListeAbility()
{
	for (int i = 0; i < ListeAbilityStatic.size(); i++) {
		cout << i+1 << ". ";
		ListeAbilityStatic[i]->afficher();
	}
}

ability* ability::returnAbility(int a)
{
	return ListeAbilityStatic[a];
}

