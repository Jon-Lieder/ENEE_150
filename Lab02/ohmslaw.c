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



double calculateVoltage(double current, double resistance){
    return current * resistance;
}



double calculateCurrent(double voltage, double resistance){
    return voltage / resistance;
}



double calculateResistance(double voltage, double current){
    return voltage / current;
}



int main(){
    char expression;
    double voltage;
    double current;
    double resistance;
    
    printf("pick\n");
    scanf("%c", &expression);

    switch (expression){
        case 'v':
            printf("current\n");
            scanf("%lf", &current);
            printf("resistance\n");
            scanf("%lf", &resistance);
            voltage = calculateVoltage(current, resistance);
            printf("%.2f\n", voltage);
            break;

        case 'c':
            printf("voltage\n");                                                           
            scanf("%lf", &voltage);                                                  
            printf("resistance\n");                                                           
            scanf("%lf", &resistance);                                               
            current = calculateCurrent(voltage, resistance);                    
            printf("%.2f\n", current);                                                           
            break; 

        case 'r':
            printf("voltage\n");
            scanf("%lf", &voltage);
            printf("current\n");
            scanf("%lf", &current);
            resistance = calculateResistance(voltage, current);
            printf("%.2f\n", resistance);
            break;
    }
        

    return 0;
}
