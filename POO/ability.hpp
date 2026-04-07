#ifndef DEF_ABILITY
#define DEF_ABILITY

#include <iostream>
#include <string>
#include <vector>

class ability {
public :
	ability();
	ability(std::string choix_nom, int choix_degat, int choix_cou);
	void afficher();
	static void afficherListeAbility();
	static ability* returnAbility(int a);
	int getDegat() { return degat; }
	int getCout() { return cou; }
	std::string getNom() { return nom; }
	static std::vector<ability*> getListeAbility(){ return ListeAbilityStatic; }

private :
	std::string nom;
	int degat;
	int cou;
	static std::vector<ability*> ListeAbilityStatic;
};

#endif