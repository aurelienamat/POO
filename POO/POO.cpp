// POO.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include <string>
#include <vector>
#include "Personnage.hpp"
#include "ability.hpp"

using namespace std;

int main()
{
    //Création des personnages
    Personnage goliath("goliath"),david("david");

    //Création des ability
    vector<ability*> listeAbility;
    new ability("soinI", -10, 10, listeAbility);

    string choixPrenom;
    std::cout << "Votre nom : ";
    cin >> choixPrenom;

    Personnage aure(choixPrenom);
    std::cout << "Votre perso a ete cree, voici ses infos : " << endl;
    aure.afficher();

    //Crée une ability
    string choixNomAbility;
    std::cout << "Entrez le nom de l'abilite que vous voulez creer : ";
    cin >> choixNomAbility;
    new ability(choixNomAbility, 10, 10, listeAbility);
    std::cout << "Abilite cree" << endl;

    //Lister les ability
    std::cout << "Voici toutes les ability : " << endl;
    for (int i = 0; i < listeAbility.size(); i++) {
        std::cout << i + 1 << ". ";
        listeAbility[i]->afficher();
        std::cout << endl;
    }


    int choixAbility;
    std::cout << "Numero de l'ability que vous souhaitez ajouter à votre inventaire : ";
    cin >> choixAbility;

    aure.addAbility(*listeAbility[choixAbility - 1]);

    aure.afficher();


}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
