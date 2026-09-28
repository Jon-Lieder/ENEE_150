#include <stdio.h>
#include <string.h>

#include "matrixInput.h"
#include "matrixOutput.h"
#include "config.h"


/*
 * inputMatrix
 *
 * Reads in numbers from system.txt and places them in an augmented matrix of the 
 * form [ A | b ] where A is a square matrix and b is a column matrix.
 *
 * Parameters:
 *      *file - The input file system.txt already open in read mode back from main().
 *      ab[][] - double containing a 2 dimensional matrix 
 *      a[][] - double containing a square matrix that is the left side of [ A | b ]
 *      b[] - double containing a column matrix that is the right side of [ A | b ]
 *
 * Returns:
 *      Nothing
 */
void inputMatrix(FILE *file, double ab[ROWS][AUG_COLS], double a[ROWS][COLS], double b[ROWS], FILE *output_file){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < AUG_COLS; j++){
            fscanf(file, "%lf", &ab[i][j]);
            if(j < COLS){
                a[i][j] = ab[i][j];
            }
            else{
                b[i] = ab[i][j];
            }
        }
    }
}

