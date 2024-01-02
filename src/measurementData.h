#ifndef MEASUREMENTDATA_H
#define MEASUREMENTDATA_H
#include <stdlib.h>

typedef struct
{
    unsigned short sensorId;
    unsigned short measuredValue;
    unsigned short warningLow;
    unsigned short warningHigh;
    unsigned short alarmLow;
    unsigned short alarmHigh;

} measurementData;

typedef struct
{
    measurementData measurementData[100];
    int numSensors;
}measurementDataSort;

typedef struct
{
    unsigned short sensorId;
    unsigned short warningsLow;
    unsigned short warningsHigh;
    unsigned short alarmsLow;
    unsigned short alarmsHigh;

} warningsAlarmsData;

int sortMeasurementsData(measurementDataSort *sortMeasurementsDataArray,measurementData *ptrData, int numLines);

void readData(FILE *datei, unsigned int numLines, measurementData *ptrData);

unsigned int numLines(FILE *datei);

void warningsAlarms(measurementDataSort *sortMeasurementsDataArray, warningsAlarmsData *warningsAlarmsArray, int numSensors);

#endif