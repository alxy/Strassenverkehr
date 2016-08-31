#include "AktivesVO.h"

// Statischer ID Zähler
int AktivesVO::p_iMaxID = 0;

/**
 * @description Initialisierung der Parameter (Membervariablen)
 *
 * @access protected 
 * @return void
 */
void AktivesVO::vInitialisierung()
{
	p_iID = ++p_iMaxID;
	p_sName = "";
	p_dZeit = 0;
}

/**
 * @description Standardkonstruktor
 *
 * @access public 
 * @return 
 */
AktivesVO::AktivesVO()
{
	vInitialisierung();
}


/**
 * @description Konstruktor mit Parameter
 *
 * @access public 
 * @param string name
 * @return 
 */
AktivesVO::AktivesVO(string name)
{
	vInitialisierung();

	p_sName = name;
}


/**
 * @description Destruktor
 *
 * @access public 
 * @return 
 */
AktivesVO::~AktivesVO()
{
}

/**
 * @description Basis-Ausgabefunktion der Oberklasse AktivesVO
 *
 * @access public 
 * @param ostream & out
 * @return ostream &
 */
ostream & AktivesVO::ostreamAusgabe(ostream & out)
{
	out.setf(ios::left);
	out << setw(4) << p_iID << setw(7) << p_sName;
	return out;
}

/**
 * @description Überladung des Ausgabe-Operators (<<)
 *
 * @access public 
 * @param ostream & out
 * @param AktivesVO & aktivesVO
 * @return ostream&
 */
ostream& operator <<(ostream& out, AktivesVO& aktivesVO)
{
	return aktivesVO.ostreamAusgabe(out);
}
