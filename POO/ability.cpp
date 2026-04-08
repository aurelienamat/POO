#include "ability.hpp"
#include "ui.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<ability*> ability::ListeAbilityStatic;

ability::ability(){
	ListeAbilityStatic.push_back(this);
}

ability::ability(string choix_nom, int choix_degat, int choix_cou) : degat(choix_degat), cou(choix_cou), nom(choix_nom){
	ListeAbilityStatic.push_back(this);
}

void ability::afficher() {
	cout << BOLD << MAGENTA << nom << RESET
		 << " | " << RED << "Degats: " << BOLD << degat << RESET
		 << " | " << BLUE << "Mana: " << BOLD << cou << RESET << "\n";
}

void ability::afficherListeAbility()
{
	for (int i = 0; i < ListeAbilityStatic.size(); i++) {
		cout << CYAN << "  " << i+1 << ". " << RESET;
		ListeAbilityStatic[i]->afficher();
	}
}

ability* ability::returnAbility(int a)
{
	return ListeAbilityStatic[a];
}

