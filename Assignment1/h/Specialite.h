/********************************************
* Titre: Travail pratique #1 - Medecin.h
* Date: 10 janvier 2017
* Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
*******************************************/

#ifndef SPECIALITE_H
#define SPECIALITE_H

#include <string>
using namespace std;

class Specialite
{
public:
	// Constructeurs par defaut et par parametre
	Specialite();
	Specialite(string domaine, int niveau);
	~Specialite();

	// Methodes d'acces
	string obtenirDomaine()const;
	int obtenirNiveau()const;

	// Methodes de modification
	void modifierDomaine(string domaine);
	void modifierNiveau(int niveau);
	void afficherSpecialite()const;  // une methode que nous avons creee pour afficher la specialite

private:

	// Variables privees
	string domaine_;
	int niveau_;
	
};
#endif