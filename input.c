#include <stdio.h>
#include <stdlib.h>
#include "ReadValues.h"
#include "input.h"

int getNumOfDays() {
    int result = readPositiveInteger("Input number of travel days: ", 1, 9999);

    return result;
}

int getTimeDeparture() {
    struct Hour* h = readHour("Input the hour you will depart and begin the trip on.\n");
    int result = h->hour * 100 + (h->meridiem * 1200);

    return result;
} 

int getTimeArrival() {
    struct Hour* h = readHour("Input the hour you will arrive back home from your tip.\n");
    int result = h->hour * 100 + (h->meridiem * 1200);

    return result;
}

int getAirFare() {
    struct Money* m = readDollarInput("\nInput round-trip airfare expenses: ");
    int result = m->dollars * 100 + m->cents;
    return result;
}

int getCarRental() {
    struct Money* m = readDollarInput("\nInput car rental expenses: ");
    int result = m->dollars * 100 + m->cents;
    return result;
}

float getMileDriven() {
    float result = 0.0;

    struct Money* m = readDollarInput("\nInput miles driven if there's a private vehicle used (0 if none): ");
    result = m->dollars + (float) m->cents / 100;

    return result;
}

int getIntegerMilesDriven()
{
    int result = 0;
    result = readPositiveInteger("\nInput miles driven if there's a private vehicle used (0 if none): ", 0, 999999999);
    return result;
}

int getParkingFee() {
    struct Money* m = readDollarInput("\nInput parking fees amount: ");
    int result = m->dollars * 100 + m->cents;
    return result;
}

int* getTaxiFees(int numOfDays) {
    int *result = malloc(numOfDays * sizeof(int));

    if (result == NULL) {
        printf("System did not allocate necessary memory!\n");
        exit(EXIT_FAILURE);
    }

    for (int i=0; i < numOfDays; ++i) {
        int userInput = -1;
        while (userInput < 0) {
            printf("\nDay %d:\n", i+1);
            struct Money* m = readDollarInput("Input taxi fees, 0 if there's no taxi fee: ");
            userInput = m->dollars * 100 + m->cents;
        }
        *(result + i) = userInput; 
    }

    return result;
}

int getRegistrationFee() {
    struct Money* m = readDollarInput("\nInput conference or seminar registration fees: ");
    int result = m->dollars * 100 + m->cents;
    return result;
}

int getHotelExpense() {
    struct Money* m = readDollarInput("\nInput hotel expenses: ");
    int result = m->dollars * 100 + m->cents;
    return result;
}

int* getMealExpenses(int numOfDays, int departTime, int arrivalTime) {
    int *result = malloc(numOfDays * 3 * sizeof(int));

    if (result == NULL) {
        printf("System did not allocate necessary memory!\n");
        exit(EXIT_FAILURE);
    }

    for (int i=0; i < numOfDays; ++i) 
    {
        printf("\nDay %d:\n", i+1);

        if(i == 0)
        {
            int firstDayInput = 0;
            struct Money* firstDayDollars;
            if(departTime < 700)
            {
                printf("Breakfast-");
                firstDayDollars = readDollarInput("Input meal fee, 0 if there's no meal fee: ");
                firstDayInput = firstDayDollars->dollars * 100 + firstDayDollars->cents;
                *(result) = firstDayInput;
            }
            else
                *(result) = 0; 
            if(departTime < 1200)
            {
                printf("Lunch-");
                firstDayDollars = readDollarInput("Input meal fee, 0 if there's no meal fee: ");
                firstDayInput = firstDayDollars->dollars * 100 + firstDayDollars->cents;
                *(result + 1) = firstDayInput;
            }
            else
                *(result + 1) = 0;
            if(departTime < 1800)
            {
                printf("Dinner-");
                firstDayDollars = readDollarInput("Input meal fee, 0 if there's no meal fee: ");
                firstDayInput = firstDayDollars->dollars * 100 + firstDayDollars->cents;
                *(result + 2) = firstDayInput;
            }
            else
            {
                *(result + 2) = 0;
                printf("No meals covered the first day due to late departure time.\n");
            }
            continue;
        }
        if(i == numOfDays - 1 && i != 0)
        {
            int lastDayInput = 0;
            struct Money* lastDayDollars;
            
            if(arrivalTime >= 800)
            {
                printf("Breakfast-");
                lastDayDollars = readDollarInput("Input meal fee, 0 if there's no meal fee: ");
                lastDayInput = lastDayDollars->dollars * 100 + lastDayDollars->cents;
                *(result + i * 3) = lastDayInput;
            }
            else
            {
                *(result + i * 3) = 0;
                printf("No meals covered the last day due to early return time.\n");
            }
            if(arrivalTime >= 1300)
            {
                printf("Lunch-");
                lastDayDollars = readDollarInput("Input meal fee, 0 if there's no meal fee: ");
                lastDayInput = lastDayDollars->dollars * 100 + lastDayDollars->cents;
                *(result + i * 3 + 1) = lastDayInput;
            }
            else
                *(result + i * 3 + 1) = 0;
            
            if(arrivalTime >= 1900)
            {
                printf("Dinner-");
                lastDayDollars = readDollarInput("Input meal fee, 0 if there's no meal fee: ");
                lastDayInput = lastDayDollars->dollars * 100 + lastDayDollars->cents;
                *(result + i * 3 + 2) = lastDayInput;
            }
            else
                *(result + i * 3 + 2) = 0;
            
            continue;
        }
        for (int j=0; j < 3; ++j) 
        {
            if(j == 0) {
                printf("Breakfast-");
            } else if (j == 1) {
                printf("Lunch-");
            } else {
                printf("Dinner-");
            }

            int userInput = -1;
            while (userInput < 0) {
                struct Money* m = readDollarInput("Input meal fee, 0 if there's no meal fee: ");
                userInput = m->dollars * 100 + m->cents;
            }
            *(result + i * 3 + j) = userInput; 
        }
    }

    return result;
}
