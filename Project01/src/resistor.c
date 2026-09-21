#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "resistor.h"

/*
 * inputResistor
 *
 * Prompts the user to enter a resistor identifier, nominal resistance, and tolerance percentage for
 * that resistor. Contains basic error handling for positive nominalresistance and positive
 * tolerance values.
 *
 * Parameters:
 *      *resistor - a pointer to the current resistor within the resistor struct 
 *
 * Returns:
 *      Nothing
 */
void inputResistor(Resistor *resistor){
    bool input_stream = true;

    printf("Enter the resistor identifier:\t");
    scanf("%5s", resistor->identifier);
    
    while(input_stream){
        printf("Enter the nominal resistance of resistor %5s:\t", resistor->identifier);
        scanf("%lf", &resistor->nominal_resistance);

        if(resistor->nominal_resistance > 0){
            input_stream = false;
            break;
        }

        else{
            continue;
        }
    }
    
    input_stream = true; 

    while(input_stream){
        printf("Enter the allowable tolerance as a percentage in range of [0%%, 100%%]:\t");
        scanf("%lf", &resistor->tolerance);
        
        if(resistor->tolerance >= 0 && resistor->tolerance <= 100){
            input_stream = false;
            break;
        }
        else{
            continue;
        }
    }    
}


/*
 * Determines whether or not the current resistor's percent deviation is less than or greater than 
 * the acceptable tolerance and classifying that result as pass or fail.
 *
 * Parameters:
 *      *resistor - a pointer containing the current resistor within the Resistor struct
 *
 * Returns:
 *      Nothing
 */
void passOrFail(Resistor *resistor){
    switch(fabs(resistor->percent_deviation) > resistor->tolerance){
        case 0: // deviation LESS THAN tolerance
            resistor->status = PASS;
            break;
        case 1: // deviation MORE THAN tolerance
            resistor->status = FAIL;  
            break;
    }
}

