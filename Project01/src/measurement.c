#include <stdio.h>
#include <stdbool.h>
#include "measurement.h"
#include "constants.h" 


/*
 * obtainVoltage
 *
 * Prompts user to enter the voltage from a measurement.
 *
 * Paramters:
 *      *measurement - A pointer to the instance of a Measurement struct
 *
 * Returns:
 *      Nothing
 */
void obtainVoltage(Measurement *measurement){
    bool input_stream = true;
    
    while(input_stream){
        printf("Enter voltage (V):\t");
        scanf("%lf", &measurement->voltage);
    
        if(measurement->voltage > 0){
            input_stream = false;
            break;
        }
        else{
            continue;
        }
    }
}


/* obtainCurrent
 *
 * Prompts user to enter the current frmo a measurement.
 *
 * Parameters:
 *      *measurement - A pointer to the instance of a Measurement struct
 *
 * Returns:
 *      Nothing
 */
void obtainCurrent(Measurement *measurement){
    bool input_stream = true;

    while(input_stream){
        printf("Enter current (A):\t");
        scanf("%lf", &measurement->current);
    
        if(measurement->current > 0){
            input_stream = false;
            break;
        }
        else{
            continue;
        }
    }
}   


/*
 * whichMaximumResistance
 *
 * Locates which measurement the maximum resistance value occurred.
 *
 * Parameters:
 *      measurement[] - an array of the Measurement struct containing all 3 measurements
 *      maximum_restistance - double value of the largest calculated resistance within the measurements.
 *
 * Returns:
 *      The measurement number where the maximum resistance occurred.
 */
int whichMaximumResistance(Measurement measurement[], double maximum_resistance){
    int i = 0; // declaring iterator outside of loop for return

    for(i = 0; i < NUMBER_OF_TRIALS; i++){
        if (measurement[i].resistance == maximum_resistance){break;}
    }
    
    return i+1; // Returns the measurement number where maxiumum resistance occurred
}


/*
 * whichMinimumResistance
 *
 * Locates which measurement the minimum resistance value occurred.
 *
 * Parameters:
 *      measurement[] - an array of the Measurement struct containing all 3 measurements
 *      minimum_resistance - double value of the smallest calculated resistance within the measurements.
 *
 * Returns:
 *      The measurement number where the minimum resistance occurred.
 */
int whichMinimumResistance(Measurement measurement[], double minimum_resistance){
    int i = 0; // declaring iterator outside of loop for return

    for(i = 0; i < NUMBER_OF_TRIALS; i++){
        if (measurement[i].resistance == minimum_resistance){break;}
    }

    return i+1; // Returns the measurement number where minimum resistance occurred
}


/*
 * whichMaximumPower
 *
 * Locates which measurement the maximum power value occurred.
 *
 * Parameters:
 *      measurement[] - an array of the Measurement struct containing all 3 measurements.
 *      maximum_power - double value of the largest calculated power within the measurements.
 */
int whichMaximumPower(Measurement measurement[], double maximum_power){
    int i = 0; // declaring iterator outside of loop for return

    for(i = 0; i < NUMBER_OF_TRIALS; i++){
        if (measurement[i].power == maximum_power){break;}
    }
    
    return i+1; // Returns the measurement number where maximum power occurred
}
