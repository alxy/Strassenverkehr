#pragma once

class Fahrzeug;
class Weg;

class FahrAusnahme
{
protected:
	Fahrzeug* p_pFahrzeug;
	Weg* p_pWeg;
public:
	FahrAusnahme();
	FahrAusnahme(Fahrzeug* fahrzeug, Weg* weg);
	virtual void vBearbeiten() = 0;
	virtual ~FahrAusnahme();
};

