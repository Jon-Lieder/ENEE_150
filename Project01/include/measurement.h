#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include "resistor.h"

typedef struct {
    double voltage;
    double current;
    Resistor resistor;
    double power;
    double resistance;
//    double standard_deviation;
} Measurement;

// void takeMeasurement();

int whichMaximumResistance(Measurement measurement[], double maximum_resistance);

int whichMinimumResistance(Measurement measurement[], double minimum_resistance);
//double calculatePower(double voltage, double current);


int whichMaximumPower(Measurement measurement[], double maximum_power);

#endif
