#include <stdio.h>
#include "measurementData.h"

measurementDataSort *expandArray(measurementDataSort *sortMeasurementsDataArray){

    return sortMeasurementsDataArray = (measurementDataSort*) realloc(sortMeasurementsDataArray,10*sizeof(measurementDataSort));
}


int checkID(measurementDataSort *sortMeasurementsDataArray,unsigned short sensorId,int numSensors){
    int j = 0;
    while (j<numSensors)
    {
       if(sortMeasurementsDataArray[j].measurementData[0].sensorId==sensorId){
            return sensorId;
        }
        j++;
    }
    return -1;
}

int checkNumber(measurementDataSort *sortMeasurementsDataArray,unsigned short sensorId,int numSensors){
    unsigned int j = 0;
    while (j<numSensors)
    {
       if(sortMeasurementsDataArray[j].measurementData[0].sensorId==sensorId){
            return j;
        }
        j++;
    }
    return -1;
}

void sortMeasurementsData(measurementDataSort *sortMeasurementsDataArray,measurementData *ptrData, int numLines){
    sortMeasurementsDataArray = (measurementDataSort*) malloc(10*sizeof(measurementDataSort));
    unsigned int save;
    int numSensors=0;
    for (unsigned int i = 0; i < numLines; i++)
    {
        save = checkID(sortMeasurementsDataArray,ptrData[i].sensorId,numSensors);

        if (save==-1)
        {
            sortMeasurementsDataArray[numSensors].numSensors=1;
            sortMeasurementsDataArray[numSensors].measurementData[sortMeasurementsDataArray[numSensors].numSensors-1]=ptrData[i];
            numSensors++;
        }else{
            unsigned int j = checkNumber(sortMeasurementsDataArray,save,numSensors);
            sortMeasurementsDataArray[j].measurementData[sortMeasurementsDataArray[j].numSensors]=ptrData[i];
            sortMeasurementsDataArray[j].numSensors ++;
        }   
    }
    for (int i = 0; i < numSensors; i++)
    {
        printf("\n%d:\n",sortMeasurementsDataArray[i].measurementData[0].sensorId);
        for (int j = 0; j < sortMeasurementsDataArray[i].numSensors; j++)
        {  
           printf("%d,",sortMeasurementsDataArray[i].measurementData[j].measuredValue); 
        }
        
    }
    
}


