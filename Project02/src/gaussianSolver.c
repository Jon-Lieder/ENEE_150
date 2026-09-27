#include <stdio.h>
#include <string.h>

#include "config.h"
#include "matrixMath.h"
#include "matrixOutput.h"

void gaussianSolver(double ab[ROWS][AUG_COLS], FILE *file){
    double row_elim = 0, ab_G_temp[ROWS][AUG_COLS], gauss_soln[ROWS];
    memcpy(ab_G_temp, ab, sizeof(ab_G_temp)); 

    for (int k = 0 ; k < ROWS - 1 ; k++){
        for (int i = k + 1 ; i < ROWS ; i++){
            row_elim = ab_G_temp[i][k] / ab_G_temp[k][k];
            for (int j = k ; j < AUG_COLS ; j++){
                ab_G_temp[i][j] -= row_elim * ab_G_temp[k][j];
            }
        }
    }

    for (int i = 0 ; i < ROWS ; i++){
        for (int j = 0 ; j < AUG_COLS ; j++){
            printf("%lf ", ab_G_temp[i][j]);        
        }
    printf("\n");
    }

    gauss_soln[2] = ab_G_temp[2][3] / ab_G_temp[2][2];
    gauss_soln[1] = (ab_G_temp[1][3] - ab_G_temp[1][2]*gauss_soln[2]) / ab_G_temp[1][1];
    gauss_soln[0] = (ab_G_temp[0][3] - ab_G_temp[0][2]*gauss_soln[2] - ab_G_temp[0][1]*gauss_soln[1]) / ab_G_temp[0][0];

    printf("Gaussian x1 = %.2lf\n", gauss_soln[0]);
    printf("Gaussian x2 = %.2lf\n", gauss_soln[1]);
    printf("Gaussian x3 = %.2lf\n", gauss_soln[2]);

    gaussianOutput(ab_G_temp, gauss_soln, file);
}   
