#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "resistor.h"


void inputResistor(Resistor *r){
    bool input_stream = true;

    printf("Enter the resistor identifier:\t");
    scanf("%5s", r->identifier);
    
    while(input_stream){
        printf("Enter the nominal resistance of resistor %5s:\t", r->identifier);
        scanf("%lf", &r->nominal_resistance);

        if(r->nominal_resistance > 0){
            input_stream = false;
            break;
        }

        else{
            continue;
        }
    }
    
    input_stream = true; 

    while(input_stream){
        printf("Enter the allowable tolerance as a percentage in range of [0%%, 100%%]:\t");
        scanf("%lf", &r->tolerance);
        
        if(r->tolerance >= 0 && r->tolerance <= 100){
            input_stream = false;
            break;
        }
        else{
            continue;
        }
    }    



// printf("%lf\n", r->nominal_resistance); 
}


void passOrFail(Resistor *resistor){
    printf("deviation = %lf\n", resistor->percent_deviation);
    printf("tolerance = %lf\n", resistor->tolerance);
    switch(fabs(resistor->percent_deviation) > resistor->tolerance){
        case 0: // deviation LESS THAN tolerance
            resistor->status = PASS;
            break;
        case 1: // deviation MORE THAN tolerance
            resistor->status = FAIL;  
            break;
    }
}


void outputReport(Resistor *r){}


void recordCounts(Resistor *resistor){
    
}
//double calculateResistance(double voltage, double current){
//    return voltage / current;
//}
