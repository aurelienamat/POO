#ifndef DEF_ABILITY
#define DEF_ABILITY

#include <iostream>
#include <string>
#include <vector>

class ability {
public :
	ability();
	ability(std::string choix_nom, int choix_degat, int choix_cou, std::vector<ability*>& listeAbility);
	void afficher();

private :
	std::string nom;
	int degat;
	int cou;
};

#endif