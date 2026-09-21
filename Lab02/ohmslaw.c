/* Name:            Jon Lieder
 * Course:          ENEE 150
 * Assignment:      Lab 01
 * Project:         Problem 1 -- Ohm's Law Calculator
 * Date:            September 3, 2026
 *
 * Description:
 * This program prompts the user for [PLACEHOLDER] then calculates voltage, 
 * current, or resistance according to Ohm's Law.
 */

#include <stdio.h>


/*
 * calculateVoltage
 *
 * Calculates the voltage of a measurement in accordance to Ohm's Law ( V=IR )
 *
 * Parameters:
 *      current - double value containing the current measurement in amperes
 *      resistance - double value containing the resistance measurement in ohms
 *
 * Returns:
 *      current * resistance (voltage)
 */
double calculateVoltage(double current, double resistance){
    return current * resistance;
}


/*
 * calculateCurrent
 *
 * Calculates the current of a measurement in accordance to Ohm's Law ( V=IR )
 *
 * Parameters:
 *      voltage - double value containing the voltage measurement in volts
 *      resistance - double value containing the resistance measurement in ohms
 *
 * Returns:
 *      voltage / resistance (current)
 */
double calculateCurrent(double voltage, double resistance){
    return voltage / resistance;
}


/*
 * calculateResistance
 *
 * Calculates the resistance of a measurement in accordance to Ohm's Law ( V=IR )
 *
 * Parameters:
 *      voltage - double value containing the voltage measurement in volts
 *      current - double value containing the current measurement in amperes
 *
 * Returns:
 *      voltage / current (resistance)
 */
double calculateResistance(double voltage, double current){
    return voltage / current;
}



int main(){
    int expression;
    double voltage;
    double current;
    double resistance;
    
    printf("OHM'S LAW CALCULATOR\n\n1. Calculate Voltage\n2. Calculate Current\n3. Calculate Resistance\n\n");
    printf("Enter Selection: ");
    scanf("%d", &expression);

    switch (expression){
        case 1:
            printf("Enter current in amperes: ");
            scanf("%lf", &current);
            printf("Enter resistance in ohms: ");
            scanf("%lf", &resistance);
            voltage = calculateVoltage(current, resistance);
            printf("Voltage = %.2f V\n", voltage);
            break;

        case 2:
            printf("Enter voltage in volts: ");                                                           
            scanf("%lf", &voltage);                                                  
            printf("Enter resistance in ohms: ");                                                           
            scanf("%lf", &resistance);                                               
            current = calculateCurrent(voltage, resistance);                    
            printf("Current = %.2f A\n", current);                                                           
            break; 

        case 3:
            printf("Enter voltage in volts: ");
            scanf("%lf", &voltage);
            printf("Enter current in amperes: ");
            scanf("%lf", &current);
            resistance = calculateResistance(voltage, current);
            printf("Resistance = %.2f ohms\n", resistance);
            break;
    }
        

    return 0;
}
