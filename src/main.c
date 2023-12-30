#include <stdio.h>
#include "measurementData.h"

int main()
{
    FILE *datei;
    measurementData *ptrData=NULL;
    measurementDataSort *sortMeasurementsDataArray;
    datei=fopen("processData.txt","r");

    unsigned int numLine=numLines(datei);

    printf("\n%d\n", numLine);

    ptrData = readData(datei, numLine);

    fclose(datei);

    for (int i = 0; i < numLine; i++)
    {
        printf("%d;%d;%d;%d;%d;%d\n", ptrData[i].sensorId, ptrData[i].measuredValue, ptrData[i].warningLow, ptrData[i].warningHigh, ptrData[i].alarmLow, ptrData[i].alarmHigh);
    }

    sortMeasurementsData(sortMeasurementsDataArray,ptrData,numLine);

    while (1)
    {}
    return 0;
}
