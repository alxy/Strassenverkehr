#pragma once

#include<string>
#include<iostream>
#include<iomanip>

using namespace std;

class AktivesVO
{
protected:
	static int p_iMaxID;
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
};

ostream& operator <<(ostream& out, AktivesVO& aktivesVO);
