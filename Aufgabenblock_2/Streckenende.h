#pragma once
#include "FahrAusnahme.h"
class Streckenende :
	public FahrAusnahme
{
public:
	Streckenende();
	Streckenende(Fahrzeug* fahrzeug, Weg* weg);
	virtual ~Streckenende();
	void vBearbeiten();
};

