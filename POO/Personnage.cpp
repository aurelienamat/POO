#include "Personnage.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Personnage::Personnage() :vie(100), mana(50){

}

Personnage::Personnage(string choixPrenom):vie(100),mana(50),prenom(choixPrenom){
	ability bf;
	this->addAbility(bf);
}

void Personnage::afficher() {
	cout << "Prenom : " << prenom << endl;
	cout << "vie : " << vie << endl;
	cout << "mana : " << mana << endl;
	
	cout << "Voici toute les ability de votre personnage : " << endl;
	for (int i = 0; i < listeAbilityPerso.size(); i++) {
		std::cout << i + 1 << ". ";
		listeAbilityPerso[i].afficher();
		cout << endl;
	}
}

void Personnage::addAbility(ability name)
{
	listeAbilityPerso.push_back(name);
}
