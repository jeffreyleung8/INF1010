/********************************************
* Titre: Travail pratique #4 - Reine.h
* Date: 2 mars 2017
* Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
*******************************************/
#pragma once

#ifndef REINE_H
#define REINE_H

#include <iostream>
#include "Piece.h"
#include <string>
#include "Fou.h"
#include "Tour.h"
using namespace std;

class Reine : public Piece
{
public:
	Reine();
	Reine(const string& id, const string& couleur, int positionX, int positionY);
	Reine(const Pion& pion);
	virtual ~Reine();

	virtual bool estMouvementValide(int toX, int toY)const;
	virtual bool deplacer(int toX, int toY);
	virtual ostream&  afficher(ostream& stream) const;

	 
};


#endif REINE_H