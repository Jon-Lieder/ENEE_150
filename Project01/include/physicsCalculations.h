#ifndef PHYSICSCALCULATIONS_H
#define PHYSICSCALCULATIONS_H

#include "measurement.h"

double averagePower();
double averageResistance(Measurement measurement[]);
double calculatePower();
double calculateResistance(double voltage, double current);
double maximumPower(Measurement measurement[]);
double maximumResistance(Measurement measurement[]);
double minimumResistance(Measurement measurement[]);

#endif
