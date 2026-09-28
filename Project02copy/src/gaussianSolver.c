#include <stdio.h>
#include <string.h>

#include "config.h"
#include "matrixMath.h"
#include "matrixOutput.h"


/*
 * gaussianSolver
 *
 * Copies the unaltered augmented matrix ab ( [ A | b ] ) into a temporary matrix.
 * Nested for loops are then used to place the copy in upper triangular form. Once
 * in upper triangular form, backwars substitution is performed to obtain the 
 * solutions. Lastly, the formatted output display is called.
 *
 * Parameters:
 *      ab[][] - double containing the unaltered augmented matrix [ A | b ]
 *      *file - FILE contaning the open outputfile in write mode.
 *
 * Returns:
 *      Nothing
 */
void gaussianSolver(double ab[ROWS][AUG_COLS], FILE *file){
    double row_elim = 0, ab_G_temp[ROWS][AUG_COLS], gauss_soln[ROWS];

    // Creates the local copy of ab
    memcpy(ab_G_temp, ab, sizeof(ab_G_temp)); 

    for (int k = 0 ; k < ROWS - 1 ; k++){
        for (int i = k + 1 ; i < ROWS ; i++){
            row_elim = ab_G_temp[i][k] / ab_G_temp[k][k];
            for (int j = k ; j < AUG_COLS ; j++){
                ab_G_temp[i][j] -= row_elim * ab_G_temp[k][j];
            }
        }
    }

    gauss_soln[2] = ab_G_temp[2][3] / ab_G_temp[2][2];
    gauss_soln[1] = (ab_G_temp[1][3] - ab_G_temp[1][2]*gauss_soln[2]) / ab_G_temp[1][1];
    gauss_soln[0] = (ab_G_temp[0][3] - ab_G_temp[0][2]*gauss_soln[2] - ab_G_temp[0][1]*gauss_soln[1]) / ab_G_temp[0][0];

    gaussianOutput(ab_G_temp, gauss_soln, file);
}   
