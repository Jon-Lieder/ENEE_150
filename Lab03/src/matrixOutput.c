// Include the header file for the print_matrix function
// and the SIZE definition
#include "matrixOutput.h"
// Include the standard input/output library for printf
#include <stdio.h>
// Define the function used to display a matrix
// const indicates that the matrix values will not be changed
// CHANGED: print_matrix now receives FILE *out
// so the matrix can be written to an output stream
//
// The function still returns void because it does not
// need to return a calculated value
void print_matrix(FILE *out, const double a[SIZE][SIZE]) {
    // Declare loop control variables for rows and columns
    int i, j;
    // Loop through each row of the matrix
    for (i = 0; i < SIZE; i++) {
        // Loop through each column of the current row
        for (j = 0; j < SIZE; j++) {
            // CHANGED: Use fprintf instead of printf
            // The first argument tells fprintf
            // which output stream to write to
            fprintf(out, "%8.2f", a[i][j]);
        }
        // CHANGED: Write the newline to the output stream
        // instead of directly to the screen
        fprintf(out, "\n");
    }
}
