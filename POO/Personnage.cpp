#include "Personnage.hpp"
#include "ui.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<Personnage*> Personnage::ListePersonnageStatic;

Personnage::Personnage() :vie(100), mana(50){
	ListePersonnageStatic.push_back(this);
}

Personnage::Personnage(string choixPrenom):vie(100),mana(50),prenom(choixPrenom){
	//ability* bf = new ability();
	vector<ability*> liste = ability::getListeAbility();
	for (int i = 0; i < liste.size(); i++) {
		if (liste[i]->getNom() == "Boule de feu") {
			this->addAbility(liste[i]);
		}
	}

	ListePersonnageStatic.push_back(this);
}

void Personnage::afficher() {
	cout << CYAN << BOLD << "  " << prenom << RESET << "\n";
	cout << "  " << RED << "Vie  : " << RESET;
	printHealthBar(vie);
	cout << "\n";
	cout << "  " << BLUE << "Mana : " << BOLD << mana << RESET << "\n";
}

void Personnage::afficherAbility()
{
	cout << YELLOW << "  Abilities de " << BOLD << prenom << RESET << YELLOW << " :" << RESET << "\n";
	for (int i = 0; i < listeAbilityPerso.size(); i++) {
		cout << CYAN << "  " << i + 1 << ". " << RESET;
		listeAbilityPerso[i]->afficher();
	}
}

void Personnage::addAbility(ability* name)
{
	listeAbilityPerso.push_back(name);
}

void Personnage::degat(int degats)
{
	this->vie -= degats;
	if (degats < 0) {
		cout << GREEN << "  [SOIN] " << BOLD << prenom << RESET << GREEN << " recupere " << -degats << " PV  " << RESET;
	} else {
		cout << RED << "  [DEGAT] " << BOLD << prenom << RESET << RED << " subit " << degats << "  " << RESET;
	}
	printHealthBar(this->vie);
	cout << "\n";
}

Personnage *Personnage::returnPersonnage(int a)
{
	return ListePersonnageStatic[a];
}

int Personnage::nbPerso()
{
	return ListePersonnageStatic.size();
}

ability* Personnage::returnAbility(int a) {
	return listeAbilityPerso[a];
}