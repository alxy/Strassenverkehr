#include "FahrAusnahme.h"
#include "Fahrzeug.h"
#include "Weg.h"



FahrAusnahme::FahrAusnahme()
{
}

FahrAusnahme::FahrAusnahme(Fahrzeug * fahrzeug, Weg * weg)
	: p_pFahrzeug(fahrzeug), p_pWeg(weg)
{

}


FahrAusnahme::~FahrAusnahme()
{
}
