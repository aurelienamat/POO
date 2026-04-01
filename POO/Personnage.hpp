#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <iostream>
#include <string>
#include <vector>
#include "ability.hpp"

class Personnage {
public:
	Personnage();
	Personnage(std::string choixPrenom);
	void afficher();
	void addAbility(ability name);

private :
	std::string prenom;
	int vie;
	int mana;
	std::vector<ability> listeAbilityPerso;
};


#endif