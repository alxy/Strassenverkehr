#include "Weg.h"
#include "Fahrzeug.h"
#include "FahrAusnahme.h"



Weg::Weg()
	: AktivesVO()
{
}

/**
 * @description Konstruktor
 *
 * @access public 
 * @param string name Name des Wegs
 * @param double laenge Länge des Wegs (in KM)
 * @param Begrenzung limit Geschwindigkeitsbegrenzung (innerorts, lanfstrasse, autobahn)
 * @return 
 */
Weg::Weg(string name, double laenge, Begrenzung limit)
	: AktivesVO(name), p_dLaenge(laenge), p_eLimit(limit)
{
}



Weg::~Weg()
{
}

/**
 * @description Abfertigung der Fahrzeuge auf dem Weg
 *
 * @access public 
 * @return void
 */
void Weg::vAbfertigung()
{
	// LazyListe aktualisieren
	p_pFahrzeuge.vAktualisieren();

	for (fzgList::iterator it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++)
	{
		try {
			(*it)->vAbfertigung();
		}
		catch (FahrAusnahme& fahrAusnahme) // Evtl. Ausnahmen fangen und bearbeiten
		{
			fahrAusnahme.vBearbeiten();
		}
	}


}

/**
 * @description Überladene Ausgabefunktion
 *
 * @access public 
 * @param ostream & out
 * @return ostream &
 */
ostream & Weg::ostreamAusgabe(ostream & out)
{
	AktivesVO::ostreamAusgabe(out);

	out << setw(10) << setiosflags(ios::fixed) << setprecision(2) << p_dLaenge << " ( ";
	for (fzgList::iterator it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++)
	{
		out << (*it)->getName();
		out << " ";
	}
	out << ") " << endl;

	return out;
}

/**
 * @description Getter für Länge
 *
 * @access public 
 * @return double
 */
double Weg::getLaenge() const
{
	return p_dLaenge;
}

/**
 * @description Platziert ein neues Fahrzeug fahrend, hinten auf dem Weg (in der Liste)
 *
 * @access public 
 * @param Fahrzeug * fahrzeug
 * @return void
 */
void Weg::vAnnahme(Fahrzeug * fahrzeug)
{
	fahrzeug->vNeueStrecke(this);
	p_pFahrzeuge.push_back(fahrzeug);
}

/**
 * @description Platziert ein neues Fahrzeug parkend, vorne auf dem Weg (in der Liste)
 *
 * @access public 
 * @param Fahrzeug * fahrzeug
 * @param double startzeit
 * @return void
 */
void Weg::vAnnahme(Fahrzeug * fahrzeug, double startzeit)
{
	fahrzeug->vNeueStrecke(this, startzeit);
	p_pFahrzeuge.push_front(fahrzeug);
}

/**
 * @description Getter für die Geschwindigkeitsbegrenzung
 *
 * @access public 
 * @return Begrenzung
 */
Begrenzung Weg::getLimit() const
{
	return p_eLimit;
}

/**
 * @description Getter für Name
 *
 * @access public 
 * @return std::string
 */
string Weg::getName()
{
	return p_sName;
}

/**
 * @description Entfernt ein Fahrzeug von dem Weg (aus der Liste)
 *
 * @access public 
 * @param Fahrzeug * fahrzeug
 * @return void
 */
void Weg::vAbgabe(Fahrzeug * fahrzeug)
{
	for (fzgList::iterator it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++)
	{
		if (*it == fahrzeug) {
			p_pFahrzeuge.erase(it);
		}
	}
}
