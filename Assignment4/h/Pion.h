
/********************************************
* Titre: Travail pratique #4 - Pion.h
* Date: 2 mars 2017
* Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
*******************************************/

#pragma once

#ifndef PION_H
#define PION_H


#include "Piece.h"
#include <string>

using namespace std;

class Pion : public Piece {

public:
	// Constructeurs
	Pion();
	Pion(const string& id, const string & couleur, int positionX, int positionY);

	// Destructeur
	virtual ~Pion();
	
	bool obtenirEstPositionInitiale() const;
	void setEstPositionInitiale(bool estPositionInitiale);

	virtual bool estMouvementValide(int toX, int toY)const;
	virtual bool deplacer(int toX, int toY);

private:
	bool estPositionInitiale_;

};
#endif
