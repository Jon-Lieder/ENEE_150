#include <stdio.h>
#include <stdbool.h>
#include "measurement.h"
#include "constants.h" 



void obtainVoltage(Measurement *measurement){
    bool input_stream = true;
    
    while(input_stream){
        printf("Enter voltage (V):\t");
        scanf("%lf", &measurement->voltage);
    
        if(measurement->voltage > 0){
            input_stream = false;
            break;
        }
        else{
            continue;
        }
    }
}


void obtainCurrent(Measurement *measurement){
    bool input_stream = true;

    while(input_stream){
        printf("Enter current (A):\t");
        scanf("%lf", &measurement->current);
    
        if(measurement->current > 0){
            input_stream = false;
            printf("Condition met\n");
            break;
        }
        else{
            printf("Condition met\n");
            continue;
        }
    }
}   


int whichMaximumResistance(Measurement measurement[], double maximum_resistance){
    int i = 0; // declaring iterator outside of loop for return

    for(i = 0; i < NUMBER_OF_TRIALS; i++){
        if (measurement[i].resistance == maximum_resistance){break;}
    }
    
    return i+1; // Returns the measurement number where maxiumum resistance occurred
}



int whichMinimumResistance(Measurement measurement[], double minimum_resistance){
    int i = 0; // declaring iterator outside of loop for return

    for(i = 0; i < NUMBER_OF_TRIALS; i++){
        if (measurement[i].resistance == minimum_resistance){break;}
    }

    return i+1; // Returns the measurement number where minimum resistance occurred
}



int whichMaximumPower(Measurement measurement[], double maximum_power){
    int i = 0; // declaring iterator outside of loop for return

    for(i = 0; i < NUMBER_OF_TRIALS; i++){
        if (measurement[i].power == maximum_power){break;}
    }
    
    return i+1; // Returns the measurement number where maximum power occurred
}
