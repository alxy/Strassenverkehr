#include "Welt.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "Kreuzung.h"
#include "Weg.h"
#include <typeinfo>
#include "SimuClient.h"



Welt::Welt()
{
}


Welt::~Welt()
{
}

/**
 * @description Einlesen der Verkehrsobjekte aus einem Stream
 *
 * @access public 
 * @param ifstream & in Eingabestream
 * @return void
 */
void Welt::vEinlesen(ifstream & in)
{
	while (!in.eof()) {
		string typ;
		in >> typ;

		if (typ == "KREUZUNG") {
			Kreuzung* kreuzung = new Kreuzung;
			in >> *kreuzung;

			p_pKreuzungen.push_back(kreuzung);
		}
		else if (typ == "STRASSE") {
			string nameQ, nameZ, nameW1, nameW2; // Quellkreuzung, Zielkreuzung, Hinweg, Rückweg
			double laenge; // Länge der Straße
			int tmpUeberholverbot; // Temporäre Variable für Überholverbot
			bool ueberholverbot; // Überholverbot
			int geschwindkeitsbegrenzung; // Temporäre Variable für Geschwindigkeitsbegrenzung
			Begrenzung begrenzung; // Geschwindigkeitsbegrenzung

			in >> nameQ >> nameZ >> nameW1 >> nameW2 >> laenge >> geschwindkeitsbegrenzung >> tmpUeberholverbot;

			switch (geschwindkeitsbegrenzung) // Begrenzung zuordnen (1 = innerorts, 2 = landstrasse, 3 = autobahn)
			{
			case 1:
				begrenzung = innerorts;
				break;
			case 2:
				begrenzung = landstrasse;
				break;
			case 3:
				begrenzung = autobahn;
				break;
			default:
				throw string("Ungueltiger Wert fuer GeschwindkeitsBegrenzung.");
				break;
			}

			switch (tmpUeberholverbot) // Überholverbot zuordnen (0 = nein, 1 = ja)
			{
			case 0:
				ueberholverbot = false;
				break;
			case 1:
				ueberholverbot = true;
				break;
			default:
				throw string("Ungueltiger Wert fuer Ueberholverbot.");
			}

			Kreuzung* krQ = dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(nameQ)); // Durch Casting richtigen Objekttyp sicherstellen
			Kreuzung* krZ = dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(nameZ));

			if (!krQ || !krZ) // dynamic_cast() gibt nullptr bei fehlerhaftem Typ zurück!
			{
				throw string("Ungueltiges Objekt an Strasse uebergeben.");
			}

			krQ->vVerbinde(nameW1, nameW2, laenge, krZ, begrenzung, ueberholverbot);
		}
		else if (typ == "PKW") {
			PKW* pkw = new PKW;
			in >> *pkw;

			string nameS; // Name der Startkreuzung
			double startzeit; // Startzeit
			in >> nameS;
			in >> startzeit;

			Kreuzung* kreuzung = dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(nameS)); //(Kreuzung*)AktivesVO::ptObjekt(nameS);
			if (!kreuzung)
			{
				throw string("Ungueltiges Objekt an PKW uebergeben.");
			}

			kreuzung->vAnnahme(pkw, startzeit);
		}
		else if (typ == "FAHRRAD") {
			Fahrrad* fahrrad = new Fahrrad;
			in >> *fahrrad;

			string nameS; // Name der Startkreuzung
			double startzeit; // Startzeit
			in >> nameS;
			in >> startzeit;

			Kreuzung* kreuzung = dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(nameS)); //(Kreuzung*)AktivesVO::ptObjekt(nameS);
			if (!kreuzung)
			{
				throw string("Ungueltiges Objekt an Fahrrad uebergeben.");
			}

			kreuzung->vAnnahme(fahrrad, startzeit);
		}
		else {
			throw string("Ungueltiges VerkehrsObjekt (Unbekannter Typ).");
		}
	}
}

/**
 * @description Einlesen der Verkehrsobjekte aus einem Stream, Grafische Ausgabe von Kreuzungen und Straßen
 *
 * @access public 
 * @param ifstream & in
 * @return void
 */
