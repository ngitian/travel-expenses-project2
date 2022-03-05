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
    int parkingFee;
    int taxiFee;
    int registrationFee;
    int hotelExpense;
    int mealExpense;

    int totalExpense, totalAllowable = 0;

    // input
    numOfDays = getNumOfDays();
    timeDeparture = getTimeDeparture(); 
    timeArrival = getTimeArrival();
    airFare = getAirFare();
    carRental = getCarRental();
    vehicleExpense = getVehicleExpense();
    parkingFee = getParkingFee();
    taxiFee = getTaxiFee();
    registrationFee = getRegistrationFee();
    hotelExpense = getHotelExpense();
    mealExpense = getMealExpense(numOfDays, timeDeparture, timeArrival); // require numOfDays, timeDeparture, timeArrival

    // calculation
    calculateAirfare(&totalExpense, &totalAllowable);
    calculateCarRental(&totalExpense, &totalAllowable);
    calculateVehicleExpense(&totalExpense, &totalAllowable);
    calculateParkingFees(&totalExpense, &totalAllowable, numOfDays);
    calculateTaxiFees(&totalExpense, &totalAllowable, numOfDays);
    calculateRegistrationFees(&totalExpense, &totalAllowable);
    calculateHotelExpenses(&totalExpense, &totalAllowable, numOfDays);
    calculateMealExpenses(&totalExpense, &totalAllowable);
    

    // output
    display(totalExpense, totalAllowable);

    // good bye message
    printf("Have a nice day!\n");
    return 0;
}