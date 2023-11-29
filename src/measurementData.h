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
    unsigned short sensorId;
    unsigned short *measuredValue;
    unsigned short warningLow;
    unsigned short warningHigh;
    unsigned short alarmLow;
    unsigned short alarmHigh;

} sortedData;

unsigned int numLines(FILE *datei);
measurementData  *readData(FILE *datei, unsigned int numLines);

#endif