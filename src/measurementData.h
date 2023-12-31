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

int sortMeasurementsData(measurementDataSort *sortMeasurementsDataArray,measurementData *ptrData, int numLines);

void readData(FILE *datei, unsigned int numLines, measurementData *ptrData);

unsigned int numLines(FILE *datei);

int alarmsHigh(measurementDataSort *sortMeasurementsDataArray, int numSensors);
int alarmsLow(measurementDataSort *sortMeasurementsDataArray, int numSensors);
int warningsHigh(measurementDataSort *sortMeasurementsDataArray, int numSensors);
int warningsLow(measurementDataSort *sortMeasurementsDataArray, int numSensors);

#endif