//==============================================================================
// Nom         : Graphe.cpp
// Auteurs     : Vincent Fortin & Dominique Piché & Ibrahima Séga Jr Sangaré
// Date        : 28 octobre 2016
// Description : Implémentation de la classe Arc
//==============================================================================

#pragma once
#include "Arc.h"
#include "Sommet.h"

// Constructeur par paramètres
Arc::Arc(Sommet* sommets[2], int distance) 
	: distance_(distance)
{
	sommets_[0] = sommets[0];
	sommets_[1] = sommets[1];
}

// Destructeur
Arc::~Arc()
{
	if (sommets_[0] != nullptr)
		delete sommets_[0];
	if (sommets_[1] != nullptr)
		delete sommets_[1];
}

Arc::Arc()
{
	sommets_[0] = sommets_[1] = nullptr;
}

// Retourne l'identifiant
string Arc::getIdentifiant() const
{
	return identifiant_;
}

// Retourne la distance, soit la longueur d'arc
int Arc::getDistance() const
{
	return distance_;
}

// Établit l'identifiant
void Arc::setIdentifiant(string identifiant)
{
	identifiant_ = identifiant;
}

// Établit la distance
void Arc::setDistance(int distance)
{
	distance_ = distance;
}

// Dit si un des sommets liés à l'arc contient le bon identifiant
bool Arc::contains(Sommet* sommet)
{
	if ((sommets_[0]->getIdentifiant() == sommet->getIdentifiant()) || (sommets_[1]->getIdentifiant() == sommet->getIdentifiant()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Obtenir l'autre sommet de l'arc
Sommet* Arc::getTerminal(Sommet* sommetOrigine) const
{
	if (sommetOrigine->getIdentifiant() == sommets_[0]->getIdentifiant())
	{
		if(sommets_[1]!= nullptr)
		return sommets_[1];
	}
	return sommets_[0];
}

// Dit si un des sommets liés à l'arc contient le bon type
bool Arc::hasType(const string& type) const
{
	return (sommets_[0]->getType() == type || sommets_[1]->getType() == type);
}