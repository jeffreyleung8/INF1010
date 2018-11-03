/**************************************************
* Titre: Travail pratique #3 - Main.cpp
* Date: 21 fevrier 2017
* Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
**************************************************/
#include "Roi.h"
#include "Pion.h"
#include "Tour.h"
#include "Piece.h"
#include "Echiquier.h"
#include <iostream>
using namespace std;

int main()
{
	//1-  Creez un objet de type Roi à l'aide du constructeur par défaut.

	Roi roi1 = Roi();

	//2- Donnez l'id D1 au roi défini dans l'étape 1

	roi1.modifierId("D1");

	//3-  Définissez la position (3,0) pour le roi défini dans l'étape 1

	roi1.modifierPositionX(3);
	roi1.modifierPositionY(0);

	//4-  Creez un objet de type Roi Noir à la position (3,7) ayant comme id D8.

	Roi roi2 = Roi("D8", "Noir", 3, 7);

	//5-  Creez les huit pions blancs avec les coordonnées (i,1) i : 0-->7 et les id A2-->H2


	Pion pion1("A2", "Blanc", 0, 1);
	Pion pion2("B2", "Blanc", 1, 1);
	Pion pion3("C2", "Blanc", 2, 1);
	Pion pion4("D2", "Blanc", 3, 1);
	Pion pion5("E2", "Blanc", 4, 1);
	Pion pion6("F2", "Blanc", 5, 1);
	Pion pion7("G2", "Blanc", 6, 1);
	Pion pion8("H2", "Blanc", 7, 1);

	//6-  Creez les huit pions noirs avec les coordonnées (i,6) i : 0-->7 et les id A7-->H7

	Pion pion9("A7", "Noir", 0, 6);
	Pion pion10("B7", "Noir", 1, 6);
	Pion pion11("C7", "Noir", 2, 6);
	Pion pion12("D7", "Noir", 3, 6);
	Pion pion13("E7", "Noir", 4, 6);
	Pion pion14("F7", "Noir", 5, 6);
	Pion pion15("G7", "Noir", 6, 6);
	Pion pion16("H7", "Noir", 7, 6);


	//7-  Creez les deux tours blanches d'id "A1" et "H1" dans les positions respectives (0,0) et (7,0)

	Tour tour1("A1", "Blanc", 0, 0);
	Tour tour2("H1", "Blanc", 7, 0);

	//8-  Creez les deux tours noires  d'id "A8" et "H8" dans les positions respectives (0,7) et (7,7)

	Tour tour3("A8", "Noir", 0, 7);
	Tour tour4("H8", "Noir", 7, 7);

	//9-  Creez un Echiquier

	Echiquier echiquier = Echiquier();

	//10- Ajoutez toutes les pièces précidament définies à l'echiquier

	echiquier.ajouterPion(pion1);
	echiquier.ajouterPion(pion2);
	echiquier.ajouterPion(pion3);
	echiquier.ajouterPion(pion4);
	echiquier.ajouterPion(pion5);
	echiquier.ajouterPion(pion6);
	echiquier.ajouterPion(pion7);
	echiquier.ajouterPion(pion8);
	echiquier.ajouterPion(pion9);
	echiquier.ajouterPion(pion10);
	echiquier.ajouterPion(pion11);
	echiquier.ajouterPion(pion12);
	echiquier.ajouterPion(pion13);
	echiquier.ajouterPion(pion14);
	echiquier.ajouterPion(pion15);
	echiquier.ajouterPion(pion16);

	echiquier.ajouterTour(tour1);
	echiquier.ajouterTour(tour2);
	echiquier.ajouterTour(tour3);
	echiquier.ajouterTour(tour4);

	echiquier.ajouterRoi(roi1, 0);
	echiquier.ajouterRoi(roi2, 1);

	//11-  Deplacer la piece d'id A2 à la position (0,2)  --Deplacement de Pion

	echiquier.deplacerPiece("A2", 0, 2);

	//12-  Deplacer le piece d'id H7 à la position (7,4)  --Deplacement du Pion

	echiquier.deplacerPiece("H7", 7, 4);

	//13-  Deplacer la piece d'id A2 à la position (0,4)  --Deplacement du Pion

	echiquier.deplacerPiece("A2", 0, 4);

	//14-  Deplacer la piece d'id H8 à la position (7,6)  --Deplacement de la Tour

	echiquier.deplacerPiece("H8", 7, 6);

	//15-  Deplacer la piece d'id H8 à la position (7,6)  --Deplacement de la Tour

	echiquier.deplacerPiece("H8", 7, 6);

	//16-  Enlever la piece d'id A2

	echiquier.enleverPion("A2");



	//////////////////////////////////////////////////////
	cout << endl << endl << endl;
	string id;
	cout<<"Entrer un id entre A-H et 0-7";
	cin >> id;
	cout << "Position(x,y) = ";
	echiquier.afficherPosition(id);
	int x,y;
	cout<<"Entrer une position X";
	cin>>x;
	cout<<"Entrer une position Y";
	cin >>y;

	echiquier.deplacerPiece(id, x, y);
	cout << endl;
	/////////////////////////////////////////////////////
	system("PAUSE");
	return 0;
}

