/****************************************************************************
* Fichier     : main.cpp
* Auteur      : Jeffrey Leung 1867781 et Xavier Ralay 1786307
* Travail     : TP5
* Description : Main
***************************************************************************/
#include <iostream>
#include <string>
#include "Pile.h"
#include <utility> 


using namespace std;

int main()
{
    string taches[7] = {"MENAGE", "ETUDE", "EPICERIE", "SPORT", "BENEVOLAT", "LECTURE", "AUTRE"};
    double durees[7] = {1.2, 3.5, 0.8, 2.5, 1.8, 0.75, 10};
    
    // Creer une pile de type "paires STL de (string, double)"
	pair< string, double> unePaire[7];
	for (int i = 0; i < 7; i++) {
		unePaire[i] = make_pair(taches[i], durees[i]);
	}
	
	Pile <pair< string, double>> pile;
	
	
    cout << "Empilage des taches..." << endl;
	for (int i = 0; i < 7; i++) {
		if (!pile.estPleine()) {
			if (pile.empiler(unePaire[i])) {
				cout << "Tache ajoutee sur la pile: " << unePaire[i].first << " d'une duree de " << unePaire[i].second << endl;
			}
		}
		else {
			cout << "La pile est pleine!"<<endl;
		}
	}
	cout << endl;

    // Ajouter les 7 paires correspondant aux tâches et durées ci-haut sur la pile.
    // Vous pouvez ici utiliser une boucle for standard de i = 0 à 7
    // Le programme doit afficher: "Tache ajoutee sur la pile: [nom de la tâche] d'une duree de [durée]"
    //                         ou: "La pile est pleine!"
    //                         selon le succès ou non de l'ajout.

        
    cout << "Depilage des taches..." << endl;
	for (int i = 0; i < 7; i++) {
		if (!pile.estVide()) {
			if (pile.depiler(unePaire[i])) {
				cout << "Depilage de la tache : " << unePaire[i].first << " d'une duree de " << unePaire[i].second << endl;
			}
		}
		else {
			cout << "La pile est vide!" << endl;
		}
	}
	cout << endl;
	
    // Retirer les 7 paires de (tâche,durée) de la pile, ***en assumant que vous ne connaissez pas le nombre d'éléments dans la pile***
    // (utilisez le booléen retourné par la fonction depiler())
    // Le programme doit afficher: "Depilage de la tache: [nom de la tâche] d'une duree de [durée]"
    //                         ou: "La pile est vide!"
    //                         selon le cas.

    


    system("pause");

	return 0;
}