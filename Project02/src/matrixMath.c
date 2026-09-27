#include <stdio.h>
#include "config.h"

double determinant(double matrix[ROWS][COLS]){
    double det = 0;

    for ( int i = 0 ; i < ROWS ; i++ ){
        det += matrix[0][i] * matrix[1][(1 + i)%3] * matrix[2][(2 + i)%3];
        det -= matrix[0][i] * matrix[1][(i + 2)%3] * matrix[2][(1 + i)%3];
    }

    printf("matrixMath.c line 11: det = %lf\n", det);

    return det;
}


