//==============================================================================
// Nom         : Etat.h
// Auteurs     : Vincent Fortin & Dominique Piche & Ibrahima Sega Jr Sangare
// Date        : 25 novembre 2016
// Description : Description de la classe Etat
//==============================================================================

#ifndef ETAT_H
#define ETAT_H

#include <string>
#include <vector>

using namespace std;

class Etat
{
public:
	// Constructeur par defaut
	Etat();

	// Constructeur par paramètres
	Etat(const string& identifiantEtat, vector<Etat*> suivant, bool estFinal);
	
	// Destructeur
	~Etat();

	// Getters
	string getIdentifiant() const;
	vector<Etat*> getSuivants() const;
	bool estFinal() const;
	
	// Setters
	void setIdentifiant(const string& identifiant);
	void setFinalite(bool estFinal);
	void setSuivants(const vector<Etat*> suivants);
	void ajouterSuivants(Etat* suivant);

private:
	std::string identifiantEtat_;
	vector<Etat*> suivants_;
	bool final_;

};

#endif // !ETAT_H
