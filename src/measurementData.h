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

void sortMeasurementsData(measurementDataSort *sortMeasurementsDataArray,measurementData *ptrData, int numLines);

measurementData  *readData(FILE *datei, unsigned int numLines);

unsigned int numLines(FILE *datei);

#endif