#include "calculation.h" //include header file
#include <stdbool.h>//boolean variable

    int days, departureTime, arrivalTime, parking, miles, meals;
    bool taxi, privateVehicle;
    double parkingFee, taxiFees, hotelExpenses, registrationFees;
    double totalExpenses = 0;
    double allowedExpenses = 0;
    double excessExpenses = 0;
    double savedExpenses = 0;

    void setDays(int day){
        days = day;
    }
    int getDays(void){
        return days;
    }

    void setTimes(int depTime, int arrTime){
        departureTime = depTime;
        arrivalTime = arrTime;
    }
    int getDepTime(void){
        return departureTime;
    }
    int getArrTime(void){
        return arrivalTime;
    }

    //assuming they are using one mode of transportation
    void setCar(bool privateCar, bool uber){
        privateVehicle = privateCar;
        taxi = uber;
    }
    void setAvgMiles(int distance){//sets average daily milage for vehicle
        miles = distance;
    }
    double getTaxiExpenses(int daysSpent){
        double tempTotalExpenses = ((0.27 * miles) * daysSpent);
        double tempAllowedExpenses = 10 * daysSpent;
        double tempExcess = 0;
        double tempSaved = 0;

        if(tempTotalExpenses > tempAllowedExpenses){
            tempExcess = tempTotalExpenses - tempAllowedExpenses;
        }else{
            tempSaved = tempAllowedExpenses - tempTotalExpenses;
        }

        totalExpenses = totalExpenses + tempTotalExpenses;
        allowedExpenses = allowedExpenses + tempAllowedExpenses;
        excessExpenses = excessExpenses + tempExcess;
        savedExpenses = savedExpenses + tempSaved;

        return tempTotalExpenses; //returns raw expenses for the private car
    }
    double getPrivateCarExpenses(int daysSpent){
        double tempTotalExpenses = ((0.27 * miles) * daysSpent);
        double tempAllowedExpenses = 0;
        double tempExcess = 0;
        double tempSaved = 0;

        if(tempTotalExpenses > tempAllowedExpenses){
            tempExcess = tempTotalExpenses - tempAllowedExpenses;
        }else{
            tempSaved = tempAllowedExpenses - tempTotalExpenses;
        }

        totalExpenses = totalExpenses + tempTotalExpenses;
        allowedExpenses = allowedExpenses + tempAllowedExpenses;
        excessExpenses = excessExpenses + tempExcess;
        savedExpenses = savedExpenses + tempSaved;

        return tempTotalExpenses; //returns raw expenses for the private car
    }
    void setParkingFees(int fee){
        parkingFee = fee;
    }
    double getParkingFees(void){
        double tempParkingFee = 0;
        double tempAllowedFee = 0;
        double tempExcess = 0;
        double tempSaved = 0;

        if(privateVehicle){
            tempParkingFee = days * parkingFee;
            tempAllowedFee = days * 6;
        }
        else{
            tempParkingFee = 0;
        }

        if(tempParkingFee > tempAllowedFee){
            tempExcess = tempParkingFee - tempAllowedFee;
        }else{
            tempSaved = tempAllowedFee - tempParkingFee;
        }

        totalExpenses = totalExpenses + tempParkingFee;
        allowedExpenses = allowedExpenses + tempAllowedFee;
        excessExpenses = excessExpenses + tempExcess;
        savedExpenses = savedExpenses + tempSaved;

        return tempParkingFee;
    }

    void setRegistrationFees(double amount){
        registrationFees = amount;
    }
    double getRegistrationFees(void){
        return registrationFees;
    }

    