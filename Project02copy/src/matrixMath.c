#include <stdio.h>
#include "config.h"


/*
 * determinant
 *
 * Calcualtes the determinant of a given square matrix. 
 *
 * Parameters:
 *      matrix[][] - double containing a square matrix
 *
 * Returns:
 *      det
 */
double determinant(double matrix[ROWS][COLS]){
    double det = 0;

    for ( int i = 0 ; i < ROWS ; i++ ){

        /* The formula for determinant uses the modulus operator to wrap around the
         * bounds of the matrix as i increases. For example, when i = 2, the term
         * matrix[1][(1+i)%3] = matrix[1][(3)%3] = matrix[1][0]. 
         */
        det += matrix[0][i] * matrix[1][(1 + i)%3] * matrix[2][(2 + i)%3];
        det -= matrix[0][i] * matrix[1][(i + 2)%3] * matrix[2][(1 + i)%3];
    }

    return det;
}


