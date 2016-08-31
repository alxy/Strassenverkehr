#include "FzgFahren.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Streckenende.h"



FzgFahren::FzgFahren()
{
}

FzgFahren::FzgFahren(Weg * weg)
	: FzgVerhalten(weg)
{
}


FzgFahren::~FzgFahren()
{
}

/**
 * @description Berechnet die von @fahrzeug in @zeitraum fahrbare Strecke unter Berücksichtigung der Weglänge
 *
 * @access public 
 * @param Fahrzeug * fahrzeug
 * @param double zeitraum Fahrtzeit
 * @return double Strecke
 */
double FzgFahren::dStrecke(Fahrzeug * fahrzeug, double zeitraum)
{
	double dFahrbareStrecke = fahrzeug->dGeschwindigkeit() * zeitraum; // Theoretisch fahrbare Strecke

	if (p_pWeg->getLaenge() == fahrzeug->getAbschnittStrecke()) // Fahrzeug am Ende des Weges
		throw Streckenende(fahrzeug, p_pWeg);

	return (p_pWeg->getLaenge() < fahrzeug->getAbschnittStrecke() + dFahrbareStrecke) // Fahrzeug würde weiter als fahren als der Weg lang ist
		? p_pWeg->getLaenge() - fahrzeug->getAbschnittStrecke()
		: dFahrbareStrecke;
}
