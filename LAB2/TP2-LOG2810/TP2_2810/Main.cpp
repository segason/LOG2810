//==============================================================================
// Nom         : main.cpp
// Auteurs     : Vincent Fortin & Dominique Piche & Ibrahima Sega Jr Sangare
// Date        : 16 novembre 2016
// Description : Main du programme
//==============================================================================

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include "Automate.h"
#include "Vehicule.h"
#include "Utilisateur.h"
#include "Zone.h"

#ifdef _WIN64
#include "dirent.h"
// Source pour dirent.h: https://github.com/tronkko/dirent/blob/master/include/dirent.h
#else
#include <dirent.h>
#endif

const int MAX_SIZE = 255;

using namespace std;

//Fonctions
void afficherMenu();
vector<Zone*> creerLexiques(char cheminChar[255]);
void equilibrerFlotte(vector<Zone*>& zones);
void lancerSimulation(vector<Zone*>& zones, vector<Vehicule*>& vehicule, vector<Utilisateur*>& utilisateurs);

//Fonctions utiles
bool zoneValide(const string & origine, const vector<Zone*> & testZones);
void afficherNombreDeVehicules(const vector<Zone*> & zones, const string& titreTableau);
void afficherTrajetsVehicules(const vector<Vehicule*> & vehicules);
void assignerZones(vector<Zone*>& zones);
void assignerPositions(vector<Zone*>& zones);
void libererVehicules(vector<Vehicule*>& vehicules);
Zone* trouverZone(const vector<Zone*>& zones, Utilisateur* util);
void libererRessources(vector<Zone*>& testZones, vector<Utilisateur*>& utilisateurs, vector<Vehicule*>& vehicules);

//Foncteur pour le tri de du nombre de véhicules en ordre croissant
bool ordonnerVehiculesZone(Zone* zone1, Zone* zone2);

