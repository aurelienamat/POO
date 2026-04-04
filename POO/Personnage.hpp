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
	void afficherAbility();
	void addAbility(ability name);
	void degat(int degats);
	static Personnage returnPersonnage(int a);
	static int nbPerso();
	int getVie() { return vie; }
	int getMana() { return mana; }
	int getNbAbility() { return listeAbilityPerso.size(); }
	std::string getPrenom() { return prenom; }
	ability returnAbility(int a);

private :
	std::string prenom;
	int vie;
	int mana;
	std::vector<ability> listeAbilityPerso;
	static std::vector<Personnage*> ListePersonnageStatic;
};


#endif