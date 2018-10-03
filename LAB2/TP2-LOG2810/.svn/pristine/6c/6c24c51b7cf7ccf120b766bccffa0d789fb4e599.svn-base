//==============================================================================
// Nom         : Vehicule.cpp
// Auteurs     : Vincent Fortin & Dominique Piché & Ibrahima Séga Jr Sangaré
// Date        : 16 novembre 2016
// Description : Implémentation de la classe Vehicule
//==============================================================================

#pragma once
#include <iostream>
#include "Vehicule.h"

using namespace std;

// Constructeur par défaut
Vehicule::Vehicule():zoneActuelle_(""), positionActuelle_(""),occupation_(false), nTrajetsPleins_(0), nTrajetVides_(0)
{

}

// Constructeur par parametres
Vehicule::Vehicule(const string& zoneActuelle, const string& positionActuelle, bool occupation): nTrajetsPleins_(0), nTrajetVides_(0)
{
	zoneActuelle_ = zoneActuelle;
	positionActuelle_ = positionActuelle;
	occupation_ = occupation;
}

// Destructeur
Vehicule::~Vehicule()
{	

}

// Place le parametre recu comme zone actuelle
void Vehicule::setZoneActuelle(const string& zoneActuelle)
{
	zoneActuelle_ = zoneActuelle;
}

// Place le parametre recu comme position actuelle
void Vehicule::setPositionActuelle(const string& positionActuelle)
{

	positionActuelle_ = positionActuelle;
	

}

// Place le parametre recu comme occupation
void Vehicule::setOccupation(bool occupation)
{
	occupation_ = occupation;
}

// Mets le parametre recu comme nombre de trajets pleins
void Vehicule::setNombreDeTrajetsPleins(int n)
{
	nTrajetsPleins_ = n;
}

// Mets le paramatre recu comme nombre de trajets vides
void Vehicule::setNombreDeTrajetsVides(int n)
{
	nTrajetVides_ = n;
}

// Retourne si le vehicule est occupe ou non
bool Vehicule::estOccupe() const
{
	return occupation_;
}

// Retourne le nombre de trajets pleins
int Vehicule::getNombreDeTrajetsPleins() const
{
	return nTrajetsPleins_;
}

// Retourne le nombre de trajets vides
int Vehicule::getNombreDeTrajetsVides() const
{
	return nTrajetVides_;
}

// Retourne la zone actuelle
string Vehicule::getZoneActuelle() const
{
	return zoneActuelle_;
}

// Retourne la position actuelle
string Vehicule::getPositionActuelle() const
{
	return positionActuelle_;
}