int main()
{
	// Initialisation des variables
	
	bool exit = false;	
	bool optionA = false;
	bool optionB = false;
	char cheminChar[MAX_SIZE] = "";
	bool pointValide;
	string cheminDossier = "";
	
	vector<Zone*> testZones;
	vector<Utilisateur*> utilisateurs;
	vector<Vehicule*> vehicules;
	
	string origine = "";
	string destination = "";
	string numGroupe = "";
	string zoneDepart = "";
	

	do {
		// Prise de la reponse
		afficherMenu();

		// Initialisation de variables
		char reponse = 'z';
		string reponseString = "";

		cout << "Saisissez une option (a, b, c ou d) : ";
		cin >> reponseString;

		if (reponseString.length() == 1) {

			// Sinon ce qui suit le char est utilise comme input dans l'etape suivante
			reponse = reponseString[0]; 
			cout << endl;
			if (reponse != 'a' && reponse != 'b' && reponse != 'c' && reponse != 'd')
			{
				cout << "Entree invalide! Les choix sont : a, b, c et d. \n\n";
			}
		}
		else {
			cout << endl << "Entree invalide! Veuillez n'ecrire qu'un caractere. \n\n";
		}
		
		// Le case depend de l'entree de l'utilisateur
		switch (reponse)
		{
		case 'a' :
			cout << "Veuillez entrer le nom du repertoire ou se trouvent les fichiers .txt qui decrivent les zones. \n";
			cout << "Exemple de chemin pour Windows : C:/Users:/Vincent/Desktop/zone/\n";
			cout << "Exemple de chemin pour Linux : /home/ibrahima/zone/\n";
			cout << "Le chemin du dossier doit etre absolu et se terminer par '/' : ";
			cin >> cheminDossier;


			//C:/Users/Jean/Documents/zone/
			if (cheminDossier == "1") {
				// Debug shortcut pour Vincent
				cheminDossier = "C:/Users/Forti/Desktop/Polymtl/LOG2810/TP2_2810/zone/";
			}
			if (cheminDossier == "1337") {
				cheminDossier = "C:/Users/youca/Google Drive/Poly/Automne 2016/LOG2810/TP1/Project2/TP2_2810/zone/";
			}
			if (cheminDossier == "2") {
				cheminDossier = "C:/Users/Vincent/Desktop/LOG2810/TP2_2810/zone/";
			}			
			cout << endl;
			
			// Converti la string d'entree en char[] pour etre utilise par opendir()
			for (int i = 0; i < cheminDossier.length() + 1; i++)
			{
				cheminChar[i] = cheminDossier[i];
			}
			
			testZones =  creerLexiques(cheminChar);
			optionA = true;
			break;

		case 'b' :
			if (optionA) {
				int numClients = 0;
				int numVehicules = 0;

				cout << "Nombre de clients desire : ";
				cin >> numClients;
				cout << endl;
				for (int i = 0; i < numClients; i++) {
					Utilisateur *utilisateur = new Utilisateur;

					do {
						cout << "Point de depart du client #" << i + 1 << " : ";
						cin >> origine;

						// Test pour point valide avec bool pointValide
						pointValide = zoneValide(origine, testZones);

						if (pointValide) {
							cout << "Origine Valide!" << endl;
							utilisateur->setOrigine(origine);
						}

						else {
							cout << "Origine invalide. Veuillez reessayer." << endl;
						}
					} while (!pointValide);
						
					pointValide = false;
					do {
						cout << "Destination du client #" << i + 1 << " : ";
						cin >> destination;
						
						// Test pour point valide avec bool pointValide
						pointValide = zoneValide(destination, testZones);

						if (pointValide) {
							cout << "Destination Valide!" << endl;
							utilisateur->setDestination(destination);
						}
						else {
							cout << "Destination invalide. Veuillez reessayer." << endl;
						}
					} while (!pointValide);

					cout << "Numero de groupe du client #" << i + 1 << " : ";
					cin >> numGroupe;
					utilisateur->setNumGroupe(numGroupe);
					cout << endl;

					utilisateurs.push_back(utilisateur);
				}

				cout << "Nombre de vehicules desire (au moins deux vehicules) : ";
				do {
					cin >> numVehicules;
				} while (numVehicules <= 1);

				cout << endl;
				for (int i = 0; i < numVehicules; i++) {
					Vehicule *vehicule = new Vehicule();
					zoneDepart = "";
					cout << "Voici les zones existantes :\n";
					for (int j = 0; j < testZones.size(); j++) {
						cout << testZones[j]->getNom() << " ";
					}
					cout << "\n\nZone de depart du vehicule  #" << i + 1 << " : ";						
					cin >> zoneDepart;
					cout << endl;
					bool zoneExiste = false;

					for (int j = 0; j < testZones.size(); j++) {
						if (zoneDepart == testZones[j]->getNom())
							zoneExiste = true;
					}
					if (zoneExiste) {
						vehicule->setZoneActuelle(zoneDepart);
						vehicules.push_back(vehicule);
						cout << "Entree valide! Il vous reste " << numVehicules - i - 1 << " zones a fournir \n\n";
					}
					else {
						cout << "Le vehicule " << i+1 <<  " ne peux pas exister car le nom de zone est invalide.\n\n";
						cout << "Passez au vehicule " << numVehicules++ << " et reessayer.";
					}
				}

				optionB = true;
			} else {
				cout << "Erreur, veuillez d'abord creer les zones! \n";
			}
			break;

		case 'c' :
			if (optionB) {
				lancerSimulation(testZones, vehicules, utilisateurs);
				optionB = false;
				vector<Zone*> x;
				libererRessources(x, utilisateurs, vehicules);
			}
			else {
				cout << "Erreur, veuillez d'abord entrer les clients et les vehicules! \n";
			}
			break;

		case 'd' :
			exit = true;
			break;		
		}

	} while (!exit);

	
	libererRessources(testZones, utilisateurs, vehicules);
	return 0;
}

// Affiche le menu
void afficherMenu() {
	cout << "===================================================================\n";
	cout << "| (a) Creer les zones.                                            |\n";     
	cout << "| (b) Entrer les clients et les vehicules.                        |\n";
	cout << "| (c) Demarrer la simulation.                                     |\n";                             
	cout << "| (d) Quitter.                                                    |\n"; 
	cout << "===================================================================\n \n";
}

