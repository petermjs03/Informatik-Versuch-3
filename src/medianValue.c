#include <stdio.h>
#include "measurementData.h"

void medianValue(measurementDataSort *sortMeasurementsDataArray, measurementDataSort *sortAverageMeasurementsDataArray, int numSensors)
{

    int i = 0;
    int j = 0;
    int median = 0;

    for (i = 0; i < numSensors; i++)
    {
        sortAverageMeasurementsDataArray[i].numSensors = sortMeasurementsDataArray[i].numSensors / 3;

        for (j = 0; j < (sortMeasurementsDataArray[i].numSensors); j += 3)
        {
            if (sortMeasurementsDataArray[i].measurementData[j].measuredValue >= sortMeasurementsDataArray[i].measurementData[j + 1].measuredValue && sortMeasurementsDataArray[i].measurementData[j].measuredValue <= sortMeasurementsDataArray[i].measurementData[j + 2].measuredValue)
            {
                median = sortMeasurementsDataArray[i].measurementData[j].measuredValue;
            }
            if (sortMeasurementsDataArray[i].measurementData[j].measuredValue <= sortMeasurementsDataArray[i].measurementData[j + 1].measuredValue && sortMeasurementsDataArray[i].measurementData[j].measuredValue >= sortMeasurementsDataArray[i].measurementData[j + 2].measuredValue)
            {
                median = sortMeasurementsDataArray[i].measurementData[j].measuredValue;
            }
            if (sortMeasurementsDataArray[i].measurementData[j + 1].measuredValue >= sortMeasurementsDataArray[i].measurementData[j].measuredValue && sortMeasurementsDataArray[i].measurementData[j + 1].measuredValue <= sortMeasurementsDataArray[i].measurementData[j + 2].measuredValue)
            {
                median = sortMeasurementsDataArray[i].measurementData[j + 1].measuredValue;
            }
            if (sortMeasurementsDataArray[i].measurementData[j + 1].measuredValue <= sortMeasurementsDataArray[i].measurementData[j].measuredValue && sortMeasurementsDataArray[i].measurementData[j + 1].measuredValue >= sortMeasurementsDataArray[i].measurementData[j + 2].measuredValue)
            {
                median = sortMeasurementsDataArray[i].measurementData[j + 1].measuredValue;
            }
            if (sortMeasurementsDataArray[i].measurementData[j + 2].measuredValue >= sortMeasurementsDataArray[i].measurementData[j].measuredValue && sortMeasurementsDataArray[i].measurementData[j + 2].measuredValue <= sortMeasurementsDataArray[i].measurementData[j + 1].measuredValue)
            {
                median = sortMeasurementsDataArray[i].measurementData[j + 2].measuredValue;
            }
            if (sortMeasurementsDataArray[i].measurementData[j + 2].measuredValue <= sortMeasurementsDataArray[i].measurementData[j].measuredValue && sortMeasurementsDataArray[i].measurementData[j + 2].measuredValue >= sortMeasurementsDataArray[i].measurementData[j + 1].measuredValue)
            {
                median = sortMeasurementsDataArray[i].measurementData[j + 2].measuredValue;
            }

            sortAverageMeasurementsDataArray[i].measurementData[j / 3].measuredValue = median;
            sortAverageMeasurementsDataArray[i].measurementData[j / 3].alarmHigh = sortMeasurementsDataArray[i].measurementData[j].alarmHigh;
            sortAverageMeasurementsDataArray[i].measurementData[j / 3].alarmLow = sortMeasurementsDataArray[i].measurementData[j].alarmLow;
            sortAverageMeasurementsDataArray[i].measurementData[j / 3].warningHigh = sortMeasurementsDataArray[i].measurementData[j].warningHigh;
            sortAverageMeasurementsDataArray[i].measurementData[j / 3].warningLow = sortMeasurementsDataArray[i].measurementData[j].warningLow;
            sortAverageMeasurementsDataArray[i].measurementData[j / 3].sensorId = sortMeasurementsDataArray[i].measurementData[j].sensorId;
        }
    }
}
