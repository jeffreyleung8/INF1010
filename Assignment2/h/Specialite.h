/**************************************************
* Titre: Travail pratique #2 - Specialite.h
* Date:  9 février 2017
* Auteur: Jeffrey Leung et Xavier Ralay
* Matricule: 1867781 & 1786307
**************************************************/

#ifndef SPECIALITE_H
#define SPECIALITE_H

#include <string>
#include <iostream>

class Specialite
{
public:
	//Constructeur par défaut
	Specialite();

	//Constructeur par paramètres
	Specialite(const std::string& domaine, unsigned int niveau);

	//Méthodes d'accès
	std::string obtenirDomaine() const;
	unsigned int obtenirNiveau() const;

	//Méthodes de modification
	void modifierDomaine(const std::string& domaine);
	void modifierNiveau(unsigned int niveau);

	//Operateur<< friend pour affichage
	friend std::ostream& operator<<(std::ostream& os, const Specialite& specialite);

private:
	//variables privées
	std::string domaine_;
	unsigned int niveau_;
};
std::ostream& operator<<(std::ostream& os, const Specialite& specialite);
#endif