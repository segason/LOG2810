//==============================================================================
// Nom         : Zone.h
// Auteurs     : Vincent Fortin & Dominique Piche & Ibrahima Sega Jr Sangare
// Date        : 18 novembre 2016
// Description : Description de la classe Zone
//==============================================================================

#ifndef ZONE_H
#define ZONE_H
#include <iostream>
#include <vector>
#include "Automate.h"
#include "Vehicule.h"

using namespace std;

class Automate;
class Vehicule;

class Zone
{
public:
	// Constructeur par defaut
	Zone();

	// Destructeur
	~Zone();
	
	// Getters
	Automate* getAutomate() const;
	string getNom() const;
	vector<Vehicule*> getVehicules() const;
	vector<string> getQuartiers() const;

	// Setters
	void setAutomate(Automate* automate);
	void setNom(const string& nom);
	void setVehicules(const vector <Vehicule*>& vehicules);
	void setQuartiers(const vector <string>& q);

	void ajouterQuartier(const string& quartier);
	void ajouterVehicule(Vehicule* vehicule);
	void retirerVehicule(Vehicule* vehicule);
	bool reconLangage(const string zipCode) const;
	Vehicule* envoyerVehicule() const;

	
	size_t getNombreVehicules() const;
	size_t nQuartiers() const;

private:
	Automate* automate_;
	string nom_;
	vector <Vehicule*> vehicules_;
	vector<string> quartiers_;
};

#endif