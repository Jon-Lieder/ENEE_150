#include <stdio.h>
#include <string.h>

#include "matrixInput.h"
#include "matrixOutput.h"
#include "config.h"



void inputMatrix(FILE *file, double ab[ROWS][AUG_COLS], double a[ROWS][COLS], double b[ROWS], FILE *output_file){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < AUG_COLS; j++){
            fscanf(file, "%lf", &ab[i][j]);
            if(j < COLS){
                a[i][j] = ab[i][j];
                printf("a[%d][%d] = %lf\n", i, j, a[i][j]);
            }
            else{
                b[i] = ab[i][j];
            }
        }
        printf("b[%d] = %lf\n", i, b[i]);
    }
    printf("Please work\n");

    inputDisplay(file, ab);
    //inputDisplay(file, a);
    //inputDisplay(file, b);
}


void buildAx(FILE *file, double a[ROWS][COLS], double b[ROWS], double ax[ROWS][COLS]){
    memcpy(ax, a, ROWS * COLS * sizeof(double));
    
    for (int i = 0 ; i < ROWS ; i++){
        ax[i][0] = b[i];
        printf("%lf %lf %lf\n", ax[i][0], ax[i][1], ax[i][2]);
    }    
    //inputDisplay();
}


void buildAy(FILE *file, double a[ROWS][COLS], double b[ROWS], double ay[ROWS][COLS]){
    memcpy(ay, a, ROWS * COLS * sizeof(double));

    for(int i = 0 ; i < ROWS ; i++){
        ay[i][1] = b[i];
        printf("%lf %lf %lf\n", ay[i][0], ay[i][1], ay[i][2]);   
    }

    //inputDisplay();
}


void buildAz(FILE *file, double a[ROWS][COLS], double b[ROWS], double az[ROWS][COLS]){
    memcpy(az, a, ROWS * COLS * sizeof(double));
                                                                                                                            
    for(int i = 0 ; i < ROWS ; i++){
        az[i][2] = b[i];
        printf("%lf %lf %lf\n", az[i][0], az[i][1], az[i][2]);   
    } 

    //inputDisplay();
}

