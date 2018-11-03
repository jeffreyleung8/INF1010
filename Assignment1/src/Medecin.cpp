/********************************************
 * Titre: Travail pratique #1 - Medecin.cpp
 * Date: 10 janvier 2017
 * Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
 *******************************************/

#include"Medecin.h"
#include <iostream>
#include <iomanip>
using namespace std;


Medecin :: Medecin()
    :nom_("unknown"),horaires_(0),specialite_(nullptr)
{
}

Medecin :: Medecin(string nom, int horaires,Specialite* uneSpecialite)
    :nom_(nom),horaires_(horaires),specialite_(uneSpecialite)
{
}

Medecin ::~ Medecin()
{
    
}
string Medecin :: obtenirNom()const
{
    return nom_;
}

int Medecin ::obtenirHoraires()const
{
    return horaires_;
}

Specialite* Medecin :: obtenirSpecialite()const
{
    return specialite_;
}

void Medecin :: modifierNom(string nom)
{
    nom_ = nom;
}

void Medecin :: modifierHoraires(int horaires)
{
    horaires_ = horaires;
}

void Medecin :: modifierSpecialite(Specialite* specialite)
{
    specialite_ = specialite;
}

void Medecin::afficherMedecin()const
{
	cout << "|" << std::left << setw(28) << nom_;
	cout.unsetf(ios_base::left);
	cout << "|" << setw(14) << horaires_ << setw(15) << "|";
	specialite_->afficherSpecialite();
	cout << endl;
}