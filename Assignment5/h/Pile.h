/****************************************************************************
* Fichier     : pile.h
* Auteur      : Jeffrey Leung 1867781 et Xavier Ralay 1786307
* Travail     : TP5
* Description : D�finition de la classe Pile
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

/*La pile peut �tre repr�sent�e comme une structure de donn�es g�n�rique dans laquelle on peut ins�rer
des �l�ments dans un ordre et les r�cup�rer ensuite dans l�ordre du dernier entr�, premier sorti (voir
sch�ma ci-haut).
Dans votre impl�mentation, la pile sera un tableau dynamique qui permettra de r�aliser les actions
suivantes sur son contenu :
� � Empiler � : ajoute un �l�ment sur la pile. Terme anglais correspondant : � Push �.
� � D�piler � : enl�ve un �l�ment de la pile et le renvoie. Terme anglais correspondant : � Pop �.
� � La pile est-elle vide ? � : renvoie vrai si la pile est vide, faux sinon.
� � La pile est-elle pleine ? � : renvoie vrai si la pile est pleine, faux sinon.
La classe Pile contient les attributs suivants :
- capacite (entier) : repr�sente la capacit� du tableau dynamique
- nombreElements (entier) : repr�sente le nombre d��l�ments actuellement dans la pile
- elements : tableau dynamique de type g�n�rique
La classe Pile contient les m�thodes suivantes :
- Un constructeur par d�faut qui initialise le tableau dynamique � une capacit� par d�faut de 6. Pour
simplifier l�impl�mentation de la pile, la capacit� du tableau restera fixe.
- Un destructeur, si n�cessaire.
- Une m�thode empiler() qui re�oit un �l�ment de type g�n�rique en param�tre et l�ajoute sur la pile.
Cette m�thode retourne true si l��l�ment peut �tre ajout�, false sinon.
- Une m�thode depiler() qui effectue un retour par param�tre de l��l�ment sur le dessus de la pile.
Cette m�thode retourne true si le d�pilage est r�ussi, false sinon.
- Une m�thode estVide() qui retourne une valeur bool�enne indiquant si la pile est vide. 
4
- Une m�thode estPleine() qui retourne une valeur bool�enne indiquant si la pile est pleine.
- Une m�thode obtenirSommet() ne prenant aucun param�tre et qui retourne une r�f�rence sur
l��l�ment du dessus de la pile.
- Une m�thode obtenirTaille() qui retourne un entier indiquant le nombre d��l�ments actuellement
dans la pile.
Votre pile est sens�e accepter n�importe quel type de donn�e.
Le fichier main qui vous est fourni doit pouvoir fonctionner avec vos impl�mentations. */