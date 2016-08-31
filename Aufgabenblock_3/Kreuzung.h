#pragma once
#include <list>
#include "AktivesVO.h"

class Weg;
class Fahrzeug;

enum Begrenzung;

typedef list<Weg*> wegList;

class Kreuzung :
	public AktivesVO
{
public:
	Kreuzung();
	Kreuzung(string name, double tankvolumen = 0);
	virtual ~Kreuzung();
	void vVerbinde(string hinweg, string rueckweg, double laenge, Kreuzung* kreuzung, Begrenzung begrenzung, bool ueberholverbot = true);
	void vTanken(Fahrzeug* fahrzeug);
	void vAnnahme(Fahrzeug* fahrzeug, double startzeit = 0);
	void vAnnahme(Fahrzeug* fahrzeug, Weg* neuerWeg);
	void vAbfertigung();
	void vZeichnen(int koordinaten[2]) const; // Kreuzung initial auf dem Grafikfenster ausgeben
	void vZeichnen();
	ostream& ostreamAusgabe(ostream& out);
	istream& istreamEingabe(istream& in);
	Weg* ptZufaelligerWeg(Weg* hinweg);
	string getName() const;
	double getTankinhalt() const;
private:
	wegList p_pWege;
	double p_dTankstelle; // Tankvorrat der Tankstelle in Litern
};

template <typename I>
I random_element(I begin, I end)
{
	const unsigned long n = std::distance(begin, end);
	const unsigned long divisor = (RAND_MAX + 1) / n;

	unsigned long k;
	do { k = std::rand() / divisor; } while (k >= n); // Bessere Zufäligkeit als rand() % n

	std::advance(begin, k); // Iterator beliebig auf k erhoehen
	return begin;
}