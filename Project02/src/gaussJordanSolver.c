#include <stdio.h>
#include <string.h>

#include "config.h"
#include "matrixMath.h"
#include "matrixOutput.h"

void gaussJordanSolver(double ab[ROWS][AUG_COLS], FILE *file){
    double row_elim, scale_factor, ab_GJ_temp[ROWS][AUG_COLS];
    memcpy(ab_GJ_temp, ab, ROWS * AUG_COLS * sizeof(double));

    for (int k = 0 ; k < ROWS - 1 ; k++){
        for (int i = k+1 ; i < ROWS ; i++ ){
            row_elim = ab_GJ_temp[i][k] / ab_GJ_temp[k][k];
            for (int j = k ; j < AUG_COLS ; j++){
                ab_GJ_temp[i][j] -= row_elim * ab_GJ_temp[k][j]; 
            }
        }
    }    

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

    for (int i = 0 ; i < ROWS ; i++){
        for (int j = 0 ; j < AUG_COLS ; j++){
            printf("%lf ", ab_GJ_temp[i][j]);
        }
        printf("\n");
    }

    gaussJordanOutput(ab_GJ_temp, file);
}
