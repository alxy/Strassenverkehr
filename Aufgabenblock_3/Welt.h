#pragma once

#include<iostream>
#include <fstream>
#include <string>
#include <list>

#include "Kreuzung.h"

using namespace std;

class Welt
{
public:
	Welt();
	virtual ~Welt();
	void vEinlesen(ifstream& in);
	void vEinlesenMitGrafik(ifstream& in);
	void vSimulation();
private:
	list<Kreuzung *> p_pKreuzungen;
};

