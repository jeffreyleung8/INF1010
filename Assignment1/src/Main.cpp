/**************************************************
 * Titre: Travail pratique #1 - Main.cpp
 * Date: 10 janvier 2017
 * Auteur: Jeffrey Leung 1867781 et Xavier Ralay 1786307
**************************************************/

#include "Specialite.h"
#include "Medecin.h"
#include "Infirmier.h"
#include "Personnel.h"

#include <string>
#include <iostream>

using namespace std;

int main()
{
    //C'est a vous de voir si vous devez allouer dynamiquement ou non les elements

	//1-  Creez un objet du type Infirmier � l'aide du constructeur par d�faut
    
    Infirmier infirmier1 = Infirmier();
    
	//2-  Modifiez le nom, le prenom et le nbChambre de cet objet � l'aide des m�thodes de modification
    
    infirmier1.modifierNom("Doe");
    infirmier1.modifierPrenom ("John");
    infirmier1.modifierNbChambre(10);
    
	//3-  Creez 11 autres objets du type Infirmier � l'aide du constructeur par param�tre avec des valeurs de votre choix
    
    
    
    Infirmier infirmier2("Tremblay", "Gilles",2);
    Infirmier infirmier3("Labe", "Sylvie",3);
    Infirmier infirmier4("Labelle", "Amelie",4);
    Infirmier infirmier5("Lamontagne", "Maxime",5);
    Infirmier infirmier6("Laflamme", "John", 6);
    Infirmier infirmier7("Lamoureux", "Julie", 7);
    Infirmier infirmier8("Langlais", "Eric", 7);
    Infirmier infirmier9("Lamarre", "Roger", 8);
    Infirmier infirmier10("Laplante", "Linda", 10);
    Infirmier infirmier11("Latour", "Hug", 11);
    Infirmier infirmier12("Lessard", "Emilie", 12);
    
    //4-  Creez un objet du type Personnel � l'aide du constructeur par d�faut
    
    Personnel personnel = Personnel();
    
	//5-  Ajoutez les 12 objets du type Infimier � tableauInfirmiers de ce dernier
    
    personnel.ajouterInfirmier(infirmier1);
    personnel.ajouterInfirmier(infirmier2);
    personnel.ajouterInfirmier(infirmier3);
    personnel.ajouterInfirmier(infirmier4);
    personnel.ajouterInfirmier(infirmier5);
    personnel.ajouterInfirmier(infirmier6);
    personnel.ajouterInfirmier(infirmier7);
    personnel.ajouterInfirmier(infirmier8);
    personnel.ajouterInfirmier(infirmier9);
    personnel.ajouterInfirmier(infirmier10);
    personnel.ajouterInfirmier(infirmier11);
    personnel.ajouterInfirmier(infirmier12);
    
    
	//6-  Creez un objet du type Specialite � l'aide du constructeur par d�faut
    
    Specialite* specialite1 = new Specialite();
    
	//7-  Modifiez le domaine et le niveau de cet objet � l'aide des m�thodes de modification

    (*specialite1).modifierDomaine("Chirurgie");
    (*specialite1).modifierNiveau(15);
    
	//8-  Creez 5 autres objets du type Specialite � l'aide du constructeur par param�tre avec des valeurs de votre choix

    Specialite* specialite2 = new Specialite("Demartologie",10);
    Specialite* specialite3 = new Specialite("Gastrologie",11);
    Specialite* specialite4 = new Specialite("Sport",7);
    Specialite* specialite5 = new Specialite("Podologie",8);
    Specialite* specialite6 = new Specialite("Pediatrie",9);
   
	//9-  Creez un objet du type Medecin � l'aide du constructeur par d�faut
                           
    Medecin medecin1 = Medecin();
    
	//10- Modifiez le nom, les horaires et la specialite de ce dernier
    
    medecin1.modifierNom("House");
    medecin1.modifierHoraires(10);
	medecin1.modifierSpecialite(specialite1);
    
    
	//11- Creez 5 autres objets du type Medecin � l'aide du constructeur par param�tre avec des valeurs de votre choix
	Medecin medecin2("Sherlock",5,specialite2);
    Medecin medecin3("Holmes", 6, specialite3);
    Medecin medecin4("Kyle", 7, specialite4);
    Medecin medecin5("Jean", 8, specialite5);
    Medecin medecin6("Jules", 9, specialite6);
                           
	//12- Expliquez la relation entre les deux objets Medecin et Specialite. Justifiez votre r�ponse
	/*L'objet Medecin utilise l'objet Specialite comme pointeur. 
	  Leur relation peut se caracteriser par une agregation etant 
	  donne que l'objet Specialite n'est pas disparait lorsque
	  Medecin, l'objet qui l'utlise, est detruit*/


	//13- Ajoutez les 6 objets du type Medecin � tableauMedecins de l'objet Personnel d�j� cr��
    
    personnel.ajouterMedecin (medecin2);
    personnel.ajouterMedecin (medecin3);
    personnel.ajouterMedecin (medecin4);
    personnel.ajouterMedecin (medecin5);
    personnel.ajouterMedecin (medecin6);

	//14- Affichez la liste des medecins
	personnel.afficherMedecins();
	cout << endl << endl;

	//15- Affichez la liste des infirmiers
	personnel.afficherInfirmiers();
	cout << endl << endl << endl;

	system("PAUSE");
	return 0;
}
