/**************************************************
* Titre: Travail pratique #2 - Medecin.h
* Date:  9 février 2017
* Auteur: Jeffrey Leung et Xavier Ralay
* Matricule: 1867781 & 1786307
**************************************************/

#ifndef MEDECIN_H
#define MEDECIN_H

#include <string>
#include "Specialite.h"

using namespace std;

class Medecin 
{
public:
	// Constructeurs par parametre
	Medecin(const string& nom); 
	Medecin(const string& nom, int horaires, Specialite* specialite);

	//Constructeur par copie
	Medecin(const Medecin& unMedecin);

	//Destructeur
	~Medecin();
	
	// Methodes d'acces
	string obtenirNom() const;
	int obtenirHoraires() const;
	Specialite obtenirSpecialite() const;
	
	// Methodes de modification
	void modifierNom(const string& nom);
	void modifierHoraires(int horaires);
	void modifierSpecialite(Specialite* specialite);

	//Opérateur=
	Medecin& operator=(const Medecin& medecin);

	//Operateur<< friend pour affichage
	friend std::ostream& operator<<(std::ostream& os, const Medecin& medecin);

	//Operateurs==
	bool operator==(const Medecin& medecin) const;
	bool operator==(const std::string& nom) const;
	friend bool operator==(const std::string& nom, const Medecin& medecin);

private:
	// Variables privees
	string nom_;
	int horaires_;
	Specialite* specialite_;
	
};
std::ostream& operator<<(std::ostream& os, const Medecin& medecin);
bool operator== (const std::string& nom, const Medecin& medecin);

#endif