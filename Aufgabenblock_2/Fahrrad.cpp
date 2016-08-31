#include "Fahrrad.h"
#include "Weg.h"
#include "SimuClient.h"


/*
 * Standard Konstruktor
 */
Fahrrad::Fahrrad()
{
}

/*
 * Konstruktor (mit Initialisierungsliste)
 */
Fahrrad::Fahrrad(string name, double maxGeschwindigkeit)
	: Fahrzeug::Fahrzeug(name, maxGeschwindigkeit)
{
}

/*
 * Destruktor
 */
Fahrrad::~Fahrrad()
{
}

/*
 * Überschrieben Methode: Fahrräder dahren mit zunehmender Gesamtstrecke langsamer, aber mindestens 12 Km/h
 */
double Fahrrad::dGeschwindigkeit()
{
	double dAktGeschwindigkeit = p_dMaxGeschwindigkeit * pow(0.9, p_dGesamtStrecke / 20);

	return dAktGeschwindigkeit < 12 ? 12 : dAktGeschwindigkeit;
}

/*
 * Überschrieben Methode: Könnte weitere, Fahrrad spezifische Daten ausgeben. Hier allerdings nur für einen Zeilenumbruch genutzt.
 */
void Fahrrad::vAusgabe()
{
	Fahrzeug::vAusgabe();
	cout << endl;
}

/*
 * Ausgabefunktion die direkt auf dem Ausgabe-Stream arbeitet
 */
ostream & Fahrrad::ostreamAusgabe(ostream & out)
{
	Fahrzeug::ostreamAusgabe(out);
	out << endl;

	return out;
}

 /**
  * @description Grafische Ausgabe des Fahrrads 
  *
  * @access public 
  * @param Weg * weg
  * @return void
  */
 void Fahrrad::vZeichnen(Weg * weg)
 {
	 bZeichneFahrrad(p_sName, weg->getName(), p_dAbschnittStrecke / weg->getLaenge(), dGeschwindigkeit());
 }
