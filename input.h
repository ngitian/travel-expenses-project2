#ifndef INPUT_H
#define INPUT_H
int getNumOfDays();
int getTimeDeparture(); 
int getTimeArrival();
int getAirFare();
int getCarRental();
float getMileDriven();
int getIntegerMilesDriven();
int getParkingFee();
int* getTaxiFees(int numOfDays);
int getRegistrationFee();
int getHotelExpense();
int* getMealExpenses(int numOfDays, int departTime, int arrivalTime);
#endif
