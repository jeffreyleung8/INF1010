/**************************************************
* Titre: Travail pratique #2 - Main.cpp
* Date:  9 février 2017
* Auteur: Jeffrey Leung et Xavier Ralay
* Matricule: 1867781 & 1786307
**************************************************/

#include <string>
#include <iostream>
#include "Hopital.h"
#include "Personnel.h"
#include "Infirmier.h"
#include "Medecin.h"
#include "Const.h"

using namespace std;

int main()//utiliser operateur pour afficher 
{
	// C'est a vous de voir si vous devez allouer dynamiquement ou non les elements

	//1-  Creez 11 objets du type Infirmier � l'aide du constructeur par param�tre avec des valeurs de votre choix
	

	Infirmier* infirmier1 = new Infirmier("Doe", "John", 10);
	Infirmier* infirmier2 = new Infirmier("Tremblay", "Gilles", 2);
	Infirmier* infirmier3 = new Infirmier("Labe", "Sylvie", 3);
	Infirmier* infirmier4 = new Infirmier("Labelle", "Amelie", 4);
	Infirmier* infirmier5 = new Infirmier("Lamontagne", "Maxime", 5);
	Infirmier* infirmier6 = new Infirmier("Laflamme", "John", 6);
	Infirmier* infirmier7 = new Infirmier("Lamoureux", "Julie", 7);
	Infirmier* infirmier8 = new Infirmier("Langlais", "Eric", 8);
	Infirmier* infirmier9 = new Infirmier("Lamarre", "Roger", 9);
	Infirmier* infirmier10 = new Infirmier("Laplante", "Linda", 10);
	Infirmier* infirmier11 = new Infirmier("Latour", "Hug", 11);

	//2-  Creez deux objets du type Personnel � l'aide du constructeur par d�faut
	
	Personnel* personnelA = new Personnel();
	Personnel* personnelB = new Personnel();

	//3 - Creez deux objects de type Hopital qui vont prendre chacun en parametre le nom de l'hopital et le personnel assigné
	// Hopital Sacré-Coeur de Montréal
	// Hôpital Jean-Talon
	
	Hopital hopitalA("Hopital Sacre-Coeur de Montreal", personnelA);
	Hopital hopitalB("Hopital Jean-Talon", personnelB);

	//4-  Ajoutez les 6 objets du type Infimier � au personnel de l'Hôpital Sacré-Coeur de Montréal (avec methode)

	personnelA->ajouterInfirmier(infirmier1);
	personnelA->ajouterInfirmier(infirmier2);
	personnelA->ajouterInfirmier(infirmier3);
	personnelA->ajouterInfirmier(infirmier4);
	personnelA->ajouterInfirmier(infirmier5);
	personnelA->ajouterInfirmier(infirmier6);

	//5-  Ajoutez les 5 objets qui restent du type Infimier � au personnel de l'Hôpital Jean-Talon (avec operateur+=)

	*personnelB += infirmier7;
	*personnelB += infirmier8;
	*personnelB += infirmier9;
	*personnelB += infirmier10;
	*personnelB += infirmier11;

	//6-  Creez 7 objets du type Specialite � l'aide du constructeur par param�tre avec des valeurs de votre choix
	// Specialites : Chirurgie, Demartologie, Gastrologie, Sport, Podologie, Pediatrie, Psychiatrie

	Specialite* specialite1 = new Specialite("Chirurgie", 15);
	Specialite* specialite2 = new Specialite("Demartologie", 10);
	Specialite* specialite3 = new Specialite("Gastrologie", 11);
	Specialite* specialite4 = new Specialite("Sport", 7);
	Specialite* specialite5 = new Specialite("Podologie", 8);
	Specialite* specialite6 = new Specialite("Pediatrie", 9);
	Specialite* specialite7 = new Specialite("Psychiatrie", 45);

	//7- Creez 7 autres objets du type Medecin � l'aide du constructeur par param�tre avec des valeurs de votre choix
	// Dr. Franc : en Chirurgie
	// Dr. Sherlock : en Demartologie
	// Dr. Holmes : en Gastrologie
	// Dr. Jean : en Podologie
	// Dr. Jules : en Pediatrie
	// Dr. Kyle : en Sport
	// Dr. House : en Psychiatrie

	Medecin* medecin1 = new Medecin("Dr.Franc", 9, specialite1);
	Medecin* medecin2 = new Medecin("Dr.Sherlock", 5, specialite2);
	Medecin* medecin3 = new Medecin("Dr.Holmes", 6, specialite3);
	Medecin* medecin4 = new Medecin("Dr.Jean", 8, specialite5);
	Medecin* medecin5 = new Medecin("Dr.Jules", 9, specialite6);
	Medecin* medecin6 = new Medecin("Dr.Kyle", 7, specialite4);
	Medecin* medecin7 = new Medecin("Dr.House", 10, specialite7);

	//8- Creer un autre medecin Sherlock en utilisant l'opérateur = et en utilisant le medecin existante Sherlock.
	// Le horaire du deuxieme Sherlock devrai ensuite etre modifie pour une valeur differnte du premier Sherlock

	Medecin medecin8 = *medecin2;
	medecin8.modifierHoraires(6);

	//9- Creer un autre medecin Holmes en utilisant le constructeur de copie et en utilisant le medecin existante Holmes.
	// Le horaire du deuxieme Holmes devrai ensuite etre modifie pour une valeur differnte du premier Holmes

	Medecin medecin9(*medecin3);
	medecin9.modifierHoraires(3);

	//10- Ajoutez les medecins : parmis le personnel de l'hopital Sacré-Coeur : 
	// Dr. Franc, Dr. Sherlock, Dr. Holmes, Dr. Jean, Dr. Jules (avec methode)

	personnelA->ajouterMedecin(medecin1); //Dr.Franc
	personnelA->ajouterMedecin(medecin2); //Dr.Sherlock
	personnelA->ajouterMedecin(medecin3); //Dr.Holmes
	personnelA->ajouterMedecin(medecin4); //Dr.Jean
	personnelA->ajouterMedecin(medecin5);  //Dr.Jules

	// Dr. Sherlock(2), Dr. Holmes(2), Dr. Kyle, Dr. House (avec operateur)

	*personnelB += (medecin6); //Dr.Kyle
	*personnelB += (medecin7); //Dr.House
	*personnelB += (&medecin8); //Dr.Sherlock(2)
	*personnelB += (&medecin9); //Dr.Holmes(2)


	//11- Retirer le medecin Jean et deux infirmiers de l'hopital Sacré-Coeur et ajouter a l'hopital Jean-talon

	//Retrait de personel de l'hopital Sacré-Coeur
	personnelA->retirerMedecin(medecin4->obtenirNom()); //Dr. Jean (avec methode)
	*personnelA -= (infirmier1); //Infirmier John Doe 
	*personnelA -= (infirmier2); //Infirmier Gilles Tremblay
	

	//Ajout de personnel a l'hopital Jean-talon
	*personnelB += (medecin4); //Dr.Jean
	*personnelB += (infirmier1); //Infirmier John Doe
	*personnelB += (infirmier2); //Infirmier Gilles Tremblay
								 
	//12- Faites afficher l'hopital Sacré-Coeur puis Jean-Talon

	cout << hopitalA << endl;
	cout << hopitalB << endl;

	
	//Reponse 3 questions
	//1.Utilite de l'operateur= et du constructeur par copie
	/* L'operateur= et le constructeur par copie permet de transferer les attributs d'un objet intial a un autre objet(duplication d'un objet)
	Le constructeur de copie est appele pour transmettre une valeur passe par parametre a une fonction, initialiser un objet ou retourner une valeur dune fonction  */


	//2.Dans quel cas est-il absolument necessaire de les implenter?
	/*Il faut absolument implanter un constructeur de copie si un pointeur est present comme un attribut dans une classe
	Il faut utiliser ces deux outils lorsqu'un objet doit etre copier dans le programme(parametre de fonction, valeur de retour, duplication objet)*/


	//3.Difference l'operateur = et du constructeur par copie?
	/*L'operateur= permet d'affecter tous les attributs d'un objet a un autre de la meme classe(shallow copie). De l'autre cote, un constructeur par copie permet  
	d'effectuer deux types de copie soit le shallow copy ou le deep copy. Pour un shallow copy, il suffit simplement d'utiliser le constructeur par defaut de la 
	classe de l'objet a copier et seulement les attributs seront transmis a un nouveau objet.Pour un deep copy, il faut definir un constructeur de copie puis il 
	va copier tous les attributs. La difference avec un shallow copy est qu'en cas d'une presence de pointeurs en tant d'attribut, le constructeur de copie va 
	simplement copier l'entite pointee par le pointeur. Cela eviterait que deux objets pointent a la meme place.
	L'operateur nest pas initialise comme un constructeur de copie; il faut creer un methode operateur= avec les instructions entre accolades. Il faut renvoyer 
	le pointeur *this dans cette methode et il faut delete lancien objet avant de creer la nouvelle copie. Ces caracteristiques ne sont pas presentes pour le 
	constructeur de copie.
	*/

	
	system("PAUSE");
	return 0;
}
