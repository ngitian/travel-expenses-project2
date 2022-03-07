#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "ReadValues.h"

int flushBuffer()
{
    int currentChar, numExtraValues = 0;
    while ((currentChar = getchar()) != '\n' && currentChar != EOF)
        ++numExtraValues;
    return numExtraValues;
}

struct Money* readDollarInput(char *prompt)
{
    // Non-loop characters
    int maxWholeNumberDigits = 9; // Max whole dollar value of 999,999,999
    char inputString[3 + maxWholeNumberDigits]; // 3 = period + 2 decimal digits
    char currentChar;

    // Loop variables
    int currentNumberDigits = 0; // Current number of valid input characters
    int periodIndex = -1; // Has the user entered a period?
    int secondLoopCounter = 0;
    unsigned int valuePreDecimal = 0;
    unsigned int valuePostDecimal = 0;

    askForInput:
    printf("%s", prompt);

    for(currentNumberDigits; currentNumberDigits < maxWholeNumberDigits; currentNumberDigits++)
    {
        currentChar = getchar();
        if(currentChar < '0' || currentChar > '9')
        {
            switch(currentChar)
            {
                case '\n': case EOF:
                    if(currentNumberDigits == 0)
                        goto badInput;
                    else
                        goto goodInput;
                
                case '.':
                    // INCREMENT numdigits, add period in periodInput code
                    goto periodInput;
                
                default:
                    flushBuffer();
                    goto badInput;
            }

        }
        else
        {
            inputString[currentNumberDigits] = currentChar;
        }
    }
    for(secondLoopCounter; secondLoopCounter < 3; secondLoopCounter++, currentNumberDigits++)
    {
        currentChar = getchar();
        switch(currentChar)
        {
            case '\n': case EOF:
                if(currentNumberDigits == 1 && periodIndex == 0) // Eliminates single period input
                    goto badInput;
                else
                    goto goodInput;

            case '.':
                if(periodIndex > -1)
                {
                    flushBuffer();
                    goto badInput;
                }
                else
                {
                    periodInput:
                    inputString[currentNumberDigits] = '.';
                    periodIndex = currentNumberDigits;
                }
                break;

            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                if(periodIndex == -1)
                {
                   flushBuffer();
                   goto badInput;
                }
                else
                {
                   inputString[currentNumberDigits] = currentChar;
                }
                break;

            default:
                flushBuffer();
                goto badInput;
        }
    }
    if(flushBuffer() > 0)
        goto badInput;

    goodInput:
    // Convert from char array to decimal values
    if(periodIndex == -1)
    {
        for(int i = 0; i < currentNumberDigits; i++)
        {
            valuePreDecimal += (unsigned int)pow(10, currentNumberDigits - i - 1) * (inputString[i] - '0');
        }
        valuePostDecimal = 0;
    }
    else
    {
        for(int i = 0; i < periodIndex; i++)
        {
            valuePreDecimal += (unsigned int)pow(10, periodIndex - i - 1) * (inputString[i] - '0');
        }
        // The initial value of j depends on the maximum number of post-decimal digits allowed.
        for(int i = periodIndex + 1, j = 1; i < currentNumberDigits; i++, j--)
        {
            valuePostDecimal += (unsigned int)pow(10, j) * (inputString[i] - '0');
        }
    }

    struct Money* result = (struct Money*)malloc(sizeof(struct Money));
    result->dollars = valuePreDecimal;
    result->cents = valuePostDecimal;
    
    return result;

    badInput:
    // Reset all loop variables
    currentNumberDigits = 0;
    periodIndex = -1;
    secondLoopCounter = 0;
    valuePreDecimal = 0;
    valuePostDecimal = 0;
    printf("ERROR: Bad value entered. Please try again.\n");
    goto askForInput;
}

unsigned int readPositiveInteger(char *prompt, int minValue, int maxValue)
{
    // Non-loop characters
    int maxNumberDigits = 9; // Absolute Max value of 999,999,999
    char inputString[maxNumberDigits];
    char currentChar;

    // Loop variables
    int currentNumberDigits = 0; // Current number of valid input characters
    unsigned int value = 0;

    askForInput:
    printf("%s", prompt);

    for(currentNumberDigits; currentNumberDigits < maxNumberDigits; currentNumberDigits++)
    {
        currentChar = getchar();
        switch(currentChar)
        {
            case '\n': case EOF:
                if(currentNumberDigits == 0)
                    goto badInput;
                else
                    goto goodInput;

            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                inputString[currentNumberDigits] = currentChar;
                break;
            
            default:
                flushBuffer();
                goto badInput;
        }
    }
    if (flushBuffer() > 0)
        goto badInput;

    goodInput:
    for(int i = 0; i < currentNumberDigits; i++)
        value += (unsigned int)pow(10, currentNumberDigits - i - 1) * (inputString[i] - '0');
    
    // TODO: COMPARE WITH MIN AND MAX VALUES
    if(minValue < 0)
    {
        minValue = 0;
    }

    if(maxValue < 0)   // garbage branch prediction makes the program not run as it should
    {
        printf("This if block executed");
        maxValue = (int)pow(10, maxNumberDigits) - 1;
    }
    if(value < minValue || value > maxValue)
        goto badInput;
    return value;

    badInput:
    value = 0;
    currentNumberDigits = 0;
    printf("ERROR: Bad value entered. Please try again.\n");
    goto askForInput;
}

struct Hour* readHour(char *prompt)
{
    struct Hour* result = (struct Hour*)malloc(sizeof(struct Hour));

    printf("%s", prompt);
    result->meridiem = readPositiveInteger("In the morning (a.m.) or afternoon (p.m.)?"
        " Enter 0 for a.m. or 1 for p.m.: " , 0, 1);
    result->hour = readPositiveInteger("What hour during this time period?"
        " Enter a number from 1 to 12: ", 1, 12);
    return result;
}

