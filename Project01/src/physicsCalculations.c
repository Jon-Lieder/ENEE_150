#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "physicsCalculations.h"
#include "measurement.h"
#include "constants.h"

/* 
 * ------------------------------
 * |    RESISTANCE FUNCTIONS    |
 * ------------------------------
 */


/*
 * averageResistance
 *
 * Calculates the average resistance for a resistor across 3 different measurements.
 *
 * Parameters:
 *      measurement[] - an array of the Measurement struct containing all three measurements
 *
 * Returns:
 *      average_resistance
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


/*
 * calculateResistance
 *
 * Calculates the resistance of a measurement for the current resistor.
 *
 * Parameters:
 *      voltage - double value containing the voltage of a measurement in volts
 *      current - double value containing the current of a measurement in amperes
 *
 * Returns:
 *      voltage / current (resistance) 
 */
double calculateResistance(double voltage, double current){ 
    bool input_stream = true;
    
    while(input_stream){
        if(voltage > 0){
            break;
        }
        else{
            continue;
        }
    }
    while(input_stream){
        if(current > 0){
            input_stream = false;
            break;
        }
        else{
            continue;
        }
    }
    
    return voltage / current; // resistance formula from ohm's law
}


/*
 * maximumResistance
 *
 * Determines the maximum resistance within the 3 measurements
 *
 * Parameters:
 *      measurement[] - an array of the Measurement struct containing all 3 measurements
 *
 * Returns:
 *      maximum_resistance
 */
double maximumResistance(Measurement measurement[]){
    double maximum_resistance = 0;
    
    for (int i = 0; i < NUMBER_OF_TRIALS; i++){
        if (measurement[i].resistance > maximum_resistance){
            maximum_resistance = measurement[i].resistance;
        }
    }

    return maximum_resistance;
}


/*
 * minimumResistance
 *
 * Determines the minimum resistance within the 3 measurements
 *
 * Parameters:
 *      measurement[] - an array of the Measurement struct containing all 3 measurements
 *
 * Returns:
 *      minimum_resistance
 */
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


/*
 * calculatePower
 *
 * calculates the power of a given measurement for the current resistor.
 *
 * Parameters:
 *      voltage - double value containing the voltage reading of a measurement in volts
 *      current - double value containing the current reading of a measurement in amperes
 *
 * Returns:
 *      voltage * current (power)
 */
double calculatePower(double voltage, double current){ 
    return voltage * current; // Power formula ( P = IV )
}


/*
 * maximumPower
 *
 * Determines the maximum power that occurred within the three measurements for the current resistor.
 *
 * Parameters:
 *      measurement[] - an array of the Measurement struct containing all 3 measurements.
 *
 * Returns:
 *      maximum_power
 */
double maximumPower(Measurement measurement[]){
    double maximum_power = 0;

    for (int i = 0; i < NUMBER_OF_TRIALS; i++){
        if (measurement[i].power > maximum_power){
            maximum_power = measurement[i].power;
        }
    }

    return maximum_power;
}


/*
 * ------------------------------
 * |    Statistics Functions    |
 * ------------------------------
 */


/*
 * percentDeviation
 *
 * Calculates the percent deviation of each measurement for the current resistor/ 
 *
 * Parameters:
 *      *resistor - a pointer to an instance of the resistor struct 
 *      average_resistance - double value containing the average resistance for the current resistor
 *                           across all 3 measurements.
 *
 * Returns:
 *      Nothing
 */
void percentDeviation(Resistor *resistor, double average_resistance){
    // Formula for percent deviation
    resistor->percent_deviation = (average_resistance - resistor->nominal_resistance) 
                                    / resistor->nominal_resistance * 100 ;
}
