#include "measurementData.h"

// Dateiname: measurementData.c
// Dieses Programm wertete die Messdaten verschiedener Sensoren aus der Datei processData.txt aus.
// Es gibt die Anzahl an Warn- und Alarmgrenzen Über- und Unterschreitungen aus.
// Dabei kann der Nutzer aus drei Auswertungsmöglichkeiten entscheiden, der tatsächlichen Messwertauswertung,
// der median-gefilterten Messwertauswertung und der Mittwert-gefilterten Messwertauswertung.
// Autoren:
//          Aaron Michael Weis/ 11261863,
//          Peter Wienken/      11286202,
//          Peter Majoros/      11277532
// Version: 1.0
// Datum: 06.01.24

int main()
{
    FILE *datei;                                                  // Datei pointer
    measurementData *ptrData = NULL;                              // Sensordaten und Messwert pointer
    measurementDataSort *sortMeasurementsDataArray = NULL;        // Sortierter Sensordaten und Messwert pointer
    warningsAlarmsData *warningsAlarmsArray = NULL;               // Warn- und Alarmgrenzen pointer
    measurementDataSort *sortAverageMeasurementsDataArray = NULL; // Sortierte Mittwert-gefilterte Sensordaten und Messwert pointer
    measurementDataSort *sortMedianMeasurementsDataArray = NULL;  // Sortierte Medianwert-gefilterte Sensordaten und Messwert pointer
    int numSensors = 0;                                           // Anzahl an verschiedenen Sensor-IDs
    int numLine = 0;                                              // Anzahl an Sensordaten
    int i = 0;                                                    // Zählvariable
    int mode = 1;                                                 // Gibt an welche Messwertauswertung verwendet werden soll

    datei = fopen("processData.txt", "r"); // Datei processData.txt wird im lese-Modus geöffnet und Datei-pointer zeigt auf die Datei

    numLine = numLines(datei); // Anzahl an Sensordaten wird ermittelt und gespeichert

    ptrData = (measurementData *)malloc(numLine * sizeof(measurementData)); // Dynamische Speicherzuweisung auf passende Größe für die Anzahl an Sensordaten
    readData(datei, numLine, ptrData);                                      // Sensordaten werden eingelesen und gespeichert
    fclose(datei);                                                          // Dateistream wird geschlossen

    sortMeasurementsDataArray = (measurementDataSort *)malloc(numLine * sizeof(measurementDataSort)); // Dynamische Speicherzuweisung auf passende Größe für die Anzahl an Sensordaten

    // Dynamische Speicherzuweisung auf passende Größe für die Anzahl an Sensordaten
    for (i = 0; i < numLine; i++)
    {
        sortMeasurementsDataArray[i].measurementData = (measurementData *)malloc(numLine * sizeof(measurementData));
    }
    numSensors = sortMeasurementsData(sortMeasurementsDataArray, ptrData, numLine);

    // Speicher wird auf die nötige Größe reduziert
    for (i = 0; i < numSensors; i++)
    {
        sortMeasurementsDataArray[i].measurementData = (measurementData *)realloc(sortMeasurementsDataArray[i].measurementData, sortMeasurementsDataArray[i].numSensors * sizeof(measurementData));
    }

    free(ptrData); // Speicher freigeben

    sortMeasurementsDataArray = (measurementDataSort *)realloc(sortMeasurementsDataArray, numSensors * sizeof(measurementDataSort)); // Speicher wird auf die nötige Größe reduziert

    // Messdatenauswertung
    // Benutzer kann zwischen 3 Messdatenauswertungen wählen
    while (mode == 1)
    {
        warningsAlarmsArray = (warningsAlarmsData *)malloc(numSensors * sizeof(warningsAlarmsData)); // Dynamische Speicherzuweisung auf passende Größe für die Anzahl an Sensor-IDs

        // Modiauswahl
        printf("\n*Messdatenauswertung*\n\n");
        printf("Möchten Sie die tatsächlichen, die Mittwert-gefilterten oder die Median-geflterten Messwerte auswerten?\nGeben Sie 1 für tatsächliche, 2 für Mittwert-gefilterte oder 3 für Median-gefilterterte ein: ");
        scanf("%d", &mode);

        switch (mode)
        {
        case 1:
            warningsAlarms(sortMeasurementsDataArray, warningsAlarmsArray, numSensors); // Warn- und Alarmgrenzen Über- und Unterschreitungen werden ausgewertet

            // Ausgabe
            for (i = 0; i < numSensors; i++)
            {
                printf("\n\nSensor-ID: %d\nUnterschreitungen der unteren Warngrenze: %d\nÜberschreitungen der oberen Warngrenze: %d\nUnterschreitungen der unteren Alarmgrenze: %d\nÜberschreitungen der oberen Alarmgrenze: %d\n", warningsAlarmsArray[i].sensorId, warningsAlarmsArray[i].warningsLow, warningsAlarmsArray[i].warningsHigh, warningsAlarmsArray[i].alarmsLow, warningsAlarmsArray[i].alarmsHigh);
            }

            // Abfrage ob das Programm wiederholt werden soll
            printf("\n\nGeben Sie die 1 für einen Neustart ein oder einen anderen Wert, um das Programm zu beenden: ");
            scanf("%d", &mode);

            // Speicher freigabe
            free(warningsAlarmsArray);

            break;

        case 2:
            sortAverageMeasurementsDataArray = (measurementDataSort *)malloc(numSensors * sizeof(measurementDataSort)); // Dynamische Speicherzuweisung auf passende Größe für die Anzahl an Sensor-IDs
            // Dynamische Speicherzuweisung auf passende Größe für die Anzahl an Sensordaten
            for (i = 0; i < numSensors; i++)
            {
                sortAverageMeasurementsDataArray[i].measurementData = (measurementData *)malloc((sortMeasurementsDataArray[i].numSensors / 3) * sizeof(measurementData));
            }
            averageValue(sortMeasurementsDataArray, sortAverageMeasurementsDataArray, numSensors); // Mittwerte der Messdaten werden bestimmt
            warningsAlarms(sortAverageMeasurementsDataArray, warningsAlarmsArray, numSensors);     // Warn- und Alarmgrenzen Über- und Unterschreitungen werden ausgewertet

            // Ausgabe
            for (i = 0; i < numSensors; i++)
            {
                printf("\n\nSensor-ID: %d\nUnterschreitungen der unteren Warngrenze: %d\nÜberschreitungen der oberen Warngrenze: %d\nUnterschreitungen der unteren Alarmgrenze: %d\nÜberschreitungen der oberen Alarmgrenze: %d\n", warningsAlarmsArray[i].sensorId, warningsAlarmsArray[i].warningsLow, warningsAlarmsArray[i].warningsHigh, warningsAlarmsArray[i].alarmsLow, warningsAlarmsArray[i].alarmsHigh);
            }

            // Abfrage ob das Programm wiederholt werden soll
            printf("\n\nGeben Sie die 1 für einen Neustart ein oder einen anderen Wert, um das Programm zu beenden: ");
            scanf("%d", &mode);

            // Speicher freigabe
            free(warningsAlarmsArray);
            free(sortAverageMeasurementsDataArray);

            break;

        case 3:
            sortMedianMeasurementsDataArray = (measurementDataSort *)malloc(numSensors * sizeof(measurementDataSort)); // Dynamische Speicherzuweisung auf passende Größe für die Anzahl an Sensor-IDs
            // Dynamische Speicherzuweisung auf passende Größe für die Anzahl an Sensordaten
            for (i = 0; i < numSensors; i++)
            {
                sortMedianMeasurementsDataArray[i].measurementData = (measurementData *)malloc((sortMeasurementsDataArray[i].numSensors / 3) * sizeof(measurementData));
            }
            medianValue(sortMeasurementsDataArray, sortMedianMeasurementsDataArray, numSensors); // Medianwerte der Messdaten werden bestimmt
            warningsAlarms(sortMedianMeasurementsDataArray, warningsAlarmsArray, numSensors);    // Warn- und Alarmgrenzen Über- und Unterschreitungen werden ausgewertet

            // Ausgabe
            for (i = 0; i < numSensors; i++)
            {
                printf("\n\nSensor-ID: %d\nUnterschreitungen der unteren Warngrenze: %d\nÜberschreitungen der oberen Warngrenze: %d\nUnterschreitungen der unteren Alarmgrenze: %d\nÜberschreitungen der oberen Alarmgrenze: %d\n", warningsAlarmsArray[i].sensorId, warningsAlarmsArray[i].warningsLow, warningsAlarmsArray[i].warningsHigh, warningsAlarmsArray[i].alarmsLow, warningsAlarmsArray[i].alarmsHigh);
            }

            // Abfrage ob das Programm wiederholt werden soll
            printf("\n\nGeben Sie die 1 für einen Neustart ein oder einen anderen Wert, um das Programm zu beenden: ");
            scanf("%d", &mode);

            // Speicher freigabe
            free(warningsAlarmsArray);
            free(sortMedianMeasurementsDataArray);

            break;

        default:
            // Error Meldung und Abfrage ob das Programm wiederholt werden soll
            printf("\n*Ungültige Eingabe*\n\nGeben Sie die 1 für einen Neustart ein oder einen anderen Wert, um das Programm zu beenden: ");
            scanf("%d", &mode);

            break;
        }
    }
    // Speicher freigabe
    free(sortMeasurementsDataArray);

    return 0;
}
