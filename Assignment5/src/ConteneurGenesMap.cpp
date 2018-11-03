/****************************************************************************
* Fichier     : ConteneurGenesMap.h
* Auteur      : Jeffrey Leung 1867781 et Xavier Ralay 1786307
* Travail     : TP5
* Description : Implementation de la classe ConteneurGenesMap
***************************************************************************/
#include <map>
#include <iostream>
#include "ConteneurGenesMap.h"
#include "Foncteur.h"
#include <utility>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;

ConteneurGenesMap::ConteneurGenesMap()
{

}

ConteneurGenesMap::~ConteneurGenesMap()
{
}

void ConteneurGenesMap::inserer(unsigned int id, const string &nom, const string &desc, const string &espece, const string &contenu) {
	Gene* gene = new Gene(id, nom, desc, espece, contenu);
	uneMap_.insert(pair<string, Gene*>(espece, gene));
}

Gene* ConteneurGenesMap::trouver(unsigned int id) const {

	MemeId memeId(id);
	for (auto it = uneMap_.begin(); it != uneMap_.end(); ++it) {
		if (memeId(it->second)) {
			return it->second;
		}
	}
	return nullptr;
}

bool ConteneurGenesMap::retirer(unsigned int id) {

	MemeId memeId(id);
	DetruireGenes detruireGene;

	for(auto it = uneMap_.begin(); it != uneMap_.end(); ++it){
		if (memeId(it->second)) {
			detruireGene(it->second); //delete gene*
			uneMap_.erase(it); //enleve le gene* de la map
			return true;
		}
	}
	return false;

}
unsigned int ConteneurGenesMap::retirerEspece(const string &espece) {
	
	DetruireEspece detruireEspece(espece);

	auto iterator = uneMap_.equal_range(espece);
	unsigned int nbEspece = 0;
	for (auto it = uneMap_.begin(); it != uneMap_.end(); ++it) {
		if (it->first == espece) {
			if (detruireEspece(it->second)) {
				nbEspece++;
			}
		}
		

	}
	uneMap_.erase(espece);
	return nbEspece;
}
void ConteneurGenesMap::vider() {

	DetruireGenes detruireGene;
	
	for (auto it = uneMap_.begin(); it != uneMap_.end(); ++it) {
		detruireGene(it->second);
		uneMap_.erase(it, uneMap_.end());
	}
}

void ConteneurGenesMap::afficherParEspeceEtNom(ostream& out) const {
	
	list<Gene*> liste;

	for (auto it = uneMap_.begin(); it != uneMap_.end(); ++it){
		liste.push_back(it->second);
	}

	liste.sort(TriParEspeceEtNom());

	copy(liste.begin(), liste.end(), ostream_iterator<Gene*>(out, "\n"));

}
void ConteneurGenesMap::afficherParLongueur(ostream& out) const {

	list<Gene*> liste;

	for (auto it = uneMap_.begin(); it != uneMap_.end(); ++it) {
		liste.push_back(it->second);
	}

	liste.sort(TriParLongueur());

	copy(liste.begin(), liste.end(), ostream_iterator<Gene*>(out, "\n"));
	
}
void ConteneurGenesMap::afficherEspece(const string &espece, ostream& out) const {

	MemeEspece memeEspece = MemeEspece(espece);
	
	for (auto it = uneMap_.begin(); it != uneMap_.end(); ++it) {
		if (memeEspece(it->second)) {
			out << it->second;
		}
	}
}

unsigned int ConteneurGenesMap::modifierNoms(const string &espece, const map<string, string> &noms) {
	
	unsigned int nbNoms = 0;
	MemeEspece memeEspece = MemeEspece(espece);
	
	for (auto it = uneMap_.begin(); it != uneMap_.end(); ++it) {
		if (memeEspece(it->second)) {			
			for (auto d = noms.begin(); d != noms.end(); ++d) {
				if (it->second->getNom() == d->first) {
					it->second->setNom(d->second);
					nbNoms++;
				}
			}
		}
	}
	return nbNoms;	
}
