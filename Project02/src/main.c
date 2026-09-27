#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#include "matrixInput.h"
#include "matrixMath.h"
#include "cramerSolver.h"
#include "gaussianSolver.h"
#include "gaussJordanSolver.h"
#include "config.h"


int main(int argc, char *argv[]){
    FILE *input_ptr;
    FILE *output_ptr;
    
    //char input_file[100];
    char input_file[100] = "./inputFiles/";
    char *input_argv = argv[1];
    char output_file[100] = "./outputFiles/";
    char *output_argv = argv[2];

    double a[ROWS][COLS];
    double ax[ROWS][COLS];
    double ay[ROWS][COLS];
    double az[ROWS][COLS];
    double ab[ROWS][AUG_COLS];
    double b[ROWS];
    double x[ROWS];

    double det_a;
    double det_ax;
    double det_ay;
    double det_az;

    double x1;
    double x2;
    double x3;

    if (argc != 3){                                                                                                          
        printf("Incorrect useage. \nmatrixSovler.exe matrixData.txt results.txt\n");
        return 1;
    }   

    strcat(input_file, input_argv);
    strcat(output_file, output_argv);

    input_ptr = fopen(input_file, "r");
    output_ptr = fopen(output_file, "w");

    if (input_ptr == NULL){
        printf("(1) ERROR: Could not open input file. Terminating program.\n");
        return 1;
    }

    if (output_ptr == NULL){
        printf("(2) ERROR: Could not open output file. Terminating program. \n");
        return 1;
    }

    printf("Main line 44: Files read and opened succesfully.\n");
    
    inputMatrix(input_ptr, ab, a, b);
    buildAx(input_ptr, a, b, ax);
    buildAy(input_ptr, a, b, ay);
    buildAz(input_ptr, a, b, az);
    det_a = determinant(a);
    det_ax = determinant(ax);
    det_ay = determinant(ay);
    det_az = determinant(az); 
    x1 = cramerSolver(det_ax, det_a);
    x2 = cramerSolver(det_ay, det_a);
    x3 = cramerSolver(det_az, det_a);
    gaussianSolver(ab);
    gaussJordanSolver(ab);
}
