#include <stdio.h>
#include "physicsCalculations.h"

/* 
 * ------------------------------
 * |    RESISTANCE FUNCTIONS    |
 * ------------------------------
 */

double averageResistance(double *voltages, double *currents){
    double averageResistance = 0;
    
    for (int i = 0; i < 3; i++){
        averageResistance += (1.0 / 3.0) * voltages[i] / currents[i];
        printf("loop in physicsCalculations.c");
        printf("Volage: %lf (V)\n", voltages[i]);
        printf("Current: %lf (A)\n", currents[i]);
    }
    printf("Average Resistance = %lf\n", averageResistance);
    
    return averageResistance;
}
double calculateResistance(double voltage, double current){
    return voltage / current;
}
double maximumResistance(){return 0;}
double minimumResistance(){return 0;}

/*
 * -------------------------
 * |    Power Functions    |
 * -------------------------
 */

double averagePower(){return 0;}
double calculatePower(){return 0;}
double maximumpower(){return 0;}
