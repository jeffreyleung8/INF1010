/**************************************************
* Titre: Travail pratique #2 - Infirmier.cpp
* Date:  9 f�vrier 2017
* Auteur: Jeffrey Leung et Xavier Ralay
* Matricule: 1867781 & 1786307
**************************************************/

#include "Infirmier.h"
#include <iostream>
#include <iomanip>
#include "Const.h"

/****************************************************************************
* Fonction: Infirmier::Infirmier
* Description: Constructeur par d�faut
* Param�tres: Aucun
* Retour: Aucun
****************************************************************************/
Infirmier::Infirmier()
	: nom_(""), prenom_(""), nbChambre_(0)
{
}

/****************************************************************************
* Fonction: Infirmier::Infirmier(const std::string & nom, const std::string & prenom, unsigned int nbChambre)
* Description: Constructeur par param�tres
* Param�tres: nom(string), prenom(string), nbChambre(unsigned int)
* Retour: Aucun
****************************************************************************/
Infirmier::Infirmier(const std::string & nom, const std::string & prenom, unsigned int nbChambre)
	: nom_(nom), prenom_(prenom), nbChambre_(nbChambre)
{
}

/****************************************************************************
* Fonction: Infirmier::~Infirmier()
* Description: Destructeur
* Param�tres: Aucun
* Retour: Aucun
****************************************************************************/
Infirmier::~Infirmier()
{
}

/****************************************************************************
* Fonction: std::string Infirmier::obtenirNom() const
* Description: Retourne le nom d'un infirmier
* Param�tres: Aucun
* Retour: nom_ (string)
****************************************************************************/
std::string Infirmier::obtenirNom() const
{
	return nom_;
}

/****************************************************************************
* Fonction: std::string Infirmier::obtenirPrenom() const
* Description: Retourne le prenom d'un infirmier
* Param�tres: Aucun
* Retour: prenom_ (string)
****************************************************************************/
std::string Infirmier::obtenirPrenom() const
{
	return prenom_;
}

/****************************************************************************
 * Fonction: string Infirmier::obtenirNomComplet() const
 * Description: Retourne le nom complet d'un infirmier avec un espace
 *				entre le pr�nom et le nom
 * Param�tres: Aucun
 * Retour: un nom complet (string)
 ****************************************************************************/
std::string Infirmier::obtenirNomComplet() const
{
	return std::string(prenom_+" "+nom_);
}

/****************************************************************************
* Fonction: string Infirmier::obtenirNbChambre() const
* Description: Retourne le num�ro de chambres d'un infirmier
* Param�tres: Aucun
* Retour: nChambre_ (int)
****************************************************************************/
unsigned int Infirmier::obtenirNbChambre() const
{
	return nbChambre_;
}

/****************************************************************************
* Fonction: void Infirmier::modifierNom(const std::string & nom)
* Description: Modifie le nom d'un infirmier
* Param�tres: nom (string)
* Retour: Aucun
****************************************************************************/
void Infirmier::modifierNom(const std::string & nom)
{
	nom_ = nom;
}

/****************************************************************************
* Fonction: void Infirmier::modifierPrenom(const std::string & prenom)
* Description: Modifie le prenom d'un infirmier
* Param�tres: prenom (string)
* Retour: Aucun
****************************************************************************/
void Infirmier::modifierPrenom(const std::string & prenom)
{
	prenom_ = prenom;
}

/****************************************************************************
* Fonction: void Infirmier::modifierNbChambre(unsigned int nbChambre)
* Description: Modifie le num�ro de chambres d'un infirmier
* Param�tres: nbChambre (int)
* Retour: Aucun
****************************************************************************/
void Infirmier::modifierNbChambre(unsigned int nbChambre)
{
	nbChambre_ = nbChambre;
}

/****************************************************************************
* Fonction:std::ostream & operator<<(std::ostream & os, const Infirmier & infirmier)
* Description: L'op�rateur << (chevron) pour affichage
* Param�tres In: infirmier (Infirmier) par valeur
* Param�tres In/Out: os (Ostream pour affichage)
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
* Description: Surcharge de l'op�rateur == 
*			   Compare le nom complet de deux infirmiers (infirmier1==infirmier2)
* Param�tre: infirmier (Infirmier)
* Retour: Bool -> Vrai si infirmier1==infimier2 ou Faux si infirmier1!==infirmier2
******************************************************************************/
bool Infirmier::operator==(const Infirmier & infirmier) const
{
	return (obtenirNomComplet() == infirmier.obtenirNomComplet());
}

/*****************************************************************************
* Fonction: bool Infirmier::operator==(const std::string & nomComplet)
* Description: L'op�rateur == est surcharg�.
*			   Il compare le nom complet de deux infirmiers (infirmier1==nomComplet)
* Param�tre: nomComplet  (string)
* Retour: Bool -> Vrai si infirmier1==nomComplet ou Faux si infirmier1!==nomComplet
******************************************************************************/
bool Infirmier::operator==(const std::string & nomComplet) const
{
	return (obtenirNomComplet()==nomComplet);
}


/*****************************************************************************
* Fonction: bool operator==(const std::string & nomComplet, const Infirmier & infirmier)
* Description: L'op�rateur == est surcharg�.
*			    Il compare le nom complet de deux infirmiers (nomComplet==infirmier1)
* Param�tre: nomComplet  (string), infirmier (objet d'une classe Infirmier)
* Retour: Bool -> Vrai si nomComplet==infirmier1 ou Faux si nomComplet!==infirmier1
******************************************************************************/
bool operator==(const std::string & nomComplet, const Infirmier & infirmier)
{
	return (nomComplet==infirmier.obtenirNomComplet());
}
