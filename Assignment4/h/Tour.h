
/********************************************
* Titre: Travail pratique #4 - Tour.h
* Date: 2 mars 2017
* Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
*******************************************/

#ifndef TOUR_H
#define TOUR_H

#include "Piece.h"
#include <string>
#include "Pion.h"

using namespace std;

class Tour : public Piece {

public:
	// Constructeurs
	Tour();
	Tour(const string& id, const string& couleur, int positionX, int positionY);
	Tour(const Pion& pion);

	// Destructeur
	virtual ~Tour();
	
	virtual bool estMouvementValide(int toX, int toY)const;
	virtual bool deplacer(int toX, int toY);
};
#endif