/* Name:            Jon Lieder
 * Course:          ENEE 150
 * Project:         Lab 01
 * Assignment:      Problem 13 - Voltage Measurement Data File
 * Date:            September 4, 2026
 *
 * Description:
 *
 */


#include <stdio.h>

int voltageRead(FILE *file_ptr){
    int i = 0;
    int count = 0;
    float voltages[8];
    float maximum_voltage = 0;
    float minimum_voltage = 100; // Arbitrary large value to make for easier logic in line 24
    float voltages_sum = 0;
    float average_voltage = 0;

    while(fscanf(file_ptr, "%f", &voltages[i]) != EOF){
        if (voltages[i] < minimum_voltage){
            minimum_voltage = voltages[i];
        }
        
        if (voltages[i] > maximum_voltage){
            maximum_voltage = voltages[i];
        }

        voltages_sum += voltages[i];
        count++;
        i++;
    }

    average_voltage = voltages_sum / count;

    printf("VOLTAGE DATA SUMMARY\n\n");
    printf("Number of measurements:\t8\n");
    printf("Average Voltage:\t%.2f V\n", average_voltage);
    printf("Minimum Voltage:\t%.2f V\n", minimum_voltage);
    printf("Maximum_Voltage:\t%.2f V\n", maximum_voltage);
}


int main(int argc, char *argv[]){
    FILE *file_ptr;
    
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
