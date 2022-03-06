#include "calculation.h"

const int EXPENSE_PER_MILE = 27;
const int PARKING_ALLOWABLE_PER_DAY = 600;
const int TAXI_ALLOWABLE_PER_DAY = 1000;
const int HOTEL_ALLOWABLE_PER_DAY = 9000;

void calculateAirfare(int airFare, int *totalExpense, int *totalAllowable) {
    *totalExpense += airFare;
    *totalAllowable += airFare;
}

void calculateCarRental(int carRental, int *totalExpense, int *totalAllowable) {
    *totalExpense += carRental;
    *totalAllowable += carRental;
}

void calculateVehicleExpense(int mileDriven, int *totalExpense, int *totalAllowable) {
    *totalExpense += mileDriven * EXPENSE_PER_MILE;
    *totalAllowable += mileDriven * EXPENSE_PER_MILE;
}

void calculateParkingFees(int parkingFees, int numOfDays, int *totalExpense, int *totalAllowable) {
    *totalExpense += parkingFees;
    *totalAllowable += numOfDays * PARKING_ALLOWABLE_PER_DAY;
}

void calculateTaxiFees(int taxiFees, int numOfDays, int *totalExpense, int *totalAllowable) {

}

void calculateRegistrationFees(int registrationFees, int *totalExpense, int *totalAllowable) {
    *totalExpense += registrationFees;
    *totalAllowable += registrationFees;
}

void calculateHotelExpenses(int hotelExpenses, int numOfDays, int *totalExpense, int *totalAllowable) {
    *totalExpense += hotelExpenses;
    *totalAllowable += numOfDays * HOTEL_ALLOWABLE_PER_DAY;
}

void calculateMealExpenses(int mealExpenses, int numOfDays, int  timeDeparture, int timeArrival, int *totalExpense, int *totalAllowable) {

}
