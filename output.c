#include <stdio.h>

static float dollarConverter(int centsAmount);

void display(int totalExpense, int totalAllowable) {
    printf("Here are the results of your travel expenses:\n");
    printf("Total Expense incurred by the businessperson: $%.2f\n", dollarConverter(totalExpense));
    printf("Total Allowable expenses for the trip: $%.2f\n", dollarConverter(totalAllowable));
    printf("Excess reimbursed by the businessperson: $%.2f\n", dollarConverter(totalExpense - totalAllowable));
    printf("Amount saved by the businessperson: $%.2f\n\n", dollarConverter(totalAllowable - totalExpense));
}

static float dollarConverter(int centsAmount) {
    return (float) centsAmount / 100.0;
}
