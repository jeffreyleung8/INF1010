/**************************************************
* Titre: Travail pratique #3 - Tour.cpp
* Date: 21 fevrier 2017
* Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
**************************************************/

#include <iostream>
#include "Tour.h"
using namespace std;

/****************************************************************************
* Fonction: Tour::Tour()
* Description: Constructeur par defaut
* Paramètres: Aucun
* Retour: Aucun
****************************************************************************/

Tour::Tour()
	:Piece()
{
}

/****************************************************************************
* Fonction: Tour::Tour(string id, string couleur, int positionX, int positionY)
* Description: Constructeur par parametre
* Paramètres: id(string), couleur(string), positionX(int), positionY(int)
* Retour: Aucun
****************************************************************************/

Tour::Tour(const string& id, const string& couleur, int positionX, int positionY)
	:Piece(id, couleur, positionX, positionY)
{
}

/****************************************************************************
* Fonction: Tour::~Tour()
* Description: Destructeur
* Paramètres: Aucun
* Retour: Aucun
****************************************************************************/

Tour::~Tour()
{
}

/****************************************************************************
* Fonction: bool Tour::estMouvementValide(int toX, int toY)
* Description: Verifie si le mouvement de la Tour est valide
* Paramètres: toX(int), toY(int)
* Retour: bool -> vrai si valide  ou faux si non-valide
****************************************************************************/

bool Tour::estMouvementValide(int toX, int toY) const
{
	//Si un des positions initiale (x ou y) est egale a sa position finale, retourner vrai
	if (Piece::estMouvementValide(toX, toY)) {
		if (obtenirPositionX() == toX || obtenirPositionY() == toY) {
			return true;
		}
	}
	return false;
}

/****************************************************************************
* Fonction: void Tour::deplacer(int tox, int toY)
* Description: Deplace la Tour vers la nouvelle position
* Paramètres: toX(int), toY(int)
* Retour: Aucun
****************************************************************************/

void Tour::deplacer(int toX, int toY)
{//Verifie si le mouvement est valide pour une tour et fait le deplacement si valide
	if (Tour::estMouvementValide(toX, toY)) {
		cout << "Deplacement de la Tour " <<obtenirId()<< " de la position(" << obtenirPositionX() << "," << obtenirPositionY() << ") a la position(" << toX << "," << toY << ")" << endl;
		if (obtenirPositionX() == toX) {
			modifierPositionY(toY);
		}
		else {
			modifierPositionX(toX);
		}
	}
	else {
		cout << "Deplacement de la Tour non autorise" << endl;
	}
}
