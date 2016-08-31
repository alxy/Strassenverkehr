#pragma once
#include "FzgVerhalten.h"
class FzgParken :
	public FzgVerhalten
{
private:
	double p_dStartzeit;
public:
	FzgParken();
	FzgParken(Weg* weg, double startzeit);
	virtual ~FzgParken();
	double dStrecke(Fahrzeug* fahrzeug, double zeitraum);
};

