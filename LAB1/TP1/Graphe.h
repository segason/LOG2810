//==============================================================================
// Nom         : Graphe.cpp
// Auteurs     : Vincent Fortin & Dominique Piché & Ibrahima Séga Jr Sangaré
// Date        : 28 octobre 2016
// Description : Description de la classe Graphe
//==============================================================================
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Arc.h"
#include "Sommet.h"
#include "Vehicule.h"

using namespace std;

class Graphe {

public:
	// Constructeur
	Graphe();

	// Constreur par copie
	Graphe(const Graphe& graphe);

	// Destructeur
	~Graphe();
	
	void creerGraphe(const string& nomFichier);
	void lireGraphe();
	void plusCourtChemin(const string& origine, const string& destination, Vehicule* vehicule);
	Graphe extractionGraphe(const Vehicule& type);
	

private:
	Sommet* findSommet(const string& identifiant);
	void viderGraphe();
	int findNext(int index, string color);
	vector<Sommet*> tabSommets_;
	vector<Arc*> tabArcs_;

};