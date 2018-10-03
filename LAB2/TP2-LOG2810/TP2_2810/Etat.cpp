//==============================================================================
// Nom         : Etat.cpp
// Auteurs     : Vincent Fortin & Dominique Piche & Ibrahima Sega Jr Sangare
// Date        : 23 novembre 2016
// Description : Implementation de la classe Etat
//==============================================================================

#pragma once

#include "Etat.h"

using namespace std;

// Constructeur par defaut
Etat::Etat()
{
	suivants_ = {};
	identifiantEtat_ = "";
	final_ = false;
}

// Constructeur par parametres
Etat::Etat( const string& identifiantEtat, vector<Etat*> suivant, bool estFinal)
{
	identifiantEtat_ = identifiantEtat;
	suivants_ = suivant;
	final_ = estFinal;
}

// Destructeur
Etat::~Etat()
{

}

// Ajoute un etat recu en parametres au vecteurs d'etats
void Etat::ajouterSuivants(Etat* suivant)
{
	suivants_.push_back(suivant);
}

// Retourne l'identifiant
string Etat::getIdentifiant() const
{
	return identifiantEtat_;
}

// Retourne l'element suivant
vector<Etat*>Etat::getSuivants() const
{
	return suivants_;
}

// Indique si l'etat est final
bool Etat::estFinal() const
{
	return final_;
}

// Mets l'identifiant a celui recu en parametre
void Etat::setIdentifiant(const string& identifiant)
{
	identifiantEtat_ = identifiant;
}

// Place l'etat recu en parametre comme etat final
void Etat::setFinalite(bool estFinal)
{
	final_ = estFinal;
}

// Place l'etat recu en parametre comme etat suivant
void Etat::setSuivants(const vector<Etat*> suivants)
{
	suivants_ = suivants;
}
