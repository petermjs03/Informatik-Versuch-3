#ifndef MEASUREMENTDATA_H
#define MEASUREMENTDATA_H
#include <stdlib.h>
#include <stdio.h>

// Dateiname: measurementData.h
// Headerdatei für die Messdatenauswertung
// Autoren:
//          Aaron Michael Weis/ 11261863,
//          Peter Wienken/      11286202,
//          Peter Majoros/      11277532
// Datum: 06.01.24

// In dieser Struktur werden die Sensor- und Messdaten gespeichert
typedef struct
{
    unsigned short sensorId; // Speichert die Sensor-ID
    int measuredValue;       // Speichert den Messwert
    int warningLow;          // Speichert die untere Warngrenze
    int warningHigh;         // Speichert die obere Warngrenze
    int alarmLow;            // Speichert die untere Alarmgrenze
    int alarmHigh;           // Speichert die obere Alarmgrenze

} measurementData;

// In dieser Struktur werden die sortierten Sensordaten gespeichert
typedef struct
{
    measurementData *measurementData;
    int numSensors;
    // Speichert die Anzahl an Messwerten pro Sensor
} measurementDataSort;

// In dieser Struktur werden die Warn- und Alarmgrenzen Über- und Unterschreitungen gespeichert
typedef struct
{
    unsigned short sensorId; // Speichert die Sensor-ID
    int warningsLow;         // Speichert wie oft die untere Warngrenzen unterschritten wurde
    int warningsHigh;        // Speichert wie oft die obere Warngrenze überschritten wurde
    int alarmsLow;           // Speichert wie oft die untere Alarmgrenze unterschritten wurde
    int alarmsHigh;          // Speichert wie oft die obere Alarmgrenze überschritten wurde

} warningsAlarmsData;

int sortMeasurementsData(measurementDataSort *sortMeasurementsDataArray, measurementData *ptrData, int numLines);

int checkID(measurementDataSort *sortMeasurementsDataArray, unsigned short sensorId, int numSensors);

int checkNumber(measurementDataSort *sortMeasurementsDataArray, unsigned short sensorId, int numSensors);

void readData(FILE *datei, int numLines, measurementData *ptrData);

int numLines(FILE *datei);

void warningsAlarms(measurementDataSort *sortMeasurementsDataArray, warningsAlarmsData *warningsAlarmsArray, int numSensors);

void averageValue(measurementDataSort *sortMeasurementsDataArray, measurementDataSort *sortAverageMeasurementsDataArray, int numSensors);

void medianValue(measurementDataSort *sortMeasurementsDataArray, measurementDataSort *sortAverageMeasurementsDataArray, int numSensors);

#endif