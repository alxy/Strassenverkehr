#include "AktivesVO.h"

int AktivesVO::p_iMaxID = 0;
map<string, AktivesVO*> AktivesVO::p_pObjekte;

void AktivesVO::vInitialisierung()
{
	p_iID = ++p_iMaxID;
	p_sName = "";
	p_dZeit = 0;
}

AktivesVO::AktivesVO()
{
	vInitialisierung();
}

AktivesVO::AktivesVO(string name)
{
	vInitialisierung();

	p_sName = name;
	vObjektHinzufuegen(name); // Statisch erzeugte Objekte hinzufügen
}


AktivesVO::~AktivesVO()
{
}

ostream & AktivesVO::ostreamAusgabe(ostream & out)
{
	out.setf(ios::left);
	out << setw(4) << p_iID << setw(7) << p_sName;
	return out;
}

istream & AktivesVO::istreamEingabe(istream & in)
{
	if (p_sName != "") {
		throw string("Nur in unspezifizierte Objekte darf eingelesen werden!");
	}

	in >> p_sName;
	vObjektHinzufuegen(p_sName); // Eingelesene Objekte hinzufügen

	return in;
}

AktivesVO * AktivesVO::ptObjekt(string pointerName)
{
	map<string, AktivesVO*>::iterator it = p_pObjekte.find(pointerName);

	if (it == p_pObjekte.end())
	{
		throw string("Kein Objekt mit diesem Namen gefunden!\n");
	}

	return it->second;
}

void AktivesVO::vObjektHinzufuegen(string name)
{
	// Objekt der Liste (map) hinzufügen
	map<string, AktivesVO*>::iterator it = p_pObjekte.find(name);
	if (it == p_pObjekte.end()) // Iterator auf Endposition == Es existiert noch kein Objekt mit diesem Namen
	{
		p_pObjekte[name] = this;
	}
	else {
		throw string("Es existiert bereits ein Objekt mit diesem Namen.\n");
	}
}

/*
* Überladung des Ausgabe-Operators (<<)
*/
ostream& operator <<(ostream& out, AktivesVO& aktivesVO)
{
	return aktivesVO.ostreamAusgabe(out);
}

/**
 * @description Überladung des Eingabe-Operators (>>)
 *
 * @access public 
 * @param istream & in
 * @param AktivesVO & aktivesVO
 * @return istream&
 */
istream& operator >>(istream& in, AktivesVO& aktivesVO)
{
	return aktivesVO.istreamEingabe(in);
}
