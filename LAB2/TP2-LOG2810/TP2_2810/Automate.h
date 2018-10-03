//==============================================================================
// Nom         : Automate.h
// Auteurs     : Vincent Fortin & Dominique Piche & Ibrahima Sega Jr Sangare
// Date        : 18 novembre 2016
// Description : Description de la classe Automate
//==============================================================================

#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <iostream>
#include <vector>
#include "Etat.h"
#include "Zone.h"

class Zone;
class Etat;

class Automate
{
public:
	// Constructeur par defaut
	Automate();

	// Destructeur
	~Automate();

	// Constructeur par paramètres
	Automate(Etat* depart, Etat* courant);
	Automate& operator=(const Automate automate);

	Etat* getDepart() const;
	Etat* getCourant() const;

	Etat* trouverEtat(const string& identifiant);
	Etat* trouverDernierEtatCommun(const string& identifiant);
	void setDepart(Etat* depart);
	void setCourant(Etat* courant);

private:
	void viderAutomate(Etat* suivant);
	Etat* getEtatSuivant(const char& transition) const;
	Etat* depart_;
	Etat* courant_;
};

#endif // !AUTOMATE_H