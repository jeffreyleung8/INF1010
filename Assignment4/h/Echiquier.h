
/********************************************
* Titre: Travail pratique #4 - Echiquier.h
* Date: 2 mars 2017
* Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
*******************************************/

#ifndef ECHIQUIER_H
#define ECHIQUIER_H

#include "Piece.h"
#include "Pion.h"
#include "Roi.h"
#include "Tour.h"
#include "Fou.h"
#include "Reine.h"
#include "vector"
#include <string>


class Echiquier{



public:
	// Constructeur par defaut
	Echiquier();

	// Destructeur
	~Echiquier();

	// Methodes publiques
	
	bool deplacerPiece(const string& id, int toX, int toY);
	Echiquier& operator+=(Piece* piece);
	Echiquier& operator-=(const string& id);
	bool promouvoir(const string& id);
	
	friend std::ostream& operator<<(std::ostream& out, const Echiquier& echiquier);//A completer
	

private :	
	vector<Piece*>   vecteurPiecesBlanches_;
	vector<Piece*>   vecteurPiecesNoires_;	

};
#endif
std::ostream& operator<<(std::ostream& out, const Echiquier& echiquier);