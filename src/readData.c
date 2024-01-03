#include "measurementData.h"

void readData(FILE *datei, int numLines, measurementData *ptrData)
{
    int i = 0;

    rewind(datei);

    for (i = 0; i < numLines; i++)
    {
        fscanf(datei, "%hd;%d;%d;%d;%d;%d\n", &ptrData[i].sensorId, &ptrData[i].measuredValue, &ptrData[i].warningLow, &ptrData[i].warningHigh, &ptrData[i].alarmLow, &ptrData[i].alarmHigh);
    }

    return;
}