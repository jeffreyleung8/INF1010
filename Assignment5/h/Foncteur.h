/****************************************************************************
* Fichier     : Foncteur.h
* Auteur      : Jeffrey Leung 1867781 et Xavier Ralay 1786307
* Travail     : TP5
* Description : Définition et implementation des foncteurs
***************************************************************************/
#pragma once
#ifndef _FONCTEUR_
#define _FONCTEUR_
#include"Gene.h"
#include <iostream>
using namespace std;

class MemeId {
public:
	MemeId(int id)
		:id_(id) {};
	bool operator()(Gene* gene) {
		if(id_ == gene->getId()) {
			return true;
		}
		return false;
	}
private:
	int id_;
};

class MemeEspece {
public:
	MemeEspece(string espece)
		:espece_(espece) {}
	bool operator() (Gene* gene) {
		if (espece_ == gene->getEspece()){
			return true; 
	}
		return false;
	}
private:
	string espece_;
};

class MemeNom {
public:
	MemeNom(string nom)
		:nom_(nom){}
	bool operator()(Gene* gene) {
		if (nom_ == gene->getNom()) {
			return true;
		}
		return false;
	}
private:
	string nom_;
};

class TriParLongueur {
public: 
	bool operator()(Gene* gene1, Gene* gene2) {
		if (gene1->getContenu().size() < gene2->getContenu().size()) {
			return true;
		}
		//Si le contenu est de meme longueur, on compare le id.
		if (gene1->getContenu().size() == gene2->getContenu().size()) {
			if (gene1->getId() < gene2->getId())
				return true;
		}
		return false;
	}
};

class TriParEspeceEtNom {
public:
	bool operator()(Gene* gene1, Gene* gene2) {
		if (gene1->getEspece() == gene2->getEspece()) {
			if (gene1->getNom() < gene2->getNom()){
				return true;
			}
		}
		if (gene1->getEspece() < gene2->getEspece()) {
			return true;
		}
		return false;
	}
};

class DetruireGenes {
public:
	void operator()(Gene* gene){
		delete gene;
	}
};

class DetruireEspece {
public: 
	DetruireEspece(string espece)
		:espece_(espece){}
	bool operator()(Gene* gene) {
		if (espece_ == gene->getEspece()) {
			delete gene;
			return true;
		}
		return false;
	}
private:
	string espece_;
};
#endif
