#include "measurementData.h"

int numLines(FILE *datei)
{
    int numLines = 0;
    char letter;

    while ((letter = fgetc(datei)) != EOF)
    {
        if (letter == '\n')
        {
            numLines++;
        }
    }

    return numLines;
}