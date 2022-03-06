#include "calculation.h"

const int EXPENSE_PER_MILE = 27;
const int PARKING_ALLOWABLE_PER_DAY = 600;
const int TAXI_ALLOWABLE_PER_DAY = 1000;
const int HOTEL_ALLOWABLE_PER_DAY = 9000;

void calculateAirfare(int airFare, int *totalExpense, int *totalAllowable, int *maxAllowable) {
    *totalExpense += airFare;
    *totalAllowable += airFare;
    *maxAllowable += airFare;
}

void calculateCarRental(int carRental, int *totalExpense, int *totalAllowable, int *maxAllowable) {
    *totalExpense += carRental;
    *totalAllowable += carRental;
    *maxAllowable += carRental;
}

void calculateVehicleExpense(int mileDriven, int *totalExpense, int *totalAllowable, int *maxAllowable) {
    *totalExpense += mileDriven * EXPENSE_PER_MILE;
    *totalAllowable += mileDriven * EXPENSE_PER_MILE;
    *maxAllowable += mileDriven * EXPENSE_PER_MILE;
}

void calculateParkingFees(int parkingFees, int numOfDays, int *totalExpense, int *totalAllowable, int *maxAllowable) {
    /* Company will cover up to $6 per day
    */
    *totalExpense += parkingFees;
    if (parkingFees / numOfDays > PARKING_ALLOWABLE_PER_DAY) {
        *totalAllowable += numOfDays * PARKING_ALLOWABLE_PER_DAY;
    } else {
        *totalAllowable += parkingFees;
    }
    *maxAllowable += numOfDays * PARKING_ALLOWABLE_PER_DAY;
}

void calculateTaxiFees(int taxiFees, int numOfDays, int *totalExpense, int *totalAllowable, int *maxAllowable) {

}

void calculateRegistrationFees(int registrationFees, int *totalExpense, int *totalAllowable, int *maxAllowable) {
    *totalExpense += registrationFees;
    *totalAllowable += registrationFees;
    *maxAllowable += registrationFees;
}

void calculateHotelExpenses(int hotelExpenses, int numOfDays, int *totalExpense, int *totalAllowable, int *maxAllowable) {
    *totalExpense += hotelExpenses;
    if (hotelExpenses / numOfDays > HOTEL_ALLOWABLE_PER_DAY) {
        *totalAllowable += numOfDays * HOTEL_ALLOWABLE_PER_DAY;
    } else {
        *totalAllowable += hotelExpenses;
    }
    *maxAllowable += numOfDays * HOTEL_ALLOWABLE_PER_DAY;
}

void calculateMealExpenses(int mealExpenses, int numOfDays, int  timeDeparture, int timeArrival, int *totalExpense, int *totalAllowable, int *maxAllowable) {

}
