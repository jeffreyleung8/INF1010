/********************************************
* Titre: Travail pratique #1 - Medecin.h
* Date: 10 janvier 2017
* Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
*******************************************/

#ifndef INFIRMIER_H
#define INFIRMIER_H

#include <string>
#include <iostream>
using namespace std;

class Infirmier
{
public:
	// Constructeurs par defaut et par parametre
	Infirmier();
	Infirmier(string nom, string prenom, int nbChambre);

	// Methodes d'acces
	string obtenirNom()const;
	string obtenirPrenom()const;
	int obtenirNbChambre()const;


	// Methodes de modification
	void modifierNom(string nom);
	void modifierPrenom(string prenom);
	void modifierNbChambre(int nbChambre);
	void afficherInfirmier()const; // une methode que nous avons creee pour afficher un infirmier

private:

	// Variables privees
	string nom_;
	string prenom_;
	int nbChambre_;
};
#endif