#include <stdio.h>
#include <stdbool.h>

#include "resistor.h"
#include "measurement.h"
#include "physicsCalculations.h"
#include "constants.h"

//void formatDisplay(double *resistances, double *voltages, double *currents, double *power, double average resistance){}


//void calculateResistance(double *voltages, double *currents){}


//void calculatePower(double *voltages, double *currents){}
//const bool PASS = true;
//const bool FAIL = false;

/*
Resistor makeResistor(){
    return resistor; 
}

Measurement makeMeasurement(){ 
    return measurementi;  
}
*/

int main(int argc, char *argv[]){
    // enum continue_loop = {YES, NO};
//    FILE *input_ptr;
//    char identifier[10];
/*    double power[];
    double resistances[];
    double nominal_resistances[];
    double tolerances[];

    
    double average_resistance;

    double minimum_resistance;
    double maximum_resistance;
    double maximum_power;

    int measurement_number;
    int valid_records;
    int invalid_records;
    int passing_components;
    int failing_components;

    double percent_deviation;
    bool pass_fail;
*/
    Resistor resistor1 = {0};
    Measurement measurement[NUMBER_OF_TRIALS];
   
    inputResistor(&resistor1); 
    for (int i=0; i<3; i++){
        measurement[i].resistor = resistor1;

        printf("Measurement %d\n\n", i+1);
        printf("Enter voltage (V): ", i+1);
        scanf("%lf", &measurement[i].voltage);
        printf("Enter current (A): ", i+1);
        scanf("%lf", &measurement[i].current);
        measurement[i].power = calculatePower(measurement[i].voltage, measurement[i].current);
        measurement[i].resistance = calculateResistance(measurement[i].voltage, measurement[i].current);
        printf("%lf\n", measurement[i].power);
    }

    double avgRes = averageResistance(measurement);
    //double avgPow = averagePower(voltages, currents);
    //resistor1.resistance = calculateResistance(20, 10);
    printf("%lf\n", avgRes);
    //printf("%lf\n", avgPow);
    //m1.power = calculatePower(20,10);
//    printf("%lf\n", resistor1.resistance);
//    printf("%lf\n", measurement[2].power);
    
        //printf("Enter another resistor? (yes/no):\t");
        //scanf("%3s", &continue_loop);

    double maxPow = maximumPower(measurement);
    double minRes = minimumResistance(measurement);
    double maxRes = maximumResistance(measurement);
    
    printf("Max Pow = %lf\n", maxPow);
    printf("Min Res = %lf\n", minRes);
    printf("Max Res = %lf\n", maxRes);



    return 0;
}
