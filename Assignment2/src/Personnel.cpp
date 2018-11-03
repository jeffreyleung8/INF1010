/**************************************************
* Titre: Travail pratique #2 - Personnel.cpp
* Date:  9 février 2017
* Auteur: Jeffrey Leung et Xavier Ralay
* Matricule: 1867781 & 1786307
**************************************************/

#include "Medecin.h"
#include "Infirmier.h"
#include "Personnel.h"
#include <iostream>
#include <iomanip>
#include "Const.h"
/****************************************************************************
* Fonction: Personnel::Personnel()
* Description: Constructeur par défaut
* Paramètres: Aucun
* Retour: Aucun
****************************************************************************/
Personnel::Personnel()
{
};

/****************************************************************************
* Fonction: Personnel::~Personnel()
* Description: Destructeur
* Paramètres: Aucun
* Retour: Aucun
****************************************************************************/
Personnel::~Personnel() 
{
};

/****************************************************************************
* Fonction: bool Personnel::ajouterMedecin(Medecin* medecin)  
* Description: Ajoute un medecin dans le vecteur
* Paramètres: medecin (Medecin de type pointeur)
* Retour: Bool -> Vrai = ajout reussi  Faux = aucun ajout (deja dans le vecteur)
****************************************************************************/
bool Personnel::ajouterMedecin(Medecin* medecin)  
{
	for (unsigned int i = 0; i < medecins_.size(); i++)
	{
		if (medecin == medecins_[i])
			return false;
	}	
		medecins_.push_back(medecin);
		return true;
}

/****************************************************************************
* Fonction: bool Personnel::retirerMedecin(const std::string& nom) 
* Description: Retire un medecin du vecteur
* Paramètres: nom (string) par valeur
* Retour: Bool -> Vrai = retrait reussi  Faux = aucun retrait (pas present dans le vecteur)
****************************************************************************/
bool Personnel::retirerMedecin(const std::string& nom)  
{
	for (unsigned int i = 0; i < medecins_.size(); i++)
	{
		if (*medecins_[i] == nom)
		{
			medecins_[i] = medecins_[medecins_.size() - 1];
			medecins_.pop_back();
			i = medecins_.size();
			return true;
		}
	}
	return false;
}

/****************************************************************************
* Fonction: bool Personnel::ajouterInfirmier(Infirmier* infirmier) 
* Description: Ajoute un infirmier dans le vecteur
* Paramètres: infirmier (Infirmier de type pointeur)
* Retour: Bool -> Vrai = ajout reussi  Faux = aucun ajout (deja dans le vecteur)
****************************************************************************/
bool Personnel::ajouterInfirmier(Infirmier* infirmier) 
{
	for (unsigned int i = 0; i < infirmiers_.size(); i++)
	{
		if (*infirmier == *infirmiers_[i])
			return false;
	}
	infirmiers_.push_back(infirmier);
	return true;
}

/****************************************************************************
* Fonction: bool Personnel::retirerInfirmier(const std::string& nomComplet) 
* Description: Retire un infirmier du vecteur
* Paramètres: nomComplet (string) par valeur
* Retour: Bool -> Vrai = retrait reussi  Faux = aucun retrait (pas present dans le vecteur)
****************************************************************************/
bool Personnel::retirerInfirmier(const std::string& nomComplet) 
{
	for (unsigned int i = 0; i < medecins_.size(); i++)
	{
		if (*infirmiers_[i] == nomComplet)
		{
			infirmiers_[i] = infirmiers_[infirmiers_.size() - 1];
			infirmiers_.pop_back();
			i = infirmiers_.size();
			return true;
		}
	}
	return false;
}

/****************************************************************************
* Fonction: Personnel & Personnel::operator+=( Medecin * medecin)
* Description: Ajoute un medecin dans le vecteur avec operateur
* Paramètres: medecin (Medecin de type pointeur) 
* Retour: objet lui-meme (avec *this)
****************************************************************************/
Personnel & Personnel::operator+=( Medecin * medecin)
{
	ajouterMedecin(medecin);
	//cout << medecin->obtenirNom() << " a ete ajoute" << endl;
	return *this;
}

/****************************************************************************
* Fonction: Personnel & Personnel::operator-=(Medecin * medecin)
* Description: Retire un medecin du vecteur (avec operateur)
* Paramètres: medecin (Medecin de type pointeur)
* Retour: objet lui-meme (avec *this)
****************************************************************************/
Personnel & Personnel::operator-=(Medecin * medecin)
{
	retirerMedecin(medecin->obtenirNom());
	return *this;
}

