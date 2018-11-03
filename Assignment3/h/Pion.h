/**************************************************
* Titre: Travail pratique #3 - Pion.h
* Date: 21 fevrier 2017
* Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
**************************************************/
#pragma once

#ifndef PION_H
#define PION_H

#include <iostream>
#include "Piece.h"
#include <string>

class Pion : public Piece
{
public:
	//Constructeur par defaut
	Pion();

	//Constructeur par parametre
	Pion(const string& id, const string& couleur, int positionX, int positionY);

	//Destructeur
	~Pion();

	//Methode booleen
	bool estMouvementValide(int tox, int toY)const;

	//Methode deplacement
	void deplacer(int toX, int toY);

private:
	bool estPositionInitiale_;

};
using namespace std;
#endif 
