#include <stdio.h>
#include "config.h"


/*
 * determinant3
 *
 * Helper function. Calcualtes the determinant of the 3x3 minor matrix to help determinant4(matrix[][]) below. 
 *
 * Parameters:
 *      matrix[][] - double containing a square matrix
 *
 * Returns:
 *      det
 */
double determinant3(double matrix[ROWS-1][COLS-1]){
    double det = 0;

    for ( int i = 0 ; i < ROWS-1 ; i++ ){

        /* The formula for determinant uses the modulus operator to wrap around the
         * bounds of the matrix as i increases. For example, when i = 2, the term
         * matrix[1][(1+i)%3] = matrix[1][(3)%3] = matrix[1][0]. 
         */
        det += matrix[0][i] * matrix[1][(1 + i)%3] * matrix[2][(2 + i)%3];
        det -= matrix[0][i] * matrix[1][(i + 2)%3] * matrix[2][(1 + i)%3];
    }

    return det;
}


/*
 * determinant4
 *
 * Calculates the determinant of a 4x4 square matrix. Uses determinant 3 for the work of the minor matrix and handles
 * the remainder of the calculation.
 *
 * parameters:
 *      matrix[][] - double containing a square matrix 
 *
 * returns:
 *      Nothing
 */
double determinant4(double matrix[ROWS][COLS]){
    double det = 0, minor[ROWS-1][COLS-1], sign = 1.0;

    for (int i = 0 ; i < COLS ; i ++){
        for (int r = 1 ; r < ROWS ; r++){
            int mc = 0;
            for (int c = 0; c < COLS; c++){
                if (c == i){ 
                    continue;
                }
                minor[r-1][mc++] = matrix[r][c];
            }
        }
        det += sign * matrix[0][i] * determinant3(minor);
        sign = -sign;
    }
    return det;
}

