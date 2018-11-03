/**************************************************
* Titre: Travail pratique #2 - Medecin.cpp
* Date:  9 février 2017
* Auteur: Jeffrey Leung et Xavier Ralay
* Matricule: 1867781 & 1786307
**************************************************/

#include "Medecin.h"
#include <iostream>
#include <iomanip>
#include "Const.h"

/****************************************************************************
* Fonction: Medecin::Medecin(const string& nom): 
* Description: Constructeur par paramètre
* Paramètres: nom(string)
* Retour: Aucun
****************************************************************************/
Medecin::Medecin(const string& nom): 
	nom_(nom), horaires_(0)
{
}

/****************************************************************************
* Fonction: Medecin::Medecin(const string& nom, int horaires, Specialite* specialite)
* Description: Constructeur par paramètre
* Paramètres: nom (string), horaires (int) , uneSpecialite (Spécialité de type pointeur)
* Retour: Aucun
****************************************************************************/
Medecin::Medecin(const string& nom, int horaires, Specialite* specialite)
	: nom_(nom), horaires_(horaires), specialite_(specialite)
{
}

/****************************************************************************
* Fonction: Medecin::Medecin
* Description: Constructeur par copie
* Paramètres: unMedecin(un objet de la classe médecin)
* Retour: Aucun
****************************************************************************/
Medecin::Medecin(const Medecin & unMedecin):
	nom_(unMedecin.nom_), horaires_(unMedecin.horaires_), specialite_(unMedecin.specialite_)
{
}

/****************************************************************************
* Fonction: Medecin::~Medecin()
* Description: Destructeur
* Paramètres: Aucun
* Retour: Aucun
****************************************************************************/
Medecin::~Medecin()
{
}

/****************************************************************************
* Fonction: string Medecin::obtenirNom() const
* Description: Retourne le nom d'un médecin
* Paramètres: Aucun
* Retour: nom_ (string)
****************************************************************************/
string Medecin::obtenirNom() const
{
	return nom_;
}

/****************************************************************************
* Fonction: string Medecin::obtenirHoraires() const
* Description: Retourne le nombre d'heures(horaire) d'un médecin
* Paramètres: Aucun
* Retour: horaires_ (int)
****************************************************************************/
int Medecin::obtenirHoraires() const
{
	return horaires_;
}

/****************************************************************************
* Fonction: string Medecin::obtenirSpecialite() const
* Description: Retourne la spécialité d'un médecin
* Paramètres: Aucun
* Retour: *specialite_ (Spécialite)
****************************************************************************/
Specialite Medecin::obtenirSpecialite() const
{
	return *specialite_;
}

/****************************************************************************
* Fonction: string Medecin::modifierNom(const string& nom)
* Description: Modifie le nom d'un médecin
* Paramètres: nom (string)
* Retour: Aucun
****************************************************************************/
void Medecin::modifierNom(const string& nom)
{
	nom_ = nom;
}

/****************************************************************************
* Fonction: string Medecin::modifierHoraires(int horaires)
* Description: Modifie l'horaire d'un médecin
* Paramètres: horaires(int)
* Retour: Aucun
****************************************************************************/
void Medecin::modifierHoraires(int horaires)
{
	horaires_ = horaires;
}

/****************************************************************************
* Fonction: void Medecin::modifierSpecialite(Specialite* specialite)
* Description: Modifie la spécialité d'un médecin
* Paramètres: specialite (Specialite*) 
* Retour: Aucun
****************************************************************************/
void Medecin::modifierSpecialite(Specialite* specialite)
{
	specialite_ = specialite;
}

/*****************************************************************************
* Fonction: Medecin& Medecin::operator=(const Medecin & medecin)
* Description: Surcharge de l'opérateur =  (shallow copie)
*			   Ecrase le médecin(objet initial) par celui passé en paramètres.
* Paramètre: medecin (Medecin) par valeur
* Retour: Objet lui-meme ( *this)
******************************************************************************/
Medecin& Medecin::operator=(const Medecin & medecin)
{
	if (this != &medecin)
	{
		delete specialite_;
		specialite_ = new Specialite;
		specialite_ = medecin.specialite_;
		nom_ = medecin.nom_;
		horaires_ = medecin.horaires_;
	}
	return *this;
}

/****************************************************************************
* Fonction: ostream & operator<<(std::ostream & os, const Medecin & medecin)
* Description: L'opérateur << (chevron) pour affichage
* Paramètres In: medecin (Medecin)
* Paramètres In/Out: os (ostream pour affichage)
*****************************************************************************/
std::ostream & operator<<(std::ostream & os, const Medecin & medecin)
{
	os << "| " << medecin.nom_ << AFFICHER_ESPACE(espace_nom - medecin.nom_.size());
	os << " | " << AFFICHER_ESPACE(espace_horaires - std::to_string(medecin.horaires_).size()) << medecin.horaires_;
	os << AFFICHER_ESPACE(espace_horaires);
	os << medecin.obtenirSpecialite();
	os << endl;
	return os;
}

/*****************************************************************************
* Fonction: bool Medecin::operator==(const Medecin & medecin)
* Description: urcharge de l'opérateur == 
*			   Compare le nom complet de deux infirmiers (medecin1==medecin2)
* Paramètre: medecin  (Medecin)
* Retour: Bool -> Vrai si medecin1==medecin2 ou Faux si medecin1!==medecin2
******************************************************************************/
bool Medecin::operator==(const Medecin & medecin) const
{
	return (nom_ == medecin.nom_);
}

/*****************************************************************************
* Fonction: bool Medecin::operator==(const std::string & nom)
* Description: Surcharge de l'opérateur == 
*			   Compare le nom complet de deux infirmiers (medecin==nom)
* Paramètre: nom (string)
* Retour: Bool -> Vrai si medecin==nom ou Faux si medecin!==nom
******************************************************************************/
bool Medecin::operator==(const std::string & nom) const
{
	return (nom_ == nom);
}

/*****************************************************************************
* Fonction: bool operator==(const std::string & nom, const Medecin & medecin)
* Description: Surcharge de l'opérateur ==
*			   Compare le nom complet de deux infirmiers (nom==medecin)
* Paramètre: nom (string) et medecin (Medecin)
* Retour: Bool -> Vrai si nom==medecin ou Faux si nom!==medecin
******************************************************************************/
bool operator==(const std::string & nom, const Medecin & medecin)
{
	return (nom == medecin);
}
