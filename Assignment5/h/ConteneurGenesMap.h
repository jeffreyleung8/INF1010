/****************************************************************************
* Fichier     : ConteneurGenesMap.h
* Auteur      : Jeffrey Leung 1867781 et Xavier Ralay 1786307
* Travail     : TP5
* Description : Définition de la classe ConteneurGenesMap
***************************************************************************/
#pragma once
#ifndef _CONTENEUR_GENES_MAP_
#define _CONTENEUR_GENES_MAP_

#include <map>
#include "ConteneurGenes.h"


class ConteneurGenesMap :public ConteneurGenes
{
public:
	//Constructeur
	ConteneurGenesMap();

	//Destructeur
	~ConteneurGenesMap();

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
	multimap<string, Gene*> uneMap_; //Un multimap avec une cle type string(espece) et une valeur type Gene*
	
};


#endif 
