//==============================================================================
// Nom         : Graphe.cpp
// Auteurs     : Vincent Fortin & Dominique Piché & Ibrahima Séga Jr Sangaré
// Date        : 28 octobre 2016
// Description : Description de la classe Chemin
//==============================================================================

#pragma once
#include <vector>
#include "Sommet.h"
#include "Vehicule.h"

class Chemin
{
public:
	// Constructeur par défaut
	Chemin();

	// Constructeur par paramètres
	Chemin(Vehicule* vehicule);

	// Destructeur
	~Chemin();

	// Getters
	int getLongueur() const;
	Vehicule* getVehicule() const;
	std::vector<Sommet*> getSommets() const;

	//Setters
	void setLongueur(int longueur);
	void setSommets(vector<Sommet*> sommets);
	void setVehicule(Vehicule* vehicule);

	
	void ajouterSommet(Sommet* sommet, int distanceParcourue);
	bool sommetExiste(Sommet* sommet);
	
private:
	std::vector<Sommet*> ensSommets_;
	Vehicule* vehicule_;
	int longueur_;
	

};