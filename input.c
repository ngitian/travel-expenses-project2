#include <stdio.h>
#include <stdlib.h>
#include "ReadValues.h"
#include "input.h"

int getNumOfDays() {
    int result = -1;

    while (result <= 0) {
        char input[5];
        printf("\nInput number of travel days: ");
        scanf("%s", input);
        result = strtol(input, NULL, 10);
        if (result <= 1) {
            printf("Number of days must be greater than 1.\n");
        }
    }

    return result;
}

int getTimeDeparture() {
    int result = -1;

    while (result < 0 || result > 2359) {
        char input[4];
        printf("\nInput departure time(14:00=1400): ");
        scanf("%s", input);
        result = strtol(input, NULL, 10);
        if (result < 0) {
            printf("Can't have time less than 00:00 (0-2359)\n");
        } else if (result > 2359) {
            printf("Can't have time greater than 23:59(0-2359)\n");
        } else if (strtol(input + 2, NULL, 10) > 5) {
            printf("Can't have minutes greater than 59\n");
        }
    }

    return result;
} 

int getTimeArrival() {
    int result = 0;

    printf("\nInput arrival time(14:00=1400): ");
    scanf("%d", &result);

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

int getMileDriven() {
    int result = 0;

    printf("\nInput miles driven if there's private vehicle: ");
    scanf("%d", &result);

    return result;
}

int getParkingFee() {
    struct Money* m = readDollarInput("\nInput parking fees amount: ");
    int result = m->dollars * 100 + m->cents;
    return result;
}

int getTaxiFee() {
    int result = 0;

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

// todo: change implementation
int getMealExpenses(int numOfDays) {
    int result = 0;

    return result;
}
