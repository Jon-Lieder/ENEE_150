#ifndef RESISTOR_H
#define RESISTOR_H

typedef enum { FAIL, PASS } Status;

typedef struct {
    char identifier[5];
    double resistance;
    double tolerance;
    double deviation;       
    Status status;            // PASS or FAIL
    double measuredResistance[3];
} Resistor;

void inputResistor(Resistor *r);

//double calculateResistance(double voltage, double current);

#endif
