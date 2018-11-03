/**************************************************
* Titre: Travail pratique #2 - Medecin.cpp
* Date:  9 f�vrier 2017
* Auteur: Jeffrey Leung et Xavier Ralay
* Matricule: 1867781 & 1786307
**************************************************/

#include "Medecin.h"
#include <iostream>
#include <iomanip>
#include "Const.h"

/****************************************************************************
* Fonction: Medecin::Medecin(const string& nom): 
* Description: Constructeur par param�tre
* Param�tres: nom(string)
* Retour: Aucun
****************************************************************************/
Medecin::Medecin(const string& nom): 
	nom_(nom), horaires_(0)
{
}

/****************************************************************************
* Fonction: Medecin::Medecin(const string& nom, int horaires, Specialite* specialite)
* Description: Constructeur par param�tre
* Param�tres: nom (string), horaires (int) , uneSpecialite (Sp�cialit� de type pointeur)
* Retour: Aucun
****************************************************************************/
Medecin::Medecin(const string& nom, int horaires, Specialite* specialite)
	: nom_(nom), horaires_(horaires), specialite_(specialite)
{
}

/****************************************************************************
* Fonction: Medecin::Medecin
* Description: Constructeur par copie
* Param�tres: unMedecin(un objet de la classe m�decin)
* Retour: Aucun
****************************************************************************/
Medecin::Medecin(const Medecin & unMedecin):
	nom_(unMedecin.nom_), horaires_(unMedecin.horaires_), specialite_(unMedecin.specialite_)
{
}

/****************************************************************************
* Fonction: Medecin::~Medecin()
* Description: Destructeur
* Param�tres: Aucun
* Retour: Aucun
****************************************************************************/
Medecin::~Medecin()
{
}

/****************************************************************************
* Fonction: string Medecin::obtenirNom() const
* Description: Retourne le nom d'un m�decin
* Param�tres: Aucun
* Retour: nom_ (string)
****************************************************************************/
string Medecin::obtenirNom() const
{
	return nom_;
}

/****************************************************************************
* Fonction: string Medecin::obtenirHoraires() const
* Description: Retourne le nombre d'heures(horaire) d'un m�decin
* Param�tres: Aucun
* Retour: horaires_ (int)
****************************************************************************/
int Medecin::obtenirHoraires() const
{
	return horaires_;
}

/****************************************************************************
* Fonction: string Medecin::obtenirSpecialite() const
* Description: Retourne la sp�cialit� d'un m�decin
* Param�tres: Aucun
* Retour: *specialite_ (Sp�cialite)
****************************************************************************/
Specialite Medecin::obtenirSpecialite() const
{
	return *specialite_;
}

/****************************************************************************
* Fonction: string Medecin::modifierNom(const string& nom)
* Description: Modifie le nom d'un m�decin
* Param�tres: nom (string)
* Retour: Aucun
****************************************************************************/
void Medecin::modifierNom(const string& nom)
{
	nom_ = nom;
}

/****************************************************************************
* Fonction: string Medecin::modifierHoraires(int horaires)
* Description: Modifie l'horaire d'un m�decin
* Param�tres: horaires(int)
* Retour: Aucun
****************************************************************************/
void Medecin::modifierHoraires(int horaires)
{
	horaires_ = horaires;
}

/****************************************************************************
* Fonction: void Medecin::modifierSpecialite(Specialite* specialite)
* Description: Modifie la sp�cialit� d'un m�decin
* Param�tres: specialite (Specialite*) 
* Retour: Aucun
****************************************************************************/
void Medecin::modifierSpecialite(Specialite* specialite)
{
	specialite_ = specialite;
}

/*****************************************************************************
* Fonction: Medecin& Medecin::operator=(const Medecin & medecin)
* Description: Surcharge de l'op�rateur =  (shallow copie)
*			   Ecrase le m�decin(objet initial) par celui pass� en param�tres.
* Param�tre: medecin (Medecin) par valeur
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
* Description: L'op�rateur << (chevron) pour affichage
* Param�tres In: medecin (Medecin)
* Param�tres In/Out: os (ostream pour affichage)
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
* Description: urcharge de l'op�rateur == 
*			   Compare le nom complet de deux infirmiers (medecin1==medecin2)
* Param�tre: medecin  (Medecin)
* Retour: Bool -> Vrai si medecin1==medecin2 ou Faux si medecin1!==medecin2
******************************************************************************/
bool Medecin::operator==(const Medecin & medecin) const
{
	return (nom_ == medecin.nom_);
}

/*****************************************************************************
* Fonction: bool Medecin::operator==(const std::string & nom)
* Description: Surcharge de l'op�rateur == 
*			   Compare le nom complet de deux infirmiers (medecin==nom)
* Param�tre: nom (string)
* Retour: Bool -> Vrai si medecin==nom ou Faux si medecin!==nom
******************************************************************************/
bool Medecin::operator==(const std::string & nom) const
{
	return (nom_ == nom);
}

/*****************************************************************************
* Fonction: bool operator==(const std::string & nom, const Medecin & medecin)
* Description: Surcharge de l'op�rateur ==
*			   Compare le nom complet de deux infirmiers (nom==medecin)
* Param�tre: nom (string) et medecin (Medecin)
* Retour: Bool -> Vrai si nom==medecin ou Faux si nom!==medecin
******************************************************************************/
bool operator==(const std::string & nom, const Medecin & medecin)
{
	return (nom == medecin);
}
