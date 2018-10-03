//==============================================================================
// Nom         : Graphe.cpp
// Auteurs     : Vincent Fortin & Dominique Piché & Ibrahima Séga Jr Sangaré
// Date        : 28 octobre 2016
// Description : Implémentation de la classe Graphe
//==============================================================================

#pragma once
#include "Graphe.h"
#include <fstream>
#include <algorithm>
#include <map>
#include <utility>
#include "Chemin.h"

// Constructeur par défaut
Graphe::Graphe()
{

}

// Destructeur
Graphe::~Graphe()
{
	viderGraphe();
}

// Constructeur par paramètres
Graphe::Graphe(const Graphe& graphe)
{
	for (int i = 0; i < graphe.tabSommets_.size(); i++)
		tabSommets_.push_back(new Sommet(*(graphe.tabSommets_[i])));

	for (int i = 0; i < graphe.tabArcs_.size(); i++)
		tabArcs_.push_back(new Arc(*(graphe.tabArcs_[i])));
}

void Graphe::creerGraphe(const string& nomFichier)
{
	ifstream fichier(nomFichier);
	if (fichier.is_open())
	{
		string temp1, temp2, temp;
		while (fichier.peek() != '\n')
		{
			getline(fichier, temp1, ',');
			getline(fichier, temp2, ';');
			tabSommets_.push_back(new Sommet(string(temp1), string(temp2)));
		}

		getline(fichier, temp);

		while (fichier.peek() != '\n')
		{
			Sommet* sommets[2];
			getline(fichier, temp, ',');
			sommets[0] = findSommet(temp);
			getline(fichier, temp, ',');
			sommets[1] = findSommet(temp);
			getline(fichier, temp, ';');

			Arc* arc = new Arc(sommets, stoi(temp));
			arc->setIdentifiant(sommets[0]->getIdentifiant() + "-" + sommets[1]->getIdentifiant());
			sommets[0]->ajouterVoisin(arc);
			sommets[1]->ajouterVoisin(arc);

			tabArcs_.push_back(arc);
		}
	}
}

// Lit le graphe en cout
void Graphe::lireGraphe()
{
	cout << endl;

	for (int i = 0; i < tabSommets_.size(); i++)
	{

		cout << "(" + tabSommets_[i]->getIdentifiant() + ", " + tabSommets_[i]->getType() + ", (";
		vector<Sommet*> voisins = tabSommets_[i]->getVoisins();

		for (int j = 0; j < voisins.size(); j++)
		{

			cout << voisins[j]->getIdentifiant();

			if (j != voisins.size() - 1)
				cout << ", ";
		}

		cout << "))" << endl;
	}
}


// Trouve le prochain sommet à l'aide de l'index et du type
int Graphe::findNext(int index, string type)
{
	Sommet* currentNode = tabSommets_[index];

	for (int i = index + 1; i < tabSommets_.size(); i++)
	{
		Sommet* nextNode = tabSommets_[i];
		if (!(currentNode->isConnectedTo(nextNode)) &&
			nextNode->getType() == "rien" &&
			!nextNode->hasNeighborType(type))
			return i;
	}

	throw string("end");
}

// Extrait le sous-graphe résultant d’un graphe contenant uniquement 
// les routes empruntables suivant l’autonomie maximale du véhicule
Graphe Graphe::extractionGraphe(const Vehicule& vehicule)

{
	Graphe nouveauGraphe;	

	for (int i = 0; i < tabArcs_.size(); i++)
	{
		if (tabArcs_[i]->getDistance() <= vehicule.getAutonomieMax())
			nouveauGraphe.tabArcs_.push_back(new Arc(*(tabArcs_[i])));
	}

	bool sommetDejaPris;

	Sommet** sommetsArc;
	for (int i = 0; i < tabSommets_.size(); i++)
	{	
		sommetDejaPris = false;
		for (int j = 0; j < nouveauGraphe.tabArcs_.size(); j++)
		{

			sommetsArc = nouveauGraphe.tabArcs_[j]->getSommets();
			for (int k = 0; k < 2; k++)
				if (sommetsArc[k]->getIdentifiant() == tabSommets_[i]->getIdentifiant())
				{
				
						for (int m = 0; m < nouveauGraphe.tabSommets_.size(); m++)
							if (nouveauGraphe.tabSommets_[m]->getIdentifiant() == tabSommets_[i]->getIdentifiant())
								sommetDejaPris = true;
					if(!sommetDejaPris)
						nouveauGraphe.tabSommets_.push_back(new Sommet(*(tabSommets_[i])));
				}
		}
		

	}
	return nouveauGraphe;
}

