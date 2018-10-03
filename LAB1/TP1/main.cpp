//==============================================================================
// Nom         : Graphe.cpp
// Auteurs     : Vincent Fortin & Dominique Piché & Ibrahima Séga Jr Sangaré
// Date        : 28 octobre 2016
// Description : Main du programme
//==============================================================================

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

#include "Arc.h"
#include "Graphe.h"
#include "Sommet.h"
#include "Vehicule.h"

using namespace std;

void afficherMenu();

int main()
{
	// Permet l'affichage des accents
	setlocale(LC_ALL, "");

	// Initialisation des variables
	bool exit = false;
	bool option1 = false;

	Graphe graphe;
	Vehicule* vehicule = new Vehicule();
	string nomFichier;
	ifstream fichier;
	string carte;
	string typeVehicule;

	int autonomieMax;
	int autonomieRestante;
	
	do
	{
		// Affichage du menu
		afficherMenu();

		// Prise de la réponse
		string reponse = "";
		cout << "Saisissez une option : ";
		cin >> reponse;
		cout << endl;

		// Le case dépend de l'entrée de l'utilisateur
		switch (atoi(reponse.c_str()))
		{

		case 1:
			cout << "Veuillez entrer le type du vehicule (essence, electrique ou hybrid) : ";
			cin >> typeVehicule;
			cout << endl;
			if (typeVehicule == "essence" || typeVehicule == "electrique" || typeVehicule == "hybrid")
			{
				option1 = true;
				vehicule->setType(typeVehicule);
			}

			// Gestion d'erreur
			if (!option1)
			{
				cout << "Le type de vehicule n'est pas valide" << endl;
				break;
			}

			cout << "Veuillez entrer l'autonomie maximale du vehicule en kilomètres : ";
			cin >> reponse;
			cout << endl;
			autonomieMax = atoi(reponse.c_str());
			vehicule->setAutonomieMax(autonomieMax);
			if (autonomieMax <= 0)
			{
				cout << "Autonomie maximale inférieure ou égal à zéro." << endl;
				option1 = false;
				
				break;
			}

			cout << "Veuillez entrer l'autonomie restante du véhicule en kilomètres : ";
			cin >> reponse;
			cout << endl;
			autonomieRestante = atoi(reponse.c_str());
			vehicule->setAutonomieRestante(autonomieRestante);
			if (autonomieRestante <= 0)
			{
				cout << "Autonomie restante inférieure ou égale à zero." << endl;
				option1 = false;
				
				break;
			}
			// Gestion d'erreur
			if (autonomieRestante > autonomieMax)
			{
				cout << "Autonomie restante supérieure à l'autonomie maximale" << endl;
				option1 = false;
				break;
			}
			break;

		case 2:

			// Demande le nom complet du fichier (incluant l'extension)
			cout << "Veuillez entrer le nom complet du fichier : ";
			cin >> nomFichier;
			cout << endl;

			// Vérification que le fichier existe
			fichier.open(nomFichier);
			if (fichier.is_open()) {
				fichier.close();
				graphe.creerGraphe(nomFichier);
				graphe.lireGraphe();
			}
			else
			{
				cout << "Nom de fichier invalide.";
			}
			cout << endl << endl;
			
			break;			

		case 3:

			// On ne peut déterminer le plus court chemin sans avoir 
			// entré les informations du véhicule au préalable
			if (option1)
			{
				string depart;
				string fin;

				cout << "Point de depart : ";
				cin >> depart;
				cout << "Point de d'arrivee : ";
				cin >> fin;
				
				// TODO : Vérifier que les depart et fin existent

				Graphe grapheExtrait = graphe.extractionGraphe(*vehicule);
				grapheExtrait.plusCourtChemin(depart, fin, vehicule);									

			}
			// Gestion d'erreur
			else 
			{
				cout << "Veuillez d'abord fournir les caractéristiques du véhicule. " << endl;
			}
			break;

		case 4:

			// Fin du programme
			exit = true;
			break;
		default:
		cout << "Choisissez une option entre 1 et 4 : " << endl;
		}

	} while (!exit);
	if(vehicule != nullptr)
		delete vehicule;


}

// Menu principal
void afficherMenu()
{
	cout << "================================================" << endl << endl;
	cout << "1. Entrer les caractéristiques du véhicule." << endl;
	cout << "2. Mettre à jour la carte." << endl;
	cout << "3. Déterminer le plus court chemin." << endl;
	cout << "4. Quitter." << endl << endl;
}

