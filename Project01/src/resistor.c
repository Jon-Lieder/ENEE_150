#include <stdio.h>
#include "resistor.h"

void input_resistor(Resistor *r){
    printf("Enter the resistor identifier:\t");
    scanf("%5s", r->identifier);
}
