/**********************************************
 * Titre: Travail pratique #1 - Personnel.h
 * Date: 10 janvier 2017
 * Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
 *********************************************/

#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <string>
#include <string>

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

	// Methodes publiques
	void ajouterMedecin(Medecin& unMedecin);
	void ajouterInfirmier(Infirmier& unInfirmier);

	void afficherMedecins()const;
	void afficherInfirmiers()const;

private:

	// Variables privees
	Medecin*   tableauMedecins_;
	Infirmier* tableauInfirmiers_;

	unsigned int compteurMedecin_;
	unsigned int compteurInfirmier_;

	unsigned int capaciteTableauMedecins_;
	unsigned int capaciteTableauInfirmiers_;
};

#endif
