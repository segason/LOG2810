//==============================================================================
// Nom         : Graphe.cpp
// Auteurs     : Vincent Fortin & Dominique Piché & Ibrahima Séga Jr Sangaré
// Date        : 28 octobre 2016
// Description : Description de la classe Arc
//==============================================================================

using namespace std;
#pragma once
#include <string>
#include <vector>

class Sommet;

class Arc {

public:
	// Destructeur
	~Arc();

	// Constructeur
	Arc();
	Arc(Sommet * sommets[2], int distance = 1);

	// Setters
	void setDistance(int distance);
	void setIdentifiant(string identifiant);

	// Vérifie s'il contient le type
	bool hasType(const string& type) const;

	// Vérifie s'il contient le sommet
	bool contains(Sommet* sommet);

	// Getters
	int getDistance() const;
	string getIdentifiant() const;
	Sommet* getTerminal(Sommet* sommetOrigine) const;
	Sommet** getSommets() const
	{
		return (Sommet**)sommets_;
	}	
	
private :
	int distance_;
	string identifiant_;
	Sommet* sommets_[2];
};
