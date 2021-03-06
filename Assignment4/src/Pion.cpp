
/********************************************
* Titre: Travail pratique #4 - Pion.cpp
* Date: 2 mars 2017
* Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
*******************************************/

#include "Pion.h"


Pion::Pion():Piece("defaultId","Blanc",0,0),estPositionInitiale_(true){
}


Pion::Pion(const string& id, const string& couleur, int positionX, int positionY) : Piece(id, couleur, positionX, positionY) {
	estPositionInitiale_ = true;
}

Pion::~Pion() {
}


bool Pion::obtenirEstPositionInitiale() const{
	return estPositionInitiale_;
}

void Pion::setEstPositionInitiale(bool estPositionInitiale) {
	estPositionInitiale_ = estPositionInitiale;
}


bool Pion::estMouvementValide(int toX, int toY) const {
	if (!Piece::estMouvementValide(toX, toY))
		return false;
	if (obtenirCouleur() == "Blanc") {
		if (obtenirEstPositionInitiale()) {
			if (((toY - obtenirPositionY()) <= 2) && (toX == obtenirPositionX()) 
				&& (toY > obtenirPositionY())) {
				return true;
			}
		}
		else
		{
			if ((toY - obtenirPositionY()) <= 1 && (toX == obtenirPositionX()) 
				&& toY > obtenirPositionY()) {
				return true;
			}
		}
	}
	if (obtenirCouleur() == "Noir") {
		if (obtenirEstPositionInitiale()) {
			if (((toY - obtenirPositionY()) <= 2) && (toX == obtenirPositionX()) 
				&& (toY < obtenirPositionY())) {
				return true;
			}
		}
		else
		{
			if (((toY - obtenirPositionY()) <= 1) && (toX == obtenirPositionX()) 
				&& (toY < obtenirPositionY())) {
				return true;
			}
		}
	}
	
	return false;
	
}

bool Pion::deplacer(int toX, int toY) {
	if (estMouvementValide(toX, toY)) {
		
		modifierPositionX(toX);
		modifierPositionX(toY);
		estPositionInitiale_ = false;	
		return true;
	}
	return false;
}