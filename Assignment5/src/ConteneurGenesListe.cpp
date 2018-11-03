/****************************************************************************
* Fichier     : ConteneurGenesListe.cpp
* Auteur      : Jeffrey Leung 1867781 et Xavier Ralay 1786307
* Travail     : TP5
* Description : Implementation de la classe ConteneurGenesListe
***************************************************************************/

#include <list>
#include <iostream>
#include "ConteneurGenesListe.h"
#include "Foncteur.h"
#include <algorithm>
#include <iterator>

using namespace std;

ConteneurGenesListe::ConteneurGenesListe()
{
}

ConteneurGenesListe::~ConteneurGenesListe()
{
}

void ConteneurGenesListe::inserer(unsigned int id, const string &nom, const string &desc, const string &espece, const string &contenu) {
	Gene* gene = new Gene(id, nom, desc, espece, contenu);
	liste_.push_back(gene);
}

Gene* ConteneurGenesListe::trouver(unsigned int id) const {
	MemeId memeId(id);
		
	auto it = find_if(liste_.begin(), liste_.end(), memeId); //iterateur pointant sur le gene sil est trouve; sinon iterateur est egale a nullptr
	if (it == liste_.end()) { 
		return nullptr;
	}
	return *it;
}

bool ConteneurGenesListe::retirer(unsigned int id) {
	DetruireGenes detruireGene;
	Gene* gene = trouver(id);
	if (gene == nullptr) {
		return false;
	}
	else {
		liste_.remove(gene);
		detruireGene(gene);
		return true;
	}
}

unsigned int ConteneurGenesListe::retirerEspece(const string &espece) {
	int a = liste_.size();
	DetruireEspece detruireEspece = DetruireEspece(espece);

	auto it= remove_if(liste_.begin(), liste_.end(), detruireEspece); //iterator pointant sur les genes retournant true de detruireEspece et delete le gene si true
	liste_.erase(it, liste_.end()); //enleve les genes d'une espece de la liste
	return (a - liste_.size());
}

void ConteneurGenesListe::vider() {
DetruireGenes detruireGenes;

	for_each(liste_.begin(), liste_.end(), detruireGenes); 
	liste_.clear();

}

void ConteneurGenesListe::afficherParEspeceEtNom(ostream& out) const {

	list<Gene*> b = liste_; //creer une nouvelle liste ds laquelle on va trier les elements

	b.sort(TriParEspeceEtNom());
	copy(b.begin(), b.end(), ostream_iterator<Gene*>(out, "\n"));

}
void ConteneurGenesListe::afficherParLongueur(ostream& out) const {
	
	list<Gene*> b = liste_; //creer une nouvelle liste ds laquelle on va trier les elements

	b.sort(TriParLongueur());
	copy(b.begin(), b.end(), ostream_iterator<Gene*>(out, "\n"));

}
void ConteneurGenesListe::afficherEspece(const string &espece, ostream& out) const {
	
	MemeEspece memeEspece(espece); 
	
	copy_if(liste_.begin(), liste_.end(), ostream_iterator<Gene*>(out, "\n"), memeEspece);

}

unsigned int ConteneurGenesListe::modifierNoms(const string &espece, const map<string, string> &noms) {
	unsigned int nbNoms = 0;
	MemeEspece memeEspece(espece);

	
	auto it = find_if(liste_.begin(), liste_.end(), MemeEspece(espece)); 
	
	for (it; it != liste_.end(); ++it) {
		for (auto d = noms.begin(); d != noms.end(); ++d) {
			if ((*it)->getNom() == d->first) {
				(*it)->setNom(d->second);
				nbNoms++;
			}
		}
	}
	return nbNoms;	
}

