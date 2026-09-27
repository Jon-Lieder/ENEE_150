#include <stdio.h>
#include <string.h>

#include "config.h"
#include "matrixMath.h"


void gaussJordanSolver(double ab[ROWS][AUG_COLS]){
    double row_elim, scale_factor, ab_GJ_temp[ROWS][AUG_COLS];
    memcpy(ab_GJ_temp, ab, sizeof(ab_GJ_temp));

    for (int k = 0 ; k < ROWS - 1 ; k++){
        for (int i = k+1 ; i < ROWS ; i++ ){
            row_elim = ab[i][k] / ab[k][k];
            for (int j = k ; j < AUG_COLS ; j++){
                ab[i][j] -= row_elim * ab[k][j]; 
            }
        }
    }    

    for (int k = ROWS - 1 ; k >= 0 - 1 ; k--){
        scale_factor = ab[k][k];
        for (int j = k ; j < AUG_COLS ; j++){
            ab[k][j] /= scale_factor;
        }
        for (int i = 0 ; i < k ; i++){
            row_elim = ab[i][k];
            for (int j = k ; j < AUG_COLS ; j++){
                ab[i][j] -= row_elim * ab[k][j];
            }
        }
    }

    for (int i = 0 ; i < ROWS ; i++){
        for (int j = 0 ; j < AUG_COLS ; j++){
            printf("%lf ", ab[i][j]);
        }
        printf("\n");
    }
}
