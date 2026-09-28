#include <stdio.h>
#include "config.h"


void inputDisplay(FILE *file, double matrix[ROWS][AUG_COLS]){

    fprintf(file, "Augmented Matrix [ A | b ]\n");
    for (int i = 0 ; i < ROWS ; i++){
        fprintf(file, "\t");
        for (int j = 0 ; j < AUG_COLS ; j++){
            fprintf(file, "%.2lf ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }
}

void cramerOutput(double ax[ROWS][COLS], double ay[ROWS][COLS], double az[ROWS][COLS], double dets[AUG_COLS], double solutions[COLS], FILE *file){
    if (file == NULL){printf("Fucking kill me.\n");}

    fprintf(file, "____________________________\n");
    fprintf(file, "|\t\t             \t\t|\n");
    fprintf(file, "|\t\tCRAMER'S RULE\t\t|\n");
    fprintf(file, "|___________________________|\n");

    fprintf(file, "\nAx:\t\t\t\tdet(Ax):\t\t\tx:\n");
    for(int i = 0 ; i < ROWS ; i++){
        fprintf(file, "\t");
        for (int j = 0 ; j < COLS ; j++ ){ 
            fprintf(file, "%.0lf ", ax[i][j]);
        }
        if (i==0){        
            fprintf(file, "\t\t\t\t%.0lf\t\t\t\t%.0lf", dets[1], solutions[0]);
        }

        fprintf(file, "\n");
    }

    fprintf(file, "\n\nAy:\t\t\t\tdet(Ay):\t\t\ty:\n");
    for (int i = 0 ; i < ROWS ; i ++){
        fprintf(file, "\t");
        for (int j = 0 ; j < COLS ; j++ ){
            fprintf(file, "%.0lf ", ay[i][j]);
        }
        if (i==0){
            fprintf(file, "\t\t\t\t%.0lf\t\t\t\t%.0lf", dets[2], solutions[1]); 
        }

        fprintf(file, "\n");
    }
    
    fprintf(file, "\n\nAz:\t\t\t\tdet(Az):\t\t\tz:\n");
    for (int i = 0 ; i < ROWS ; i++ ){
        fprintf(file, "\t");
        for (int j = 0 ; j < COLS ; j++ ){
            fprintf(file, "%.0lf ", az[i][j]);
        }
        if (i==0){
            fprintf(file, "\t\t\t\t%.0lf\t\t\t\t%.0lf", dets[3], solutions[2]); 
        }
    
        fprintf(file, "\n");
    }
}

void gaussianOutput(double matrix[ROWS][AUG_COLS], double solutions[ROWS], FILE *file){
    fprintf(file, "\n\n____________________________________\n");
    fprintf(file, "|\t\t                     \t\t|\n");
    fprintf(file, "|\t\tGAUSSIAN ELIMINATION\t\t|\n"); 
    fprintf(file, "|___________________________________|\n"); 

    fprintf(file, "\nUpper Triangule [ A | b ]\n");
    for (int i = 0 ; i < ROWS ; i++ ){
        fprintf(file, "\t");
        for (int j = 0 ; j < AUG_COLS ; j++ ){
            fprintf(file, "%.0lf\t", matrix[i][j]);
        }
        fprintf(file, "\n");
    }

    fprintf(file, "\nz = %.0lf\n", solutions[2]);
    fprintf(file, "y = (1/%.0lf)[%.0lf - (%.0lf)z] = %.0lf\n", matrix[1][1], matrix[1][3], matrix[1][2], solutions[1]);
    fprintf(file, "x = (1/%.0lf)[%.0lf - (%.0lf)z - (%.0lf)y] = %.0lf\n\n\n",matrix[0][0], matrix[0][3], matrix[0][2], matrix[0][1], solutions[0] );
}

void gaussJordanOutput(double matrix[ROWS][AUG_COLS], FILE *file){
    fprintf(file, "_________________________________________\n");
    fprintf(file, "|\t\t                        \t\t|\n");
    fprintf(file, "|\t\tGAUSS-JORDAN ELIMINATION\t\t|\n");
    fprintf(file, "|\t\t                        \t\t|\n");
    fprintf(file, "|_______________________________________|\n\n");
    
    fprintf(file, "Diagonalized Augmented Matrix [ A | b ]\n");
    
    for (int i = 0 ; i < ROWS ; i++ ){
        fprintf(file, "\t");
        for (int j = 0 ; j < AUG_COLS ; j++ ){
            fprintf(file, "%.0lf\t", matrix[i][j]+0.0); // get's rid of -0 
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\nx = %.0lf\ny = %.0lf\nz = %.0lf", matrix[0][COLS], matrix[1][COLS], matrix[2][COLS]);
}


