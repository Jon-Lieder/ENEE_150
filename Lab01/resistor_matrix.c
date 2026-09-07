/* Name:            Jon Lieder
 * Course:          ENEE 150
 * Project:         Lab 01
 * Assignmnet:      Problem 7 -- Resistor Measurement Matrix
 * Date:            September 3, 2026
 *
 * Description:     
 * This program uses a 2-Dimensional array to take in resistance values of 3 different resistors
 * across four different trials for each resistor with command line input. The average resistance  
 * of each resistor is calculated and displays the input and result in an organized grid console 
 * output in the terminal.
 */

#include <stdio.h>



/* 
 * displayResistance
 *
 * Formats and displays the target output of:
 *      - An underscord divisor line to separate input with output for the user
 *      - All 12 inputted resistance values in a 3 x 4 grid with labels
 *      - All 3 resulting average resistance values 
 *
 * Parameters:
 *      resistance[][] - 2-Dimensional array containing all 12 resistance values
 *      resistors - integer value for amount of rows in resistance[][] ie. resistance[resistors][]
 *      trials - integer value for amount of trials for a given resistor ie. resistance[][trials]
 *      average_resistance - Array containing the resulting average resistance value of each resistor
 *                           over the four different trials
 *
 * Returns:
 *      Nothing
 */

void displayResistance(double *resistance, int resistors, int trials, double *average_resistance){
    /* rounding_correction fixes the issue of printf() rounding down numbers that should be rounded 
     * up resulting in a rounding error. The precision is overkill but ensures no overcorrection. */
    double rounding_correction = 0.000000001;

    /* Separates the input and output display for the user for readability */
    printf("\n______________________________________________________________________________\n");
    printf("\t\tTrial 1\t\tTrial 2\t\tTrial 3\t\tTrial 4\n");
    for(int i = 0; i < resistors; i++){
        printf("Resistor %d\t", i+1);
        for(int j=0; j < trials; j++){
            printf("%.1lf\t\t", resistance[(i * trials) + j]); 
        }
        printf("\n");
    }
    printf("\n");

    for(int i = 0 ; i < resistors; i++){
        printf("Resistor %d Average:\t%.2f ohms\n", i + 1, average_resistance[i] + rounding_correction);
    }
}



/*
 * averageResistance
 *
 * Calculates the average resistance of each resistor stored within resistance[][].
 *
 * Parameters:
 *      resistance[][] - 2-Dimensional array containing all 12 resistance values
 *      resistors - integer value for amount of rows in resistance[][] ie. resistance[resistors][] 
 *      trials - integer value for amount of trials for a given resistor ie. resistance[][trials]
 *      average_resistance[] - Array containing the resulting average resistance value of each resistor
 *                             over the four different trials
 *
 * Returns:
 *      Nothing
 */

void averageResistance(double *resistance, int resistors, int trials, double *average_resistance){
    for(int i = 0; i < resistors; i++){
        for(int j = 0; j < trials ; j++){
            /* Calculates the average of each resistor */
            average_resistance[i] += resistance[(i * trials) + j] / trials; 
        }
    }
}



/*
 * obtainValues
 *
 * Handles input obtaining resistance values from the user in a nested for loop.
 *
 * Parameters:
 *      resistance[][] - 2-Dimensional array containing all 12 resistance values
 *      resistors - integer value for amount of rows in resistance[][] ie. resistance[resistors][]
 *      trials - integer value for amount of trials for a given resistor ie. resistance[][trials]
 *
 * Returns:
 *      Nothing
 */

void obtainValues(double *resistance, int resistors, int trials){
    for(int i = 0; i < resistors; i++){
        for(int j = 0; j < trials; j++){
            printf("Enter resistor %d trial %d: ", i+1, j+1);
            scanf("%lf", &resistance[(i * trials) +j]);
        }
    }
}



int main(){
    int trials = 4;     // Used to avoid ghost numbers and increase readability of loops and arrays
    int resistors = 3;  // Used to avoid ghost numbers and increase readability of loops and arrays
    double resistance[resistors][trials];
    double average_resistance[] = {0, 0, 0};   

    /* (double *) sets the size of jumps for pointer arithmetic to sizeof(double). Needed because no
     * column count information is known to the compiler by default */ 
    obtainValues((double *)resistance, resistors, trials);
    averageResistance((double *)resistance, resistors, trials, average_resistance);
    displayResistance((double *)resistance, resistors, trials, average_resistance);    

    return 0;
}