// Lance la simulation
void lancerSimulation(vector<Zone*>& zones, vector<Vehicule*>& vehicules, vector<Utilisateur*>& utilisateurs)
{
	//assigner les véhicules aux zones
	for (Zone* zone : zones)
		for (Vehicule* vehicule : vehicules)
			if (zone->getNom() == vehicule->getZoneActuelle())
				zone->ajouterVehicule(vehicule);

	assignerPositions(zones);
	afficherNombreDeVehicules(zones, "Emplacement des vehicules pre-simulation");

	//former des groupes pour les utilisateurs
	vector<vector<Utilisateur*>> groupes;
	for (int i = 0; i < utilisateurs.size(); i++){
		vector<Utilisateur*> utils;
		utils.push_back(utilisateurs[i]);
		
		for (int j = i + 1; j < utilisateurs.size(); j++)
			if (utilisateurs[i]->getNumGroupe() == utilisateurs[j]->getNumGroupe())
			{
				utils.push_back(utilisateurs[j]);
				auto it = remove(utilisateurs.begin(), utilisateurs.end(),utilisateurs[j]);
				utilisateurs.erase(it, utilisateurs.end());
			}
		utilisateurs.erase(remove(utilisateurs.begin(), utilisateurs.end(), utilisateurs[i]), utilisateurs.end());
		if (utils.size() > 1)
			i = -1;
		groupes.push_back(utils);
	}

	//Faire les courses par groupe
	for(auto groupe : groupes)
	{
		for (auto client : groupe)
		{

			//trouevr la zone du client pour pouvoir lui envoyer un
			//vehicule
			Zone* zoneDuClient = trouverZone(zones, client);
			if (zoneDuClient != nullptr)
			{
				Vehicule* vehiculeAEnvoyer = zoneDuClient->envoyerVehicule();
				while (vehiculeAEnvoyer == nullptr)
				{
					//equilibrer la flott au cas où le client n'a pas
					//de voiture à proximité
					equilibrerFlotte(zones);
					vehiculeAEnvoyer = zoneDuClient->envoyerVehicule();
				}

				//le vehicule est maintenant envoyé et il faut modifier
				//sa zone et sa position
				vehiculeAEnvoyer->setOccupation(true);
				for (auto zone : zones) {
					if (zone->reconLangage(vehiculeAEnvoyer->getPositionActuelle()))
						zone->retirerVehicule(vehiculeAEnvoyer);
					if (zone->reconLangage(client->getDestination()))
						zone->ajouterVehicule(vehiculeAEnvoyer);
				}
				vehiculeAEnvoyer->setPositionActuelle(client->getDestination());
				vehiculeAEnvoyer->setNombreDeTrajetsPleins(vehiculeAEnvoyer->getNombreDeTrajetsPleins() + 1);

			}
		}
		libererVehicules(vehicules);
	}
	afficherNombreDeVehicules(zones, "Emplacement des vehicules post-simulation");
	cout << endl;
	afficherTrajetsVehicules(vehicules);
	for (auto zone : zones)
		while (zone->getNombreVehicules() != 0)
			zone->retirerVehicule(zone->getVehicules()[0]);
}

void afficherNombreDeVehicules(const vector<Zone*> & zones, const string& titreTableau)
{
	cout << "================="<<titreTableau<<"================\n";
	cout << "Nombre de vehicules par zone au debut et a la fin de la simulation\n\n";
	
	for (auto zone : zones) {
		cout << "Zone: " << "\t" << zone->getNom() << "\t" << "Nombre de vehicules: " << zone->getNombreVehicules() << endl;
	}
}

void afficherTrajetsVehicules(const vector<Vehicule*> & vehicules) {
	int i = 1;
	for (auto vehicule : vehicules) {
		cout << "Vehicule #" << i++ << ": " << endl;
		cout << "Trajets occupes: " << vehicule->getNombreDeTrajetsPleins() << endl;
		cout << "Trajets vides: " << vehicule->getNombreDeTrajetsVides() << endl << endl;
	}
}

// Lit tout les fichiers dans le dossier dont le chemin est donne en parametres
vector<Zone*> creerLexiques(char cheminChar[255])
{

	vector<string> fichiers;
	vector<Zone*> zones;
	ifstream file;
	DIR *dossier;
	struct dirent *entree;
	if ((dossier = opendir(cheminChar)) != NULL) {
		int i = 1;
		// Imprime tout les fichiers dans le dossier
		while ((entree = readdir(dossier)) != NULL) {

			string nomFichier = entree->d_name;
			if (nomFichier.length() > 4 && nomFichier.substr(nomFichier.length() - 4) == ".txt")
			{
				fichiers.push_back(nomFichier);
				cout << "Dans le fichier " << nomFichier << " il y a ";
				file.open(cheminChar + nomFichier);
				string premiereMoitie;
				string deuxiemeMoitie;
				Zone* zoneX = new Zone();

				cout << "la Zone" << i << " qui contient les quartiers : " << endl;
				
				Automate* automate = new Automate();
				while (!file.eof()) {
					file >> premiereMoitie;
					file >> deuxiemeMoitie;
					cout << premiereMoitie + deuxiemeMoitie << " ";
					
					string quartier = premiereMoitie + deuxiemeMoitie;
					zoneX->ajouterQuartier(quartier);
					string arcAutomate = "";
					for (int j = 0; j < quartier.size(); j++)
					{
						//Pour chaque addresse dans la zone
						//modifier l'automate pour ajouter de nouvelles possibilites
						//si cela n'a pas ete encore pris en compte
						arcAutomate = quartier.substr(0, j + 1);
						
						if (automate->trouverEtat(arcAutomate) == nullptr && automate->getDepart() != nullptr)
						{
							Etat * dernierePlace = automate->trouverDernierEtatCommun(arcAutomate);
							if (dernierePlace != nullptr)
							{
								dernierePlace->setFinalite(false);
								Etat *nouveau = new Etat(arcAutomate, {}, true);
								dernierePlace->ajouterSuivants(nouveau);
							}
						}
						else if(automate->getDepart() == nullptr)
						{
							automate->setDepart(new Etat(arcAutomate, {}, true));
							automate->setCourant(automate->getDepart());
						}
					}
					

				}
				zoneX->setAutomate(automate);
				zones.push_back(zoneX);
				cout << endl;
				zoneX->setNom("Zone" + to_string(i++));
				cout << endl;
				file.close();

				
			}
		}
		closedir(dossier);
	}
	else {
		// Le dossier n'a pas pu etre ouvert
		perror("");
	}
	return zones;
}

