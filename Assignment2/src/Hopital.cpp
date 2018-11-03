/**************************************************
* Titre: Travail pratique #2 - Hopital.cpp
* Date:  9 f�vrier 2017
* Auteur: Jeffrey Leung et Xavier Ralay
* Matricule: 1867781 & 1786307
**************************************************/

#include "Hopital.h"
#include <iostream>
#include <iomanip>
#include "Const.h"

/****************************************************************************
* Fonction: Hopital::Hopital(const std::string & nom, Personnel* personnel)
* Description: Constructeur par parametres
* Param�tres: nom (string), personnel (Personnel de type pointeur)
* Retour: Aucun
****************************************************************************/
Hopital::Hopital(const std::string & nom, Personnel* personnel)
	: nom_(nom), personnel_(personnel)
{
}

/****************************************************************************
* Fonction: Hopital::~Hopital()
* Description: Destructeur (Delete pointeur personnel_)
* Param�tres: Aucun
* Retour: Aucun
****************************************************************************/
Hopital::~Hopital()
{
	delete personnel_;
}

/****************************************************************************
* Fonction: std::string Hopital::obtenirNom() const
* Description: Retourne le nom de l'hopital
* Param�tres: Aucun
* Retour: nom_ (string)
****************************************************************************/
std::string Hopital::obtenirNom() const
{
	return nom_;
}

/****************************************************************************
* Fonction: Personnel Hopital::obtenirPersonnel() const
* Description: Retourne le pointeur personnel
* Param�tres: Aucun
* Retour: personnel_ (Personnel de type pointeur)
****************************************************************************/
Personnel Hopital::obtenirPersonnel() const
{
	return *personnel_; 
}

/****************************************************************************
* Fonction: void Hopital::modifierNom(const std::string & nom)
* Description: Modifie le nom de l'hopital
* Param�tres: nom (string)
* Retour: Aucun
****************************************************************************/
void Hopital::modifierNom(const std::string & nom)
{
	nom_ = nom;
}

/****************************************************************************
* Fonction: void Hopital::modifierPersonnel(Personnel * personnel)
* Description: Modifie le contenu pointe par personnel
* Param�tres: personnel (Personnel de type pointeur)
* Retour: Aucun
****************************************************************************/
void Hopital::modifierPersonnel(Personnel * personnel)
{
	personnel_ = personnel;
}

/****************************************************************************
* Fonction: std::ostream & operator<<(ostream & os, const Hopital & hopital)
* Description: Surcharge de l'operateur << (pour affichage)
* Param�tres In: hopital (hopital) par valeur
* Parametres In/Out: os (ostream pour affichage)
****************************************************************************/
std::ostream & operator<<(ostream & os, const Hopital & hopital)
{
	//Affichage centree du nom de l'hopital
	string tabMed = "Tableau Medecins";

	for (int i = 0; i < (tabMed.size()+espacement_medecin-hopital.nom_.size())/2; i++) {
		os << " ";
	}

	os << hopital.nom_;

	for (int i = 0; i < (tabMed.size()+espacement_medecin - hopital.nom_.size()) / 2; i++) {
		os << " ";
	}
	os << endl;

	for (int i = 0; i < tabMed.size()+espacement_medecin; i++) {
		os << "=";
	}
	os << endl;
	
	//Affichage du personnel (medecin/infirmier)
	os << *hopital.personnel_<<endl;
	return os;
}
