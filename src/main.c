#include <stdio.h>
#include "measurementData.h"

int main()
{
    FILE *datei;
    measurementData *ptrData=NULL;
    measurementDataSort *sortMeasurementsDataArray=NULL;
    int numSensors;

    datei=fopen("processData.txt","r");

    unsigned int numLine=numLines(datei);

    ptrData = (measurementData *) malloc(numLine*sizeof(measurementData));
    sortMeasurementsDataArray = (measurementData *) malloc(numLine*sizeof(measurementData));

    printf("\n%d\n", numLine);

    readData(datei, numLine, ptrData);

    fclose(datei);

    for (int i = 0; i < numLine; i++)
    {
        printf("%d;%d;%d;%d;%d;%d\n", ptrData[i].sensorId, ptrData[i].measuredValue, ptrData[i].warningLow, ptrData[i].warningHigh, ptrData[i].alarmLow, ptrData[i].alarmHigh);
    }

    numSensors = sortMeasurementsData(sortMeasurementsDataArray,ptrData,numLine);
    sortMeasurementsDataArray = (measurementDataSort*) realloc(sortMeasurementsDataArray,numSensors*sizeof(measurementDataSort));


    free(sortMeasurementsDataArray);
    free(ptrData);
    return 0;
}
