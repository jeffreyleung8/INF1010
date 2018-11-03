/**************************************************
* Titre: Travail pratique #2 - Infirmier.h
* Date:  9 f�vrier 2017
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
	//Constructeur par d�faut
	Infirmier();

	//Constructeur par param�tres
	Infirmier(const std::string& nom, const std::string& prenom, unsigned int nbChambre); 

	//Destructeur
	~Infirmier();

	//M�thodes d'acc�s
	std::string obtenirNom() const; 
	std::string obtenirPrenom() const;
	std::string obtenirNomComplet() const;
	unsigned int obtenirNbChambre() const;

	//M�thodes de modification
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
	//variables priv�es
	std::string nom_;
	std::string prenom_;
	unsigned int nbChambre_;
};
std::ostream& operator<<(std::ostream& os, const Infirmier& infirmier);
bool operator== (const std::string& nomComplet, const Infirmier& infirmier);
#endif
