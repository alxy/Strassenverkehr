#pragma once

#include<string>
#include<iostream>
#include<iomanip>
#include <map>

using namespace std;

class AktivesVO
{
protected:
	static int p_iMaxID;
	static map<string, AktivesVO*> p_pObjekte;
	string p_sName;
	int p_iID;
	double p_dZeit;

	virtual void vInitialisierung();
public:
	AktivesVO();
	AktivesVO(string name);
	virtual ~AktivesVO();
	virtual void vAbfertigung() = 0;
	virtual ostream& ostreamAusgabe(ostream& out);
	virtual istream& istreamEingabe(istream& in);
	static AktivesVO* ptObjekt(string pointerName);
private:
	void vObjektHinzufuegen(string name);
};

ostream& operator <<(ostream& out, AktivesVO& aktivesVO);
istream& operator >>(istream& in, AktivesVO& aktivesVO);
