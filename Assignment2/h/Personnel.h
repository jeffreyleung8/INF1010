/**************************************************
* Titre: Travail pratique #2 - Personnel.h
* Date:  9 février 2017
* Auteur: Jeffrey Leung et Xavier Ralay
* Matricule: 1867781 & 1786307
**************************************************/
#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <string>
#include <vector>
#include "Medecin.h"
#include "Infirmier.h"

using namespace std;

class Personnel
{
public:
	// Constructeur par defaut
	Personnel();

	// Destructeur
	~Personnel();
	
	// Methode ajout/retrait de personnel
	bool ajouterMedecin(Medecin* medecin);
	bool retirerMedecin(const std::string& nom);
	bool ajouterInfirmier(Infirmier* infirmier);
	bool retirerInfirmier(const std::string& nom);

	//Methode ajout/retrait de personnel avec operateur
	Personnel& operator+=(Medecin* medecin);
	Personnel& operator-=(Medecin* medecin);
	Personnel& operator+=(Infirmier* infirmier);
	Personnel& operator-=(Infirmier* infirmier);

	//Operateur<< friend pour affichage
	friend std::ostream& operator<<(std::ostream& os, const Personnel& personnel);

private:
	void afficherInfirmiers(ostream& os) const; 
	void afficherMedecins(ostream& os) const; 

	//Tableau vecteur de pointeurs
	vector <Medecin*> medecins_;
	vector <Infirmier*> infirmiers_;
};
std::ostream& operator<<(std::ostream& os, const Personnel& personnel);
#endif