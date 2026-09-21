/* Name:            Jon Lieder
 * Course:          ENEE 150
 * Project:         Project 01
 * Assignment:      Automated Circuit Test Analyzer
 * Date:            September 20, 2026
 *
 * Description:
 * This program takes in an input file named "" containing the resistor's identifier, nominal resistance,
 * tolerance, voltage and current measurements from three different readings. It then calculates 
 * percent error, average resistance, and a few extreme values. Lastly, the percent error is compared
 * to the acceptable tolerance to classify the component as pass or fail. All results are written to
 * an outputfile "" in ./outputFiles and displays a formatted report for the resistor. This process can
 * be repeated for multiple resistor and ends upon user input.
 */


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "resistor.h"
#include "measurement.h"
#include "physicsCalculations.h"
#include "constants.h"
#include "formatting.h"



int main(int argc, char *argv[]){
    bool additional_resistor = true;

    FILE *input_file_ptr;
    FILE *output_file_ptr;

    char choice[10] = "Yes";
    char *input_file_name = argv[1];
    char input_file_working_dir[] = "tests/";
    
    int count = 1;
    int capacity = 2;
    int maximum_power_meas, minimum_resistance_meas, maximum_resistance_meas;

    double avgRes, maximum_power, minimum_resistance, maximum_resistance;
    
    // Dynamic memory allocation. Determines the memory size each Resistor takes to allow for
    // n Resistors to be inputted by the user.
    Resistor *resistors = malloc(capacity * sizeof(Resistor));

    printf("Input File Name:\t%s\n", input_file_name);

    // Concatenate the input filename with the name of the directory it is contained in.
    strcat(input_file_working_dir, input_file_name);
    output_file_ptr = fopen("outputFiles/circuit_report.txt", "w");
    input_file_ptr = fopen(input_file_working_dir, "r");


    if(output_file_ptr == NULL){
        printf("Error opening or creating the file.\n");
        return 1;
    }

    while(additional_resistor){

        // This code block appends a new instance of resistor by reallocating the memory set aside 
        // for the resistors. 
        if (count == capacity){
            capacity += 1;
            Resistor *temp = realloc(resistors, capacity * sizeof(Resistor));
            resistors = temp;

        }
        
        Measurement measurement[NUMBER_OF_TRIALS];
        
        // obtain resistor information. more info in src/resistor.c
        inputResistor(&resistors[count - 1]); 

    // PUT INTO RESISTOR.C | RESISTOR.H
        for (int i=0; i < NUMBER_OF_TRIALS; i++){
            measurement[i].resistor = resistors[count - 1];

            printf("Measurement %d\n\n", i+1);
            obtainVoltage(&measurement[i]);
            obtainCurrent(&measurement[i]);
            measurement[i].power = calculatePower(measurement[i].voltage, measurement[i].current);
            measurement[i].resistance = calculateResistance(measurement[i].voltage, measurement[i].current);
        }

        avgRes = averageResistance(measurement);
        printf("%lf\n", avgRes);

        maximum_power = maximumPower(measurement);
        minimum_resistance = minimumResistance(measurement);
        maximum_resistance = maximumResistance(measurement);
    
        printf("Max Pow = %lf\n", maximum_power);
        printf("Min Res = %lf\n", minimum_resistance);
        printf("Max Res = %lf\n", maximum_resistance);

        minimum_resistance_meas = whichMinimumResistance(measurement, minimum_resistance); 
        maximum_resistance_meas = whichMaximumResistance(measurement, maximum_resistance);
        maximum_power_meas = whichMaximumPower(measurement, maximum_power);

        printf("Minimum resistance measurement = %d\n", minimum_resistance_meas);
        printf("Maximum resistance measurement = %d\n", maximum_resistance_meas);
        printf("Maximum power measurement = %d\n", maximum_power_meas);

        percentDeviation(&resistors[count - 1], avgRes);    
        passOrFail(&resistors[count - 1]);
        printf("Standard Deviation = %lf\n", resistors[count - 1].percent_deviation);
        printf("Resistor status:%d\n", resistors[count - 1].status);

        printf("Add additional resistor? (Yes/No):\t");
        scanf("%s", choice);
        printf("%s\n", choice);
        
        // Continues the next iteration of the main loop if the user has more resistors to enter
        if(!strcmp(choice, "Yes")){
            count++; 
            continue;
        }
        
        // Begins program exit sequence by breaking the loop condition
        else{
            additional_resistor = false;
        }

        displayToFile(measurement, &resistors[count -1]);    

    }
    
    // File closing
    fclose(output_file_ptr);
    fclose(input_file_ptr);

    // Prevents memory leakage. Doesn't really do anything in this program as it's not a long running
    // program, but good practice.
    free(resistors);

    return 0;
}
