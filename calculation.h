#ifndef CALCULATION_H
#define CALCULATION_H
void calculateAirfare(int airFare, int *totalExpense, int *totalAllowable);
void calculateCarRental(int carRental, int *totalExpense, int *totalAllowable);
void calculateVehicleExpense(int mileDriven, int *totalExpense, int *totalAllowable);
void calculateParkingFees(int parkingFees, int numOfDays, int *totalExpense, int *totalAllowable);
void calculateTaxiFees(int taxiFees, int numOfDays, int *totalExpense, int *totalAllowable);
void calculateRegistrationFees(int registrationFees, int *totalExpense, int *totalAllowable);
void calculateHotelExpenses(int hotelExpenses, int numOfDays, int *totalExpense, int *totalAllowable);
void calculateMealExpenses(int mealExpenses, int numOfDays, int  timeDeparture, int timeArrival, int *totalExpense, int *totalAllowable);
#endif
