/**************************************************
* Titre: Travail pratique #3 - Roi.h
* Date: 21 fevrier 2017
* Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
**************************************************/
#pragma once

#ifndef ROI_H
#define ROI_H

#include <iostream>
#include "Piece.h"
#include <string>
using namespace std;

class Roi : public Piece
{
public:
	//Constructeur par defaut
	Roi();

	//Constructeur par parametre
	Roi(const string& id, const string& couleur, int positionX, int positionY);

	//Destructeur
	~Roi();

	//Methode booleen
	bool estMouvementValide(int tox, int toY) const;

	//Methode deplacement
	void deplacer(int toX, int toY);

private:
};
#endif
