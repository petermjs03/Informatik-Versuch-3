#include <stdio.h>
#include "measurementData.h"

measurementData  *readData(FILE *datei, unsigned int numLines)
{
    int i=0;
    measurementData *data=(measurementData *) malloc(numLines*sizeof(measurementData));

    rewind(datei);

    for (i; i < numLines; i++)
    {
        fscanf(datei, "%d;%d;%d;%d;%d;%d\n", &data[i].sensorId, &data[i].measuredValue, &data[i].warningLow, &data[i].warningHigh, &data[i].alarmLow, &data[i].alarmHigh);
    }   

    return data;
}