/****************************************************************************
* Fonction: Personnel & Personnel::operator+=(Infirmier * infirmier)
* Description: Ajoute un infirmier dans le vecteur
* Paramètres: infirmier (Infirmier de type pointeur)
* Retour: objet lui-meme (avec *this)
****************************************************************************/
Personnel & Personnel::operator+=(Infirmier * infirmier)
{
	ajouterInfirmier(infirmier);
	return *this;
}

/****************************************************************************
* Fonction: Personnel & Personnel::operator-=(Infirmier * infirmier)
* Description: Retire un infirmier du vecteur
* Paramètres: infirmier (Infirmier de type pointeur)
* Retour: objet lui-meme (avec *this)
****************************************************************************/
Personnel & Personnel::operator-=(Infirmier * infirmier)
{
	retirerInfirmier(infirmier->obtenirNomComplet());
	return *this;
}

/****************************************************************************
* Fonction: void Personnel::afficherMedecins(ostream& os) const 
* Description: Affiche tableau de medecins
* Paramètres: os (ostream pour affichage)
* Retour: Aucun
****************************************************************************/
void Personnel::afficherMedecins(ostream& os) const 
{
	string tabMed = "Tableau Medecins";
	string nom = "Nom";
	string horaires = "Horaires";
	string domaine = "Domaine Specialite";
	string niveau = "Niveau Specialite";

	os << AFFICHER_ESPACE(espacement_medecin / 2) << tabMed 
		<< AFFICHER_ESPACE(espacement_medecin / 2) << endl;

	os << AFFICHER_LINE(espacement_medecin + tabMed.size()) << endl;

	os << "| " << nom << AFFICHER_ESPACE(espace_nom - nom.size()) 
		<< " | " << horaires << AFFICHER_ESPACE(2*espace_horaires - horaires.size())
		<< " | " << domaine << AFFICHER_ESPACE(espace_domaine - domaine.size()) 
		<< " | " << AFFICHER_ESPACE(espace_niveau - niveau.size() / 2) << niveau
		<< AFFICHER_ESPACE(espace_niveau - niveau.size() / 2)
		<< "| " << endl;
		
	os << AFFICHER_LINE(espacement_medecin + tabMed.size()) << endl;
	for (size_t i = 0; i < medecins_.size(); i++)
	{	
		os << *medecins_[i];
	}
	os << AFFICHER_LINE(espacement_medecin + tabMed.size()) << endl;
	os << AFFICHER_ESPACE(espacement_medecin + tabMed.size()) << endl;
}

/****************************************************************************
* Fonction: void Personnel::afficherInfirmiers(ostream& os) const 
* Description: Affiche tableau d'infirmiers
* Paramètres: os (ostream pour affichage)
* Retour: Aucun
****************************************************************************/
void Personnel::afficherInfirmiers(ostream& os) const 
{
	string tabInf = "Tableau Infimiers";
	string nomComplet = "Nom Complet";
	string nbChambre = "Nombre de Chambre";

	os << AFFICHER_ESPACE(espacement_infirmier/2) << tabInf 
		<< AFFICHER_ESPACE(espacement_infirmier/2) << endl;
	os << AFFICHER_LINE(espacement_infirmier + tabInf.size()) << endl;
	
	os << "| " << nomComplet << AFFICHER_ESPACE(espace_nom - nomComplet.size())
		 << " | " << nbChambre << AFFICHER_ESPACE(2 * espace_chambre - nbChambre.size())
		 << " | " << endl;
	os << AFFICHER_LINE(espacement_infirmier + tabInf.size()) << endl;

	for (size_t i = 0; i < infirmiers_.size(); i++)
	{
		os << *infirmiers_[i];
	}

	os << AFFICHER_LINE(espacement_infirmier + tabInf.size());
}

/****************************************************************************
* Fonction: std::ostream & operator<<(std::ostream & os, const Personnel & personnel)
* Description: Affiche tableau medecin et tableau infirmier
* Paramètres In: personnel (Personnel) par valeur
* Paramètres In/Out:  os (ostream pour affichage)
****************************************************************************/
std::ostream & operator<<(std::ostream & os, const Personnel & personnel)
{
	personnel.afficherMedecins(os);
	personnel.afficherInfirmiers(os);
	return os;
}