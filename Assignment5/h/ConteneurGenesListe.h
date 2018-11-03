/****************************************************************************
* Fichier     : ConteneurGenesListe.h
* Auteur      : Jeffrey Leung 1867781 et Xavier Ralay 1786307
* Travail     : TP5
* Description : Définition de la classe ConteneurGenesListe
***************************************************************************/
#pragma once
#ifndef _CONTENEUR_GENES_LISTE_
#define _CONTENEUR_GENES_LISTE_

#include <list>
#include "ConteneurGenes.h"
class ConteneurGenesListe : public ConteneurGenes
{
public:
	//Constructeur
	ConteneurGenesListe();

	//Destructeur
	~ConteneurGenesListe();

	void inserer(unsigned int id, const string &nom, const string &desc, const string &espece, const string &contenu);
	Gene* trouver(unsigned int id) const;

	bool retirer(unsigned int id);
	unsigned int retirerEspece(const string &espece);
	void vider();

	void afficherParEspeceEtNom(ostream& out) const;
	void afficherParLongueur(ostream& out) const;
	void afficherEspece(const string &espece, ostream& out) const;

	unsigned int modifierNoms(const string &espece, const map<string, string> &noms);
private:
	list<Gene*> liste_; //liste contenant des variables de type Gene*
};


#endif 
