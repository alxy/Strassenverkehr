#pragma once

#include <math.h>

#include "Fahrzeug.h"

class Fahrrad :
	public Fahrzeug
{
public:
	Fahrrad();
	Fahrrad(string name, double maxGeschwindigkeit);
	virtual ~Fahrrad();
	double dGeschwindigkeit();
	void vAusgabe();
	ostream& ostreamAusgabe(ostream& out);
};

