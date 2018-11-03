/**************************************************
* Titre: Travail pratique #3 - Tour.cpp
* Date: 21 fevrier 2017
* Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
**************************************************/

#include <iostream>
#include "Pion.h"
using namespace std;

/****************************************************************************
* Fonction: Pion::Pion()
* Description: Constructeur par defaut
* Paramètres: Aucun
* Retour: Aucun
****************************************************************************/

Pion::Pion()
	:Piece()
{
	estPositionInitiale_ = 1;
}

/****************************************************************************
* Fonction: Pion::Pion(string id, string couleur, int positionX, int positionY)
* Description: Constructeur par parametre
* Paramètres: id(string), couleur(string), positionX(int), positionY(int)
* Retour: Aucun
****************************************************************************/

Pion::Pion(const string& id, const string& couleur, int positionX, int positionY)
	:Piece(id, couleur, positionX, positionY)
{
	estPositionInitiale_ = 1;
}

/****************************************************************************
* Fonction: Pion::~Pion()
* Description: Destructeur
* Paramètres: Aucun
* Retour: Aucun
****************************************************************************/

Pion::~Pion()
{
}

/****************************************************************************
* Fonction: bool Pion::estMouvementValide(int toX, int toY)
* Description: Verifie si le mouvement du pion est valide
* Paramètres: toX(int), toY(int)
* Retour: bool -> vrai si valide  ou faux si non-valide
****************************************************************************/

bool Pion::estMouvementValide(int toX, int toY)const
{ //Distingue le mouvement d'un pion blanc et noir
  // Pour un pion blanc, sil est a sa position initiale, il peut deplacer de 1 ou 2 cases vers le haut
  //Pour un pion noir, sil est a sa position initiale, il peut deplacer de 1 ou 2 cases vers le bas
	if (Piece::estMouvementValide(toX, toY)) {
		if (obtenirCouleur() == "blanc") {
			if (obtenirPositionX() == toX) {
				if ((estPositionInitiale_ == 1) && ((toY - obtenirPositionY()) <= 2)) {
					return true;
				}
				else if ((estPositionInitiale_ == 0) && ((toY - obtenirPositionY()) <= 1)) {
					return true;
				}
			}
			return false;
		}
		else {
			if (obtenirPositionX() == toX) {
				if (estPositionInitiale_ == 1 && toY - obtenirPositionY() <= 2) {
					return true;
				}
				else if (estPositionInitiale_ == 0 && toY - obtenirPositionY() <= 1) {
					return true;
				}
			}
			return false;
		}
	}
}

/****************************************************************************
* Fonction: void Pion::deplacer(int toX, int toY)
* Description: Deplace le pion vers la nouvelle position
* Paramètres: toX(int), toY(int)
* Retour: Aucun
**************************************************************************/


void Pion::deplacer(int toX, int toY)
{
	//Verifie si le mouvement est valide pour un pion
	if (Pion::estMouvementValide(toX, toY))
	{
		cout << "Deplacement du Pion " << obtenirId()<< " de la position(" << obtenirPositionX() << "," << obtenirPositionY() << ") a la position(" << toX << "," << toY << ")" << endl;
		modifierPositionY(toY);
	//Apres le premier deplacement, le pion nest plus a sa position initiale donc estPositionInitiale_ = false
		if (estPositionInitiale_ == 1) {
			estPositionInitiale_ = 0;
		}
		
	}
	else {
		cout << "Deplacement du Pion non autorise" << endl;
	}
}

