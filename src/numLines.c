#include <stdio.h>
#include "measurementData.h"

unsigned int numLines(FILE *datei)
{
    unsigned int numLines=0;
    char letter;

    while ((letter=fgetc(datei))!=EOF)
    {
        if (letter=='\n')
        {
            numLines++;
        }       
    }
    
    return numLines;
}