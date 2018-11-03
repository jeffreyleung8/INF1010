/**********************************************
 * Titre: Travail pratique #1 - Personnel.cpp
 * Date: 10 janvier 2017
 * Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
 *********************************************/



#include "Medecin.h"
#include "Infirmier.h"
#include "Personnel.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

Personnel::Personnel()
    :compteurMedecin_(0),
    compteurInfirmier_(0),capaciteTableauMedecins_(3),capaciteTableauInfirmiers_(3) 
{
	tableauMedecins_ = new Medecin[capaciteTableauMedecins_];   //alloue initialement 3 espaces
	tableauInfirmiers_ = new Infirmier[capaciteTableauInfirmiers_]; //alloue initialement 3 espaces
}

Personnel::~Personnel()
{
    delete []tableauMedecins_;
    delete []tableauInfirmiers_;
}

void Personnel::ajouterMedecin(Medecin& unMedecin)
{
	 if (compteurMedecin_ >= capaciteTableauMedecins_) {  //double la capacite lorsque la capacite est insuffisante
		
		unsigned int newCapacite = capaciteTableauMedecins_ * 2;
		Medecin * temp = new Medecin[newCapacite];

		for (unsigned int i = 0; i < compteurMedecin_; i++)
			temp[i] = tableauMedecins_[i];

		delete[] tableauMedecins_;
	
		tableauMedecins_ = temp;
		capaciteTableauMedecins_ = newCapacite;
	}
	tableauMedecins_[compteurMedecin_++] = unMedecin;

}

void Personnel::ajouterInfirmier(Infirmier& unInfirmier)
{
		if(compteurInfirmier_ >= capaciteTableauInfirmiers_) //double la capacite lorsque la capacite est insuffisante
	{
		unsigned int newCapacite = capaciteTableauInfirmiers_ * 2;
		Infirmier *temp = new Infirmier[newCapacite];

		for (unsigned int i = 0; i < compteurInfirmier_; i++)
			temp[i] = tableauInfirmiers_[i];

	
		delete[] tableauInfirmiers_;


		tableauInfirmiers_ = temp;
		capaciteTableauInfirmiers_ = newCapacite;
	}
	tableauInfirmiers_[compteurInfirmier_++] = unInfirmier;
}

void Personnel::afficherMedecins() const
{ 
	string nomTableau = "Tableau  Medecins";

	for (int k = 0; k < 50; k++) {
		cout << "=";	
	}
	cout << nomTableau;
	for (int k = 0; k < 50; k++) {
		cout << "=";
	}
	cout << endl;

	for (int j = 0; j <117; j++) {
		cout << "=";
	}
	cout << endl;
	cout << std::left << "|" << setw(28) << "Nom" << "|" << setw(28) << "Horaires" << "|" << setw(28) << "Domaine Specialite" << "|" << setw(28) << "Niveau Specialite" << "|" << endl;

	for (unsigned int i = 0; i < compteurMedecin_; i++) {
		tableauMedecins_[i].afficherMedecin();
	}
	
	for (int j = 0; j <117; j++) {
		cout << "=";
	}
	cout << endl;
}

void Personnel::afficherInfirmiers()const
{
	string nomTableau = "Tableau  Infirmiers";
	int x = nomTableau.size();

	for (int k = 0; k < 40; k++) {
		cout << "=";
	}
	cout << nomTableau;
	for (int k = 0; k < 40; k++) {
		cout << "=";
	}
	cout << endl;

	for (int j = 0; j <99; j++) {
		cout << "=";
	}
	cout << endl;
	cout << std::left << "|" << setw(28) << "Nom" << "|" << setw(28) << "Prenom" << "|" << setw(39) << "Nombre de Chambres" << "|" << endl;

	for (unsigned int i = 0; i < compteurInfirmier_; i++) {
		tableauInfirmiers_[i].afficherInfirmier();  
	}
	for (int j = 0; j <99; j++) {
		cout << "=";
	}
	
}
