/**************************************************
* Titre: Travail pratique #3 - Echiquier.cpp
* Date: 21 fevrier 2017
* Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
**************************************************/
#include "Echiquier.h"
#include <iostream>

using namespace std;


/****************************************************************************
* Fonction: Echiquier::Echiquier()
* Description: Constructeur defaut
* Paramètres: Aucun
* Retour: Aucun
*Commentaire: Il y a un maximun de 16 pions et de 4 tours dans le jeu donc on
***********  fixe chaque capacite de pion et de tour par son nombre maximun
****************************************************************************/

Echiquier::Echiquier()
	:compteurPion_(0), compteurTour_(0), capaciteTableauPion_(16), capaciteTableauTour_(4)
{
	tableauPions_ = new Pion[capaciteTableauPion_];
	tableauTours_ = new Tour[capaciteTableauTour_];
}

/****************************************************************************
* Fonction: Echiquier::~Echiquier()
* Description: Destructeur
* Paramètres: Aucun
* Retour: Aucun
****************************************************************************/

Echiquier::~Echiquier()
{
	delete []tableauPions_;
	delete []tableauTours_;
}

/****************************************************************************
* Fonction: void Echiquier::ajouterRoi(const Roi &unRoi, int position)
* Description: Ajoute un roi
* Paramètres: unRoi(Roi) et position(int)
* Retour: Aucun
****************************************************************************/

void Echiquier::ajouterRoi(const Roi &unRoi, int position)
{
	rois_[position] = unRoi;
	cout << "Le roi " << unRoi.obtenirId() << " a ete ajoute" << endl;
}

/****************************************************************************
* Fonction: void Echiquier::ajouterTour(const Tour& uneTour)
* Description: Ajoute une tour
* Paramètres: unTour(Tour)
* Retour: Aucun
****************************************************************************/

void Echiquier::ajouterTour(const Tour& uneTour)
{
	if (compteurTour_<capaciteTableauTour_) {
		tableauTours_[compteurTour_] = uneTour;
		compteurTour_++;
		cout << "La tour " << uneTour.obtenirId() << " a ete ajoute" << endl;
	}
}

/****************************************************************************
* Fonction: void Echiquier::ajouterPion(const Pion& unPion)
* Description: Ajoute un pion
* Paramètres: unPion(Pion)
* Retour: Aucun
****************************************************************************/

void Echiquier::ajouterPion(const Pion& unPion)
{
	if (compteurPion_<capaciteTableauPion_) {
		tableauPions_[compteurPion_] = unPion;
		compteurPion_++;
		cout << "Le pion " << unPion.obtenirId() << " a ete ajoute" << endl;
	}

}

/****************************************************************************
* Fonction: void Echiquier::enleverTour(const string id)
* Description: Enleve une tour
* Paramètres: id(string)
* Retour: Aucun
****************************************************************************/

void Echiquier::enleverTour(const string& id)
{
	for (unsigned int i = 0; i < compteurTour_; i++) {
		if (id == tableauTours_[i].obtenirId()) {
			tableauTours_[i] = tableauTours_[i + 1];
			compteurTour_--;
			cout << "La tour " << id << " a ete enlevee" << endl;
		}
	}
}
/****************************************************************************
* Fonction: void Echiquier::enleverPion(const string id)
* Description: Enleve un pion
* Paramètres: id (string)
* Retour: Aucun
****************************************************************************/

void Echiquier::enleverPion(const string& id)
{
	for (unsigned int i = 0; i< compteurPion_; i++) {
		if (id == tableauPions_[i].obtenirId()) {
			tableauPions_[i] = tableauPions_[i + 1];
			compteurPion_--;
			cout << "Le pion " << id << " a ete enleve"<<endl;
		}
	}
}

/****************************************************************************
* Fonction: void  Echiquier::deplacerPiece(string id, int toX, int toY)
* Description: Deplace une piece sur le jeu
* Paramètres: id(string), toX(int), toY(int)
* Retour: Aucun
****************************************************************************/

void  Echiquier::deplacerPiece(const string& id, int toX, int toY)
{
	//Parcours chaque tableau pour trouver le id en parametre
	//Si le id est trouve, il va deplace la piece tout en verifiant si le mouvement est valide

	for (unsigned int i = 0; i<compteurPion_; i++) {
		if (id == tableauPions_[i].obtenirId()) {
			tableauPions_[i].deplacer(toX, toY);
		}
	}
	for (unsigned int j = 0; j<compteurTour_; j++) {
		if (id == tableauTours_[j].obtenirId()) {
			tableauTours_[j].deplacer(toX, toY);
		}
	}
	for (unsigned int k = 0; k<2; k++) {
		if (id == rois_[k].obtenirId()) {
			rois_[k].deplacer(toX, toY);
		}
	}
}

//Methode qui demande le id d'un piece et la deplace
void Echiquier::afficherPosition(const string& id) {
	//Parcours chaque tableau pour trouver le id en parametre
	//Si le id est trouve, il va deplace la piece tout en verifiant si le mouvement est valide
	for (unsigned int i = 0; i<compteurPion_; i++) {
		if (id == tableauPions_[i].obtenirId()) {
			cout << "(" << tableauPions_[i].obtenirPositionX() << ","<< tableauPions_[i].obtenirPositionY()<<")" << endl;
		}
	}
	for (unsigned int j = 0; j<compteurTour_; j++) {
		if (id == tableauTours_[j].obtenirId()) {
			cout <<"("<< tableauTours_[j].obtenirPositionX() << ","<<tableauTours_[j].obtenirPositionY() << ")" << endl;
		}
	}
	for (unsigned int k = 0; k<2; k++) {
		if (id == rois_[k].obtenirId()) {
			cout<<"("<< rois_[k].obtenirPositionX() <<","<< rois_[k].obtenirPositionY() << ")" << endl;
		}
	}
	
}