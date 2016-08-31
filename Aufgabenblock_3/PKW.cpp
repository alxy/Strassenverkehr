#include "PKW.h"
#include "FzgVerhalten.h"
#include "Weg.h"
#include "SimuClient.h"



/*
 * Standard Kostruktor
 */
PKW::PKW()
{
}

/*
 * Kostruktor
 */
PKW::PKW(string name, double maxGeschwindigkeit, double verbrauch, double tankvolumen)
	: Fahrzeug(name, maxGeschwindigkeit), p_dVerbrauch(verbrauch), p_dTankvolumen(tankvolumen), p_dTankinhalt(tankvolumen / 2)
{

}

/*
* Copy-Konstruktor
*/
PKW::PKW(const PKW & pkw)
	: Fahrzeug(pkw)
{
	// Verbrauch, Tankvolumen übernehmen / Inhalt initialisieren
	p_dVerbrauch = pkw.p_dVerbrauch;
	p_dTankvolumen = pkw.p_dTankvolumen;
	p_dTankinhalt = p_dTankvolumen / 2;
}

/*
 * Destruktor
 */
PKW::~PKW()
{
}

/*
 * Berechnung des Gesamtverbrauchs (in Litern)
 */
double PKW::dVerbrauch()
{
	return p_dGesamtStrecke / 100 * p_dVerbrauch;
}

/*
 * Überschrieben Methode: Implementiert Tankvorgang des Autos und gibt die getankte Menge zurück
 */
double PKW::dTanken(double menge)
{
	double getankteMenge = 0;
	if (menge < 0) {
		getankteMenge = p_dTankvolumen - p_dTankinhalt;
	}
	else {
		getankteMenge = (p_dTankinhalt + menge) > p_dTankvolumen ? p_dTankvolumen - p_dTankinhalt : menge;
	}

	p_dTankinhalt += getankteMenge;
	return getankteMenge;
}

/*
 * Überschrieben Methode: Implementiert Abfertigung des PKW, aktualisiert Tankinhalt
 */
void PKW::vAbfertigung()
{
	if (p_dTankinhalt > 0) {
		double gesamtStreckeAlt = p_dGesamtStrecke;
		Fahrzeug::vAbfertigung();
		double gefahreneStrecke = p_dGesamtStrecke - gesamtStreckeAlt;
		double verbrauch = gefahreneStrecke / 100 * p_dVerbrauch;

		p_dTankinhalt = (p_dTankinhalt - verbrauch < 0) ? 0 : p_dTankinhalt - verbrauch;
	}
	else {
		p_dZeit = dGlobaleZeit; // Zeit der Abfertigung setzen, falls PKW steht
	}
}

/*
 * Überschrieben Methode: Gibt weitere, PKW spezifische Daten aus
 */
void PKW::vAusgabe()
{
	Fahrzeug::vAusgabe();
	cout.setf(ios::left);
	cout << setiosflags(ios::fixed) << setprecision(2) << setw(15) << dVerbrauch() << setw(15) << p_dTankinhalt << endl;
}

/*
 * Überschrieben Methode: PKW fährt mit maximaler Geschwindigkeit
 */
double PKW::dGeschwindigkeit()
{
	if (p_dTankinhalt <= 0)
	{
		return 0.0;
	}

	double dLimit = p_pVerhalten->getWeg()->getLimit();
	return p_dMaxGeschwindigkeit > dLimit ? dLimit : p_dMaxGeschwindigkeit;
}

 double PKW::getTankinhalt()
 {
	 return p_dTankinhalt;
 }

/*
 * Ausgabefunktion die direkt auf dem Ausgabe-Stream arbeitet und weitere, PKW spezifische Daten ausgibt
 */
ostream & PKW::ostreamAusgabe(ostream & out)
{
	Fahrzeug::ostreamAusgabe(out);
	out.setf(ios::left);
	out << setiosflags(ios::fixed) << setprecision(2) << setw(15) << dVerbrauch() << setw(15) << p_dTankinhalt << endl;

	return out;
}

istream & PKW::istreamEingabe(istream & in)
{
	Fahrzeug::istreamEingabe(in);
	in >> p_dVerbrauch >> p_dTankvolumen;
	p_dTankinhalt = p_dTankvolumen / 2; // Tankinhalt initialisieren ( Halbes Tankvolumen )
	return in;
}

void PKW::vZeichnen(Weg * weg)
{
	bZeichnePKW(p_sName, weg->getName(), p_dAbschnittStrecke / weg->getLaenge(), dGeschwindigkeit(), p_dTankinhalt);
}
