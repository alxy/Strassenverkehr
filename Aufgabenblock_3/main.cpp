#include <vector>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <typeinfo>

#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "Weg.h"
#include "SimuClient.h"
#include "LazyListe.h"
#include "Kreuzung.h"
#include "Welt.h"

// Globale Zeit, die zur Abfertigung der Fahrzeuge benutzt wird
double dGlobaleZeit = 0;

void vErhoeheGlobaleZeit(float schritt)
{
	dGlobaleZeit = roundf((dGlobaleZeit + schritt) * 100) / 100; // Runden auf zwei Stellen
}

//void vAufgabe_1()
//{
//	// Direkte (statische) Instanziierung einiger Objekte
//	Fahrzeug fahrzeug1("PKW1", 70);
//	Fahrzeug fahrzeug2("PKW2", 40);
//
//	string fahrzeug3Name;
//	string fahrzeug4Name;
//
//	// Dynamische Instanziierung der Objekt (Fahrzeugnamen können vom Benutzer eingegeben werden)
//	cout << "Bitte einen Namen fuer Fahrzeug 3 eingeben: " << endl;
//	cin >> fahrzeug3Name;
//	Fahrzeug* fahrzeug3 = new Fahrzeug(fahrzeug3Name, 10);
//
//	cout << "Bitte einen Namen fuer Fahrzeug 4 eingeben: " << endl;
//	cin >> fahrzeug4Name;
//	Fahrzeug* fahrzeug4 = new Fahrzeug(fahrzeug4Name, 120);
//
//
//	// Abfertigungsschleife
//	for (int i = 0; i < 16; i++)
//	{
//		dGlobaleZeit += 0.25;
//
//		// Ausgabe des Tabellenkopfes
//		cout.setf(ios::left);
//		cout << setw(4) << "ID" << setw(7) << "Name" << setw(3) << ":" << setw(9) << "MaxKmh" << setw(19) << "GesamtStrecke" << endl;
//		cout << setw(42) << setfill('+') << "" << setfill(' ') << endl;
//
//		// Datenverarbeitung und Ausgabe
//		fahrzeug1.vAbfertigung();
//		fahrzeug1.vAusgabe();
//		cout << endl;
//
//		fahrzeug2.vAbfertigung();
//		fahrzeug2.vAusgabe();
//		cout << endl;
//
//		fahrzeug3->vAbfertigung();
//		fahrzeug3->vAusgabe();
//		cout << endl;
//
//		fahrzeug4->vAbfertigung();
//		fahrzeug4->vAusgabe();
//		cout << endl;
//
//		cout << endl << endl;
//
//	}
//
//	// Freigeben des dynamischen Speichers
//	delete fahrzeug4;
//	delete fahrzeug3;
//}

