/**************************************************
* Titre: Travail pratique #3 - Piece.h
* Date: 21 fevrier 2017
* Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
**************************************************/
#pragma once

#ifndef PIECE_H
#define PIECE_H


#include <iostream>
#include <string>

using namespace std;

class Piece {
public :
	//Constructeur par defaut
	Piece();
	//Constructeur par parametres
	Piece(const string& id, const string& couleur, int positionX, int positionY); 

	//Destructeur
	~Piece();

	//Methode d'acces et de modification
	string obtenirId() const;
	void modifierId(const string& id);

	string obtenirCouleur() const;
	void modifierCouleur(const string& id);

	int obtenirPositionX() const;	
	void modifierPositionX(int x);

	int obtenirPositionY() const;
	void modifierPositionY(int y);

	//Methode booleen
	bool estMouvementValide(int toX, int toY)const; 

private:

	string id_;
	string couleur_;
	int positionX_;
	int positionY_;

};
#endif