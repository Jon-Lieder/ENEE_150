#include <stdio.h>
#include "physicsCalculations.h"
#include "measurement.h"
#include "constants.h"

/* 
 * ------------------------------
 * |    RESISTANCE FUNCTIONS    |
 * ------------------------------
 */

double averageResistance(Measurement measurement[]){
    double average_resistance = 0;
    
    for (int i = 0; i < 3; i++){
        average_resistance += measurement[i].voltage / ( measurement[i].current * NUMBER_OF_TRIALS );
        printf("loop in physicsCalculations.c\n");
        printf("Volage: %lf (V)\n", measurement[i].voltage);
        printf("Current: %lf (A)\n", measurement[i].current);
    }
    printf("Average Resistance = %lf\n", average_resistance);
    
    return average_resistance;
}



double calculateResistance(double voltage, double current){ return voltage / current; }



double maximumResistance(Measurement measurement[]){
    double maximum_resistance = 0;
    
    for (int i = 0; i < NUMBER_OF_TRIALS; i++){
        if (measurement[i].resistance > maximum_resistance){
            maximum_resistance = measurement[i].resistance;
        }
    }

    return maximum_resistance;
}



double minimumResistance(Measurement measurement[]){
    double minimum_resistance = measurement[0].resistance;

    for (int i = 0; i < NUMBER_OF_TRIALS; i++){                                                     
        if (measurement[i].resistance < minimum_resistance){                                        
            minimum_resistance = measurement[i].resistance;                                         
        }                                                                                           
    }   

    return minimum_resistance;
}

/*
 * -------------------------
 * |    Power Functions    |
 * -------------------------
 */


// WASTE OF TIME
/*
double averagePower(double *voltages, double *currents){
    double averagePower = 0;

    for (int i = 0; i < NUMBER_OF_TRIALS; i++ ){
        averagePower += voltages[i] * ( currents[i] * NUMBER_OF_TRIALS ); 
    }

    return averagePower;
}
*/

double calculatePower(double voltage, double current){ return voltage * current; }

double maximumPower(Measurement measurement[]){
    double maximum_power = 0;

    for (int i = 0; i < NUMBER_OF_TRIALS; i++){
        if (measurement[i].power > maximum_power){
            maximum_power = measurement[i].power;
        }
    }

    return maximum_power;
}
