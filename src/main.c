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
    int numLine = 0;
    int i = 0;
    int mode = 1;

    datei = fopen("processData3.txt", "r");

    numLine = numLines(datei);

    ptrData = (measurementData *)malloc(numLine * sizeof(measurementData));
    readData(datei, numLine, ptrData);
    fclose(datei);

    sortMeasurementsDataArray = (measurementDataSort *)malloc(numLine * sizeof(measurementDataSort));
    numSensors = sortMeasurementsData(sortMeasurementsDataArray, ptrData, numLine);

    free(ptrData);

    sortMeasurementsDataArray = (measurementDataSort *)realloc(sortMeasurementsDataArray, numSensors * sizeof(measurementDataSort));

    while (mode == 1)
    {
        warningsAlarmsArray = (warningsAlarmsData *)malloc(numSensors * sizeof(warningsAlarmsData));
        
        printf("\n*Messdatenauswertung*\n\n");
        printf("Möchten Sie die tatsächlichen, die Mittwert-gefilterten oder die Median-geflterten Messwerte auswerten?\nGeben Sie 1 für tatsächliche, 2 für Mittwert-gefilterte oder 3 für Median-gefilterterte ein: ");
        scanf("%d", &mode);

        switch (mode)
        {
        case 1:
            warningsAlarms(sortMeasurementsDataArray, warningsAlarmsArray, numSensors);

            for (i = 0; i < numSensors; i++)
            {
                printf("\n\nSensor-ID: %d\nUnterschreitungen der unteren Warngrenze: %d\nÜberschreitungen der oberen Warngrenze: %d\nUnterschreitungen der unteren Alarmgrenze: %d\nÜberschreitungen der oberen Alarmgrenze: %d\n", warningsAlarmsArray[i].sensorId, warningsAlarmsArray[i].warningsLow, warningsAlarmsArray[i].warningsHigh, warningsAlarmsArray[i].alarmsLow, warningsAlarmsArray[i].alarmsHigh);
            }

            printf("\n\nGeben Sie die 1 für einen Neustart ein oder einen anderen Wert, um das Programm zu beenden: ");
            scanf("%d", &mode);

            free(warningsAlarmsArray);

            break;

        case 2:
            sortAverageMeasurementsDataArray = (measurementDataSort *)malloc(numSensors * sizeof(measurementDataSort));
            averageValue(sortMeasurementsDataArray, sortAverageMeasurementsDataArray, numSensors);
            warningsAlarms(sortAverageMeasurementsDataArray, warningsAlarmsArray, numSensors);

            for (i = 0; i < numSensors; i++)
            {
                printf("\n\nSensor-ID: %d\nUnterschreitungen der unteren Warngrenze: %d\nÜberschreitungen der oberen Warngrenze: %d\nUnterschreitungen der unteren Alarmgrenze: %d\nÜberschreitungen der oberen Alarmgrenze: %d\n", warningsAlarmsArray[i].sensorId, warningsAlarmsArray[i].warningsLow, warningsAlarmsArray[i].warningsHigh, warningsAlarmsArray[i].alarmsLow, warningsAlarmsArray[i].alarmsHigh);
            }

            printf("\n\nGeben Sie die 1 für einen Neustart ein oder einen anderen Wert, um das Programm zu beenden: ");
            scanf("%d", &mode);

            free(warningsAlarmsArray);
            free(sortAverageMeasurementsDataArray);

            break;

        case 3:
            sortMedianMeasurementsDataArray = (measurementDataSort *)malloc(numSensors * sizeof(measurementDataSort));
            medianValue(sortMeasurementsDataArray, sortMedianMeasurementsDataArray, numSensors);
            warningsAlarms(sortMedianMeasurementsDataArray, warningsAlarmsArray, numSensors);

            for (i = 0; i < numSensors; i++)
            {
                printf("\n\nSensor-ID: %d\nUnterschreitungen der unteren Warngrenze: %d\nÜberschreitungen der oberen Warngrenze: %d\nUnterschreitungen der unteren Alarmgrenze: %d\nÜberschreitungen der oberen Alarmgrenze: %d\n", warningsAlarmsArray[i].sensorId, warningsAlarmsArray[i].warningsLow, warningsAlarmsArray[i].warningsHigh, warningsAlarmsArray[i].alarmsLow, warningsAlarmsArray[i].alarmsHigh);
            }

            printf("\n\nGeben Sie die 1 für einen Neustart ein oder einen anderen Wert, um das Programm zu beenden: ");
            scanf("%d", &mode);
            
            free(warningsAlarmsArray);
            free(sortMedianMeasurementsDataArray);

            break;

        default:
            printf("\n*Ungültige Eingabe*\n\nGeben Sie die 1 für einen Neustart ein oder einen anderen Wert, um das Programm zu beenden: ");
            scanf("%d", &mode);
    
            break;
        }
    }
    free(sortMeasurementsDataArray);

    return 0;
}
