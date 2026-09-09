#include <stdio.h>
#include "measurement.h"
#include "constants.h" 



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
