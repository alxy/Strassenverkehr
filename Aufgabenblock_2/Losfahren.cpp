#include "Losfahren.h"
#include "Fahrzeug.h"
#include "Weg.h"



Losfahren::Losfahren()
{
}

Losfahren::Losfahren(Fahrzeug * fahrzeug, Weg * weg)
	: FahrAusnahme(fahrzeug, weg)
{
}


Losfahren::~Losfahren()
{
}

/**
 * @description Bearbeiten der Losfahren-Exception
 *
 * @access public 
 * @return void
 */
void Losfahren::vBearbeiten()
{
	p_pWeg->vAbgabe(p_pFahrzeug); // Von Weg entfernen
	p_pWeg->vAnnahme(p_pFahrzeug); // "Hinten" auf den Weg stellen
	p_pFahrzeug->vNeueStrecke(p_pWeg); // Fahrzeug "losfahren" lassen
	cout << endl << "***EXCEPTION LOSFAHREN****" << endl << *p_pFahrzeug << *p_pWeg << "*******************" << endl;
}
