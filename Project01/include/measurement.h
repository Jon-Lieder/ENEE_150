#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include "resistor.h"

typedef struct {
    double voltage;
    double current;
    Resistor resistor;
    double power;
} Measurement;

void takeMeasurement(){}

#endif
