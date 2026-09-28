#include <stdio.h>
#include "config.h"
#include "matrixInput.h"
#include "matrixOutput.h"
#include "matrixMath.h"


/*
 * cramerSolver
 *
 * Provides a full solution of a linear system based on the theory of cramer's rule.
 * Calls matrixMath.c to calculate the determinants of A, Ax, Ay, and Az, then using
 * those values obtains x_i = det(A_i) / det(A) for each variable in the system. 
 * Lastly, the output formatting display function call is handled here.
 *
 * Parameters:
 *      ab[][] - double containing the unaltered augmented matrix
 *      solutions[] - double array containing the solution variables x, y, z
 *      dets[] - double array containing the determinants of each matrix A, Ax, Ay, Az
 *      file* - output file to be sent to the display formatting function call once
 *      all results are obtained.
 *
 * Returns:
 *      Nothing
 */
double cramerSolver(double ab[ROWS][AUG_COLS], double solutions[ROWS], double dets[AUG_COLS], FILE *file){
    double a[ROWS][COLS], ax[ROWS][COLS], ay[ROWS][COLS], az[ROWS][COLS];

    for (int i = 0 ; i < ROWS ; i ++){
        for (int j = 0 ; j < COLS ; j++){
            a[i][j] = ax[i][j] = ay[i][j] = az[i][j] = ab[i][j];
        }
        ax[i][0] = ab[i][AUG_COLS - 1];
        ay[i][1] = ab[i][AUG_COLS - 1];
        az[i][2] = ab[i][AUG_COLS - 1];
    }

    dets[0] = determinant(a);
    dets[1] = determinant(ax);
    dets[2] = determinant(ay);
    dets[3] = determinant(az);

    if (dets[0] == 0){
        return 0;
    }
    
    solutions[0] = dets[1] / dets[0]; // x
    solutions[1] = dets[2] / dets[0]; // y
    solutions[2] = dets[3] / dets[0]; // z
    
    cramerOutput(ax, ay, az, dets, solutions, file);

    return 1;
}
