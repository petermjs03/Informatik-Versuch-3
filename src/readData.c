#include "measurementData.h"

void readData(FILE *datei, int numLines, measurementData *ptrData)
{
    /*
    Eingabe: pointer auf ein File, anzahl an Zeilen im File, Array von Daten Strukturen
    Aufgabe: ließt File ein und schreibt die daten in ein Array von measurementData Strukturen
    */
    rewind(datei); // setzt den File posotion auf beginn

    // für jede Zeile wird ein daten Struct angelegt.
    for (int i = 0; i < numLines; i++)
    {
        // Einscannen der Daten im vorgegebenen Format.
        fscanf(datei, "%hd;%d;%d;%d;%d;%d\n", &ptrData[i].sensorId, &ptrData[i].measuredValue, &ptrData[i].warningLow, &ptrData[i].warningHigh, &ptrData[i].alarmLow, &ptrData[i].alarmHigh);
    }

    return;
}