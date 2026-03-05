#include "Personnage.hpp"
#include <iostream>
#include <string>

using namespace std;

Personnage::Personnage() :vie(100), mana(50), bf() {

}

Personnage::Personnage(string choixPrenom):vie(100),mana(50),prenom(choixPrenom), bf() {

}

void Personnage::afficher() {
	cout << "Prenom : " << prenom << endl;
	cout << "vie : " << vie << endl;
	cout << "mana : " << mana << endl;
	bf.afficher();
}