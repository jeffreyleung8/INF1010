/********************************************
* Titre: Travail pratique #4 - Echiquier.cpp
* Date: 2 mars 2017
* Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
*******************************************/
#include "Echiquier.h"
#include <time.h>
#include <stdio.h>      
#include <stdlib.h> 

Echiquier::Echiquier() {
}


Echiquier::~Echiquier() {
	for (unsigned int i = 0; i < vecteurPiecesBlanches_.size(); i++)
	{
		delete vecteurPiecesBlanches_[i];
		vecteurPiecesBlanches_[i] = nullptr;
	}
	for (unsigned int i = 0; i < vecteurPiecesNoires_.size(); i++)
	{
		delete vecteurPiecesNoires_[i];
		vecteurPiecesNoires_[i] = nullptr;
	}
}


bool Echiquier::deplacerPiece(const string& id, int toX, int toY) {
	//Parcours le vecteur des pieces blanches et pieces noires et verifie si le id est compatible avec un objet du vecteur
	//Effectue le deplacement si le id est compatible
	for (unsigned int i = 0; i <  vecteurPiecesBlanches_.size(); i++) {
		if (vecteurPiecesBlanches_[i]->obtenirId() == id) {
			if (vecteurPiecesBlanches_[i]->deplacer(toX, toY)) {
				cout << "Deplacement de la piece reussi" << endl;
				return true;
			}

			
		}
	}
	for (unsigned int i = 0; i < vecteurPiecesNoires_.size(); i++) {
		if (vecteurPiecesNoires_[i]->obtenirId() == id) {
			if (vecteurPiecesNoires_[i]->deplacer(toX, toY)) {
				cout << "Deplacement de la piece reussi"<<endl;
				return true;
			}
		}
	}
	cout << "Mouvement non valide" << endl;
	return false;
}

Echiquier& Echiquier::operator+=(Piece* piece) {

	Piece* piece1; 
	
		//Dynamic cast (Si piece peut etre converti en le type A, il va rentrer dans la boucle A)
		//Ex. Si piece est de type Pion, dans la boucle du Roi, la condition serait faux car le dynamic cast au Roi donne nullptr. 
		//Par contre, dans la prochaine boucle, la piece peut etre converti en pion et ne donnerait pas un nullptr donc rentre dans cette boucle.
		if (dynamic_cast<Roi*>(piece)!=nullptr) {
			
			piece1 = new Roi(piece->obtenirId(), piece->obtenirCouleur(), piece->obtenirPositionX(), piece->obtenirPositionY());
		}

		 if (dynamic_cast<Pion*>(piece) != nullptr) {
			
			piece1 = new Pion(piece->obtenirId(), piece->obtenirCouleur(), piece->obtenirPositionX(), piece->obtenirPositionY());
		}

		if (dynamic_cast<Tour*>(piece) != nullptr) {
			
			piece1 = new Tour(piece->obtenirId(), piece->obtenirCouleur(), piece->obtenirPositionX(), piece->obtenirPositionY());
		}

		if (dynamic_cast<Fou*>(piece) != nullptr) {
			
			piece1 = new Fou(piece->obtenirId(), piece->obtenirCouleur(), piece->obtenirPositionX(), piece->obtenirPositionY());
		}

		if (dynamic_cast<Reine*>(piece) != nullptr) {
	
			piece1 = new Reine(piece->obtenirId(), piece->obtenirCouleur(), piece->obtenirPositionX(), piece->obtenirPositionY());
		}

		if (piece->obtenirCouleur() == "Blanc") {
			vecteurPiecesBlanches_.push_back(piece1);
		}
		else {
			vecteurPiecesNoires_.push_back(piece1);
		
		}
	return *this;
}

Echiquier& Echiquier::operator-=(const string& id) {
	for (unsigned int i = 0; i < vecteurPiecesBlanches_.size(); i++) {
		if (vecteurPiecesBlanches_[i]->obtenirId() == id) {
			delete vecteurPiecesBlanches_[i]; //detruire l'objet i en raison de la relation composition 
			for (unsigned int j = i; j < (vecteurPiecesBlanches_.size() - 1); j++) {
				vecteurPiecesBlanches_[j] = vecteurPiecesBlanches_[j + 1]; //decale les objets vers le haut a partir de l'objet i
			}
			vecteurPiecesBlanches_.pop_back(); //enleve le dernier element qui est mtn a la position precedente
		}
	}
	for (unsigned int i = 0; i < vecteurPiecesNoires_.size(); i++) {
		if (vecteurPiecesNoires_[i]->obtenirId() == id) {
			delete vecteurPiecesNoires_[i]; //detruire l'objet i en raison de la relation composition 
			for (unsigned int j = i; j < (vecteurPiecesNoires_.size()-1); j++) {
				vecteurPiecesNoires_[j] = vecteurPiecesNoires_[j + 1]; //decale les objets vers le haut a partir de l'objet i
			}
			vecteurPiecesNoires_.pop_back(); //enleve le dernier element qui est mtn a la position precedente
		}
	}
	return *this;
}

