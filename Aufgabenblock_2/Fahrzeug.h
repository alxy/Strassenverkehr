#pragma once

#include<string>
#include<iostream>
#include<iomanip>

#include "AktivesVO.h"

class Weg;
class FzgVerhalten;

using namespace std;

extern double dGlobaleZeit; // Zugirff auf globale Variable ermöglichen

class Fahrzeug :
	public AktivesVO
{
protected:
	
	double p_dMaxGeschwindigkeit; // Maximale Geschwindkeit (in Km/h)
	double p_dGesamtStrecke; // Gesamte gefahrene Strecke
	double p_dGesamtZeit; // Gesamte Fahrtzeit
	double p_dAbschnittStrecke; // Auf aktuellem Weg zurückgelegte Strecke

	FzgVerhalten* p_pVerhalten;

	void vInitialisierung();
public:
	Fahrzeug();
	Fahrzeug(string name);
	Fahrzeug(string name, double maxGeschwindigkeit);
	Fahrzeug(const Fahrzeug& fahrzeug);
	virtual void vAusgabe();
	virtual void vAbfertigung();
	virtual double dTanken(double menge = -1);
	virtual double dGeschwindigkeit();
	virtual ~Fahrzeug();
	virtual ostream& ostreamAusgabe(ostream& out);
	bool operator<(const Fahrzeug& fahrzeug);
	double getAbschnittStrecke() const;
	void vNeueStrecke(Weg* weg);
	void vNeueStrecke(Weg* weg, double startzeit);
	string getName() const;
	virtual void vZeichnen(Weg* weg) = 0;
};