void Welt::vEinlesenMitGrafik(ifstream & in)
{
	while (!in.eof()) {
		string typ;
		in >> typ;

		if (typ == "KREUZUNG") {
			Kreuzung* kreuzung = new Kreuzung;
			in >> *kreuzung;

			int koordinaten[2];
			in >> koordinaten[0] >> koordinaten[1];
			bZeichneKreuzung(koordinaten[0], koordinaten[1]);

			p_pKreuzungen.push_back(kreuzung);
		}
		else if (typ == "STRASSE") {
			string nameQ, nameZ, nameW1, nameW2; // Quellkreuzung, Zielkreuzung, Hinweg, Rückweg
			double laenge;
			int tmpUeberholverbot;
			bool ueberholverbot;
			int geschwindkeitsbegrenzung;
			Begrenzung begrenzung;
			int anzahlKoord;

			in >> nameQ >> nameZ >> nameW1 >> nameW2 >> laenge >> geschwindkeitsbegrenzung >> tmpUeberholverbot >> anzahlKoord;

			int* koordinaten = new int[2 * anzahlKoord];

			for (int i = 0; i < 2 * anzahlKoord; i++)
			{
				in >> koordinaten[i];
			}

			switch (geschwindkeitsbegrenzung)
			{
			case 1:
				begrenzung = innerorts;
				break;
			case 2:
				begrenzung = landstrasse;
				break;
			case 3:
				begrenzung = autobahn;
				break;
			default:
				throw string("Ungueltiger Wert fuer GeschwindkeitsBegrenzung.");
				break;
			}

			switch (tmpUeberholverbot)
			{
			case 0:
				ueberholverbot = false;
				break;
			case 1:
				ueberholverbot = true;
				break;
			default:
				throw string("Ungueltiger Wert fuer Ueberholverbot.");
			}

			Kreuzung* krQ = dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(nameQ));
			Kreuzung* krZ = dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(nameZ));

			if (!krQ || !krZ)
			{
				throw string("Ungueltiges Objekt an Strasse uebergeben.");
			}



			krQ->vVerbinde(nameW1, nameW2, laenge, krZ, begrenzung, ueberholverbot);
			bZeichneStrasse(nameW1, nameW2, laenge, anzahlKoord, koordinaten);
			delete koordinaten; // Speicher freigeben
		}
		else if (typ == "PKW") {
			PKW* pkw = new PKW;
			in >> *pkw;

			string nameS; // Name der Startkreuzung
			double startzeit; // Startzeit
			in >> nameS;
			in >> startzeit;

			Kreuzung* kreuzung = dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(nameS)); //(Kreuzung*)AktivesVO::ptObjekt(nameS);
			if (!kreuzung)
			{
				throw string("Ungueltiges Objekt an PKW uebergeben.");
			}

			kreuzung->vAnnahme(pkw, startzeit);
		}
		else if (typ == "FAHRRAD") {
			Fahrrad* fahrrad = new Fahrrad;
			in >> *fahrrad;

			string nameS; // Name der Startkreuzung
			double startzeit; // Startzeit
			in >> nameS;
			in >> startzeit;

			Kreuzung* kreuzung = dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(nameS)); //(Kreuzung*)AktivesVO::ptObjekt(nameS);
			if (!kreuzung)
			{
				throw string("Ungueltiges Objekt an Fahrrad uebergeben.");
			}

			kreuzung->vAnnahme(fahrrad, startzeit);
		}
		else {
			throw string("Ungueltiges VerkehrsObjekt (Unbekannter Typ).");
		}
	}
}

/**
 * @description Simulation der Welt
 *
 * @access public 
 * @return void
 */
void Welt::vSimulation()
{
	for (list<Kreuzung *>::iterator it = p_pKreuzungen.begin(); it != p_pKreuzungen.end(); it++) // Alle Kreuzungen abfertigen und zeichnen
	{
		(*it)->vAbfertigung();
		(*it)->vZeichnen();
	}
}
