//==============================================================================
// Nom         : Graphe.cpp
// Auteurs     : Vincent Fortin & Dominique Piché & Ibrahima Séga Jr Sangaré
// Date        : 28 octobre 2016
// Description : Implémentation de la classe Sommet
//==============================================================================

#pragma once
#include "Sommet.h"
#include "Arc.h"

// Constructeur par paramètres
Sommet::Sommet(string identifiant, string type)
	: identifiant_(identifiant), type_(type)
{

}

// Destructeur
Sommet::~Sommet()
{
	vectorArc_.erase(vectorArc_.begin(), vectorArc_.end());
}

// Trouve les voisins
vector<Sommet*> Sommet::getVoisins() const
{
	// Crée un de sommets nommé voisins
	vector<Sommet*> voisins;

	for (int i = 0; i < vectorArc_.size(); i++)
	{
		Sommet** sommetsArc = vectorArc_[i]->getSommets();

		if (sommetsArc[0]->getIdentifiant() != identifiant_)
			voisins.push_back(sommetsArc[0]);
		else
			voisins.push_back(sommetsArc[1]);
	}

	return voisins;
}

// Retourne l'identifiant
string Sommet::getIdentifiant() const
{
	return identifiant_;
}

// Retourne le type de carburant
string Sommet::getType() const
{
	return type_;
}

// Retourne le vecteur arc
vector<Arc*> Sommet::getArcs() const
{
	return vectorArc_;
}

// Retourne le degré
int Sommet::getDegre() const
{
	return degre_;
}

// Établit l'identifiant
void Sommet::setIdentifiant(string identifiant)
{
	identifiant_ = identifiant;
}

// Établit le type
void Sommet::setType(string type)
{
	type_ = type;
}

// Ajoute un voisin
void Sommet::ajouterVoisin(Arc* voisin)
{
	vectorArc_.push_back(voisin);
	degre_++;
}

// Dit si le sommet est connecté au sommet fourni
bool Sommet::isConnectedTo(Sommet* sommet)
{
	for (int i = 0; i < degre_; i++)
		if (vectorArc_[i]->contains(sommet))
			return true;

	return false;
}

// Dit s'il y a un voisin avec le type sélectionné
bool Sommet::hasNeighborType(string type)
{
	vector<Sommet*> sommets = getVoisins();
	for (int i = 0; i < sommets.size(); i++)
	{
		if (sommets[i]->getType() == type)
		{
			return true;
		}
	}

	return false;
}