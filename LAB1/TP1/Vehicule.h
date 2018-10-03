//==============================================================================
// Nom         : Graphe.cpp
// Auteurs     : Vincent Fortin & Dominique Piché & Ibrahima Séga Jr Sangaré
// Date        : 28 octobre 2016
// Description : Description de la classe Vehicule
//==============================================================================

#pragma once
#include <string>

using namespace std;

class Vehicule
{
public:
	// Constructeur par défaut
	Vehicule();

	// Constructeur par paramètres
	Vehicule(Vehicule* vehicule);
	Vehicule(int autonomieRestante, int autonomieMax, const string& type);

	// Destructeur
	~Vehicule();
	
	// Setters
	void setAutonomieRestante(int autonomieRestante);
	void setAutonomieMax(int autonomieMax);
	void setType(const string& sourceEnergie);

	// Getters
	int getAutonomieRestante() const;
	int getAutonomieMax() const;
	string getType() const;

	// Remplit le véhicule de carburant
	void pleinCarburant();

private:
	int autonomieRestante_;
	int autonomieMax_;
	string type_;
};