void vAufgabe_2() {

	// Deklaration der Variablen (Vector aus STL)
	vector<Fahrzeug*> fahrzeuge;
	int iAnzahlPKWs, iAnzahlFahrraeder;

	// Benutzereingaben
	cout << "Wieviele PKWs sollen erstellt werden? ";
	cin >> iAnzahlPKWs;

	cout << "Wieviele Fahrraeder sollen erstellt werden? ";
	cin >> iAnzahlFahrraeder;

	cout << endl << endl;

	// Einlesen der Daten für PKWs und dynmische Instanziierung
	for (int i = 1; i <= iAnzahlPKWs; i++)
	{
		string sName;
		double dMaxGeschwindigkeit, dVerbrauch, dTankvolumen;

		cout << "Bitte geben Sie einen Namen fuer PKW " << i << " ein: ";
		cin >> sName;

		cout << "Bitte geben Sie eine maximale Geschwindkeit fuer PKW " << i << " ein: ";
		cin >> dMaxGeschwindigkeit;

		cout << "Bitte geben Sie einen Verbauch (pro 100 KM) fuer PKW " << i << " ein: ";
		cin >> dVerbrauch;

		cout << "Bitte geben Sie ein Tankvolumen (in Litern) fuer PKW " << i << " ein: ";
		cin >> dTankvolumen;

		fahrzeuge.push_back(new PKW(sName, dMaxGeschwindigkeit, dVerbrauch, dTankvolumen));

		cout << "PKW " << i << " wurde erfolgreich erstellt!" << endl << endl;
	}

	// Einlesen der Daten für Fahrräder und dynmische Instanziierung
	for (int i = 1; i <= iAnzahlFahrraeder; i++)
	{
		string sName;
		double dMaxGeschwindigkeit;

		cout << "Bitte geben Sie einen Namen fuer Fahrrad " << i << " ein: ";
		cin >> sName;

		cout << "Bitte geben Sie eine maximale Geschwindkeit fuer Fahrrad " << i << " ein: ";
		cin >> dMaxGeschwindigkeit;

		fahrzeuge.push_back(new Fahrrad(sName, dMaxGeschwindigkeit));

		cout << "Fahrrad " << i << " wurde erfolgreich erstellt!" << endl << endl;
	}

	cout << endl << endl;

	// Abfeertigungsschleife
	for (int i = 0; i < 30; i++)
	{
		cout << "Globale Zeit (in Stunden): " << setiosflags(ios::fixed) << setprecision(2) << dGlobaleZeit << endl;

		// Ausgabe des Tabellenkopfes
		cout.setf(ios::left);
		cout << setw(4) << "ID" << setw(7) << "Name" << setw(3) << ":" << setw(9) << "MaxKmh" << setw(19) << "GesamtStrecke" << setw(19) << "Geschwindigkeit" << setw(15) << "Verbrauch" << "Tankinhalt" << endl;
		cout << setw(87) << setfill('+') << "" << setfill(' ') << endl;

		// Schleife über alle Fahrzeuge, Abfertigung und Ausgabe
		for (vector<Fahrzeug*>::iterator it = fahrzeuge.begin(); it != fahrzeuge.end(); ++it) {

			// Nach 3 Stunden Volltanken
			if (dGlobaleZeit == 3)
				(*it)->dTanken();

			(*it)->vAbfertigung();
			(*it)->vAusgabe();
		}

		cout << endl << endl;

		dGlobaleZeit += 0.25;

	}

}

void vAufgabe_3()
{
	// Ausgabe des Tabellenkopfes
	cout.setf(ios::left);
	cout << setw(4) << "ID" << setw(7) << "Name" << setw(3) << ":" << setw(9) << "MaxKmh" << setw(19) << "GesamtStrecke" << setw(19) << "Geschwindigkeit" << setw(15) << "Verbrauch" << "Tankinhalt" << endl;
	cout << setw(87) << setfill('+') << "" << setfill(' ') << endl;

	// Instanziierung einiger Test-Fahrzeuge
	PKW pkw1("Golf", 200, 15, 60);
	PKW pkw2("Audi A6", 250, 7.5, 80);
	Fahrrad fahrrad1("Fahrrad", 22);

	// Abfertigung simulieren um entsprechende Testdaten zu generieren
	dGlobaleZeit = 3;
	pkw1.vAbfertigung();
	pkw2.vAbfertigung();
	fahrrad1.vAbfertigung();

	// Testausgabe um Output-Operator Überladung zu testen
	cout << pkw1 << pkw2 << fahrrad1 << endl;

	// Testausgabe um Kleiner-Operator Überladung zu testen
	if (pkw1 < pkw2)
		cout << "PKW1 ist weniger gefahren als PKW2!" << endl;

	// Testausgabe um Kopieren mittels Copy-Konsturktor zu testen
	cout << "Kopieren mittels Copy-Konstruktor:" << endl;

	PKW pkw3 = pkw1; // Copy-Konstruktor (Problem: Es wird bei normalem Verhalten alles kopiert, insbesondere auch die ID und die gefahrene Strecke)
	cout << pkw1 << pkw3 << endl;
}

void vAufgabe_4()
{
	PKW pkw1("Golf", 200, 15, 60);
	PKW pkw2("Audi A6", 250, 7.5, 80);
	Fahrrad fahrrad1("Fahrrad", 22);

	Weg weg1("Weg1", 50, innerorts);
	Weg weg2("Weg2", 10);

	weg1.vAnnahme(&pkw1);
	weg1.vAnnahme(&pkw2, 5);
	weg1.vAnnahme(&fahrrad1);

	for (int i = 0; i < 30; i++)
	{
		cout << "Globale Zeit (in Stunden): " << setiosflags(ios::fixed) << setprecision(2) << dGlobaleZeit << endl;

		weg1.vAbfertigung();
		cout << weg1 << pkw1 << pkw2 << fahrrad1;

		dGlobaleZeit += 0.25;
	}

}

