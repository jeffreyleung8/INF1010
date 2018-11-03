/********************************************
* Titre: Travail pratique #4 - Reine.cpp
* Date: 2 mars 2017
* Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
*******************************************/

#include "Reine.h"
#include <iostream>
using namespace std;

Reine::Reine() : Piece("defaultId", "Blanc", 0, 0) {

}

Reine::Reine(const string& id, const string& couleur, int positionX, int positionY)
	: Piece(id, couleur, positionX, positionY) 
{
}
Reine::Reine(const Pion & pion)
	: Piece(pion.obtenirId(), pion.obtenirCouleur(), pion.obtenirPositionX(), pion.obtenirPositionY())
{
}

Reine::~Reine() {
}

bool Reine::estMouvementValide(int toX, int toY)const {
	if (!Piece::estMouvementValide(toX, toY)) {
			return false;
	}
	//Mouvement comme la Tour
	if ((obtenirPositionX() == toX) || (obtenirPositionY() == toY)) {
			return true;
	}
	//Mouvement comme une Fou
	if (abs(obtenirPositionX() - toX) == abs(obtenirPositionY() - toY)) {
			return true;
	}

		return false;	
}

bool Reine::deplacer(int toX, int toY) {
		if (estMouvementValide(toX, toY)) {
			modifierPositionX(toX);
			modifierPositionX(toY);
			return true;
		}
		return false;
	
}

ostream& Reine::afficher(ostream& stream) const {
	stream << "Reine " << this->obtenirCouleur() << " d'id " << this->obtenirId() << " : " << endl;
	stream << "Position (" << this->obtenirPositionX() << ", " << this->obtenirPositionY() << ")" << endl;
	return stream;
}
