#include "calculation.h"

const int EXPENSE_PER_MILE = 27;
const int PARKING_ALLOWABLE_PER_DAY = 600;
const int TAXI_ALLOWABLE_PER_DAY = 1000;
const int HOTEL_ALLOWABLE_PER_DAY = 9000;
const int BREAKFAST_ALLOWABLE = 900;
const int LUNCH_ALLOWABLE = 1200;
const int DINNER_ALLOWABLE = 1600;

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

void calculateVehicleExpense(float mileDriven, int *totalExpense, int *totalAllowable, int *maxAllowable) {
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

void calculateTaxiFees(int *taxiFees, int numOfDays, int *totalExpense, int *totalAllowable, int *maxAllowable) {
    for (int i=0; i < numOfDays; ++i) {
        int fee = *(taxiFees + i);
        *totalExpense += fee;

        if (fee > TAXI_ALLOWABLE_PER_DAY) {
            *totalAllowable += TAXI_ALLOWABLE_PER_DAY;
        } else {
            *totalAllowable += fee;
        }

        *maxAllowable += TAXI_ALLOWABLE_PER_DAY;
    }
}

void calculateRegistrationFees(int registrationFees, int *totalExpense, int *totalAllowable, int *maxAllowable) {
    *totalExpense += registrationFees;
    *totalAllowable += registrationFees;
    *maxAllowable += registrationFees;
}

void calculateHotelExpenses(int hotelExpenses, int numOfDays, int *totalExpense, int *totalAllowable, int *maxAllowable) {
    int hotelNight = numOfDays - 1;
    *totalExpense += hotelExpenses;
    if (hotelExpenses / hotelNight > HOTEL_ALLOWABLE_PER_DAY) {
        *totalAllowable += hotelNight * HOTEL_ALLOWABLE_PER_DAY;
    } else {
        *totalAllowable += hotelExpenses;
    }
    *maxAllowable += hotelNight * HOTEL_ALLOWABLE_PER_DAY;
}

void calculateMealExpenses(int* mealExpenses, int numOfDays, int  timeDeparture, int timeArrival, int *totalExpense, int *totalAllowable, int *maxAllowable) {
    printf("%d\n", *(mealExpenses + 0));
    printf("%d\n", *(mealExpenses + 1));
    printf("%d\n", *(mealExpenses + 2));
    for (int i=0; i < numOfDays; ++i) {
        for (int j=0; j<3; ++j) {
            int fee = *(mealExpenses + i + j);
            *totalExpense += fee;

            int allowable;
            if (j == 0) { // breakfast
                allowable = BREAKFAST_ALLOWABLE;
            } else if (j == 1) { // lunch
                allowable = LUNCH_ALLOWABLE;
            } else { // dinner
                allowable = DINNER_ALLOWABLE;
            }
            
            // only 1 day, first day and last
            if (i == 0 && i == numOfDays - 1) {
                if (j == 0) { // breakfast cover if depart < 7 and arrival > 8
                    if (timeArrival < 700 || timeDeparture > 800) {
                        break;
                    }
                } else if (j == 1) { // lunch cover if depart < 12 and arrival > 13
                    if (timeArrival < 1200 || timeDeparture > 1300) {
                        break;
                    }
                } else { // dinner cover if depart < 18 and arrival > 19
                    if (timeArrival < 1800 || timeDeparture > 1900) {
                        break;
                    }
                }

                if (fee > allowable) {
                    *totalAllowable += allowable;
                } else {
                    *totalAllowable += fee;
                }
                *maxAllowable += allowable;

            } else if (i == 0) { // first day
                if (timeDeparture > 1800) {
                    break;
                } else if (timeDeparture > 1200) { 
                    if (j == 1) {
                        break;
                    }
                } else if (timeDeparture > 700) {
                    if (j == 0) {
                        break;
                    }
                }

                if (fee > allowable) {
                    *totalAllowable += allowable;
                } else {
                    *totalAllowable += fee;
                }
                *maxAllowable += allowable;

            } else if (i == numOfDays - 1) { // last day

                if (timeArrival < 800) {
                    break;
                } else if (timeArrival < 1300) { 
                    if (j == 1) {
                        break;
                    }
                } else if (timeArrival < 1900) {
                    if (j == 2) {
                        break;
                    }
                }

                if (fee > allowable) {
                    *totalAllowable += allowable;
                } else {
                    *totalAllowable += fee;
                }
                *maxAllowable += allowable;

            } else if (i != 0 || i != numOfDays - 1) { // in between day, everything is cover normally
                if (fee > allowable) {
                    *totalAllowable += allowable;
                } else {
                    *totalAllowable += fee;
                }
                *maxAllowable += allowable;
            }

        }

    }

}
