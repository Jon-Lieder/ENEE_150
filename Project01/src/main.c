#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "resistor.h"
#include "measurement.h"
#include "physicsCalculations.h"
#include "constants.h"
#include "formatting.h"

//void formatDisplay(double *resistances, double *voltages, double *currents, double *power, double average resistance){}


//int main(int argc, char *argv[]){
int main(){
    bool additional_resistor = true;
    char choice[] = "yes";
    FILE *outputfile_ptr;
    int count = 1;
    int capacity = 2;
    Resistor *resistors = malloc(capacity * sizeof(Resistor));

//    char identifier[10];
    outputfile_ptr = fopen("circuit_data.txt", "w");

    if(outputfile_ptr == NULL){
        printf("Error opening or creating the file.\n");
        return 1;
    }

    while(additional_resistor){

        if (count == capacity){
            capacity += 1;
            Resistor *temp = realloc(resistors, capacity * sizeof(Resistor));
            resistors = temp;

        }

        Measurement measurement[NUMBER_OF_TRIALS];
 
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

        double avgRes = averageResistance(measurement);
        printf("%lf\n", avgRes);

        double maximum_power = maximumPower(measurement);
        double minimum_resistance = minimumResistance(measurement);
        double maximum_resistance = maximumResistance(measurement);
    
        printf("Max Pow = %lf\n", maximum_power);
        printf("Min Res = %lf\n", minimum_resistance);
        printf("Max Res = %lf\n", maximum_resistance);

        int minimum_resistance_meas = whichMinimumResistance(measurement, minimum_resistance); 
        int maximum_resistance_meas = whichMaximumResistance(measurement, maximum_resistance);
        int maximum_power_meas = whichMaximumPower(measurement, maximum_power);

        printf("Minimum resistance measurement = %d\n", minimum_resistance_meas);
        printf("Maximum resistance measurement = %d\n", maximum_resistance_meas);
        printf("Maximum power measurement = %d\n", maximum_power_meas);

        percentDeviation(&resistors[count - 1], avgRes);    
        passOrFail(&resistors[count - 1]);
        printf("Standard Deviation = %lf\n", resistors[count - 1].percent_deviation);
        printf("Resistor status:%d\n", resistors[count - 1].status);

        printf("Add additional resistor? (Yes/No):\t");
        scanf("%s", &choice);
        printf("%s\n", choice);
        
        if(!strcmp(choice, "Yes")){
            count++;
            continue;
        }

        else{
            additional_resistor = false;
            break;
        }

//        displayToFile();    

    }
    
    fclose(outputfile_ptr);

    return 0;
}
