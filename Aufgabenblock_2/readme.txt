Zum Starten des Simulationsservers ist zumindest ein Runtimesystem
von Java 8 (JRE) erforderlich. Im CIP-Pool ist das entsprechende JDK installiert 
und der Speicherort des jar-Files bekannt. Das jar-File wird beim
Initialisieren des Servers (bInitialisiereGrafik()) automatisch gestartet.

Möchten Sie den Server zuhause einsetzen, so müssen Sie das jar-File in 
das Projektverzeichnis kopieren und das JRE installiert haben.

Hier gleich die Lösungen zu häufigen Problemen ;-) :

    1) Das JRE ist nicht installiert.
       Um dies zu erkennen, öffnen Sie eine CMD-Eingabeaufforderung und geben dort
       java -Version
       ein. Wenn dies zur Meldung "Unbekannter Befehl" führt oder die Version vor 1.8 liegt:
       -> Laden Sie das JRE vom Serviceportal oder von http://java.sun.com/
       herunter und installieren Sie es. Achten Sie darauf, dass es sich um die 32Bit-Variante
       handelt. Bei einem 64-Bit-Betriebssystem müssen Sie diese ggf. zusätzlich zur 64Bit-JRE
       installieren.
       Die 32Bit-Variante ist zum automatischen Start des Simulationsservers erforderlich.
       Sie können auch nur mit der 64Bit-Variante arbeiten. Dann müssen Sie den Simuserver selbst
       starten und die Fehlermeldung dazu beim Start ignorieren.
       
    2) Ihre Firewall verhindert Kommunikation mit Port 7654.
       Ihr Programm muss mit Ihrem lokalen Rechner (127.0.0.1) Kommunikation
       über Port 7654 aufnehmen können. Bei ersten Start des Simulationsservers muss dies
       meistens explizit erlaubt werden.

    3) Das Programm findet den jar-File nicht in Ihrem Projektverzeichnis.
       -> Kopieren Sie den jar-File dorthin (Wenn Sie das Programm aus der VS starten, ist es
       das Verzeichnis, wo auch ihre cpp- und h-Dateien liegen).
       Im CIP-Pool wird automatisch der jar-File vom Server (P:\UserGrp\PI2) gestartet.

    4) Sie benutzen die Visual Studio Version 6 oder Visual Studio 2003 / 2005 / 2008 /2010.
       Diese Versionen werden nicht (mehr) unterstützt. Bitte laden Sie Visual Studio 2012 oder 2013
       Sie erhalten dies z.B. vom MSDN AA Portal (Dreamspark).

Wenn Punkt 4 das Problem noch nicht löst, wenden Sie sich bitte an die Betreuung
(persönlich, per E-Mail oder Diskussionsgruppe).

    Falls die Parameterübergabe an die DLL nicht funktioniert, achten Sie bitte darauf, dass Sie
    das Projekt im DEBUG-Modus (nicht RELEASE-Modus!) erzeugt haben.
