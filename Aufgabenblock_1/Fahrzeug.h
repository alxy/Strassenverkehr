#pragma once

#include<string>
#include<iostream>
#include<iomanip>

using namespace std;

extern double dGlobaleZeit; // Zugirff auf globale Variable ermöglichen

class Fahrzeug
{
protected:
	static int p_iMaxID; // Zähler für angelegte Fahrzeugobjekte (Counter)
	string p_sName; // Fahrzeugname
	int p_iID; // ID (eindeutig)
	double p_dMaxGeschwindigkeit; // Maximale Geschwindkeit (in Km/h)
	double p_dGesamtStrecke; // Gesamte gefahrene Strecke
	double p_dGesamtZeit; // Gesamte Fahrtzeit
	double p_dZeit; // Zeit, zu der das Fahrzeug zuletzt abgefertigt wurde

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
};
ostream& operator <<(ostream& out, Fahrzeug& fahrzeug);
