#include <stdio.h>
#include "measurementData.h"

void readData(FILE *datei, unsigned int numLines, measurementData *ptrData)
{
    int i = 0;

    rewind(datei);

    for (i; i < numLines; i++)
    {
        fscanf(datei, "%d;%d;%d;%d;%d;%d\n", &ptrData[i].sensorId, &ptrData[i].measuredValue, &ptrData[i].warningLow, &ptrData[i].warningHigh, &ptrData[i].alarmLow, &ptrData[i].alarmHigh);
    }

    return;
}