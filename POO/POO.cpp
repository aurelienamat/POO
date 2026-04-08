// POO.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Personnage.hpp"
#include "ability.hpp"
#include "ui.hpp"

using namespace std;


void deleteNew() {
    vector<ability*> Liste = ability::getListeAbility();

    for (int i = 0; i < Liste.size(); i++) {
        delete Liste[i];
    }
}

void tourAutre(vector<Personnage*> &PersonnageArene, string choixPrenom) {
    Personnage* WhoAttack;
    do {
        WhoAttack = PersonnageArene[rand() % PersonnageArene.size()];
    } while (WhoAttack->getPrenom() == choixPrenom);

    printTitle("TOUR ENEMIE");

    Personnage* WhoToAttack;
    do {
        WhoToAttack = PersonnageArene[rand() % PersonnageArene.size()];
    } while (WhoToAttack->getPrenom() == WhoAttack->getPrenom());

    ability* ab = WhoAttack->returnAbility(rand() % WhoAttack->getNbAbility());
    cout << YELLOW << "  >> " << BOLD << WhoAttack->getPrenom() << RESET
         << YELLOW << " utilise " << MAGENTA << BOLD << ab->getNom() << RESET
         << YELLOW << " sur " << BOLD << WhoToAttack->getPrenom() << RESET << "\n";

    WhoToAttack->degat(ab->getDegat());
}

Personnage* findPerso(string choixPrenom) {
    for (int i = 0; i < Personnage::nbPerso(); i++) {
        if (Personnage::returnPersonnage(i)->getPrenom() == choixPrenom) {
            return Personnage::returnPersonnage(i);
        }
    }
    //Retourne le premier perso de la liste tant pis
    return Personnage::returnPersonnage(0);
}

//Fonction qui vérifie si il est toujours en vie
bool InLive(vector<Personnage*> PersonnageArene) {
    for (int i = 0; i < PersonnageArene.size(); i++) {
        if (PersonnageArene[i]->getVie() <= 0) {
            return 1;
        }
    }
    return 0;
}

//Fonction de combat
void combat(vector<Personnage*> &PersonnageArene, string choixPrenom) {
    Personnage* aure = findPerso(choixPrenom);

    printTitle("ENTREE DANS L'ARENE");
    for (int i = 0; i < Personnage::nbPerso(); i++) {
        PersonnageArene.push_back(Personnage::returnPersonnage(i));
        cout << GREEN << "  + " << BOLD << PersonnageArene[i]->getPrenom() << RESET << GREEN << " a rejoint l'arene !\n" << RESET;
    }

    while (InLive(PersonnageArene) == 0)
    {
        printTitle("VOTRE TOUR");

        cout << YELLOW << "  Cibles disponibles :\n" << RESET;
        for (int i = 0; i < PersonnageArene.size(); i++) {
            if (PersonnageArene[i]->getPrenom() != choixPrenom) {
                cout << CYAN << "  " << i + 1 << ". " << BOLD << PersonnageArene[i]->getPrenom() << RESET << "  ";
                printHealthBar(PersonnageArene[i]->getVie());
                cout << "\n";
            }
        }

        cout << "\n" << WHITE << "  Qui attaquer ? " << RESET;
        int choixPersoAttaque;
        do {
            cin >> choixPersoAttaque;
        } while (choixPersoAttaque > (int)PersonnageArene.size() || choixPersoAttaque < 1);

        aure->afficherAbility();
        cout << "\n" << WHITE << "  Quelle ability ? " << RESET;
        int choixAttaque;
        do {
            cin >> choixAttaque;
        } while (choixAttaque > aure->getNbAbility() || choixAttaque < 1);

        ability* ab = aure->returnAbility(choixAttaque - 1);
        cout << "\n" << CYAN << "  >> " << BOLD << choixPrenom << RESET
             << CYAN << " utilise " << MAGENTA << BOLD << ab->getNom() << RESET
             << CYAN << " sur " << BOLD << PersonnageArene[choixPersoAttaque - 1]->getPrenom() << RESET << "\n";

        PersonnageArene[choixPersoAttaque - 1]->degat(ab->getDegat());

        printSeparator('-');
        tourAutre(PersonnageArene, choixPrenom);
        printSeparator('-');
    }

    printTitle("FIN DU COMBAT");
    /*cout << GREEN << BOLD << "  Survivants :\n" << RESET;
    for (int i = 0; i < PersonnageArene.size(); i++) {
        if (PersonnageArene[i]->getVie() > 0) {
            cout << "  " << CYAN << BOLD << PersonnageArene[i]->getPrenom() << RESET << "  ";
            printHealthBar(PersonnageArene[i]->getVie());
            cout << "\n";
        }
    }
    cout << "\n";*/
}

int main()
{
    enableANSI();
    srand(time(0));

    printBanner();

    // Création des abilities
    new ability("SoinI", -10, 10);
    new ability("Morsure", 15, 0);
    new ability("Boule de feu", 10, 20);

    // Création des PNJ
    Personnage goliath("Goliath"), david("David");

    printTitle("CREATION DE VOTRE PERSONNAGE");
    cout << WHITE << "  Votre nom : " << RESET;
    string choixPrenom;
    cin >> choixPrenom;

    Personnage aure(choixPrenom);
    cout << "\n";
    printSeparator('-');
    aure.afficher();
    aure.afficherAbility();
    printSeparator('-');

    cout << "\n" << WHITE << "  Appuyez sur Entree pour continuer..." << RESET;
    getchar(); getchar();

    printTitle("CHOISIR UNE ABILITY");
    ability::afficherListeAbility();
    cout << "\n" << WHITE << "  Votre choix : " << RESET;
    int choixNomAbility;
    do {
        cin >> choixNomAbility;
    } while (choixNomAbility > (int)ability::getListeAbility().size() || choixNomAbility < 1);

    aure.addAbility(ability::returnAbility(choixNomAbility - 1));
    cout << "\n";
    aure.afficherAbility();

    cout << "\n" << YELLOW << BOLD << "  Pret pour le combat ? Appuyez sur Entree..." << RESET;
    getchar(); getchar();

    vector<Personnage*> PersonnageArene;
    combat(PersonnageArene, choixPrenom);

    cout << GREEN << BOLD << "  Survivants :\n" << RESET;
    for (int i = 0; i < PersonnageArene.size(); i++) {
        if (PersonnageArene[i]->getVie() > 0) {
            cout << "  " << CYAN << BOLD << PersonnageArene[i]->getPrenom() << RESET << "  ";
            printHealthBar(PersonnageArene[i]->getVie());
            cout << "\n";
        }
    }
    cout << "\n";

    deleteNew();
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
