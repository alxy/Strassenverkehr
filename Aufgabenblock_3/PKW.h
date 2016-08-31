#pragma once
#include "Fahrzeug.h"
class PKW :
	public Fahrzeug
{
public:
	PKW();
	PKW(string name, double maxGeschwindigkeit, double verbrauch, double tankvolumen = 55);
	PKW(const PKW& pkw);
	virtual ~PKW();
	double dVerbrauch();
	double dTanken(double menge = -1);
	void vAbfertigung();
	void vAusgabe();
	double dGeschwindigkeit();
	double getTankinhalt();
	ostream& ostreamAusgabe(ostream& out);
	istream& istreamEingabe(istream& in);
	void vZeichnen(Weg* weg);
private:
	double p_dVerbrauch; // Verbrauch auf 100 Km
	double p_dTankinhalt; // Tankinhalt in Litern
	double p_dTankvolumen; // Tankvolumen / 55 l, falls nicht anders initialisiert
};

