/**************************************************
* Titre: Travail pratique #2 - Specialite.h
* Date:  9 f�vrier 2017
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
	//Constructeur par d�faut
	Specialite();

	//Constructeur par param�tres
	Specialite(const std::string& domaine, unsigned int niveau);

	//M�thodes d'acc�s
	std::string obtenirDomaine() const;
	unsigned int obtenirNiveau() const;

	//M�thodes de modification
	void modifierDomaine(const std::string& domaine);
	void modifierNiveau(unsigned int niveau);

	//Operateur<< friend pour affichage
	friend std::ostream& operator<<(std::ostream& os, const Specialite& specialite);

private:
	//variables priv�es
	std::string domaine_;
	unsigned int niveau_;
};
std::ostream& operator<<(std::ostream& os, const Specialite& specialite);
#endif