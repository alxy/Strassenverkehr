#include "Fahrzeug.h"
#include "Weg.h"
#include "FzgFahren.h"
#include "FzgParken.h"

/*
 * Initialisierung der Variablen mit Standardwerten
 */
void Fahrzeug::vInitialisierung()
{
	p_dGesamtStrecke = 0;
	p_dGesamtZeit = 0;
	p_dMaxGeschwindigkeit = 0;
	p_dAbschnittStrecke = 0;
	p_pVerhalten = 0;
}

/*
 * Standard Konstruktor
 */
Fahrzeug::Fahrzeug()
	: AktivesVO()
{
	vInitialisierung();
}


/*
 * Konstruktor
 */
Fahrzeug::Fahrzeug(string name)
	: AktivesVO(name)
{
	vInitialisierung();
}

/*
 * Konstruktor
 */
Fahrzeug::Fahrzeug(string name, double maxGeschwindigkeit)
	: AktivesVO(name)
{
	vInitialisierung();

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
		double dFahrtStrecke = p_pVerhalten->dStrecke(this, dFahrtZeit);

		p_dGesamtStrecke += dFahrtStrecke;
		p_dAbschnittStrecke += dFahrtStrecke;
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
	AktivesVO::ostreamAusgabe(out);
	out.setf(ios::left);
	out << setw(3) << ":" << setw(9) << setiosflags(ios::fixed) << setprecision(2) << p_dMaxGeschwindigkeit << setw(19) << p_dGesamtStrecke << setw(19) << dGeschwindigkeit() << setw(15) << p_dAbschnittStrecke;
	return out;
}

/*
 * Überladung des Kleiner-Operators (<)
 */
bool Fahrzeug::operator<(const Fahrzeug & fahrzeug)
{
	return p_dGesamtStrecke < fahrzeug.p_dGesamtStrecke;
}


/**
 * @description Getter für AbschnittStrecke
 *
 * @access public 
 * @return double
 */
double Fahrzeug::getAbschnittStrecke() const
{
	return p_dAbschnittStrecke;
}


/**
 * @description Fahrzeug "fahrend" auf dem Weg platzieren und Verhalten initialisieren
 *
 * @access public 
 * @param Weg * weg
 * @return void
 */
void Fahrzeug::vNeueStrecke(Weg * weg)
{
	delete p_pVerhalten; // Mögliche alte Instanz löschen (Speicherloch verhindern)
	p_pVerhalten = new FzgFahren(weg);
}

/**
 * @description Fahrzeug "parkend" auf dem Weg platzieren und Verhalten initialsieren
 *
 * @access public 
 * @param Weg * weg
 * @param double startzeit Zeitpunkt, an dem das Fahrzeug losfahren soll
 * @return void
 */
void Fahrzeug::vNeueStrecke(Weg * weg, double startzeit)
{
	delete p_pVerhalten; // Mögliche alte Instanz löschen (Speicherloch verhindern)
	p_pVerhalten = new FzgParken(weg, startzeit);
}

/**
 * @description Getter für Name
 *
 * @access public 
 * @return std::string
 */
string Fahrzeug::getName() const
{
	return p_sName;
}
