#ifndef RESISTOR_H
#define RESISTOR_H

typedef enum { FAIL, PASS } Status;

typedef struct {
    char identifier[5];
    double nominal_resistance;
    double tolerance;
    double deviation;       
    Status status;            // PASS or FAIL
    double measuredResistance[3];
    double percent_deviation;
} Resistor;

void inputResistor(Resistor *r);

void passOrFail(Resistor resistor);

//double calculateResistance(double voltage, double current);

#endif
