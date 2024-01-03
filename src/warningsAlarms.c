#include "measurementData.h"

void warningsAlarms(measurementDataSort *sortMeasurementsDataArray, warningsAlarmsData *warningsAlarmsArray, int numSensors)
{
    int i = 0;
    int j = 0;
    int numWarningsHigh = 0;
    int numWarningsLow = 0;
    int numAlarmsHigh = 0;
    int numAlarmsLow = 0;

    for (i = 0; i < numSensors; i++)
    {
        numWarningsHigh = 0;
        numWarningsLow = 0;
        numAlarmsHigh = 0;
        numAlarmsLow = 0;
        for (j = 0; j < sortMeasurementsDataArray[i].numSensors; j++)
        {
            if (sortMeasurementsDataArray[i].measurementData[j].measuredValue >= sortMeasurementsDataArray[i].measurementData[j].warningHigh && sortMeasurementsDataArray[i].measurementData[j].measuredValue < sortMeasurementsDataArray[i].measurementData[j].alarmHigh)
            {
                numWarningsHigh++;
            }
            if (sortMeasurementsDataArray[i].measurementData[j].measuredValue <= sortMeasurementsDataArray[i].measurementData[j].warningLow && sortMeasurementsDataArray[i].measurementData[j].measuredValue > sortMeasurementsDataArray[i].measurementData[j].alarmLow)
            {
                numWarningsLow++;
            }
            if (sortMeasurementsDataArray[i].measurementData[j].measuredValue >= sortMeasurementsDataArray[i].measurementData[j].alarmHigh)
            {
                numAlarmsHigh++;
            }
            if (sortMeasurementsDataArray[i].measurementData[j].measuredValue <= sortMeasurementsDataArray[i].measurementData[j].alarmLow)
            {
                numAlarmsLow++;
            }
        }
        warningsAlarmsArray[i].sensorId = sortMeasurementsDataArray[i].measurementData[0].sensorId;
        warningsAlarmsArray[i].warningsHigh = numWarningsHigh;
        warningsAlarmsArray[i].warningsLow = numWarningsLow;
        warningsAlarmsArray[i].alarmsHigh = numAlarmsHigh;
        warningsAlarmsArray[i].alarmsLow = numAlarmsLow;
    }
    return;
}