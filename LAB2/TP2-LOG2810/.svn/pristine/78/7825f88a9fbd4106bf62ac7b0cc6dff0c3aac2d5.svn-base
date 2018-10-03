//==============================================================================
// Nom         : Vehicule.h
// Auteurs     : Vincent Fortin & Dominique Piche & Ibrahima Sega Jr Sangare
// Date        : 16 novembre 2016
// Description : Description de la classe Vehicule
//==============================================================================

#ifndef VEHICULE_H
#define VEHICULE_H

#include <iostream>
#include <vector>
#include "Zone.h"


using namespace std;
class Zone;
 
class Vehicule
{
public:
	// Constructeur par defaut
	Vehicule();
	Vehicule(const string& zoneActuelle, const string& positionActuelle, bool occupation);

	// Destructeur
	~Vehicule();

	// Setters
	void setZoneActuelle(const string& zoneActuelle);
	void setPositionActuelle(const string& positionActuelle);
	void setOccupation(bool occupation);
	void setNombreDeTrajetsPleins(int n);
	void setNombreDeTrajetsVides(int n);

	// Getters
	bool estOccupe() const;
	int getNombreDeTrajetsPleins() const;
	int getNombreDeTrajetsVides() const;
	string getZoneActuelle() const;
	string getPositionActuelle() const;


private:	
	string zoneActuelle_;
	string positionActuelle_;
	bool occupation_;
	int nTrajetsPleins_;
	int nTrajetVides_;
};

#endif // !VEHICULE_H