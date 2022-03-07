#ifndef READVALUES_H
#define READVALUES_H
struct Money
{
    unsigned int dollars;
    unsigned int cents;
};

enum meridiem {am, pm};

struct Hour
{
    unsigned int hour;
    enum meridiem meridiem;
};

int flushBuffer();
struct Money* readDollarInput(char *prompt);
unsigned int readPositiveInteger(char *prompt, int minValue, int maxValue);
struct Hour* readHour(char *prompt);
#endif