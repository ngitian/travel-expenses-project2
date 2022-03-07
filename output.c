#include <stdio.h>
#include "output.h"

static float dollarConverter(int centsAmount);

void display(int totalExpense, int totalAllowable, int maxAllowable) {
    printf("\nHere are the results of your travel expenses:\n");
    printf("Total Expense incurred by the businessperson: $%.2f\n",dollarConverter(totalExpense));
    printf("Total Allowable expenses for the trip: $%.2f\n", dollarConverter(totalAllowable));

    if (totalExpense > maxAllowable) {
        printf("Excess reimbursed by the businessperson: $%.2f\n", dollarConverter(totalExpense - totalAllowable));
    } else {
        printf("Businessperson does not need to reimbursed any money.\n");
    }

    if (totalExpense < maxAllowable) {
        printf("Amount saved by the businessperson: $%.2f\n\n", dollarConverter(maxAllowable - totalExpense));
    } else {
        printf("No amount saved by the businessperson.\n\n");
    }
}

static float dollarConverter(int centsAmount) {
    return (float) centsAmount / 100.0;
}
