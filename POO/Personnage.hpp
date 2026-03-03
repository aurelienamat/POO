#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <iostream>
#include <string>

class Personnage {
public:
	Personnage();
	Personnage(std::string choixPrenom);
	void afficher();

private :
	std::string prenom;
	int vie;
	int mana;
};


#endif