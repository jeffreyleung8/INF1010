/**************************************************
* Titre: Travail pratique #2 - Hopital.h
* Date:  9 f�vrier 2017
* Auteur: Jeffrey Leung et Xavier Ralay
* Matricule: 1867781 & 1786307
**************************************************/
#ifndef HOPITAL_H
#define HOPITAL_H

#include "Personnel.h"
#include <string>
#include <iostream>
#include <vector>

class Hopital
{
public:
	Hopital(const std::string& nom, Personnel* personnel);
	~Hopital();

	//M�thode d'acc�s
	std::string obtenirNom() const;
	Personnel obtenirPersonnel() const;

	//M�thode de modification
	void modifierNom(const std::string& nom);
	void modifierPersonnel(Personnel* personnel);

	//Op�rateur friend pour affichage
	friend std::ostream& operator<<(ostream& os, const Hopital& hopital);

private:
	std::string nom_;
	Personnel* personnel_;

};
std::ostream& operator<<(ostream& os, const Hopital& hopital);
#endif