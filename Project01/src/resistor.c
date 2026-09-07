#include <stdio.h>
#include "resistor.h"

void inputResistor(Resistor *r){
    printf("Enter the resistor identifier:\t");
    scanf("%5s", r->identifier);
}

//double calculateResistance(double voltage, double current){
//    return voltage / current;
//}
