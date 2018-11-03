
/**************************************************
* Titre: Travail pratique #4 - Main.cpp
* Date: 2 mars 2017
* Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
**************************************************/

#include "Piece.h"
#include "Roi.h"
#include "Tour.h"
#include "Pion.h"
#include "Fou.h"
#include "Reine.h"

#include "Echiquier.h"

#include <string.h>
#include <iostream>

using namespace std;

int main()
{
	//1-  Creez les huit pions blancs avec les coordonnées (i,1) i : 0-->7 et les id A2-->H2
	Pion* pion1 = new Pion("A2", "Blanc", 0, 1);
	Pion* pion2 = new Pion("B2", "Blanc", 1, 1);
	Pion* pion3 = new Pion("C2", "Blanc", 2, 1);
	Pion* pion4 = new Pion("D2", "Blanc", 3, 1);
	Pion* pion5 = new Pion("E2", "Blanc", 4, 1);
	Pion* pion6 = new Pion("F2", "Blanc", 5, 1);
	Pion* pion7 = new Pion("G2", "Blanc", 6, 1);
	Pion* pion8 = new Pion("H2", "Blanc", 7, 1);

	//2-Creez les huit pions noirs avec les coordonnées (i,6) i : 0-->7 et les id A7-->H7
	
	Pion* pion9 = new Pion("A7", "Noir", 0, 6);
	Pion* pion10 = new Pion("B7", "Noir", 1, 6);
	Pion* pion11 = new Pion("C7", "Noir", 2, 6);
	Pion* pion12 = new Pion("D7", "Noir", 3, 6);
	Pion* pion13 = new Pion("E7", "Noir", 4, 6);
	Pion* pion14 = new Pion("F7", "Noir", 5, 6);
	Pion* pion15 = new Pion("G7", "Noir", 6, 6);
	Pion* pion16 = new Pion("H7", "Noir", 7, 6);

	//3-  Creez les deux tours blanches d'id "A1" et "H1" dans les positions respectives (0,0) et (7,0)

	Tour* tour1 = new Tour("A1", "Blanc", 0, 0);
	Tour* tour2 = new Tour("H1", "Blanc", 7, 0);

	//4-  Creez les deux tours noires  d'id "A8" et "H8" dans les positions respectives (0,7) et (7,7)

	Tour* tour3 = new Tour("A8", "Noir", 0, 7);
	Tour* tour4 = new Tour("H8", "Noir", 7, 7);

	//5-  Creez les Fous blanc et noirs
	Fou* fou1 = new Fou("C1", "Blanc", 7, 0);
	Fou* fou2 = new Fou("F1", "Blanc", 7, 0);
	Fou* fou3 = new Fou("C8", "Noir", 0, 7);
	Fou* fou4 = new Fou("F8", "Noir", 0, 7);

	//6-  Creez les deux reines D1 et D8	

	Reine* reine1 = new Reine("D8", "Noir", 0, 7);
	Reine* reine2 = new Reine("D1", "Blanc", 7, 0);

	//7-  Creez les deux rois E1 et E8
	Roi* roi1 = new Roi("E8", "Noir", 0, 7);
	Roi* roi2 = new Roi("E1", "Blanc", 7, 0);

	// 8- Creez un echiquier 
	Echiquier echiquier1 = Echiquier();


	cout << "----------AJOUT DES PIECES----------" << endl;
	//9- Ajoutez toutes les pièces précidament définies à l'echiquier	
	echiquier1 += pion1;
	echiquier1 += pion2;
	echiquier1 += pion3;
	echiquier1 += pion4;
	echiquier1 += pion5;
	echiquier1 += pion6;
	echiquier1 += pion7;
	echiquier1 += pion8;
	echiquier1 += pion9;
	echiquier1 += pion10;
	echiquier1 += pion11;
	echiquier1 += pion12;
	echiquier1 += pion13;
	echiquier1 += pion14;
	echiquier1 += pion15;
	echiquier1 += pion16;

	echiquier1 += fou1;
	echiquier1 += fou2;
	echiquier1 += fou3;
	echiquier1 += fou4;

	echiquier1 += tour1;
	echiquier1 += tour2;
	echiquier1 += tour3;
	echiquier1 += tour4;

	echiquier1 += reine1;
	echiquier1 += reine2;

	echiquier1 += roi1;
	echiquier1 += roi2;

	cout << "----------TEST DES DEPLACEMENTS------------" << endl;
	//10-  Deplacer la piece d'id A2 à la position (0,2)  --Deplacement de Pion
	echiquier1.deplacerPiece("A2", 0, 2);

	//11-  Deplacer le piece d'id H7 à la position (7,4)  --Deplacement du Pion
	echiquier1.deplacerPiece("H7", 7, 4);

	//12-  Deplacer la piece d'id A2 à la position (0,4)  --Deplacement du Pion
	echiquier1.deplacerPiece("A2", 0, 4);

	//13-  Deplacer la piece d'id H8 à la position (7,6)  --Deplacement de la Tour
	echiquier1.deplacerPiece("H8", 7, 6);

	//14-  Deplacer la piece d'id H8 à la position (7,6)  --Deplacement de la Tour
	echiquier1.deplacerPiece("H8", 7, 6);

	//15-  Enlever la piece d'id A2 
	echiquier1 -= "A2";

	cout << "----------TEST DES PROMOTIONS------------" << endl;
	
	//16- Promouvoir la piece d'id F6.
	echiquier1.promouvoir("F6");

	//17- Promouvoir la piece d'id B2.	
	echiquier1.promouvoir("B2");

	//18- Affichage de l'Echiquier
	cout << echiquier1;


	/*Questions
	1. La classe Piece est une classe abstraite car il y a une methode pure virtuelle, c'est-a-dire qu'une des methode est affecte a 0.
	Par consequent, aucun objet ne peut directement appartenir a cette classe. Par contre, un objet d'une classe derive de cette classe abstraite
		peut herite de ces methodes et de certains attributs.
	2. Le destructeur virtuel sert a pouvoir appele, lors de l'execution, le bon destructeur; le destructeur du type reel de l'objet.
	3. On peut construire une classe Reine en heritant de la Tour et du Fou puisque la reine est comme la somme de la tour et d'un fou en terme de mouvement.
	*/
	//Si vous avez besoin de lancer avec un arret a la fin, faites ctrl+F5;
	system("PAUSE");
	return 0;
}
