/********************************************
* Titre: Travail pratique #4 - Fou.cpp
* Date: 2 mars 2017
* Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
*******************************************/
#include "Fou.h"

Fou::Fou()
	:Piece("defaultId", "defaultCouleur", 0, 0)
{
}

Fou::Fou(const string& id, const string& couleur, int positionX, int positionY)
	: Piece(id, couleur, positionX, positionY)
{
}
Fou::Fou(const Pion& pion)
	: Piece(pion.obtenirId(), pion.obtenirCouleur(), pion.obtenirPositionX(), pion.obtenirPositionY())
{
}
Fou::~Fou()
{
}
bool Fou::estMouvementValide(int toX, int toY) const
{
	if (!Piece::estMouvementValide(toX, toY))
		return false;
	if (abs(obtenirPositionX() - toX) == abs(obtenirPositionY() - toY)){
		return true;
	}
	else
		return false;
}
bool Fou::deplacer(int toX, int toY)
{
	if (estMouvementValide(toX, toY)) {
		modifierPositionX(toX);
		modifierPositionX(toY);
		return true;
	}
	return false;
}
ostream&  Fou::afficher(ostream& stream) const
{
	stream << "Fou " << this->obtenirCouleur() << " d'id " << this->obtenirId() << " : " << endl;
	stream << "Position (" << this->obtenirPositionX() << ", " << this->obtenirPositionY() << ")" << endl;
	return stream;
}