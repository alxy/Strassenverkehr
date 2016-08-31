#include <vector>

#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"

// Globale Zeit, die zur Abfertigung der Fahrzeuge benutzt wird
double dGlobaleZeit = 0;

void vAufgabe_1()
{
	// Direkte (statische) Instanziierung einiger Objekte
	Fahrzeug fahrzeug1("PKW1", 70);
	Fahrzeug fahrzeug2("PKW2", 40);

	string fahrzeug3Name;
	string fahrzeug4Name;

	// Dynamische Instanziierung der Objekt (Fahrzeugnamen können vom Benutzer eingegeben werden)
	cout << "Bitte einen Namen fuer Fahrzeug 3 eingeben: " << endl;
	cin >> fahrzeug3Name;
	Fahrzeug* fahrzeug3 = new Fahrzeug(fahrzeug3Name, 10);

	cout << "Bitte einen Namen fuer Fahrzeug 4 eingeben: " << endl;
	cin >> fahrzeug4Name;
	Fahrzeug* fahrzeug4 = new Fahrzeug(fahrzeug4Name, 120);


	// Abfertigungsschleife
	for (int i = 0; i < 16; i++)
	{

		// Ausgabe des Tabellenkopfes
		cout.setf(ios::left);
		cout << setw(4) << "ID" << setw(7) << "Name" << setw(3) << ":" << setw(9) << "MaxKmh" << setw(19) << "GesamtStrecke" << setw(19) << "Geschwindigkeit" << endl;
		cout << setw(60) << setfill('+') << "" << setfill(' ') << endl;

		// Datenverarbeitung und Ausgabe
		fahrzeug1.vAbfertigung();
		fahrzeug1.vAusgabe();
		cout << endl;

		fahrzeug2.vAbfertigung();
		fahrzeug2.vAusgabe();
		cout << endl;

		fahrzeug3->vAbfertigung();
		fahrzeug3->vAusgabe();
		cout << endl;

		fahrzeug4->vAbfertigung();
		fahrzeug4->vAusgabe();
		cout << endl;

		cout << endl << endl;

		dGlobaleZeit += 0.25;

	}

	// Freigeben des dynamischen Speichers
	delete fahrzeug4;
	delete fahrzeug3;
}

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

/*
 * Nur zu Testzwecken
 * Benutzung des Debuggers
 */
void vAufgabe1_deb() {
	Fahrzeug* fahrzeuge[4];

	fahrzeuge[0] = new Fahrzeug("PKW1", 10);
	fahrzeuge[1] = new Fahrzeug("PKW2", 20);
	fahrzeuge[2] = new Fahrzeug("PKW3", 30);
	fahrzeuge[3] = new Fahrzeug("PKW4", 40);

	fahrzeuge[2] = 0; // Absichtlich einen Fehler erzeugen

	for (int i = 0; i < 4; i++)
	{
		fahrzeuge[i]->vAusgabe();
	}


}

int main()
{
	//vAufgabe_1();
	//vAufgabe1_deb();
	//vAufgabe_2();
	vAufgabe_3();
}