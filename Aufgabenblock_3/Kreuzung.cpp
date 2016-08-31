#include "Kreuzung.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include "FzgVerhalten.h"
#include "SimuClient.h"



Kreuzung::Kreuzung()
{
}

Kreuzung::Kreuzung(string name, double tankvolumen)
	: AktivesVO(name), p_dTankstelle(tankvolumen)
{
}


Kreuzung::~Kreuzung()
{
}

void Kreuzung::vVerbinde(string hinweg, string rueckweg, double laenge, Kreuzung * kreuzung, Begrenzung begrenzung, bool ueberholverbot)
{
	Weg* pHinweg = new Weg(hinweg, laenge, 0, kreuzung, begrenzung, ueberholverbot);
	Weg* pRueckweg = new Weg(rueckweg, laenge, pHinweg, this, begrenzung, ueberholverbot);
	pHinweg->setRueckweg(pRueckweg);

	p_pWege.push_back(pHinweg);
	kreuzung->p_pWege.push_back(pRueckweg);
}

void Kreuzung::vTanken(Fahrzeug * fahrzeug)
{
	if (p_dTankstelle > 0)
	{
		p_dTankstelle -= fahrzeug->dTanken();
	}
	else {
		p_dTankstelle = 0;
	}
}

void Kreuzung::vAnnahme(Fahrzeug * fahrzeug, double startzeit)
{
	if (startzeit == 0)
	{
		(*p_pWege.begin())->vAnnahme(fahrzeug); // Fahrzeug fährt sofort los/weiter
	} 
	else
	{
		(*p_pWege.begin())->vAnnahme(fahrzeug, startzeit); // Fahrzeug parkt zunächst am Anfang des Weges
	}
	vTanken(fahrzeug);
}

void Kreuzung::vAnnahme(Fahrzeug * fahrzeug, Weg * neuerWeg)
{
	neuerWeg->vAnnahme(fahrzeug);
	vTanken(fahrzeug);
}

void Kreuzung::vAbfertigung()
{
	for (wegList::iterator it = p_pWege.begin(); it != p_pWege.end(); it++)
	{
		(*it)->vAbfertigung();
	}
}

void Kreuzung::vZeichnen(int koordinaten[2]) const
{
	bZeichneKreuzung(koordinaten[0], koordinaten[1]);
}

void Kreuzung::vZeichnen()
{
	for (wegList::iterator it = p_pWege.begin(); it != p_pWege.end(); it++)
	{
		(*it)->vZeichnen();
	}
}

ostream & Kreuzung::ostreamAusgabe(ostream & out)
{
	out << "Kreuzung ";
	AktivesVO::ostreamAusgabe(out);
	out << " hat folgende Wege:" << endl;

	for (wegList::iterator it = p_pWege.begin(); it != p_pWege.end(); it++)
	{
		out << *(*it);
	}

	return out << endl;
}

istream & Kreuzung::istreamEingabe(istream & in)
{
	AktivesVO::istreamEingabe(in);
	in >> p_dTankstelle;
	return in;
}

Weg * Kreuzung::ptZufaelligerWeg(Weg * hinweg)
{
	Weg* zufaelligerWeg = 0;

	if (p_pWege.size() == 1)
	{
		return p_pWege.front();
	}

	do
	{
		zufaelligerWeg = *random_element(p_pWege.begin(), p_pWege.end());
	} while (hinweg && zufaelligerWeg == hinweg->getRueckweg());

	return zufaelligerWeg;
	
}

string Kreuzung::getName() const
{
	return p_sName;
}

double Kreuzung::getTankinhalt() const
{
	return p_dTankstelle;
}
