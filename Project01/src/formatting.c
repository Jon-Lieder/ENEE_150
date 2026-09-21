#include <stdio.h>
#include <string.h>
#include "formatting.h"
#include "measurement.h"
#include "resistor.h"

void displayToFile(Measurement measurement[], Resistor *resistor){
    char choice[] = "No";

    printf("ID\t\tNominal\Avg R\t\tMin T\t\tMax R\tMax Power\tDeviation\tStatus\n");
    printf("Resistor identifier: %s\n", resistor->identifier);    
    if (!strcmp(choice,"No")){
        printf("Valid Components:\t\n");
        printf("Invalid Records:\t\t\n");
        printf("Passed:\t\t\t\t\n");
        
        //maxDeviation
        printf("Greatest Deviation:\t\n");
    }
}
