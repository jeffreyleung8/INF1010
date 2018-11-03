/**************************************************
* Titre: Travail pratique #3 - Roi.cpp
* Date: 21 fevrier 2017
* Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
**************************************************/
#include <iostream>
#include "Roi.h"
using namespace std;

/****************************************************************************
* Fonction: Roi::Roi()
* Description: Constructeur par defaut
* Paramètres: Aucun
* Retour: Aucun
****************************************************************************/

Roi::Roi()
	:Piece()
{
}

/****************************************************************************
* Fonction: Roi::Roi(string id, string couleur, int positionX, int positionY)
* Description: Constructeur par parametre
* Paramètres: Aucun
* Retour: Aucun
****************************************************************************/

Roi::Roi(const string& id, const string& couleur, int positionX, int positionY)
	:Piece(id, couleur, positionX, positionY)
{
}

/****************************************************************************
* Fonction: Roi::~Roi()
* Description: Destructeur
* Paramètres: Aucun
* Retour: Aucun
****************************************************************************/

Roi::~Roi()
{
}

/****************************************************************************
* Fonction: bool Roi::estMouvementValide(int toX, int toY)
* Description: Verifie si le mouvement d'un roi est valide
* Paramètres: toX(int) , toY(int)
* Retour: bool -> vrai si mouvement valide ou faux si mouvement invalide
****************************************************************************/

bool Roi::estMouvementValide(int toX, int toY)  const
{ //Le deplacement d'un roi est valide(true) si la difference entre la position initiale(x et y) et la position finale (x et y) 
  //en valeur absolue est inferieur ou egale a 1
	if (Piece::estMouvementValide(toX, toY)) {
		if (abs(obtenirPositionX() - toX) <= 1 && abs(obtenirPositionY() - toY) <= 1) {
			return true;
		}
	}
	return false;
}

/****************************************************************************
* Fonction: void Roi::deplacer(int tox, int toY)
* Description: Deplace le roi vers la nouvelle position
* Paramètres: toX(int) , toY(int)
* Retour: Aucun
****************************************************************************/

void Roi::deplacer(int toX, int toY)
{ //Verifie si le mouvement est valide pour un roi et fait le deplacement si valide
	if (Roi::estMouvementValide(toX, toY)) {
		modifierPositionX(toX);
		modifierPositionY(toY);
		cout << "Deplacement du Roi de la position(" << obtenirPositionX() << "," << obtenirPositionY() << ") a la position(" << toX << "," << toY << ")" << endl;
	}
	cout << "Deplacement du Roi non autorise" << endl;
}
