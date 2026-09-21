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

/*
 * experimentalPercentError
 *
 * Calculates the percent error for a given experiment entered by the user. 
 *
 * Parameters:
 *      size - int value containing the size of the arrays (5)
 *      *percent_error - pointer to the percent_error array
 *      *experiment_measurements - pointer to the experimental_measurements array containing values
 *                                 inputted by the user for the different measurements
 *      *theoretical_values - pointer to the theoretical_values array containing the expected values
 *                            for each measurement
 *
 * Returns:
 *      Nothing
 */
void experimentalPercentError(int size, double *percent_error, 
                                double *experiment_measurements,
                                double *theoretical_values){
    printf("Test\tTheoretical\tExperimental\tError\n");
    for(int i = 0; i < size; i++){
        percent_error[i] = ( experiment_measurements[i] - theoretical_values[i] )
                                                         / theoretical_values[i] * 100;

        printf(" %d\t    %.2lf\t    %.2lf\t%.2lf%% \n", i+1, 
                                                    theoretical_values[i], 
                                                    experiment_measurements[i],
                                                    percent_error[i]); 
    }
}


/*
 * obtainExperimentalMeasurements
 *
 * Prompts the user for input for five different measurements and stores them within an array.
 *
 * Parameters:
 *      size - int value containing the size of the arrays (5)
 *      *experiment_measurements - pointer to the experimental_measurements array containing values
 *                                 inputted by the user for the different measurements
 *      *theoretical_values - pointer to the theoretical_values array containing the expected values
 *                            for each measurement
 *
 * Returns:
 *      Nothing
 */
void obtainExperimentalMeasurements(int size, double *experiment_measurements, double *theoretical_values){
    int count = 1;

    printf("EXPERIMENTAL ERROR ANALYSIS\n\n"); 

    for(int i = 0; i < size; i++){        
        printf("Theoretical: %.2lf\tEnter the experimental value: ", theoretical_values[i]);
        scanf("%lf", &experiment_measurements[i]);
        count++;
    }
    printf("\n");
}


int main(){
    double percent_error[5];
    double experiment_measurements[5]; 
    double theoretical_values[] = {10.0 ,20.0 ,30.0 ,40.0, 50.0};
    int size = sizeof(theoretical_values) / sizeof(theoretical_values[0]);  // Calculates how many elements are in the array  
    obtainExperimentalMeasurements(size, experiment_measurements, theoretical_values);
    experimentalPercentError(size, percent_error, experiment_measurements, theoretical_values);
    return 0;
}
