/* Name:            Jon Lieder
 * Course:          ENEE 150
 * Project:         Project 2
 * Assignment:      Linear Systems Solver
 * Date:            09/27/2026
 *
 * Description:
 * This program is run with ./bin/linearSolver.exe system.txt results.txt.
 * An augmented matrix is read in from an external file, and three forms of
 * solving systems are computed and compared: cramer's rule, gaussian elimination
 * followed by substitution, and gauss-jordan eliminated. The results are then 
 * compared and written to an output file: results.txt. 
 */


#include <stdio.h>
#include <string.h>

#include "matrixInput.h"
#include "matrixOutput.h"
#include "matrixMath.h"
#include "cramerSolver.h"
#include "gaussianSolver.h"
#include "gaussJordanSolver.h"
#include "config.h"


int main(int argc, char *argv[]){
    FILE *input_ptr;
    FILE *output_ptr;
    
    char input_file[100] = "./inputFiles/";
    char *input_argv = argv[1];
    char output_file[100] = "./outputFiles/";
    char *output_argv = argv[2];

    double a[ROWS][COLS];
    double ab[ROWS][AUG_COLS];
    double b[ROWS];
    double solutions[ROWS];
    double dets[AUG_COLS];

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

    inputMatrix(input_ptr, ab, a, b, output_ptr);
    cramerSolver(ab, solutions, dets, output_ptr);
    gaussianSolver(ab, output_ptr);
    gaussJordanSolver(ab, output_ptr);
}
