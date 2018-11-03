
/********************************************
* Titre: Travail pratique #4 - Roi.h
* Date: 2 mars 2017
* Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
*******************************************/

#ifndef ROI_H
#define ROI_H


#include "Piece.h"
#include <string>

using namespace std;

class Roi : public Piece{

public :
	Roi();
	Roi(const string& id, const string& couleur, int positionX, int positionY);
	virtual ~Roi();

	virtual bool estMouvementValide(int toX, int toY)const;
	virtual bool deplacer(int toX, int toY);

};
#endif