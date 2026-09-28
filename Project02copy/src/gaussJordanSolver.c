#include <stdio.h>
#include <string.h>

#include "config.h"
#include "matrixMath.h"
#include "matrixOutput.h"



/*
 * gaussJordanSolver
 *
 * This function copies the unaltered augmented matrix ab [ A | b ] into a local 
 * temporary matrix. Nested for loops are used to first place the matrix in upper 
 * triangular form. The second set of nested for loops then work backwords and
 * eliminate values above the pivots and scale the pivot rows so that pivots = 1.
 * Lastly, the formatted display output is called.
 *
 * Parameters:
 *      ab[][] - double containing the unaltered augmented matrix [ A | b ]
 *      *file - FILE containing the output file already open in write mode
 *
 * Returns:
 *      Nothing
 */
void gaussJordanSolver(double ab[ROWS][AUG_COLS], FILE *file){
    double row_elim, scale_factor, ab_GJ_temp[ROWS][AUG_COLS];
    memcpy(ab_GJ_temp, ab, ROWS * AUG_COLS * sizeof(double));

    // Upper triangular form code block
    for (int k = 0 ; k < ROWS - 1 ; k++){
        for (int i = k+1 ; i < ROWS ; i++ ){
            row_elim = ab_GJ_temp[i][k] / ab_GJ_temp[k][k];
            for (int j = k ; j < AUG_COLS ; j++){
                ab_GJ_temp[i][j] -= row_elim * ab_GJ_temp[k][j]; 
            }
        }
    }    

    // Above pivot elimination and scaling
    for (int k = ROWS - 1 ; k >= 0 ; k--){
        scale_factor = ab_GJ_temp[k][k];
        for (int j = k ; j < AUG_COLS ; j++){
            ab_GJ_temp[k][j] /= scale_factor;
        }
        for (int i = 0 ; i < k ; i++){
            row_elim = ab_GJ_temp[i][k];
            for (int j = k ; j < AUG_COLS ; j++){
                ab_GJ_temp[i][j] -= row_elim * ab_GJ_temp[k][j];
            }
        }
    }

    gaussJordanOutput(ab_GJ_temp, file);
}
