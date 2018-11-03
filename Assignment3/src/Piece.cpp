/**************************************************
* Titre: Travail pratique #3 - Piece.cpp
* Date: 21 fevrier 2017
* Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
**************************************************/


#include "Piece.h"
#include <iostream>
#include <string>


using namespace std;

/****************************************************************************
* Fonction: Piece::Piece()
* Description: Constructeur defaut
* Paramètres: Aucun
* Retour: Aucun
****************************************************************************/

Piece::Piece()
	: positionX_(0), positionY_(0), id_("unknown"), couleur_("unknown")
{
}

/****************************************************************************
* Fonction: Piece::Piece(string id, string couleur, int positionX, int positionY)
* Description: Constructeur par parametres
* Paramètres: string id, string couleur, int positionX, int positionY
* Retour: Aucun
****************************************************************************/

Piece::Piece(const string& id, const string& couleur, int positionX, int positionY)
	: id_(id), couleur_(couleur), positionX_(positionX), positionY_(positionY)
{
}

/****************************************************************************
* Fonction: Piece::~Piece()
* Description: Destructeur
* Paramètres: Aucun
* Retour: Aucun
****************************************************************************/

Piece::~Piece()
{
}

/****************************************************************************
* Fonction: string Piece:: obtenirId()
* Description: Retourne l'id de la piece
* Paramètres: Aucun
* Retour: id_(string)
****************************************************************************/

string Piece::obtenirId() const
{
	return id_;
}

/****************************************************************************
* Fonction:string obtenirCouleur
* Description: Retourne la couleur de la piece
* Paramètres: Aucun
* Retour: id_(string)
****************************************************************************/

string Piece::obtenirCouleur() const
{
	return couleur_;
}

/****************************************************************************
* Fonction: int obtenir positionX
* Description: Retourne la positionX de la piece
* Paramètres: Aucun
* Retour: positionX_(int)
****************************************************************************/

int Piece::obtenirPositionX() const
{
	return positionX_;
}

/****************************************************************************
* Fonction: int obtenir positionX
* Description: Retourne la positionX de la piece
* Paramètres: Aucun
* Retour: positionX_(int)
****************************************************************************/

int Piece::obtenirPositionY() const
{
	return positionY_;
}

/****************************************************************************
* Fonction: Void modifierId(strinf id)
* Description: Modifie l'Id de la piece
* Paramètres: id(string)
* Retour: Aucun
****************************************************************************/

void Piece::modifierId(const string& id)
{

	id_ = id;
}

/****************************************************************************
* Fonction: Void modifierCouleur(string couleur)
* Description: Modifie la couleur de la piece
* Paramètres: couleur(string)
* Retour: Aucun
****************************************************************************/

void Piece::modifierCouleur(const string& couleur)
{
	couleur_ = couleur;
}

/****************************************************************************
* Fonction: Void modifierPositionX(int positionX)
* Description: Modifie la positionX de la piece
* Paramètres: positionX(int)
* Retour: Aucun
****************************************************************************/

void Piece::modifierPositionX(int positionX)
{
	positionX_ = positionX;
}

/****************************************************************************
* Fonction: Void modifierPositionY(int positionY)
* Description: Modifie la positionY de la piece
* Paramètres: positionY(int)
* Retour: Aucun
****************************************************************************/

void Piece::modifierPositionY(int positionY)
{
	positionY_ = positionY;
}

/****************************************************************************
* Fonction:bool estMouvementValide(int toX, int toY);
* Description: Verifie si le mouvement est valide
* Paramètres: toX(int), toY (int)
* Retour: Le mouvement est considérée valide si la position change ET que la nouvelle position est comprise entre 0 et 7 aussi bien pour l'abscisse que pour l'ordonnée. Dans le cas o, le mouvement n'est pas valide
****************************************************************************/

bool Piece::estMouvementValide(int toX, int toY) const
{
	//Si une des positions n'est pas egale a la position initiale et le position x et y est dans l'echiquier, la methode retourne true
	if ((positionX_ != toX || positionY_ != toY) && (toX <= 7 && toX >= 0) && (toY <= 7 && toY >= 0)) {
		return true;
	}
	cout << "Deplacement de la piece non autorisee" << endl;
	return false;
	
}

