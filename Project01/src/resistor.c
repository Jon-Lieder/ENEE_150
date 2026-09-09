#include <stdio.h>
#include "resistor.h"

void inputResistor(Resistor *r){
    printf("Enter the resistor identifier:\t");
    scanf("%5s", r->identifier);

    printf("Enter the nominal resistance of resistor %5s:\t", r->identifier);
    scanf("%lf", &r->nominal_resistance);

    printf("Enter the allowable tolerance as a percentage:\t");
    scanf("%lf", &r->tolerance);
    // printf("%lf\n", r->nominal_resistance); 
}


void passOrFail(Resistor resistor){
    switch(resistor.deviation > resistor.tolerance){
        case 0: // deviation LESS THAN tolerance
            resistor.status = PASS;
            break;
        case 1: // deviation MORE THAN tolerance
            resistor.status = FAIL;  
            break;
    }
}

//double calculateResistance(double voltage, double current){
//    return voltage / current;
//}
