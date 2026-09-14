/* Name:            Jon Lieder
 * Course:          ENEE 150
 * Project:         Lab 01
 * Assignment:      Problem 5 -- Experimental Percent Error
 * Date:            September 3, 2026
 *
 * Description:     
 * This program calculates the experimental precent error by comparing the known
 * theoretical values with five experimental values. The five experimental values
 * are defined and initialized within an array in main().
 */

#include <stdio.h>

void experimentalPercentError(int size, double *percent_error, 
                                double *experiment_measurements,
                                double *theoretical_values){
    
    for(int i = 0; i < size; i++){
        percent_error[i] = ( experiment_measurements[i] - theoretical_values[i] )
                                                         / theoretical_values[i] * 100;
        printf("percent error [%d] = %.2lf %% \n", i, percent_error[i]); 
    }
}

void obtainExperimentalMeasurements(int size, double *experiment_measurements){
    int count = 1;
    for(int i = 0; i < size; i++){        
        printf("Enter the experimental error for measurement %d:\t", count);
        scanf("%lf", &experiment_measurements[i]);
        count++;
    }
}

int main(){
    double percent_error[5];
    double experiment_measurements[5]; 
    double theoretical_values[] = {10.0 ,20.0 ,30.0 ,40.0, 50.0};
    int size = sizeof(theoretical_values) / sizeof(theoretical_values[0]);  // Calculates how many elements are in the array  
    obtainExperimentalMeasurements(size, experiment_measurements);
    experimentalPercentError(size, percent_error, experiment_measurements, theoretical_values);
    return 0;
}
