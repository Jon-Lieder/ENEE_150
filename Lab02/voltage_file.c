/* Name:            Jon Lieder
 * Course:          ENEE 150
 * Project:         Lab 01
 * Assignment:      Problem 13 - Voltage Measurement Data File
 * Date:            September 4, 2026
 *
 * Description:
 * This program reads voltage values from "voltage.txt". With these values, the minimum and
 * maximum voltages are obtained by comparing each of the values and the average voltage is 
 * calculated. The results are then output on the command line in a formatted display.
 */


#include <stdio.h>

/*
 * voltageRead
 *
 * Reads each voltage value from a file and locates the minimum and maximum data point. Calculates 
 * the average with a running sum to be divided by the amount of data points that were recorded. 
 *
 * Parameters:
 *      *file_ptr - a pointer to the inputted file
 *
 * Returns:
 *      Nothing
 */
void voltageRead(FILE *file_ptr){
    int count = 0;
    float voltages[8];
    float maximum_voltage = 0;
    float minimum_voltage = 100; // Arbitrary large value to make for easier logic in line 24
    float voltages_sum = 0;
    float average_voltage = 0;

    while(fscanf(file_ptr, "%f", &voltages[count]) != EOF){
        if (voltages[count] < minimum_voltage){
            minimum_voltage = voltages[count];
        }
        
        if (voltages[count] > maximum_voltage){
            maximum_voltage = voltages[count];
        }

        voltages_sum += voltages[count];
        count++;
    }

    average_voltage = voltages_sum / count;

    printf("VOLTAGE DATA SUMMARY\n\n");
    printf("Number of measurements:\t%d\n", count);
    printf("Average Voltage:\t%.2f V\n", average_voltage);
    printf("Minimum Voltage:\t%.2f V\n", minimum_voltage);
    printf("Maximum_Voltage:\t%.2f V\n", maximum_voltage);
}


int main(int argc, char *argv[]){
    FILE *file_ptr;
  
    // OPTIONAL TO GET USED TO THIS TOPIC:
    // adds a file flag for command line arguments to override the default file   
    if ((argv[0] == "-f" || argv[0] == "--file") && argc == 2){
        file_ptr = fopen(argv[1], "r"); 
    }
    else{
        file_ptr = fopen("voltage.txt" , "r");
    }
    
    voltageRead(file_ptr);

    if (file_ptr == NULL){
        printf("File could not be opened correctly");
        return 1;
    }

    fclose(file_ptr);

    return 0;
}