void vAufgabe_5()
{
	PKW pkw1("Golf", 200, 15, 60);
	PKW pkw2("Audi_A6", 250, 7.5, 80);

	PKW pkw3("Astra", 150, 4.5, 50);
	PKW pkw4("Audi_A3", 230, 7.5, 80);

	Fahrrad fahrrad1("Fahrrad", 22);

	Weg weg1("Weg1", 500, innerorts);
	Weg weg2("Weg2", 500);

	weg1.vAnnahme(&pkw1, 2);
	weg1.vAnnahme(&pkw2);
	weg1.vAnnahme(&fahrrad1);

	weg2.vAnnahme(&pkw3, 1);
	weg2.vAnnahme(&pkw4);

	bInitialisiereGrafik(800, 500);

	int koordinaten[4] = { 700, 250, 100, 250 };
	bZeichneStrasse("Weg1", "Weg2", weg1.getLaenge(), 2, koordinaten);

	for (int i = 0; i < 50; i++)
	{
		vSetzeZeit(dGlobaleZeit);
		cout << "Globale Zeit (in Stunden): " << setiosflags(ios::fixed) << setprecision(2) << dGlobaleZeit << endl;

		pkw1.vZeichnen(&weg1);
		pkw2.vZeichnen(&weg1);
		fahrrad1.vZeichnen(&weg1);

		pkw3.vZeichnen(&weg2);
		pkw4.vZeichnen(&weg2);

		weg1.vAbfertigung();
		weg2.vAbfertigung();

		cout << weg1 << weg2 << pkw1 << pkw2 << pkw3 << endl << endl;

		vErhoeheGlobaleZeit(0.25);
	}

	//vBeendeGrafik();

}

void vAufgabe_6()
{
	PKW pkw1("Golf", 200, 15, 60);
	PKW pkw2("Audi_A6", 250, 7.5, 80);

	PKW pkw3("Astra", 150, 4.5, 50);
	PKW pkw4("Audi_A3", 230, 7.5, 80);

	Fahrrad fahrrad1("Fahrrad", 22);

	Weg weg1("Weg1", 500, innerorts);
	Weg weg2("Weg2", 500);

	weg1.vAnnahme(&pkw1, 2);
	weg1.vAnnahme(&pkw2);
	weg1.vAnnahme(&fahrrad1);

	weg2.vAnnahme(&pkw3, 1);
	weg2.vAnnahme(&pkw4);

	bInitialisiereGrafik(800, 500);

	int koordinaten[4] = { 700, 250, 100, 250 };
	bZeichneStrasse("Weg1", "Weg2", weg1.getLaenge(), 2, koordinaten);

	for (int i = 0; i < 50; i++)
	{
		vSetzeZeit(dGlobaleZeit);
		cout << "Globale Zeit (in Stunden): " << setiosflags(ios::fixed) << setprecision(2) << dGlobaleZeit << endl;

		weg1.vZeichnen();
		weg2.vZeichnen();

		weg1.vAbfertigung();
		weg2.vAbfertigung();

		cout << weg1 << weg2 << pkw1 << pkw2 << pkw3 << endl << endl;

		vErhoeheGlobaleZeit(0.25);
	}

	//vBeendeGrafik();

}

