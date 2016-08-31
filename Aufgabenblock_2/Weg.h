#pragma once

#include "AktivesVO.h"
#include<list>
#include "LazyListe.h"

class Fahrzeug;

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
	fzgList p_pFahrzeuge;
	Begrenzung p_eLimit;

public:
	Weg();
	Weg(string name, double laenge, Begrenzung limit = autobahn);
	virtual ~Weg();
	void vAbfertigung();
	ostream& ostreamAusgabe(ostream& out);
	double getLaenge() const;
	void vAnnahme(Fahrzeug* fahrzeug);
	void vAnnahme(Fahrzeug* fahrzeug, double startzeit);
	Begrenzung getLimit() const;
	string getName();
	void vAbgabe(Fahrzeug* fahrzeug);
};

