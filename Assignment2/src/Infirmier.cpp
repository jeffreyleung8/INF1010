/**************************************************
* Titre: Travail pratique #2 - Infirmier.cpp
* Date:  9 février 2017
* Auteur: Jeffrey Leung et Xavier Ralay
* Matricule: 1867781 & 1786307
**************************************************/

#include "Infirmier.h"
#include <iostream>
#include <iomanip>
#include "Const.h"

/****************************************************************************
* Fonction: Infirmier::Infirmier
* Description: Constructeur par défaut
* Paramètres: Aucun
* Retour: Aucun
****************************************************************************/
Infirmier::Infirmier()
	: nom_(""), prenom_(""), nbChambre_(0)
{
}

/****************************************************************************
* Fonction: Infirmier::Infirmier(const std::string & nom, const std::string & prenom, unsigned int nbChambre)
* Description: Constructeur par paramètres
* Paramètres: nom(string), prenom(string), nbChambre(unsigned int)
* Retour: Aucun
****************************************************************************/
Infirmier::Infirmier(const std::string & nom, const std::string & prenom, unsigned int nbChambre)
	: nom_(nom), prenom_(prenom), nbChambre_(nbChambre)
{
}

/****************************************************************************
* Fonction: Infirmier::~Infirmier()
* Description: Destructeur
* Paramètres: Aucun
* Retour: Aucun
****************************************************************************/
Infirmier::~Infirmier()
{
}

/****************************************************************************
* Fonction: std::string Infirmier::obtenirNom() const
* Description: Retourne le nom d'un infirmier
* Paramètres: Aucun
* Retour: nom_ (string)
****************************************************************************/
std::string Infirmier::obtenirNom() const
{
	return nom_;
}

/****************************************************************************
* Fonction: std::string Infirmier::obtenirPrenom() const
* Description: Retourne le prenom d'un infirmier
* Paramètres: Aucun
* Retour: prenom_ (string)
****************************************************************************/
std::string Infirmier::obtenirPrenom() const
{
	return prenom_;
}

/****************************************************************************
 * Fonction: string Infirmier::obtenirNomComplet() const
 * Description: Retourne le nom complet d'un infirmier avec un espace
 *				entre le prénom et le nom
 * Paramètres: Aucun
 * Retour: un nom complet (string)
 ****************************************************************************/
std::string Infirmier::obtenirNomComplet() const
{
	return std::string(prenom_+" "+nom_);
}

/****************************************************************************
* Fonction: string Infirmier::obtenirNbChambre() const
* Description: Retourne le numéro de chambres d'un infirmier
* Paramètres: Aucun
* Retour: nChambre_ (int)
****************************************************************************/
unsigned int Infirmier::obtenirNbChambre() const
{
	return nbChambre_;
}

/****************************************************************************
* Fonction: void Infirmier::modifierNom(const std::string & nom)
* Description: Modifie le nom d'un infirmier
* Paramètres: nom (string)
* Retour: Aucun
****************************************************************************/
void Infirmier::modifierNom(const std::string & nom)
{
	nom_ = nom;
}

/****************************************************************************
* Fonction: void Infirmier::modifierPrenom(const std::string & prenom)
* Description: Modifie le prenom d'un infirmier
* Paramètres: prenom (string)
* Retour: Aucun
****************************************************************************/
void Infirmier::modifierPrenom(const std::string & prenom)
{
	prenom_ = prenom;
}

/****************************************************************************
* Fonction: void Infirmier::modifierNbChambre(unsigned int nbChambre)
* Description: Modifie le numéro de chambres d'un infirmier
* Paramètres: nbChambre (int)
* Retour: Aucun
****************************************************************************/
void Infirmier::modifierNbChambre(unsigned int nbChambre)
{
	nbChambre_ = nbChambre;
}

/****************************************************************************
* Fonction:std::ostream & operator<<(std::ostream & os, const Infirmier & infirmier)
* Description: L'opérateur << (chevron) pour affichage
* Paramètres In: infirmier (Infirmier) par valeur
* Paramètres In/Out: os (Ostream pour affichage)
*****************************************************************************/
std::ostream & operator<<(std::ostream & os, const Infirmier & infirmier)
{
	os << "| " << infirmier.obtenirNomComplet() << AFFICHER_ESPACE(espace_nom - infirmier.obtenirNomComplet().size());
	os << " | " << AFFICHER_ESPACE(espace_chambre - std::to_string(infirmier.nbChambre_).size() / 2);
	os << infirmier.nbChambre_ << AFFICHER_ESPACE(espace_chambre);
	os << "|" << std::endl;
	return os;
}

/*****************************************************************************
* Fonction:bool Infirmier::operator==(const Infirmier & infirmier) const
* Description: Surcharge de l'opérateur == 
*			   Compare le nom complet de deux infirmiers (infirmier1==infirmier2)
* Paramètre: infirmier (Infirmier)
* Retour: Bool -> Vrai si infirmier1==infimier2 ou Faux si infirmier1!==infirmier2
******************************************************************************/
bool Infirmier::operator==(const Infirmier & infirmier) const
{
	return (obtenirNomComplet() == infirmier.obtenirNomComplet());
}

/*****************************************************************************
* Fonction: bool Infirmier::operator==(const std::string & nomComplet)
* Description: L'opérateur == est surchargé.
*			   Il compare le nom complet de deux infirmiers (infirmier1==nomComplet)
* Paramètre: nomComplet  (string)
* Retour: Bool -> Vrai si infirmier1==nomComplet ou Faux si infirmier1!==nomComplet
******************************************************************************/
bool Infirmier::operator==(const std::string & nomComplet) const
{
	return (obtenirNomComplet()==nomComplet);
}


/*****************************************************************************
* Fonction: bool operator==(const std::string & nomComplet, const Infirmier & infirmier)
* Description: L'opérateur == est surchargé.
*			    Il compare le nom complet de deux infirmiers (nomComplet==infirmier1)
* Paramètre: nomComplet  (string), infirmier (objet d'une classe Infirmier)
* Retour: Bool -> Vrai si nomComplet==infirmier1 ou Faux si nomComplet!==infirmier1
******************************************************************************/
bool operator==(const std::string & nomComplet, const Infirmier & infirmier)
{
	return (nomComplet==infirmier.obtenirNomComplet());
}
