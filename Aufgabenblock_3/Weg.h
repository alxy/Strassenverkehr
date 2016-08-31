#pragma once

#include "AktivesVO.h"
#include<list>
#include "LazyListe.h"

class Fahrzeug;
class Kreuzung;

typedef LazyListe<Fahrzeug*> fzgList;

enum Begrenzung
{
	innerorts = 50,
	landstrasse = 100,
	autobahn = 99999
};

class Weg :
	public AktivesVO
{
private:
	double p_dLaenge;
	double p_dVirtuelleSchranke;
	fzgList p_pFahrzeuge;
	Begrenzung p_eLimit;
	bool p_bUeberholverbot;
	Weg* p_pRueckweg;
	Kreuzung* p_pKreuzung; // Zielkreuzung

public:
	Weg();
	Weg(string name, double laenge, Begrenzung limit = autobahn, bool ueberholverbot = true);
	Weg(string name, double laenge, Weg* rueckweg, Kreuzung* kreuzung, Begrenzung limit = autobahn, bool ueberholverbot = true);
	virtual ~Weg();
	void vAbfertigung();
	ostream& ostreamAusgabe(ostream& out);
	double getLaenge() const;
	void vAnnahme(Fahrzeug* fahrzeug);
	void vAnnahme(Fahrzeug* fahrzeug, double startzeit);
	Begrenzung getLimit() const;
	string getName();
	void vAbgabe(Fahrzeug* fahrzeug);
	void vZeichnen();
	double getVirtuelleSchranke() const;
	void setVirtuelleSchranke(double schranke);
	void setRueckweg(Weg* rueckweg);
	Kreuzung* getKreuzung() const;
	Weg* getRueckweg() const;
};

