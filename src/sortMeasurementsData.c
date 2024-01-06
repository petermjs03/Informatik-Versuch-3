#include "measurementData.h"

int checkID(measurementDataSort *sortMeasurementsDataArray, unsigned short sensorId, int numSensors)
{
    /*
    Eingabe: pointer auf measurementDataSort Strukt array, Sensor Id die zuprüfen ist, Anzahl an Sensoren.
    Ausgabe: sensorId wenn der Sensor schon im Array inhalten ist, sonst -1.
    */
    int j = 0; // Zähl variable
    while (j < numSensors)
    {
        if (sortMeasurementsDataArray[j].measurementData[0].sensorId == sensorId)//überprüfung ob der Sensor vorhanden ist
        {
            return sensorId;// Rückgabe der Sensor ID
        }
        j++;
    }
    return -1;//Rückgabe wenn der Sensor nicht vorhanden ist.
}

int checkNumber(measurementDataSort *sortMeasurementsDataArray, unsigned short sensorId, int numSensors)
{
    /*
    Eingabe: pointer auf measurementDataSort Strukt array, Sensor Id die zuprüfen ist, Anzahl an Sensoren.
    Ausgabe: Stelle des Sensors im Array, oder -1
    */
    int j = 0; // Zähl variable
    while (j < numSensors)
    {
        if (sortMeasurementsDataArray[j].measurementData[0].sensorId == sensorId)//überprüfung ob der Sensor vorhanden ist
        {
            return j;//Rückgabe der Stelle im Array sortMeasurementsDataArray
        }
        j++;
    }
    return -1;//Rückgabe wenn der Sensor nicht vorhanden ist.
}

int sortMeasurementsData(measurementDataSort *sortMeasurementsDataArray, measurementData *ptrData, int numLines)
{
    /*
    Eingabe: pointer auf measurementDataSort Strukt array, pointer auf unsortierten Daten Struct, Anzahl an Zeilen der eingegbenen Daten.
    Aufgabe: Sortiert die unsortierten Daten in die measurementDataSortdatenStruktur. 
    Ausgabe: Gibt die Anzahl an Sensoren zurück.
    */
    int save,j =0 ; // hilf variablen zum Zwischenstand speicher.
    int numSensors = 0; // Rückgabe Variable die, die Anzahl an Sensoren zurück gibt.

    //Schleife zum Durchlaufen aller Zeilen im unsortierten data Array.
    for (int i = 0; i < numLines; i++)
    {
        save = checkID(sortMeasurementsDataArray, ptrData[i].sensorId, numSensors);// Überprüfung der ID

        if (save == -1)//safe ist -1 wenn die sensor Id noch nicht im neuen Array vorhanden ist.
        {   
            //Ein neuer Eintrag wird im Array angelegt.
            sortMeasurementsDataArray[numSensors].numSensors = 1;// Die Anzahl an Sensoren wird im neuen Eintrag auf 1 gesetzt
            //Die restlichen Daten werden übertragen.
            sortMeasurementsDataArray[numSensors].measurementData[sortMeasurementsDataArray[numSensors].numSensors - 1] = ptrData[i];
            numSensors++;
        }
        else
        {

            j = checkNumber(sortMeasurementsDataArray, save, numSensors);// Die anstelle an dem der Sensor schon einträge hat wird ermittelt.
            //Ein nächster Eintrag wird getätigt.
            sortMeasurementsDataArray[j].measurementData[sortMeasurementsDataArray[j].numSensors] = ptrData[i];
            //die Anzahl an einträgen wird vergrößert.
            sortMeasurementsDataArray[j].numSensors++;
        }
    }
    return numSensors;
}
