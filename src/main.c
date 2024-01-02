#include <stdio.h>
#include "measurementData.h"

int main()
{
    FILE *datei;
    measurementData *ptrData = NULL;
    measurementDataSort *sortMeasurementsDataArray = NULL;
    warningsAlarmsData *warningsAlarmsArray = NULL;
    measurementDataSort *sortAverageMeasurementsDataArray = NULL;
    measurementDataSort *sortMedianMeasurementsDataArray = NULL;
    int numSensors = 0;
    unsigned int numLine = 0;

    datei = fopen("processData2.txt", "r");

    numLine = numLines(datei);

    ptrData = (measurementData *)malloc(numLine * sizeof(measurementData));
    sortMeasurementsDataArray = (measurementDataSort *)malloc(numLine * sizeof(measurementDataSort));

    printf("\n%d\n", numLine);

    readData(datei, numLine, ptrData);

    fclose(datei);

    for (int i = 0; i < numLine; i++)
    {
        printf("%d;%d;%d;%d;%d;%d\n", ptrData[i].sensorId, ptrData[i].measuredValue, ptrData[i].warningLow, ptrData[i].warningHigh, ptrData[i].alarmLow, ptrData[i].alarmHigh);
    }

    numSensors = sortMeasurementsData(sortMeasurementsDataArray, ptrData, numLine);

    free(ptrData);

    sortMeasurementsDataArray = (measurementDataSort *)realloc(sortMeasurementsDataArray, numSensors * sizeof(measurementDataSort));
    warningsAlarmsArray = (warningsAlarmsData *)malloc(numSensors * sizeof(warningsAlarmsData));
    sortAverageMeasurementsDataArray = (measurementDataSort *)malloc(numSensors * sizeof(measurementDataSort));
    sortMedianMeasurementsDataArray = (measurementDataSort *)malloc(numSensors * sizeof(measurementDataSort));

    averageValue(sortMeasurementsDataArray, sortAverageMeasurementsDataArray, numSensors);
    medianValue(sortMeasurementsDataArray, sortMedianMeasurementsDataArray, numSensors);
    warningsAlarms(sortMeasurementsDataArray, warningsAlarmsArray, numSensors);

    free(sortMeasurementsDataArray);
    free(warningsAlarmsArray);
    free(sortAverageMeasurementsDataArray);
    free(sortMedianMeasurementsDataArray);

    return 0;
}
