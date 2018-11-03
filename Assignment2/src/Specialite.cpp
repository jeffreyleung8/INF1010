/**************************************************
* Titre: Travail pratique #2 - Specialite.cpp
* Date:  9 février 2017
* Auteur: Jeffrey Leung et Xavier Ralay
* Matricule: 1867781 & 1786307
**************************************************/

#include "Specialite.h"
#include <iostream>
#include <iomanip>
#include "Const.h"

/****************************************************************************
* Fonction: Specialite::Specialite
* Description: Constructeur par défaut
* Paramètres: Aucun
* Retour: Aucun
****************************************************************************/
Specialite::Specialite()
{
}

/****************************************************************************
* Fonction: Specialite::Specialite
* Description: Constructeur par paramètres
* Paramètres: domaine (string) par valeur
*			  niveau (int) par valeur
* Retour: Aucun
****************************************************************************/
Specialite::Specialite(const std::string & domaine, unsigned int niveau)
	: domaine_(domaine), niveau_(niveau)
{
}

/****************************************************************************
* Fonction: string Infirmier::obtenirDomaine() const
* Description: Retourne le domaine de spécialité d'un médecin
* Paramètres: Aucun
* Retour: domaine_ (string)
****************************************************************************/
std::string Specialite::obtenirDomaine() const
{
	return domaine_;
}

/****************************************************************************
* Fonction: string Infirmier::obtenirNiveau() const
* Description: Retourne le niveau de spécialité d'un médecin
* Paramètres: Aucun
* Retour: niveau_ (int)
****************************************************************************/
unsigned int Specialite::obtenirNiveau() const
{
	return niveau_;
}

/****************************************************************************
* Fonction: string Infirmier::modifierDomaine()
* Description: Modifie le domaine de spécialité d'un médecin
* Paramètres: domaine (string)
* Retour: Aucun
****************************************************************************/
void Specialite::modifierDomaine(const std::string & domaine)
{
	domaine_ = domaine;
}

/****************************************************************************
* Fonction: string Infirmier::modifierNiveau()
* Description: Modifie le niveau de spécialité d'un médecin
* Paramètres: niveau (int)
* Retour: Aucun
****************************************************************************/
void Specialite::modifierNiveau(unsigned int niveau)
{
	niveau_ = niveau;
}

/****************************************************************************
* Fonction: ostream & operator<<(std::ostream & os, const Specialite & specialite)
* Description: L'opérateur << (chevron) pour afficher specialite
* Paramètres In: specialite (Objet de la classe Specialite) 
* Paramètres In/Out: os (ostream pour affichage)
*****************************************************************************/
std::ostream & operator<<(std::ostream & os, const Specialite & specialite)
{
	os << " | " << specialite.domaine_ << AFFICHER_ESPACE(espace_domaine - specialite.domaine_.size());
	os << " | " << AFFICHER_ESPACE(espace_niveau - std::to_string(specialite.niveau_).size()) << specialite.niveau_;
	
	os << AFFICHER_ESPACE(espace_niveau) << " | ";
	return os;
}
