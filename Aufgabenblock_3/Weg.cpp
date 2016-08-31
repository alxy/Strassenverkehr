#include "Weg.h"
#include "Fahrzeug.h"
#include "FahrAusnahme.h"
#include "Kreuzung.h"



Weg::Weg()
	: AktivesVO()
{
}

Weg::Weg(string name, double laenge, Begrenzung limit, bool ueberholverbot)
	: AktivesVO(name), p_dLaenge(laenge), p_eLimit(limit), p_bUeberholverbot(ueberholverbot), p_dVirtuelleSchranke(laenge)
{
}

Weg::Weg(string name, double laenge, Weg * rueckweg, Kreuzung * kreuzung, Begrenzung limit, bool ueberholverbot)
	: AktivesVO(name), p_dLaenge(laenge), p_pRueckweg(rueckweg), p_pKreuzung(kreuzung), p_eLimit(limit), p_bUeberholverbot(ueberholverbot), p_dVirtuelleSchranke(laenge)
{
}



Weg::~Weg()
{
}

void Weg::vAbfertigung()
{
	p_pFahrzeuge.vAktualisieren();

	for (fzgList::iterator it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++)
	{
		try {
			(*it)->vAbfertigung();
		}
		catch (FahrAusnahme& fahrAusnahme)
		{
			fahrAusnahme.vBearbeiten();
		}
	}

	p_dVirtuelleSchranke = p_dLaenge; // Virtuelle Schranke "resetten"


}

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

double Weg::getLaenge() const
{
	return p_dLaenge;
}

void Weg::vAnnahme(Fahrzeug * fahrzeug)
{
	fahrzeug->vNeueStrecke(this);
	p_pFahrzeuge.push_back(fahrzeug);
}

void Weg::vAnnahme(Fahrzeug * fahrzeug, double startzeit)
{
	fahrzeug->vNeueStrecke(this, startzeit);
	p_pFahrzeuge.push_front(fahrzeug);
}

Begrenzung Weg::getLimit() const
{
	return p_eLimit;
}

string Weg::getName()
{
	return p_sName;
}

void Weg::vAbgabe(Fahrzeug * fahrzeug)
{
	for (fzgList::iterator it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++)
	{
		if (*it == fahrzeug) {
			p_pFahrzeuge.erase(it);
		}
	}
}

void Weg::vZeichnen()
{
	p_pFahrzeuge.vAktualisieren();
	for (fzgList::iterator it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++)
	{
		(*it)->vZeichnen(this);
	}
}

double Weg::getVirtuelleSchranke() const
{
	return p_bUeberholverbot ? p_dVirtuelleSchranke : p_dLaenge;
}

void Weg::setVirtuelleSchranke(double schranke)
{
	p_dVirtuelleSchranke = schranke;
}

void Weg::setRueckweg(Weg * rueckweg)
{
	p_pRueckweg = rueckweg;
}

Kreuzung * Weg::getKreuzung() const
{
	return p_pKreuzung;
}

Weg * Weg::getRueckweg() const
{
	return p_pRueckweg;
}
