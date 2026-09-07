#ifndef RESISTOR_H
#define RESISTOR_H

typedef enum { FAIL, PASS } Status;

typedef struct {
    char identifier[5];
    double resistance;
    double tolerance;
    double deviation;       
    Status status;            // PASS or FAIL
} Resistor;

void input_resistor(Resistor *r);

#endif
