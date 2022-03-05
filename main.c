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
    int vehicleExpense;
    int parkingFees;
    int taxiFees;
    int registrationFees;
    int hotelExpenses;
    int mealExpenses; // need to implement meal Expense as array

    int totalExpense, totalAllowable = 0;

    // input
    numOfDays = getNumOfDays();
    timeDeparture = getTimeDeparture(); 
    timeArrival = getTimeArrival();
    airFare = getAirFare();
    carRental = getCarRental();
    vehicleExpense = getVehicleExpense();
    parkingFees = getParkingFee();
    taxiFees = getTaxiFee();
    registrationFees = getRegistrationFee();
    hotelExpenses = getHotelExpense();
    mealExpenses = getMealExpenses(numOfDays); // require numOfDays, need to be change

    // calculation
    calculateAirfare(airFare, &totalExpense, &totalAllowable);
    calculateCarRental(carRental, &totalExpense, &totalAllowable);
    calculateVehicleExpense(vehicleExpense, &totalExpense, &totalAllowable);
    calculateParkingFees(parkingFees, numOfDays, &totalExpense, &totalAllowable);
    calculateTaxiFees(taxiFees, numOfDays, &totalExpense, &totalAllowable);
    calculateRegistrationFees(registrationFees, &totalExpense, &totalAllowable);
    calculateHotelExpenses(hotelExpenses, numOfDays, &totalExpense, &totalAllowable);
    calculateMealExpenses(mealExpenses, numOfDays, timeDeparture, timeArrival, &totalExpense, &totalAllowable);
    
    // output
    display(totalExpense, totalAllowable);

    // good bye message
    printf("Have a nice day!\n");
    return 0;
}