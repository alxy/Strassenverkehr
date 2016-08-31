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

double FzgFahren::dStrecke(Fahrzeug * fahrzeug, double zeitraum)
{
	double dFahrbareStrecke = fahrzeug->dGeschwindigkeit() * zeitraum;
	double dVirtuelleSchranke = p_pWeg->getVirtuelleSchranke();

	if (p_pWeg->getLaenge() == fahrzeug->getAbschnittStrecke()) // Fahrzeug am Ende des Weges
		throw Streckenende(fahrzeug, p_pWeg);

	if (dFahrbareStrecke == 0) { // Tank leer
		return 0.0;
	}

	if (fahrzeug->getAbschnittStrecke() + dFahrbareStrecke > dVirtuelleSchranke) // Fahrzeug würde vorherfahrendes Fahrzeug überholen
	{
		dFahrbareStrecke = dVirtuelleSchranke - fahrzeug->getAbschnittStrecke();
	}

	p_pWeg->setVirtuelleSchranke(fahrzeug->getAbschnittStrecke() + dFahrbareStrecke); // Virtuelle Schranke auf Position des Autos setzen

	return (p_pWeg->getLaenge() < fahrzeug->getAbschnittStrecke() + dFahrbareStrecke) // Fahrzeug würde weiter als fahren als der Weg lang ist
		? p_pWeg->getLaenge() - fahrzeug->getAbschnittStrecke()
		: dFahrbareStrecke;
}
