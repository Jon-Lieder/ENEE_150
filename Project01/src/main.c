#include <stdio.h>
#include <stdbool.h>

#include "resistor.h"
#include "measurement.h"

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

//    FILE *input_ptr;
    
//    char identifier[10];
/*    
    double voltages[];
    double currents[];
    double power[];
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
    Resistor r1 = {0};
    Measurement m1 = {10, 10, r1, 1};
    input_resistor(&r1);

    return 0;
}
