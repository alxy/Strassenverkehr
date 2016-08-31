#pragma once
#include "FahrAusnahme.h"
class Losfahren :
	public FahrAusnahme
{
public:
	Losfahren();
	Losfahren(Fahrzeug* fahrzeug, Weg* weg);
	virtual ~Losfahren();
	void vBearbeiten();
};

