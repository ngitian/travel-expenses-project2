#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "calculation.h"
#include "output.h"

int main() {

    // greeting
    printf("Welcome to travel expenses calculator!\n");


    // declare variables (in cents)
    int numOfDays = 0;
    int timeDeparture, timeArrival; // in 24-hour format (e.g. 14:00 = 1400)
    int airFare = 0;
    int carRental = 0;
    float mileDriven = 0.0;
    int intMilesDriven = 0;
    int parkingFees = 0;
    int *taxiFees;
    int registrationFees = 0;
    int hotelExpenses = 0;
    int *mealExpenses = 0;

    int totalExpense = 0;
    int totalAllowable = 0;
    int maxAllowable = 0;

    // input
    numOfDays = getNumOfDays();
    timeDeparture = getTimeDeparture(); // todo: fix bug for 1 day trip, check for arrival before departure
    timeArrival = getTimeArrival(); // todo: input validation for mins
    airFare = getAirFare();
    carRental = getCarRental();
    //mileDriven = getMileDriven();
    intMilesDriven = getIntegerMilesDriven();
    parkingFees = getParkingFee();
    taxiFees = getTaxiFees(numOfDays);
    registrationFees = getRegistrationFee();
    if (numOfDays > 1) {
        hotelExpenses = getHotelExpense();
    }
    mealExpenses = getMealExpenses(numOfDays, timeDeparture, timeArrival);

    // calculation
    calculateAirfare(airFare, &totalExpense, &totalAllowable, &maxAllowable);
    calculateCarRental(carRental, &totalExpense, &totalAllowable, &maxAllowable);
    calculateVehicleExpense(intMilesDriven, &totalExpense, &totalAllowable, &maxAllowable);
    calculateParkingFees(parkingFees, numOfDays, &totalExpense, &totalAllowable, &maxAllowable);
    calculateTaxiFees(taxiFees, numOfDays, &totalExpense, &totalAllowable, &maxAllowable);
    calculateRegistrationFees(registrationFees, &totalExpense, &totalAllowable, &maxAllowable);
    if (numOfDays > 1) {
        calculateHotelExpenses(hotelExpenses, numOfDays, &totalExpense, &totalAllowable, &maxAllowable);
    }
    //for (int i = 0; i < numOfDays; ++i) {
    //    for (int j = 0; j < 3; ++j) {
    //        printf("%d, %d\n", i * 3 + j, *(mealExpenses + i * 3 + j));
    //    }
    //}
    calculateMealExpenses(mealExpenses, numOfDays, timeDeparture, timeArrival, &totalExpense, &totalAllowable, &maxAllowable);

    
    // output
    display(totalExpense, totalAllowable, maxAllowable);

    // free memory
    free(taxiFees);
    free(mealExpenses);

    // good bye message
    printf("Have a nice day!\n");
    return 0;
}