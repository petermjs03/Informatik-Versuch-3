#include "measurementData.h"

// Dateiname: medianValue.c
// Diese Funktion berechnet den Median aus drei aufeinander folgenden Messwerten
// und speichert diesen in einem neuen Array. Es werden ebenfalls alle Sensordaten an das neue Array übergeben.
// Autor:
//          Aaron Michael Weis/ 11261863
// Datum: 06.01.24

void medianValue(measurementDataSort *sortMeasurementsDataArray, measurementDataSort *sortMedianMeasurementsDataArray, int numSensors)
{

    int i = 0;      // Zählvariable
    int j = 0;      // Zählvariable
    int median = 0; // Speichert den Medianwert

    for (i = 0; i < numSensors; i++)
    {
        sortMedianMeasurementsDataArray[i].numSensors = sortMeasurementsDataArray[i].numSensors / 3; // Die Anzahl der Messwerte im neuen Array ist um den Faktor 1/3 kleiner als im alten

        for (j = 0; j < (sortMeasurementsDataArray[i].numSensors); j += 3)
        {
            // Median Bestimmung
            if (sortMeasurementsDataArray[i].measurementData[j].measuredValue >= sortMeasurementsDataArray[i].measurementData[j + 1].measuredValue && sortMeasurementsDataArray[i].measurementData[j].measuredValue <= sortMeasurementsDataArray[i].measurementData[j + 2].measuredValue)
            {
                median = sortMeasurementsDataArray[i].measurementData[j].measuredValue;
            }
            if (sortMeasurementsDataArray[i].measurementData[j].measuredValue <= sortMeasurementsDataArray[i].measurementData[j + 1].measuredValue && sortMeasurementsDataArray[i].measurementData[j].measuredValue >= sortMeasurementsDataArray[i].measurementData[j + 2].measuredValue)
            {
                median = sortMeasurementsDataArray[i].measurementData[j].measuredValue;
            }
            if (sortMeasurementsDataArray[i].measurementData[j + 1].measuredValue >= sortMeasurementsDataArray[i].measurementData[j].measuredValue && sortMeasurementsDataArray[i].measurementData[j + 1].measuredValue <= sortMeasurementsDataArray[i].measurementData[j + 2].measuredValue)
            {
                median = sortMeasurementsDataArray[i].measurementData[j + 1].measuredValue;
            }
            if (sortMeasurementsDataArray[i].measurementData[j + 1].measuredValue <= sortMeasurementsDataArray[i].measurementData[j].measuredValue && sortMeasurementsDataArray[i].measurementData[j + 1].measuredValue >= sortMeasurementsDataArray[i].measurementData[j + 2].measuredValue)
            {
                median = sortMeasurementsDataArray[i].measurementData[j + 1].measuredValue;
            }
            if (sortMeasurementsDataArray[i].measurementData[j + 2].measuredValue >= sortMeasurementsDataArray[i].measurementData[j].measuredValue && sortMeasurementsDataArray[i].measurementData[j + 2].measuredValue <= sortMeasurementsDataArray[i].measurementData[j + 1].measuredValue)
            {
                median = sortMeasurementsDataArray[i].measurementData[j + 2].measuredValue;
            }
            if (sortMeasurementsDataArray[i].measurementData[j + 2].measuredValue <= sortMeasurementsDataArray[i].measurementData[j].measuredValue && sortMeasurementsDataArray[i].measurementData[j + 2].measuredValue >= sortMeasurementsDataArray[i].measurementData[j + 1].measuredValue)
            {
                median = sortMeasurementsDataArray[i].measurementData[j + 2].measuredValue;
            }

            // Median und Sensordaten werden an das neue Array übergeben
            sortMedianMeasurementsDataArray[i].measurementData[j / 3].measuredValue = median;
            sortMedianMeasurementsDataArray[i].measurementData[j / 3].alarmHigh = sortMeasurementsDataArray[i].measurementData[j].alarmHigh;
            sortMedianMeasurementsDataArray[i].measurementData[j / 3].alarmLow = sortMeasurementsDataArray[i].measurementData[j].alarmLow;
            sortMedianMeasurementsDataArray[i].measurementData[j / 3].warningHigh = sortMeasurementsDataArray[i].measurementData[j].warningHigh;
            sortMedianMeasurementsDataArray[i].measurementData[j / 3].warningLow = sortMeasurementsDataArray[i].measurementData[j].warningLow;
            sortMedianMeasurementsDataArray[i].measurementData[j / 3].sensorId = sortMeasurementsDataArray[i].measurementData[j].sensorId;
        }
    }
}
