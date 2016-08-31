#include "Streckenende.h"
#include "Fahrzeug.h"
#include "Weg.h"


Streckenende::Streckenende()
{
}

Streckenende::Streckenende(Fahrzeug * fahrzeug, Weg * weg)
	: FahrAusnahme(fahrzeug, weg)
{
}


Streckenende::~Streckenende()
{
}

/**
 * @description Bearbeiten der Streckenende-Exception
 *
 * @access public 
 * @return void
 */
void Streckenende::vBearbeiten()
{
	p_pWeg->vAbgabe(p_pFahrzeug); // Fahrzeug von Liste entfernen
	cout << endl << "***EXCEPTION STRECKENENDE****" << endl << *p_pFahrzeug << *p_pWeg << "*******************" << endl;
}
