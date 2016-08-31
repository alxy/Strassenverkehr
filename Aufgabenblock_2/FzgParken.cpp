#include "FzgParken.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Losfahren.h"


FzgParken::FzgParken()
{
}

FzgParken::FzgParken(Weg * weg, double startzeit)
	: FzgVerhalten(weg), p_dStartzeit(startzeit)
{
}


FzgParken::~FzgParken()
{
}

/**
 * @description Streckenfunktion eines parkenden Fahrzeugs. Im Normalfall 0; Zum Startzeitpunkt wird "Losfahren" geworfen
 *
 * @access public 
 * @param Fahrzeug * fahrzeug
 * @param double zeitraum Hier nicht benötigt
 * @return double
 */
double FzgParken::dStrecke(Fahrzeug * fahrzeug, double zeitraum)
{
	if(dGlobaleZeit < p_dStartzeit)
		return 0.0;

	throw Losfahren(fahrzeug, p_pWeg);
}
