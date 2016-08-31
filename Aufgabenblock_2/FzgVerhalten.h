#pragma once

class Weg;
class Fahrzeug;

class FzgVerhalten
{
protected:
	Weg* p_pWeg;
public:
	FzgVerhalten();
	FzgVerhalten(Weg* weg);
	virtual ~FzgVerhalten() = 0;
	virtual double dStrecke(Fahrzeug* fahrzeug, double zeitraum) = 0;
	Weg* getWeg() const;
};