void vAufgabe_6a()
{
	LazyListe<int> liste;
	typedef LazyListe<int>::iterator llIterator;

	// Liste mit 10 zufällen Zahlen befüllen
	for (int i = 0; i < 10; i++)
	{
		int zahl = rand() % 11;
		liste.push_back(zahl);
	}

	liste.vAktualisieren();

	// Liste ausgeben
	for (llIterator it = liste.begin(); it != liste.end(); it++)
	{
		cout << *it << endl;
	}

	// Lösche alle Elemente > 5
	for (llIterator it = liste.begin(); it != liste.end(); it++)
	{
		if (*it > 5) {
			liste.erase(it);
		}
	}

	// Liste ausgeben
	for (llIterator it = liste.begin(); it != liste.end(); it++)
	{
		cout << *it << endl;
	}

	liste.vAktualisieren();

	// Liste ausgeben
	for (llIterator it = liste.begin(); it != liste.end(); it++)
	{
		cout << *it << endl;
	}

	// Beliebige Zahlen an Anfang und Ende einfügen
	liste.push_back(33);
	liste.push_back(51);
	liste.push_front(73);
	liste.push_front(56);

	liste.vAktualisieren();

	// Liste ausgeben
	for (llIterator it = liste.begin(); it != liste.end(); it++)
	{
		cout << *it << endl;
	}
}

void vAufgabe_7()
{
	PKW pkw1("Audi_A3", 80, 7.5, 20);
	PKW pkw2("Audi_A6", 150, 7.5, 80);
	Fahrrad fahrrad1("Fahrrad", 40);

	Weg weg1("Weg1", 200, autobahn);
	Weg weg2("Weg2", 200);

	weg1.vAnnahme(&pkw1, 2);
	weg1.vAnnahme(&fahrrad1, 1);

	bInitialisiereGrafik(800, 500);

	int koordinaten[4] = { 700, 250, 100, 250 };
	bZeichneStrasse(weg1.getName(), weg2.getName(), weg1.getLaenge(), 2, koordinaten);

	// Ausgabe des Tabellenkopfes
	cout.setf(ios::left);
	cout << setw(4) << "ID" << setw(7) << "Name" << setw(3) << ":" << setw(9) << "MaxKmh" << setw(19) << "GesamtStrecke" << setw(19) << "Geschwindigkeit" << setw(15) << "Verbrauch" << "Tankinhalt" << endl;
	cout << setw(87) << setfill('+') << "" << setfill(' ') << endl;

	for (int i = 0; i < 50; i++)
	{
		vSetzeZeit(dGlobaleZeit);
		cout << "Globale Zeit (in Stunden): " << setiosflags(ios::fixed) << setprecision(2) << dGlobaleZeit << endl;

		if (i == 25)
		{
			weg1.vAnnahme(&pkw2, dGlobaleZeit + 1); // Parkendes Fahrzeug hinzufügen
		}

		weg1.vZeichnen();
		weg1.vAbfertigung();

		cout << weg1 << pkw1 << fahrrad1 << endl << endl;

		vErhoeheGlobaleZeit(0.25);
	}
}

