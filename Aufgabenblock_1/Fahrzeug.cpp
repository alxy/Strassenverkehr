#include "Fahrzeug.h"

int Fahrzeug::p_iMaxID = 0;

/*
 * Initialisierung der Variablen mit Standardwerten
 */
void Fahrzeug::vInitialisierung()
{
	p_iID = ++p_iMaxID;
	p_sName = "";
	p_dGesamtStrecke = 0;
	p_dGesamtZeit = 0;
	p_dMaxGeschwindigkeit = 0;
	p_dZeit = 0;
}

/*
 * Standard Konstruktor
 */
Fahrzeug::Fahrzeug()
{
	vInitialisierung();

	//cout << "Fahrzeug " << p_sName << " mit der ID " << p_iID << " erstellt!" << endl;
}


/*
 * Konstruktor
 */
Fahrzeug::Fahrzeug(string name)
{
	vInitialisierung();

	p_sName = name;

	//cout << "Fahrzeug " << p_sName << " mit der ID " << p_iID << " erstellt!" << endl;
}

/*
 * Konstruktor
 */
Fahrzeug::Fahrzeug(string name, double maxGeschwindigkeit)
{
	vInitialisierung();

	p_sName = name;
	p_dMaxGeschwindigkeit = maxGeschwindigkeit;
}

/*
 * Copy-Konstruktor
 */
Fahrzeug::Fahrzeug(const Fahrzeug & fahrzeug)
{
	// Werte zurücksetzen
	vInitialisierung();

	// Name und MaxGeschwindigkeit übernehmen
	p_sName = fahrzeug.p_sName;
	p_dMaxGeschwindigkeit = fahrzeug.p_dMaxGeschwindigkeit;
}

/*
 * Ausgabe der Fahrzeuginformationen 
 */
void Fahrzeug::vAusgabe()
{
	cout.setf(ios::left);
	cout << setw(4) << p_iID << setw(7) << p_sName << setw(3) << ":" << setw(9) << setiosflags(ios::fixed) << setprecision(2) << p_dMaxGeschwindigkeit << setw(19) << p_dGesamtStrecke << setw(19) << dGeschwindigkeit();

}

/*
 * Abfertigung des Fahrzeugs (Berechnung der Strecke, der Fahrtzeit und Setzen des letzten Abfertigungszeitpunkts)
 */
void Fahrzeug::vAbfertigung()
{
	if (dGlobaleZeit > p_dZeit) {
		double dFahrtZeit = dGlobaleZeit - p_dZeit;
		p_dGesamtStrecke += dFahrtZeit * dGeschwindigkeit();
		p_dGesamtZeit += dFahrtZeit;
		p_dZeit = dGlobaleZeit;
	}
}

/*
 * Dummy-Funktion zum Tanken (sollte in Kindklassen überschrieben werden)
 * Fahrzeuge ohne Tank können nicht betankt werden...
 */
double Fahrzeug::dTanken(double menge)
{
	return 0.0;
}

/*
 * Rückgabe der Geschwindkeit
 */
double Fahrzeug::dGeschwindigkeit()
{
	return p_dMaxGeschwindigkeit;
}

/*
 * Destruktor
 */
Fahrzeug::~Fahrzeug()
{
	//cout << "Fahrzeug " << p_sName << " mit der ID " << p_iID << " geloescht!" << endl;
}

/*
 * Ausgabefunktion die direkt auf dem Ausgabe-Stream arbeitet
 */
ostream & Fahrzeug::ostreamAusgabe(ostream & out)
{
	out.setf(ios::left);
	out << setw(4) << p_iID << setw(7) << p_sName << setw(3) << ":" << setw(9) << setiosflags(ios::fixed) << setprecision(2) << p_dMaxGeschwindigkeit << setw(19) << p_dGesamtStrecke << setw(19) << dGeschwindigkeit();
	return out;
}

/*
 * Überladung des Kleiner-Operators (<)
 */
bool Fahrzeug::operator<(const Fahrzeug & fahrzeug)
{
	return p_dGesamtStrecke < fahrzeug.p_dGesamtStrecke;
}

/*
 * Überladung des Ausgabe-Operators (<<)
 */
ostream& operator <<(ostream& out, Fahrzeug& fahrzeug)
{
	return fahrzeug.ostreamAusgabe(out);
}
