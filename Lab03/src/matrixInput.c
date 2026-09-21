// Include the header file that contains the read_matrix function prototype
// and the SIZE definition used for the matrix
#include "matrixInput.h"
// Include the standard input/output library for printf and scanf
#include <stdio.h>
// Define the function that reads values into a matrix
int read_matrix(FILE *in, double a[SIZE][SIZE]){
    // Declare loop control variables for rows and columns
    int i, j;
    // Loop through each row of the matrix
    for (i = 0; i < SIZE; i++) {
        // Loop through each column of the current row
        for (j = 0; j < SIZE; j++) {
            // CHANGED: Use fscanf instead of scanf
            // The first argument tells fscanf which stream to read from
            //
            // fscanf returns the number of values successfully read
            // If one double is not read, return 0 to report failure
            if (fscanf(in, "%lf",
                &a[i][j]) != 1) {
                return 0;
            }
        }
    }
    // NEW: Return 1 after all matrix values are read successfully
    return 1;
}
