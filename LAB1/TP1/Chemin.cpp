#pragma once
#include "Chemin.h"

using namespace std;

Chemin::Chemin()
{
	ensSommets_ = std::vector<Sommet*>();
	longueur_ = 0;
	vehicule_ = nullptr;
}

Chemin::Chemin(Vehicule* vehicule): vehicule_(vehicule)
{
	ensSommets_ = std::vector<Sommet*>();
	longueur_ = 0;
}

Chemin::~Chemin()
{
	ensSommets_.erase(ensSommets_.begin(), ensSommets_.end());
	if (vehicule_ != nullptr)
		delete vehicule_;
}

int Chemin::getLongueur() const
{
	return longueur_;
}

Vehicule* Chemin::getVehicule() const
{
	return vehicule_;
}

std::vector<Sommet*> Chemin::getSommets() const
{
	return ensSommets_;
}

void Chemin::setLongueur(int longueur)
{
	longueur_ = longueur;
}

void Chemin::setSommets(vector<Sommet*> sommets)
{
	ensSommets_ = sommets;
}

void Chemin::setVehicule(Vehicule* vehicule)
{
	vehicule_ = vehicule;
}

void Chemin::ajouterSommet(Sommet* sommet, int distanceParcourue)
{
	if (sommet->getType() == vehicule_->getType() || sommet->getType() == "hybrid")
		vehicule_->setAutonomieRestante(vehicule_->getAutonomieMax());
	else
		vehicule_->setAutonomieRestante((vehicule_->getAutonomieRestante() - distanceParcourue));
	ensSommets_.push_back(sommet);
	longueur_ += distanceParcourue;
}

bool Chemin::sommetExiste(Sommet* sommet)
{
	for (Sommet* unSommet : ensSommets_)
		if (sommet->getIdentifiant() == unSommet->getIdentifiant())
			return true;
	return false;
}
