
/********************************************
* Titre: Travail pratique #4 - Piece.h
* Date: 2 mars 2017
* Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
*******************************************/

#ifndef PIECE_H
#define PIECE_H


#include <iostream>
#include <string>

using namespace std;

 class Piece {


public :
	// Constructeurs
	Piece() {}
	Piece(const string& id, const string& couleur, int positionX, int positionY):id_(id), couleur_(couleur), positionX_(positionX), positionY_(positionY){}

	// Destructeur
	virtual ~Piece() {}

	// Accesseur et modificateur
	string obtenirId() const {
		return id_; 
	}

	void modifierId(const string& id) {
		id_ = id;
	}

	string obtenirCouleur() const { 
		return couleur_;
	}

	void modifierCouleur(const string& couleur) {
		couleur_ = couleur; 
	}

	int obtenirPositionX() const {
		return positionX_; 
	}
	void modifierPositionX(int x) {
		positionX_ = x; 
	}

	int obtenirPositionY() const {
		return positionY_; 
	}

	void modifierPositionY(int y) {
		positionY_ = y;
	}

	
	virtual bool estMouvementValide(int toX, int toY) const{
		if ((positionX_ != toX || positionY_ != toY) && (toX <= 7 && toX >= 0) && (toY <= 7 && toY >= 0)) {
			return true;
		}
		cout << "Deplacement de la piece non autorisee" << endl;
		return false;
		
	} 

	//Methode virtuelle pures
	virtual bool deplacer(int toX, int toY) = 0; // A MODIFIER

	
	string obtenirType() const 	{ 

		return (typeid(*this).name());
		
	}

	friend std::ostream& operator<<(std::ostream& out, const Piece& piece)
	{
		return piece.afficher(out);
	}

	                                            
	virtual ostream&  afficher(ostream& stream) const {  // A MODIFIER SI NECESSAIRE
		stream << "Piece " << this->obtenirCouleur() << " d'id " << this->obtenirId() << " : " << endl;
		stream << "Position (" << this->obtenirPositionX() << ", " << this->obtenirPositionY() << ")" << endl;
		return stream;
	}

private:

	string id_;
	string couleur_;
	int positionX_;
	int positionY_;

};
#endif