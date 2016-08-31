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

void Losfahren::vBearbeiten()
{
	p_pWeg->vAbgabe(p_pFahrzeug); // Parkendes Fahrzeug entfernen
	p_pWeg->vAnnahme(p_pFahrzeug); // Fahrend hinzufügen...
	p_pFahrzeug->vNeueStrecke(p_pWeg); // ... und das Verhalten (FzgFahrend) entsprechend setzen
	cout << endl << "***EXCEPTION LOSFAHREN****" << endl << p_pFahrzeug->getName() << " faehrt ab um " << dGlobaleZeit << " auf Weg " << p_pWeg->getName() << endl << "*******************" << endl;
}
