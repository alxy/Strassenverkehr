#include "FahrAusnahme.h"
#include "Fahrzeug.h"
#include "Weg.h"



/**
 * @description Standard-Konstruktor
 *
 * @access public 
 * @return 
 */
FahrAusnahme::FahrAusnahme()
{
}


/**
 * @description Konstruktor mit Parametern
 *
 * @access public 
 * @param Fahrzeug * fahrzeug
 * @param Weg * weg
 * @return 
 */
FahrAusnahme::FahrAusnahme(Fahrzeug * fahrzeug, Weg * weg)
	: p_pFahrzeug(fahrzeug), p_pWeg(weg)
{

}


FahrAusnahme::~FahrAusnahme()
{
}
