#ifndef CALCULATION_H
#define CALCULATION_H
void calculateAirfare(int airFare, int *totalExpense, int *totalAllowable, int *maxAllowable);
void calculateCarRental(int carRental, int *totalExpense, int *totalAllowable, int *maxAllowable);
void calculateVehicleExpense(int mileDriven, int *totalExpense, int *totalAllowable, int *maxAllowable);
void calculateParkingFees(int parkingFees, int numOfDays, int *totalExpense, int *totalAllowable, int *maxAllowable);
void calculateTaxiFees(int taxiFees, int numOfDays, int *totalExpense, int *totalAllowable, int *maxAllowable);
void calculateRegistrationFees(int registrationFees, int *totalExpense, int *totalAllowable, int *maxAllowable);
void calculateHotelExpenses(int hotelExpenses, int numOfDays, int *totalExpense, int *totalAllowable, int *maxAllowable);
void calculateMealExpenses(int mealExpenses, int numOfDays, int  timeDeparture, int timeArrival, int *totalExpense, int *totalAllowable, int *maxAllowable);
#endif
