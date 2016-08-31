#include "FzgVerhalten.h"
#include "Fahrzeug.h"
#include "Weg.h"



FzgVerhalten::FzgVerhalten()
{
}

FzgVerhalten::FzgVerhalten(Weg * weg)
	: p_pWeg(weg)
{
}


FzgVerhalten::~FzgVerhalten()
{
}

Weg * FzgVerhalten::getWeg() const
{
	return p_pWeg;
}