bool Echiquier::promouvoir(const string& id) {
	srand(int (time(NULL)));
	int x = rand() % 3; // x peut avoir comme valeur 0, 1 ou 2
	
	Piece* temp= nullptr;
	Pion* piece1;

	for (unsigned int i = 0; i < vecteurPiecesBlanches_.size(); i++) {
		if (vecteurPiecesBlanches_[i]->obtenirId() == id && (dynamic_cast<Pion*>(vecteurPiecesBlanches_[i]) != nullptr)) {
			temp = vecteurPiecesBlanches_[i]; //copie l'objet i
			switch (x)
			{
			case 0: piece1 = dynamic_cast <Pion*> (vecteurPiecesBlanches_[i]);  //affecte l'objet i (qui est converti en pion) a piece1
					vecteurPiecesBlanches_[i] = new Reine (*piece1);  //alloue une nouvelle espace de type Reine contenant le contenu de piece1
					cout << "Promotion reussie" << endl;
					delete temp;  //detruit l' ancien objet i
					return true;
					break;
			case 1: piece1 = dynamic_cast <Pion*> (vecteurPiecesBlanches_[i]);  //affecte l'objet i (qui est converti en pion) a piece1 
					vecteurPiecesBlanches_[i] = new Tour (*piece1); //alloue une nouvelle espace de type Tour contenant le contenu de piece1
					cout << "Promotion reussie" << endl;
					delete temp;  //detruit l' ancien objet i
					return true;
					break;
			case 2: piece1 = dynamic_cast <Pion*> (vecteurPiecesBlanches_[i]);  //affecte l'objet i (qui est converti en pion) a piece1
					vecteurPiecesBlanches_[i] = new Fou(*piece1); //alloue une nouvelle espace de type Fou contenant le contenu de piece1
					cout << "Promotion reussie" << endl;
					delete temp;  //detruit l' ancien objet i
					return true;
					break;
			}
				
		}
	}

	for (unsigned int i = 0; i < vecteurPiecesNoires_.size(); i++) {
		if (vecteurPiecesNoires_[i]->obtenirId() == id && (dynamic_cast<Pion*>(vecteurPiecesNoires_[i]) != nullptr)) {
			temp = vecteurPiecesNoires_[i];
			switch (x)
			{
			case 0: piece1 = dynamic_cast <Pion*> (vecteurPiecesNoires_[i]); // affecte l'objet i (qui est converti en pion) a piece1
					vecteurPiecesNoires_[i] = new Reine(*piece1); //alloue une nouvelle espace de type Reine contenant le contenu de piece1
					cout << "Promotion reussie" << endl;	
					delete temp;  //detruit l' ancien objet i
					return true;
					break;
			case 1: piece1 = dynamic_cast <Pion*> (vecteurPiecesNoires_[i]); // affecte l'objet i (qui est converti en pion) a piece1
					vecteurPiecesNoires_[i] = new Tour(*piece1); //alloue une nouvelle espace de type Tour contenant le contenu de piece1
					cout << "Promotion reussie" << endl;	
					delete temp;  //detruit l' ancien objet i
					return true;
					break;
			case 2: piece1 = dynamic_cast <Pion*> (vecteurPiecesNoires_[i]); //affecte l'objet i (qui est converti en pion) a piece1
					vecteurPiecesNoires_[i] = new Fou(*piece1); //alloue une nouvelle espace de type Fou contenant le contenu de piece1
					cout << "Promotion reussie" << endl;		
					delete temp;  //detruit l' ancien objet i
					return true;
					break;
			}
			
		}
	}
	cout << "Promotion impossible" << endl;
	return false;
}

std::ostream & operator<<(std::ostream & out, const Echiquier & echiquier)
{
	out << "------------INFORMATION PIECES BLANCHES------------" << endl;
	out << "Il y a " << echiquier.vecteurPiecesBlanches_.size() << " Pieces blanches" << endl;
	for (unsigned int i = 0; i < echiquier.vecteurPiecesBlanches_.size(); i++)
	{
		echiquier.vecteurPiecesBlanches_[i]->afficher(out); //appele la methode du type reel de l'objet i de couleur blanche
	}


	out << endl;
	out << "------------INFORMATION PIECES NOIRES--------------" << endl;
	out << "Il y a " << echiquier.vecteurPiecesNoires_.size() << " Pieces noires" << endl;
	for (unsigned int i = 0; i < echiquier.vecteurPiecesNoires_.size(); i++)
	{
		echiquier.vecteurPiecesNoires_[i]->afficher(out); //appele la methode du type reel de l'objet i de couleur noire
	}
	return out;
}