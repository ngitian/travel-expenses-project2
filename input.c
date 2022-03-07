#include <stdio.h>
#include <stdlib.h>
#include "ReadValues.h"
#include "input.h"

int getNumOfDays() {
    int result = readPositiveInteger("Input number of travel days: ", 1, 9999);

    return result;
}

int getTimeDeparture() {
    struct Hour* h = readHour("Input depart time hour\n");
    int result = h->hour * 100 + (h->meridiem * 1200);
    printf("%d\n", result);

    return result;
} 

int getTimeArrival() {
    struct Hour* h = readHour("Input arrival time hour\n");
    int result = h->hour * 100 + (h->meridiem * 1200);
    printf("%d\n", result);

    return result;
}

int getAirFare() {
    struct Money* m = readDollarInput("\nInput round-trip airfare amount: ");
    int result = m->dollars * 100 + m->cents;
    return result;
}

int getCarRental() {
    struct Money* m = readDollarInput("\nInput car rental amount: ");
    int result = m->dollars * 100 + m->cents;
    return result;
}

float getMileDriven() {
    float result = 0.0;

    struct Money* m = readDollarInput("\nInput miles driven if there's a private vehicle used (0 if none): ");
    result = m->dollars + (float) m->cents / 100;

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

int* getMealExpenses(int numOfDays) {
    int *result = malloc(numOfDays * 3 * sizeof(int));

    if (result == NULL) {
        printf("System did not allocate necessary memory!\n");
        exit(EXIT_FAILURE);
    }

    for (int i=0; i < numOfDays; ++i) {
        printf("\nDay %d:\n", i+1);
        for (int j=0; j < 3; ++j) {
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
            *(result + i + j) = userInput; 
        }
    }

    return result;
}