// Equilibre la flotte
void equilibrerFlotte(vector<Zone*>& zones)
{
	assignerZones(zones);
	assignerPositions(zones);	
}

// Assigne les vehicules a des zones
void assignerZones(vector<Zone*>& zones) {
	vector<Zone*> zonesVides;

	// On commence par mettre les zones en ordre pour pouvoir
	// ajouter des vehicules aux zones qui en ont le moins
	sort(zones.begin(), zones.end(),ordonnerVehiculesZone);

	// Si les zones sont vides ont les ajoute a un vecteur qui leur est dediee
	for (int i = 0; i < zones.size(); i++)
		if (zones[i]->getNombreVehicules() == 0)
			zonesVides.push_back(zones[i]);

	vector<Zone*> temp = zones;
	// Puis ont assigne les vehicules
	for (Zone * zone : zonesVides) {
		size_t maxVehicule = temp.size() - 1;
		if (temp[maxVehicule]->getNombreVehicules() > 0) {
			//assigner un vehicule venant de la zone ayant le plus grand nombre
			//de vehicules
			auto vehicule = temp[maxVehicule]->getVehicules()[0];
			temp[maxVehicule]->retirerVehicule(vehicule);

			vehicule->setNombreDeTrajetsVides(vehicule->getNombreDeTrajetsVides() + 1);
			vehicule->setPositionActuelle("");
			vehicule->setZoneActuelle(zone->getNom());
			zone->ajouterVehicule(vehicule);
			
			auto it = remove(temp.begin(), temp.end(), zone);
			temp.erase(it, temp.end());
		}
		sort(temp.begin(), temp.end(), ordonnerVehiculesZone);
	}
}

// On assigne des positions alleatoires aux vehicules ajoutes aux zones
void assignerPositions(vector<Zone*>& zones) {
	for (Zone* zone : zones)
		for (Vehicule* vehicule : zone->getVehicules())
			if (vehicule->getPositionActuelle().empty())
				vehicule->setPositionActuelle(zone->getQuartiers()[rand() % zone->nQuartiers()]);
}

// On libere les vehicules en mettant le booleen estOccupe a faux
void libererVehicules(vector<Vehicule*>& vehicules)
{
	for (auto vehicule : vehicules)
		if (vehicule->estOccupe())
			vehicule->setOccupation(false);
}

bool ordonnerVehiculesZone(Zone* zone1, Zone* zone2)
{
	return zone1->getNombreVehicules() < zone2->getNombreVehicules();
}

// Permet de trouver les zones
Zone* trouverZone(const vector<Zone*>& zones, Utilisateur* util)
{
	for (auto zone : zones)
		if (zone->reconLangage(util->getOrigine()))
			return zone;
	return  nullptr;
}

void libererRessources(vector<Zone*>& testZones, vector<Utilisateur*>& utilisateurs, vector<Vehicule*>& vehicules)
{

	while(!vehicules.empty())
	{
		delete vehicules.back();
		vehicules.pop_back();
	}

	while(!utilisateurs.empty())
	{
		delete utilisateurs.back();
		utilisateurs.pop_back();
	}

	while(!testZones.empty())
	{
		delete testZones.back();
		testZones.pop_back();
	}
}

// Permet de verifier qu'un quartier entre en parametre est valide
bool zoneValide(const string & origine, const vector<Zone*> & testZones)
{
	for (auto zone : testZones)
		if (zone->reconLangage(origine))
			return true;
	return false;
}