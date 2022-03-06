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
    long valuePreDecimal = 0;
    long valuePostDecimal = 0;

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
            valuePreDecimal += (long)pow(10, currentNumberDigits - i - 1) * (inputString[i] - '0');
        }
        valuePostDecimal = 0;
    }
    else
    {
        for(int i = 0; i < periodIndex; i++)
        {
            valuePreDecimal += (long)pow(10, periodIndex - i - 1) * (inputString[i] - '0');
        }
        // The initial value of j depends on the maximum number of post-decimal digits allowed.
        for(int i = periodIndex + 1, j = 1; i < currentNumberDigits; i++, j--)
        {
            valuePostDecimal += (long)pow(10, j) * (inputString[i] - '0');
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

int main()
{
    while(1)
    {
        struct Money* test = readDollarInput("Enter some dollars: ");
        printf("Pre-Decimal: %ld - Post-Decimal: %ld\n", test->dollars, test->cents);
    }
    return 0;
}