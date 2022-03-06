#ifndef READVALUES_H
#define READVALUES_H
struct Money
{
    long dollars;
    long cents;
};

int flushBuffer();
struct Money* readDollarInput(char *prompt);
#endif
