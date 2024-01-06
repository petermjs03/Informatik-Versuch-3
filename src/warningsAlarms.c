#include "measurementData.h"

// Dateiname: warningsAlarms.c
// Diese Funktion überprüft wie oft die Messwerte eines Sensors die
// Alarm- und Wangrenzen über- bzw. unterschritten haben und speichert dies in einem Array ab.
// Autor:
//          Aaron Michael Weis/ 11261863
// Datum: 06.01.24

void warningsAlarms(measurementDataSort *sortMeasurementsDataArray, warningsAlarmsData *warningsAlarmsArray, int numSensors)
{
    int i = 0;               // Zählvariable
    int j = 0;               // Zählvariable
    int numWarningsHigh = 0; // Speichert wie oft die obere Warngrenze überschritten wurde
    int numWarningsLow = 0;  // Speichert wie oft die untere Warngrenzen unterschritten wurde
    int numAlarmsHigh = 0;   // Speichert wie oft die obere Alarmgrenze überschritten wurde
    int numAlarmsLow = 0;    // Speichert wie oft die untere Alarmgrenze unterschritten wurde

    for (i = 0; i < numSensors; i++)
    {
        // Variablen müssen für jeden neuen Sensor wieder auf 0 gesetzt werden
        numWarningsHigh = 0;
        numWarningsLow = 0;
        numAlarmsHigh = 0;
        numAlarmsLow = 0;
        for (j = 0; j < sortMeasurementsDataArray[i].numSensors; j++)
        {
            // Messwert wird mit Warn- und Alarmgrenzen verglichen, falls eine Grenze über- oder unterschritten wird, zählt die jeweilige Variable um 1 hoch
            if (sortMeasurementsDataArray[i].measurementData[j].measuredValue >= sortMeasurementsDataArray[i].measurementData[j].warningHigh && sortMeasurementsDataArray[i].measurementData[j].measuredValue < sortMeasurementsDataArray[i].measurementData[j].alarmHigh)
            {
                numWarningsHigh++;
            }
            if (sortMeasurementsDataArray[i].measurementData[j].measuredValue <= sortMeasurementsDataArray[i].measurementData[j].warningLow && sortMeasurementsDataArray[i].measurementData[j].measuredValue > sortMeasurementsDataArray[i].measurementData[j].alarmLow)
            {
                numWarningsLow++;
            }
            if (sortMeasurementsDataArray[i].measurementData[j].measuredValue >= sortMeasurementsDataArray[i].measurementData[j].alarmHigh)
            {
                numAlarmsHigh++;
            }
            if (sortMeasurementsDataArray[i].measurementData[j].measuredValue <= sortMeasurementsDataArray[i].measurementData[j].alarmLow)
            {
                numAlarmsLow++;
            }
        }
        // Anzahl an Über- un Unterschreitungen werden zusammen mit der Sensor-ID an das Struktur-Array übergeben
        warningsAlarmsArray[i].sensorId = sortMeasurementsDataArray[i].measurementData[0].sensorId;
        warningsAlarmsArray[i].warningsHigh = numWarningsHigh;
        warningsAlarmsArray[i].warningsLow = numWarningsLow;
        warningsAlarmsArray[i].alarmsHigh = numAlarmsHigh;
        warningsAlarmsArray[i].alarmsLow = numAlarmsLow;
    }
    return;
}