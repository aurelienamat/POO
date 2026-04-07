#include "Personnage.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<Personnage*> Personnage::ListePersonnageStatic;

Personnage::Personnage() :vie(100), mana(50){
	ListePersonnageStatic.push_back(this);
}

Personnage::Personnage(string choixPrenom):vie(100),mana(50),prenom(choixPrenom){
	ability* bf = new ability();
	this->addAbility(bf);

	ListePersonnageStatic.push_back(this);
}

void Personnage::afficher() {
	cout << "Info personnage : " << endl;
	cout << "Prenom : " << prenom << endl;
	cout << "vie : " << vie << endl;
	cout << "mana : " << mana << endl;
	
}

void Personnage::afficherAbility()
{
	cout << "Voici toute les ability de votre personnage : " << endl;
	for (int i = 0; i < listeAbilityPerso.size(); i++) {
		std::cout << i + 1 << ". ";
		listeAbilityPerso[i]->afficher();
	}
}

void Personnage::addAbility(ability* name)
{
	listeAbilityPerso.push_back(name);
}

void Personnage::degat(int degats)
{
	std::cout << this->prenom << " | vie " << this->vie << " -> ";
	this->vie -= degats;
	std::cout << this->vie << endl;
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