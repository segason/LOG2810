//==============================================================================
// Nom         : Zone.cpp
// Auteurs     : Vincent Fortin & Dominique Piche & Ibrahima Sega Jr Sangare
// Date        : 16 novembre 2016
// Description : Implementation de la classe Zone
//==============================================================================

#include "Zone.h";
#include <algorithm>

// Constructeur par defaut
Zone::Zone()
{
	nom_ = "";
	vehicules_ = {};
	quartiers_ = {};
	automate_ = nullptr;
}

// Destructeur
Zone::~Zone()
{
	if (automate_ != nullptr)
	{
		delete automate_;
		automate_ = nullptr;
	}
}

// Retourne l'automate
Automate* Zone::getAutomate() const
{
	return automate_;
}

// Retourne le nom
string Zone::getNom() const
{
	return nom_;
}

// Retourne le vecteur de vehicules
vector<Vehicule*> Zone::getVehicules() const
{
	return vehicules_;
}

// Retourne le vector de quartiers
vector<string> Zone::getQuartiers() const
{
	return quartiers_;
}

// Place le parametre recu comme automate
void Zone::setAutomate(Automate* automate)
{
	automate_ = automate;
}

// Place le parametre recu comme nom
void Zone::setNom(const string& nom)
{
	nom_ = nom;
}

// Place le parametre recu comme vecteur de vehicules
void Zone::setVehicules(const vector<Vehicule*>& vehicules)
{
	vehicules_ = vehicules;
}

// Place le parametre recu comme vecteur de quartiers
void Zone::setQuartiers(const vector<string>& q)
{
	quartiers_ = q;
}

// Ajoute le parametre recu dans le vecteur de quartiers
void Zone::ajouterQuartier(const string& quartier)
{
	quartiers_.push_back(quartier);
}

// Ajoute le parametre recu dans le vecteur de vehicules
void Zone::ajouterVehicule(Vehicule* vehicule) {
	vehicules_.push_back(vehicule);
}

// Retirer le vehicule recu en parametre du vecteur de vehicules
void Zone::retirerVehicule(Vehicule* vehicule)
{
	auto it = remove(vehicules_.begin(), vehicules_.end(), vehicule);
	vehicules_.erase(it, vehicules_.end());
}

// Retourne l'etat de l'automate selon le parametre recu
bool Zone::reconLangage(const string zipCode) const
{
	return automate_->trouverEtat(zipCode) != nullptr;
}

Vehicule* Zone::envoyerVehicule() const
{
	for (auto vehicule : vehicules_)
		if (!vehicule->estOccupe())
			return vehicule;
	return nullptr;
}


// Retourne le nombre de vehicules dans le vecteur de vehicules
size_t Zone::getNombreVehicules() const
{
	return vehicules_.size();
}

// Retourne le nombre de quartiers dans le vecteur de quartiers
size_t Zone::nQuartiers() const
{
	return quartiers_.size();
}
