#include <stdio.h>
#include "input.h"
#include "calculation.h"
#include "output.h"

int main() {

    // greeting
    printf("Welcome to travel expenses calculator!\n");


    // declare variables (in cents)
    int numOfDays;
    int timeDeparture, timeArrival; // in 24-hour format (e.g. 14:00 = 1400)
    int airFare;
    int carRental;
    int mileDriven;
    int parkingFees;
    int taxiFees;
    int registrationFees;
    int hotelExpenses;
    int mealExpenses; // need to implement meal Expense as array

    int totalExpense = 0;
    int totalAllowable = 0;
    int maxAllowable = 0;

    // input
    numOfDays = getNumOfDays();
    timeDeparture = getTimeDeparture(); 
    timeArrival = getTimeArrival();
    airFare = getAirFare();
    carRental = getCarRental();
    mileDriven = getMileDriven();
    parkingFees = getParkingFee();
    taxiFees = getTaxiFee();
    registrationFees = getRegistrationFee();
    hotelExpenses = getHotelExpense();
    mealExpenses = getMealExpenses(numOfDays); // require numOfDays, need to be change

    // calculation
    calculateAirfare(airFare, &totalExpense, &totalAllowable, &maxAllowable);
    calculateCarRental(carRental, &totalExpense, &totalAllowable, &maxAllowable);
    calculateVehicleExpense(mileDriven, &totalExpense, &totalAllowable, &maxAllowable);
    calculateParkingFees(parkingFees, numOfDays, &totalExpense, &totalAllowable, &maxAllowable);
    calculateTaxiFees(taxiFees, numOfDays, &totalExpense, &totalAllowable, &maxAllowable);
    calculateRegistrationFees(registrationFees, &totalExpense, &totalAllowable, &maxAllowable);
    calculateHotelExpenses(hotelExpenses, numOfDays, &totalExpense, &totalAllowable, &maxAllowable);
    calculateMealExpenses(mealExpenses, numOfDays, timeDeparture, timeArrival, &totalExpense, &totalAllowable, &maxAllowable);
    
    // output
    display(totalExpense, totalAllowable, maxAllowable);

    // good bye message
    printf("Have a nice day!\n");
    return 0;
}