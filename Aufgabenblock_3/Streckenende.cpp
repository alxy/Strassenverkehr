#include "Streckenende.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "SimuClient.h"
#include "Kreuzung.h"


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

void Streckenende::vBearbeiten()
{
	Weg* neuerWeg = p_pWeg->getKreuzung()->ptZufaelligerWeg(p_pWeg); // Zufälligen neuen Weg auswählen

	p_pWeg->vAbgabe(p_pFahrzeug); // Fahrzeug von altem Weg entfernen
	p_pWeg->getKreuzung()->vAnnahme(p_pFahrzeug, neuerWeg); // Fahrzeug auf neuen Weg/neue Kreuzung setzen
	p_pFahrzeug->setAbschnittStrecke(0.0); // Abschnitt Strecke resetten (Fahrzeug fährt auf neuer Strecke)
	bLoescheFahrzeug(p_pFahrzeug->getName()); // Fahrzeug löschen (von Grafikfenster)

	cout
		<< "ZEIT: " << dGlobaleZeit << endl
		<< "KREUZUNG: " << p_pWeg->getKreuzung()->getName() << " (" << p_pWeg->getKreuzung()->getTankinhalt() << " Liter)" << endl
		<< "WECHSEL: " << p_pWeg->getName() << " -> " << neuerWeg->getName() << endl
		<< "FAHRZEUG: " << *p_pFahrzeug << endl;

	//cout << endl << "***EXCEPTION STRECKENENDE****" << endl << p_pFahrzeug->getName() << " ist am Ende von " << p_pWeg->getName() << " angekommen." << endl << "*******************" << endl;
}
