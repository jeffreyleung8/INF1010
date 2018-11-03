/**********************************************
* Titre: Travail pratique #1 - Personnel.cpp
* Date: 10 janvier 2017
* Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
*********************************************/

#include "Specialite.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Constructeurs par defaut et par parametre
Specialite::Specialite()
	:domaine_("unknown"), niveau_(0)
{
}

//Destructeur
Specialite::~ Specialite()
{
}

Specialite::Specialite(string domaine, int niveau)
	: domaine_(domaine), niveau_(niveau)
{
}


// Methodes d'acces
string Specialite::obtenirDomaine()const
{
	return domaine_;
}
int Specialite::obtenirNiveau()const
{
	return niveau_;
}

// Methodes de modification
void Specialite::modifierDomaine(string domaine)
{
	domaine_ = domaine;
}
void Specialite::modifierNiveau(int niveau)
{
	niveau_ = niveau;
}

void Specialite::afficherSpecialite()const
{
	cout << std::left << setw(28) << domaine_;
	cout.unsetf(ios_base::left);
	cout << "|" << setw(14) << niveau_ << setw(15) << "|";
}