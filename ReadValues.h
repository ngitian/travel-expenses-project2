struct Money
{
    unsigned int dollars;
    unsigned int cents;
};

enum meridiem {am, pm};

int flushBuffer();
struct Money* readDollarInput(char *prompt);
unsigned int readPositiveInteger(char *prompt, int minValue, int maxValue);
