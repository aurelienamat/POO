// POO.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Personnage.hpp"
#include "ability.hpp"

using namespace std;


void tourAutre(vector<Personnage> PersonnageArene, string choixPrenom) {
    Personnage WhoAttack;
    do {
        WhoAttack = PersonnageArene[rand() % PersonnageArene.size()];
    } while (WhoAttack.getPrenom() == choixPrenom);

    cout << "Au tour de " << WhoAttack.getPrenom();

    //Qui il attaque ?
    Personnage WhoToAttack;
    do {
        WhoToAttack = PersonnageArene[rand() % PersonnageArene.size()];
    } while (WhoToAttack.getPrenom() == WhoAttack.getPrenom());

    cout << " d'attaquer " << WhoToAttack.getPrenom() << endl;

    //Avec quelle arme ?
    WhoToAttack.degat(WhoAttack.returnAbility(rand() % WhoAttack.getNbAbility()).getDegat());
}

Personnage findPerso(string choixPrenom) {
    for (int i = 0; i < Personnage::nbPerso(); i++) {
        if (Personnage::returnPersonnage(i).getPrenom() == choixPrenom) {
            return Personnage::returnPersonnage(i);
        }
    }
    //Retourne le premier perso de la liste tant pis
    return Personnage::returnPersonnage(0);
}

//Fonction qui vérifie si il est toujours en vie
bool InLive(vector<Personnage> PersonnageArene) {
    for (int i = 0; i < PersonnageArene.size(); i++) {
        if (PersonnageArene[i].getVie() <= 0) {
            return 1;
        }
    }
    return 0;
}

//Fonction de combat
void combat(vector<Personnage> PersonnageArene, string choixPrenom) {
    Personnage aure = findPerso(choixPrenom);
    //Rejoint l'arène
    //Plus tard un aura une fonctione pour savoir qui va rejoindre l'arène
    for (int i = 0; i < Personnage::nbPerso(); i++) {
        PersonnageArene.push_back(Personnage::returnPersonnage(i));
        std::cout << PersonnageArene[i].getPrenom() << " a rejoint l'arene" << endl;
    }
    while (InLive(PersonnageArene) == 0)
    {
        cout << "Qui veux tu attaquer (1,2...): " << endl;
        for (int i = 0; i < PersonnageArene.size(); i++) {
            if (PersonnageArene[i].getPrenom() != choixPrenom) {
                std::cout << i + 1 << ". " << PersonnageArene[i].getPrenom() << " | vie " << PersonnageArene[i].getVie() << endl;
            }
        }

        int choixPersoAttaque;
        do {
            cin >> choixPersoAttaque;
        } while (choixPersoAttaque > PersonnageArene.size() || choixPersoAttaque < 1);
        aure.afficherAbility();
        cout << "Avec quelle ability :  ";
        int choixAttaque;
        do {
            cin >> choixAttaque;
        } while (choixAttaque > aure.getNbAbility() || choixAttaque < 0);

        PersonnageArene[choixPersoAttaque - 1].degat(aure.returnAbility(choixAttaque - 1).getDegat());

        /*for (int i = 0; i < PersonnageArene.size(); i++) {
            std::cout << i + 1 << ". " << PersonnageArene[i].getPrenom() << " | vie " << PersonnageArene[i].getVie() << endl;
        }*/

        //Au tour des autres
        //Qui va jouer ?
        tourAutre(PersonnageArene, choixPrenom);

    }
    cout << endl <<"Fin du combat ! Voici les derniers en vie " << endl;
    for (int i = 0; i < PersonnageArene.size(); i++) {
        if (PersonnageArene[i].getVie() > 0) {
            std::cout << i + 1 << ". " << PersonnageArene[i].getPrenom() << " | vie " << PersonnageArene[i].getVie() << endl;
        }
    }
}

int main()
{
    srand(time(0));
    //Création des personnages
    Personnage goliath("goliath"),david("david");

    //Création des ability
    vector<ability*> listeAbility;
    new ability("soinI", -10, 10);
    new ability("Morsure", 15, 0);

    string choixPrenom;
    std::cout << "Votre nom : ";
    cin >> choixPrenom;

    Personnage aure(choixPrenom);
    std::cout << "Votre perso a ete cree, voici ses infos : " << endl;
    aure.afficher();
    aure.afficherAbility();

    getchar();
    getchar();

    //Choisie une ability
    std::cout << "Voici toutes les ability : " << endl;
    ability::afficherListeAbility();
    int choixNomAbility;
    std::cout << "Entrez le nom de l'abilite que vous voulez choisir : " ;
    do {
        cin >> choixNomAbility;
    } while (choixNomAbility > ability::getListeAbility().size() || choixNomAbility < 1);

    aure.addAbility(ability::returnAbility(choixNomAbility-1));

    aure.afficherAbility();

    //Debut du combat
    std::cout << "Debut du combat, etes vous pret ? " << endl;

    getchar();
    getchar();
    
    vector<Personnage> PersonnageArene;

    combat(PersonnageArene, choixPrenom);
    //Ajout de tous les personnage dans l'arene
    //for (int i = 0; i < Personnage::nbPerso(); i++) {
    //    PersonnageArene.push_back(Personnage::returnPersonnage(i));
    //    std::cout << PersonnageArene[i].getPrenom() << " a rejoint l'arene" << endl;
    //}

    ////combat
    ////Possibilité d'ajouter une fonction qui retourne 1 
    ////Quand la vie d'un des mec de l'arene est a 0
    ////Comme ça combat jusqu'a la mort
    //// Et pas obliger de faire chaque ligne ou d'avoir un nombre de tour definie
    //
    ////et une fonction combat ?
    //
    //cout << " Tu commences, qui veux tu attaquer (1,2...): " << endl;
    //for (int i = 0; i < PersonnageArene.size(); i++) {
    //    if (PersonnageArene[i].getPrenom() != choixPrenom) {
    //        std::cout << i +1 << ". " << PersonnageArene[i].getPrenom() << " | vie " << PersonnageArene[i].getVie() << endl;
    //    }
    //}
    //int choixPersoAttaque;
    //cin >> choixPersoAttaque;
    //aure.afficherAbility();
    //cout << "Avec quelle ability :  ";
    //int choixAttaque;
    //cin >> choixAttaque;

    //PersonnageArene[choixPersoAttaque-1].degat(aure.returnAbility(choixAttaque - 1).getDegat());

    //for (int i = 0; i < PersonnageArene.size(); i++) {
    //    std::cout << i + 1 << ". " << PersonnageArene[i].getPrenom() << " | vie " << PersonnageArene[i].getVie() << endl;
    //}
}
