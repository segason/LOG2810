//==============================================================================
// Nom         : Automate.cpp
// Auteurs     : Vincent Fortin & Dominique Piche & Ibrahima Sega Jr Sangare
// Date        : 16 novembre 2016
// Description : Implementation de la classe Automate
//==============================================================================

#include <fstream>
#include "Automate.h"

#ifdef _WIN64
#include "dirent.h"
// Source pour dirent.h: https://github.com/tronkko/dirent/blob/master/include/dirent.h
#else
#include <dirent.h>
#endif

// Constructeur par defaut
Automate::Automate()
{
	depart_ = courant_ = nullptr;
}

// Surcharge de l'operateur '=' afin de pouvoir comparer des automates
Automate& Automate::operator=(const Automate automate)
{	
	if (this != &automate) {
		depart_ = automate.depart_;
		courant_ = automate.courant_;
	}
	return *this;
}

// Constructeur par parametre
Automate::Automate(Etat* depart, Etat* courant)
{
	depart_ = depart;
	courant_ = courant;
}

// Destructeur
Automate::~Automate()
{
	viderAutomate(depart_);
	depart_ = nullptr;
}



// Retourne l'etat de depart
Etat* Automate::getDepart() const
{
	return depart_;
}

// Retourne l'etat courant
Etat* Automate::getCourant() const
{
	return courant_;
}



// Selon le parametre recu retourne l'etat suivant
Etat* Automate::getEtatSuivant(const char& transition) const
{
	for (Etat* etat : courant_->getSuivants())
		if (courant_->getIdentifiant() + transition == etat->getIdentifiant())
			return etat;
	return nullptr;
}

// Trouve l'etat courant a l'aide de l'indentifiant recu en parametre
Etat* Automate::trouverEtat(const string& identifiant)
{
	int i = 0;
	courant_ = depart_;
	while (courant_ != nullptr && !courant_->estFinal())
	{
		if (courant_->getIdentifiant() == identifiant)
			return courant_;
		courant_ = getEtatSuivant(identifiant[++i]);
	}

	if (courant_ != nullptr && courant_->estFinal())
		if (courant_->getIdentifiant() == identifiant)
			return courant_;
	return nullptr;

}

// Trouve le dernier etat en commun avec celui recu en parametre
Etat* Automate::trouverDernierEtatCommun(const string& identifiant)
{
	courant_ = depart_;
	int i = 0;
	auto dernier = courant_;
	while (courant_!= nullptr && !courant_->estFinal())
	{
		dernier = courant_;
		courant_ = getEtatSuivant(identifiant[++i]);
	}
	if (courant_ != nullptr && courant_->estFinal())
		return courant_;
	return dernier;
}

// Place le parametre recu comme etat de depart
void Automate::setDepart(Etat* depart)
{
	depart_ = depart;
}

// Place le parametre recu comme etat courant
void Automate::setCourant(Etat* courant)
{
	courant_ = courant;
}

void Automate::viderAutomate(Etat* suivant)
{
	if (!suivant->estFinal())
		for (int i = 0; i < suivant->getSuivants().size(); i++)
			viderAutomate(suivant->getSuivants()[i]);
	delete suivant;
	suivant = nullptr;
}
