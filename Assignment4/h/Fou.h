
/********************************************
* Titre: Travail pratique #4 - Fou.h
* Date: 2 mars 2017
* Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
*******************************************/

#ifndef FOU_H
#define FOU_H

#include "Piece.h"
#include <string>
#include "Pion.h"
using namespace std;

class Fou : public Piece {

public:
	// Constructeurs
	Fou();
	Fou(const string& id, const string& couleur, int positionX, int positionY);
	Fou(const Pion& pion);
	// Destructeur
	virtual ~Fou();

	virtual bool estMouvementValide(int toX, int toY) const;
	virtual bool deplacer(int toX, int toY);
	virtual ostream&  afficher(ostream& stream) const;

	
};
#endif