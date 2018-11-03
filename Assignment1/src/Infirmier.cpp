/**********************************************
* Titre: Travail pratique #1 - Personnel.cpp
* Date: 10 janvier 2017
* Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
*********************************************/

#include "Infirmier.h"
#include <iostream>
#include <iomanip>

using namespace std;

Infirmier::Infirmier()
	:nom_("unknown"), prenom_("unknown"), nbChambre_(0)
{

}
Infirmier::Infirmier(string nom, string prenom, int nbChambre)
	: nom_(nom), prenom_(prenom), nbChambre_(nbChambre)
{

}

string Infirmier:: obtenirNom()const
{
	return nom_;
}
string Infirmier::obtenirPrenom()const
{
	return prenom_;
}
int Infirmier::obtenirNbChambre()const
{
	return nbChambre_;
}


void Infirmier::modifierNom(string nom)
{
	nom_ = nom;
}
void Infirmier::modifierPrenom(string prenom)
{
	prenom_ = prenom;
}
void Infirmier::modifierNbChambre(int nbChambre)
{
	nbChambre_ = nbChambre;
}
void Infirmier::afficherInfirmier()const
{
	cout << "|" << std::left << setw(28) << nom_;
	cout.unsetf(ios_base::left);
	cout << "|" << std::left << setw(28) << prenom_;
	cout.unsetf(ios_base::left);
	cout << "|" << setw(20) << nbChambre_ <<setw(20) <<"|" ;
	cout << endl;
}

