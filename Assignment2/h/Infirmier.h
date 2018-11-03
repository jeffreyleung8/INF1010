/**************************************************
* Titre: Travail pratique #2 - Infirmier.h
* Date:  9 février 2017
* Auteur: Jeffrey Leung et Xavier Ralay
* Matricule: 1867781 & 1786307
**************************************************/

#ifndef INFIRMIER_H
#define INFIRMIER_H

#include <string>
#include <iostream>

class Infirmier
{
public:
	//Constructeur par défaut
	Infirmier();

	//Constructeur par paramètres
	Infirmier(const std::string& nom, const std::string& prenom, unsigned int nbChambre); 

	//Destructeur
	~Infirmier();

	//Méthodes d'accès
	std::string obtenirNom() const; 
	std::string obtenirPrenom() const;
	std::string obtenirNomComplet() const;
	unsigned int obtenirNbChambre() const;

	//Méthodes de modification
	void modifierNom(const std::string& nom);
	void modifierPrenom(const std::string& prenom);
	void modifierNbChambre(unsigned int nbChambre);

	//Operateur<< friend pour affichage
	friend std::ostream& operator<<(std::ostream& os, const Infirmier& infirmier);

	//Operateur==
	bool operator==(const Infirmier& infirmier) const;
	bool operator==(const std::string& nomComplet) const;
	friend bool operator==(const std::string& nomComplet, const Infirmier& infirmier);

private:
	//variables privées
	std::string nom_;
	std::string prenom_;
	unsigned int nbChambre_;
};
std::ostream& operator<<(std::ostream& os, const Infirmier& infirmier);
bool operator== (const std::string& nomComplet, const Infirmier& infirmier);
#endif
