/****************************************************************************
* Fichier     : pile.h
* Auteur      : Jeffrey Leung 1867781 et Xavier Ralay 1786307
* Travail     : TP5
* Description : Définition de la classe Pile
***************************************************************************/
#pragma 
#ifndef _PILE_H_
#define _PILE_H_
template <typename T>
class Pile 
{
public:
	//Constructeur par defaut
	Pile();

	//Destructeur
	~Pile();

	//Methode
	bool empiler(const T& t);

	bool depiler(T& t);

	bool estVide();
	
	bool estPleine();

	T& obtenirSommet();

	int obtenirTaille();
 private:
	int capacite_;
	int nbElements_;
	T* tab_;
};

template <typename T>
Pile<T>::Pile()
	:nbElements_(0), capacite_(6), tab_(nullptr) 
	{ tab_ = new T[capacite_]; }


template <typename T>
Pile<T>::~Pile() 
	{delete[]tab_;}


template <typename T>
bool Pile<T>::empiler(const T& t){
	if (nbElements_ < capacite_) {
		tab_[nbElements_++] = t;
		return true;
	}
	return false;
}

template <typename T>
bool Pile<T>::depiler(T& t){
	if(nbElements_ != 0){
		t = tab_[nbElements_ - 1];
		nbElements_--;
		return true;
	}
	return false;
}


template <typename T>
bool Pile<T>::estVide(){
	if (nbElements_ == 0) {
		return true;
	}
	return false;
}

template <typename T>
bool Pile<T>::estPleine(){
	if (nbElements_ == capacite_) {
		return true;
	}
	return false;
}

template <typename T>
T& Pile<T>::obtenirSommet() {
	return tab_[nbElements_-1];
}


template <typename T>
int Pile<T>::obtenirTaille()
{
	return nbElements_;
}


#endif 

/*La pile peut être représentée comme une structure de données générique dans laquelle on peut insérer
des éléments dans un ordre et les récupérer ensuite dans l’ordre du dernier entré, premier sorti (voir
schéma ci-haut).
Dans votre implémentation, la pile sera un tableau dynamique qui permettra de réaliser les actions
suivantes sur son contenu :
• « Empiler » : ajoute un élément sur la pile. Terme anglais correspondant : « Push ».
• « Dépiler » : enlève un élément de la pile et le renvoie. Terme anglais correspondant : « Pop ».
• « La pile est-elle vide ? » : renvoie vrai si la pile est vide, faux sinon.
• « La pile est-elle pleine ? » : renvoie vrai si la pile est pleine, faux sinon.
La classe Pile contient les attributs suivants :
- capacite (entier) : représente la capacité du tableau dynamique
- nombreElements (entier) : représente le nombre d’éléments actuellement dans la pile
- elements : tableau dynamique de type générique
La classe Pile contient les méthodes suivantes :
- Un constructeur par défaut qui initialise le tableau dynamique à une capacité par défaut de 6. Pour
simplifier l’implémentation de la pile, la capacité du tableau restera fixe.
- Un destructeur, si nécessaire.
- Une méthode empiler() qui reçoit un élément de type générique en paramètre et l’ajoute sur la pile.
Cette méthode retourne true si l’élément peut être ajouté, false sinon.
- Une méthode depiler() qui effectue un retour par paramètre de l’élément sur le dessus de la pile.
Cette méthode retourne true si le dépilage est réussi, false sinon.
- Une méthode estVide() qui retourne une valeur booléenne indiquant si la pile est vide. 
4
- Une méthode estPleine() qui retourne une valeur booléenne indiquant si la pile est pleine.
- Une méthode obtenirSommet() ne prenant aucun paramètre et qui retourne une référence sur
l’élément du dessus de la pile.
- Une méthode obtenirTaille() qui retourne un entier indiquant le nombre d’éléments actuellement
dans la pile.
Votre pile est sensée accepter n’importe quel type de donnée.
Le fichier main qui vous est fourni doit pouvoir fonctionner avec vos implémentations. */