#include "measurementData.h"

int numLines(FILE *datei)
{
    /*
    Eingabe: pointer auf ein File
    Aufgabe: zählt die Zeilen
    */

    int numLines = 0; //Variable zum zählen der Zeilen
    char letter; // Variable zum zwischen speicher von Chars

    //schleife ließt alle chars ein bis zum EOF
    while ((letter = fgetc(datei)) != EOF)
    {
        if (letter == '\n')
        {
            numLines++;//bei jedem Absatz beginnt eine neue Zeile und die Anzahl wird erhöht.
        }
    }

    return numLines;//Rückgabe der Anzahl an Zeilen.
}