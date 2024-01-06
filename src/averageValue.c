#include "measurementData.h"

// Dateiname: averageValue.c
// Diese Funktion berechnet den Durchschnitt aus drei aufeinander folgenden Messwerten
// und speichert diesen in einem neuen Array. Es werden ebenfalls alle Sensordaten an das neue Array übergeben.
// Autor:
//          Aaron Michael Weis/ 11261863
// Datum: 06.01.24

void averageValue(measurementDataSort *sortMeasurementsDataArray, measurementDataSort *sortAverageMeasurementsDataArray, int numSensors)
{

    int i = 0; // Zählvariable
    int j = 0; // Zählvariable

    for (i = 0; i < numSensors; i++)
    {
        sortAverageMeasurementsDataArray[i].numSensors = sortMeasurementsDataArray[i].numSensors / 3; // Die Anzahl der Messwerte im neuen Array ist um den Faktor 1/3 kleiner als im alten

        for (j = 0; j < (sortMeasurementsDataArray[i].numSensors); j += 3)
        {
            // Berechnung und Speichern des Durchschnitts
            sortAverageMeasurementsDataArray[i].measurementData[j / 3].measuredValue = (sortMeasurementsDataArray[i].measurementData[j].measuredValue + sortMeasurementsDataArray[i].measurementData[j + 1].measuredValue + sortMeasurementsDataArray[i].measurementData[j + 2].measuredValue) / 3;

            // Sensordaten werden übergeben
            sortAverageMeasurementsDataArray[i].measurementData[j / 3].alarmHigh = sortMeasurementsDataArray[i].measurementData[j].alarmHigh;
            sortAverageMeasurementsDataArray[i].measurementData[j / 3].alarmLow = sortMeasurementsDataArray[i].measurementData[j].alarmLow;
            sortAverageMeasurementsDataArray[i].measurementData[j / 3].warningHigh = sortMeasurementsDataArray[i].measurementData[j].warningHigh;
            sortAverageMeasurementsDataArray[i].measurementData[j / 3].warningLow = sortMeasurementsDataArray[i].measurementData[j].warningLow;
            sortAverageMeasurementsDataArray[i].measurementData[j / 3].sensorId = sortMeasurementsDataArray[i].measurementData[j].sensorId;
        }
    }
}