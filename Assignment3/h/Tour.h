/**************************************************
* Titre: Travail pratique #3 - Tour.h
* Date: 21 fevrier 2017
* Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
**************************************************/
#pragma once

#ifndef TOUR_H
#define TOUR_H

#include <iostream>
#include "Piece.h"
#include <string>

using namespace std;

class Tour : public Piece
{
public:
	//Constructeur par defaut
	Tour();

	//Constructeur par parametre
	Tour(const string& id, const string& couleur, int positionX, int positionY);

	//Destructeur
	~Tour();

	//Methode booleen
	bool estMouvementValide(int toX, int toY)const;

	//Methode deplacement
	void deplacer(int tox, int toY);

private:

};
#endif