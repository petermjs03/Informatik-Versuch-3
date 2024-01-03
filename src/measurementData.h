#ifndef MEASUREMENTDATA_H
#define MEASUREMENTDATA_H
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    unsigned short sensorId;
    int measuredValue;
    int warningLow;
    int warningHigh;
    int alarmLow;
    int alarmHigh;

} measurementData;

typedef struct
{
    measurementData measurementData[100];
    int numSensors;
} measurementDataSort;

typedef struct
{
    unsigned short sensorId;
    int warningsLow;
    int warningsHigh;
    int alarmsLow;
    int alarmsHigh;

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