// Trouve le plus court chemin à l'aide de l'algorithme de Djikstra
void Graphe::plusCourtChemin(const string& origine, const string& destination, Vehicule* vehicule)
{
	Sommet* sommetDepart = findSommet(origine);
	Sommet* sommetFin = findSommet(destination);

	if (sommetDepart == NULL || sommetFin == NULL || vehicule->getAutonomieRestante() <= 0)
	{
		cout << "Aucun chemin ne peut etre trouve, car vos sommets terminaux\n sont soit inexistant, soit du mauvais type." << endl;
		return;
	}

	bool pasDetrajet = false;
	Chemin* cheminCouverts = new Chemin(new Vehicule(vehicule));
	cheminCouverts->ajouterSommet(sommetDepart, 0);
	vector<Chemin*> trajet = { new Chemin(*cheminCouverts) };
	Chemin* bonTrajet = nullptr;

	while(!pasDetrajet && !cheminCouverts->sommetExiste(sommetFin))
	{
		
		Chemin* parcoursActuel = nullptr;
		Arc* plusCourtTrajet = nullptr;

		for (Chemin* chemin : trajet) {
			Sommet* sommet = chemin->getSommets()[chemin->getSommets().size() - 1];
			for (Arc* arcDuParcours : sommet->getArcs()) {
				if (!cheminCouverts->sommetExiste(arcDuParcours->getSommets()[1]) && arcDuParcours->getDistance() <= chemin->getVehicule()->getAutonomieRestante())
				{
					if (plusCourtTrajet != nullptr)
					{
						if (arcDuParcours->getDistance() + chemin->getLongueur() < plusCourtTrajet->getDistance() + parcoursActuel->getLongueur())
						{
							parcoursActuel = chemin;
							plusCourtTrajet = arcDuParcours;
						}
					}
					else
					{
						parcoursActuel = chemin;
						plusCourtTrajet = arcDuParcours;
					}
				}
			}
		}
		if(plusCourtTrajet == nullptr)
		{
			pasDetrajet = true;
			cout << "Il n'y a pas de trajet possible\n";
		}
		else
		{
			Chemin* trajetPotentiel = new Chemin(*parcoursActuel);
			trajetPotentiel->ajouterSommet(plusCourtTrajet->getSommets()[1], plusCourtTrajet->getDistance());

			trajet.push_back(trajetPotentiel);
			bonTrajet = trajetPotentiel;
			cheminCouverts->ajouterSommet(plusCourtTrajet->getSommets()[1], plusCourtTrajet->getDistance());
		}

	}

	if (bonTrajet != nullptr && !pasDetrajet)
	{
		
		vehicule->setAutonomieRestante(bonTrajet->getVehicule()->getAutonomieRestante());
		for (Sommet* sommet : bonTrajet->getSommets())
		{
			cout << sommet->getIdentifiant();
			if (sommet->getIdentifiant() != bonTrajet->getSommets()[bonTrajet->getSommets().size() - 1]->getIdentifiant())
				cout << " -> ";
		}
		cout << " \nKilométrage: " << bonTrajet->getLongueur() << endl;
	}
	delete cheminCouverts;
	trajet.erase(trajet.begin(), trajet.end());
}


// Trouve le sommet correspondant à l'identifiant
Sommet* Graphe::findSommet(const string& identifiant)
{
	for (int i = 0; i < tabSommets_.size(); i++)
		if (tabSommets_[i]->getIdentifiant() == identifiant)
			return tabSommets_[i];
	return NULL;
}

// Vide le graphe
void Graphe::viderGraphe()
{
	tabArcs_.erase(tabArcs_.begin(), tabArcs_.end());
	tabSommets_.erase(tabSommets_.begin(), tabSommets_.end());
	tabArcs_.clear();
	tabSommets_.clear();
}