void vAufgabe_8()
{
	bInitialisiereGrafik(1000, 700);

	PKW pkw1("Audi_A3", 80, 7.5, 20);
	PKW pkw2("Audi_A6", 100, 7.5, 80);
	Fahrrad fahrrad1("Fahrrad", 40);

	// Kreuzungen anlegen und anzeigen
	Kreuzung kr1("K1");
	Kreuzung kr2("K2", 1000);
	Kreuzung kr3("K3");
	Kreuzung kr4("K4");

	int iK1[2] = { 680, 40 };
	int iK2[2] = { 680, 300 };
	int iK3[2] = { 680, 570 };
	int iK4[2] = { 320, 300 };

	kr1.vZeichnen(iK1);
	kr2.vZeichnen(iK2);
	kr3.vZeichnen(iK3);
	kr4.vZeichnen(iK4);

	kr1.vVerbinde("W12", "W21", 40, &kr2, innerorts, true);
	kr2.vVerbinde("W23a", "W32a", 115, &kr3, autobahn, false);
	kr2.vVerbinde("W23b", "W32b", 40, &kr3, innerorts, true);
	kr2.vVerbinde("W24", "W42", 55, &kr4, innerorts, true);
	kr3.vVerbinde("W34", "W43", 85, &kr4, autobahn, false);
	kr4.vVerbinde("W44a", "W44b", 130, &kr4, landstrasse, false);

	int iW12[][2] = { { 680, 40 },{ 680, 300 } };
	int iW23a[][2] = { { 680, 300 },{ 850, 300 },{ 970, 390 },{ 970, 500 },{ 850, 570 },{ 680, 570 } };
	int iW23b[][2] = { { 680, 300 },{ 680, 570 } };
	int iW24[][2] = { { 680, 300 },{ 320, 300 } };
	int iW34[][2] = { { 680, 570 },{ 500, 570 },{ 350, 510 },{ 320, 420 },{ 320, 300 } };
	int iW44[][2] = { { 320, 300 },{ 320, 150 },{ 200, 60 },{ 80, 90 },{ 70, 250 },{ 170, 300 },{ 320, 300 } };

	bZeichneStrasse("W12", "W21", 40, 2, (int *)iW12);
	bZeichneStrasse("W23a", "W32a", 115, 6, (int *)iW23a);
	bZeichneStrasse("W23b", "W32b", 40, 2, (int *)iW23b);
	bZeichneStrasse("W24", "W42", 55, 2, (int *)iW24);
	bZeichneStrasse("W34", "W43", 85, 5, (int *)iW34);
	bZeichneStrasse("W44a", "W44b", 130, 7, (int *)iW44);

	kr1.vAnnahme(&pkw1);
	kr2.vAnnahme(&pkw2);
	kr1.vAnnahme(&fahrrad1);

	for (int i = 0; i < 100; i++)
	{
		vSetzeZeit(dGlobaleZeit);
		cout << "Globale Zeit (in Stunden): " << setiosflags(ios::fixed) << setprecision(2) << dGlobaleZeit << endl;

		kr1.vAbfertigung();
		kr2.vAbfertigung();
		kr3.vAbfertigung();
		kr4.vAbfertigung();

		kr1.vZeichnen();
		kr2.vZeichnen();
		kr3.vZeichnen();
		kr4.vZeichnen();

		cout << kr1 << kr2 << kr3 << kr4;

		vErhoeheGlobaleZeit(0.1);
	}
}

void vAufgabe_9()
{
	ifstream infile("Simu.dat");
	Welt welt;

	try
	{
		welt.vEinlesen(infile);
	}
	catch (string ex)
	{
		cout << ex << endl;
		return;
	}

	for (int i = 0; i < 50; i++)
	{
		vSetzeZeit(dGlobaleZeit);
		cout << "Globale Zeit (in Stunden): " << setiosflags(ios::fixed) << setprecision(2) << dGlobaleZeit << endl;

		welt.vSimulation();

		vErhoeheGlobaleZeit(0.1);
	}
}

void vAufgabe_9_Grafik()
{
	ifstream infile("SimuDisplay.dat");
	Welt welt;

	bInitialisiereGrafik(1000, 1000);

	try
	{
		welt.vEinlesenMitGrafik(infile);
	}
	catch (string ex)
	{
		cout << ex << endl;
		return;
	}

	for (int i = 0; i < 100; i++)
	{
		vSetzeZeit(dGlobaleZeit);
		cout << "Globale Zeit (in Stunden): " << setiosflags(ios::fixed) << setprecision(2) << dGlobaleZeit << endl;

		welt.vSimulation();
		vErhoeheGlobaleZeit(0.1);
	}
}

/*
 * Nur zu Testzwecken
 * Benutzung des Debuggers
 */
//void vAufgabe1_deb() {
//	Fahrzeug* fahrzeuge[4];
//
//	fahrzeuge[0] = new Fahrzeug("PKW1", 10);
//	fahrzeuge[1] = new Fahrzeug("PKW2", 20);
//	fahrzeuge[2] = new Fahrzeug("PKW3", 30);
//	fahrzeuge[3] = new Fahrzeug("PKW4", 40);
//
//	fahrzeuge[2] = 0; // Absichtlich einen Fehler erzeugen
//
//	for (int i = 0; i < 4; i++)
//	{
//		fahrzeuge[i]->vAusgabe();
//	}
//
//
//}

int main()
{
	//vAufgabe_1();
	//vAufgabe1_deb();
	//vAufgabe_2();
	//vAufgabe_3();
	//vAufgabe_4();
	//vAufgabe_5();
	//vAufgabe_6();
	//vAufgabe_6a();
	//vAufgabe_7(); // Funktioniert nicht mehr nach Modifikation für A8
	vAufgabe_8();
	//vAufgabe_9();
	//vAufgabe_9_Grafik();
}