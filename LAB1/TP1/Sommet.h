//==============================================================================
// Nom         : Graphe.cpp
// Auteurs     : Vincent Fortin & Dominique Pich� & Ibrahima S�ga Jr Sangar�
// Date        : 28 octobre 2016
// Description : Description de la classe Sommet
//==============================================================================

using namespace std;
#pragma once
#include <string>
#include <vector>

class Arc;

class Sommet {

public:
	// Constructeur
	Sommet(string identifiant = "NotAvailable", string type = "rien");
	
	// Destructeur
	~Sommet();
	
	// Setters
	void setIdentifiant(string identifiant);
	void setType(string type);

	// Ajoute un voisin
	void ajouterVoisin(Arc* voisin);

	// V�rifie si le sommet est connect�
	bool isConnectedTo(Sommet* sommet);

	// V�rifie s'il a le voisin
	bool hasNeighborType(string identifiant);

	// Getters
	string getIdentifiant() const;
	string getType() const;

	int getDegre() const;

	vector<Sommet*> getVoisins() const;
	vector<Arc*> getArcs() const;
	
private:
	string identifiant_;
	string type_;
	vector<Arc*> vectorArc_;
	int degre_;
};