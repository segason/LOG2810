//==============================================================================
// Nom         : Graphe.cpp
// Auteurs     : Vincent Fortin & Dominique Piché & Ibrahima Séga Jr Sangaré
// Date        : 28 octobre 2016
// Description : Description de la classe Vehicule
//==============================================================================

#pragma once
#include "Vehicule.h""
#include <iostream>

using namespace std;

// Constructeur par défaut
Vehicule::Vehicule() 
{

}

Vehicule::Vehicule(Vehicule* vehicule)
{
	autonomieRestante_ = vehicule->autonomieRestante_;
	autonomieMax_ = vehicule->autonomieMax_;
	type_ = vehicule->type_;
	
}

// Destructeur
Vehicule::~Vehicule()
{

}

// Constructeur par paramètres
Vehicule::Vehicule(int autonomieRestante, int autonomieMax, const string& type) : 
	autonomieRestante_(autonomieRestante), autonomieMax_(autonomieMax), type_(type)
{

}

// Établit l'autonomie restante
void Vehicule::setAutonomieRestante(int autonomieRestante)
{
	autonomieRestante_ = autonomieRestante;
}

// Établit l'autonomie maximale
void Vehicule::setAutonomieMax(int autonomieMax)
{
	autonomieMax_ = autonomieMax;
}

// Établit le type de carburant utilisé
void Vehicule::setType(const string& type)
{
	type_ = type;
}

// Retourne l'autonomie restante
int Vehicule::getAutonomieRestante() const
{
	return autonomieRestante_;
}

// Retourne l'autonomie maximale
int Vehicule::getAutonomieMax() const
{
	return autonomieMax_;
}

// Retourne le type de carburant utilisé
string Vehicule::getType() const
{
	return type_;
}

// Remplit le véhicule de carburant
void Vehicule::pleinCarburant()
{
	autonomieRestante_ = autonomieMax_;
}