#pragma once
#include "FzgVerhalten.h"

class FzgFahren :
	public FzgVerhalten
{
public:
	FzgFahren();
	FzgFahren(Weg* weg);
	virtual ~FzgFahren();
	double dStrecke(Fahrzeug* fahrzeug, double zeitraum);
};

