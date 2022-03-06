#include "ReadValues.h"
#include "input.h"

#include <stdio.h>

int getNumOfDays() {
    int result = 0;

    return result;
}

int getTimeDeparture() {
    int result = 0;

    return result;
} 

int getTimeArrival() {
    int result = 0;

    return result;
}

int getAirFare() {
    struct Money* m = readDollarInput("Input round-trip airfare amount: ");
    int result = m->dollars * 100 + m->cents;
    return result;
}

int getCarRental() {
    struct Money* m = readDollarInput("Input car rental amount: ");
    int result = m->dollars * 100 + m->cents;
    return result;
}

int getMileDriven() {
    int result = 0;

    return result;
}

int getParkingFee() {
    struct Money* m = readDollarInput("Input parking fees amount: ");
    int result = m->dollars * 100 + m->cents;
    return result;
}

int getTaxiFee() {
    int result = 0;

    return result;
}

int getRegistrationFee() {
    struct Money* m = readDollarInput("Input conference or seminar registration fees: ");
    int result = m->dollars * 100 + m->cents;
    return result;
}

int getHotelExpense() {
    struct Money* m = readDollarInput("Input hotel expenses: ");
    int result = m->dollars * 100 + m->cents;
    return result;
}

// todo: change implementation
int getMealExpenses(int numOfDays) {
    int result = 0;

    return result;
}
