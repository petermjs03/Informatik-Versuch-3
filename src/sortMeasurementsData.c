#include "measurementData.h"

int checkID(measurementDataSort *sortMeasurementsDataArray, unsigned short sensorId, int numSensors)
{
    int j = 0;
    while (j < numSensors)
    {
        if (sortMeasurementsDataArray[j].measurementData[0].sensorId == sensorId)
        {
            return sensorId;
        }
        j++;
    }
    return -1;
}

int checkNumber(measurementDataSort *sortMeasurementsDataArray, unsigned short sensorId, int numSensors)
{
    int j = 0;
    while (j < numSensors)
    {
        if (sortMeasurementsDataArray[j].measurementData[0].sensorId == sensorId)
        {
            return j;
        }
        j++;
    }
    return -1;
}

int sortMeasurementsData(measurementDataSort *sortMeasurementsDataArray, measurementData *ptrData, int numLines)
{
    int save;
    int numSensors = 0;
    int i = 0;
    int j = 0;
    for (i = 0; i < numLines; i++)
    {
        save = checkID(sortMeasurementsDataArray, ptrData[i].sensorId, numSensors);

        if (save == -1)
        {
            sortMeasurementsDataArray[numSensors].numSensors = 1;
            sortMeasurementsDataArray[numSensors].measurementData[sortMeasurementsDataArray[numSensors].numSensors - 1] = ptrData[i];
            numSensors++;
        }
        else
        {
            j = checkNumber(sortMeasurementsDataArray, save, numSensors);
            sortMeasurementsDataArray[j].measurementData[sortMeasurementsDataArray[j].numSensors] = ptrData[i];
            sortMeasurementsDataArray[j].numSensors++;
        }
    }
    return numSensors;
}
