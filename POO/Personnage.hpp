#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <iostream>
#include <string>
#include "ability.hpp"

class Personnage {
public:
	Personnage();
	Personnage(std::string choixPrenom);
	void afficher();

private :
	std::string prenom;
	int vie;
	int mana;
	ability bf;
};


#endif