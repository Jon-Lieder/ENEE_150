#include <stdio.h>
#include <string.h>

#include "config.h"
#include "matrixMath.h"

void gaussianSolver(double ab[ROWS][AUG_COLS]){
    double row_elim = 0, ab_G_temp[ROWS][AUG_COLS];
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
}   
