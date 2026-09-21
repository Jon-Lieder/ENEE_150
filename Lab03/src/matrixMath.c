// Include the header file for the matrix math functions
// and the SIZE definition
#include "matrixMath.h"
// Define the function used to transpose a matrix
void transpose_matrix(
    const double a[SIZE][SIZE],
    double result[SIZE][SIZE])
{
    // Declare loop control variables for rows and columns
    int i, j;
    // Loop through each row of the original matrix
    for (i = 0; i < SIZE; i++) {
        // Loop through each column of the original matrix
        for (j = 0; j < SIZE; j++) {
            // Swap the row and column positions
            // to create the transpose
            result[j][i] = a[i][j];
        }
    }
}

// Define the function used to calculate the determinant
// of a 3 x 3 matrix
double determinant(const double a[SIZE][SIZE])
{
    // Calculate and return the determinant
    // using expansion across the first row
    return (a[0][0] * (a[1][1] * a[2][2]
            - a[1][2] * a[2][1])
            - a[0][1] * (a[1][0] * a[2][2]
            - a[1][2] * a[2][0])
            + a[0][2] * (a[1][0] * a[2][1]
            - a[1][1] * a[2][0]));
}


// Define the function used to multiply two matrices
void multiply_matrix(
const double a[SIZE][SIZE],
const double b[SIZE][SIZE],
double result[SIZE][SIZE])
{
    // Declare loop control variables
    int i, j, k;
    // Loop through each row of Matrix A
    for (i = 0; i < SIZE; i++) {
        // Loop through each column of Matrix B
        for (j = 0; j < SIZE; j++) {
            // Start the current result element at zero
            result[i][j] = 0.0;
            // Multiply matching row and column elements
            // and add them together
            for (k = 0; k < SIZE; k++) {
                result[i][j] +=
                a[i][k] * b[k][j];
            }
        }
    }
}
