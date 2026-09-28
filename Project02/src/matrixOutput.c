#include <stdio.h>
#include "config.h"



/*
 * inputDisplay
 *
 * Displays the original unaltered ab matrix [ A | b ] at the top of results.txt
 *
 * Parameters:
 *      *file - FILE containint the open write file to write to.
 *      matrix[][] - double containing the unaltered augmented matrix [ A | b ]
 *
 * Returns
 *      Nothing
 */
void inputDisplay(FILE *file, double matrix[ROWS][AUG_COLS]){
    
    fprintf(file, "________________________________________\n");
    fprintf(file, "|\t\t                           \t\t|\n");
    fprintf(file, "|\t\tAugmented Matrix [ A | b ]:\t\t|\n");
    fprintf(file, "|_______________________________________|\n\n");
    for (int i = 0 ; i < ROWS ; i++){
        fprintf(file, "\t");
        for (int j = 0 ; j < AUG_COLS ; j++){
            fprintf(file, "%.0lf ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n\n");
}


/*
 * cramerOutput
 *
 * Writes formatted output for the cramer's rule solution to results.txt in the format:
 *              { MATRIX }          { DETERMINANT }         { VARIABLE }
 *
 * Parameters:
 *      aw[][] - double containing an altered matrix where b replaces the first column of A
 *      ax[][] - double containing an altered matrix where b replaces the second column of A
 *      ay[][] - double containing an altered matrix where b replaces the third column A
 *      az[][] - double containing an altered matrix where b replaces the fourth column of A
 *      dets[] - double containing the determinants of A, Aw, Ax, Ay, Az respectively
 *      solutions[] - double containing all solved answers for each variable w, x, y, and z
 *      *file - FILE contaning the open output file to write to
 *
 * Returns:
 *      Nothing
 */
void cramerOutput(double aw[ROWS][COLS], double ax[ROWS][COLS], double ay[ROWS][COLS], double az[ROWS][COLS], double dets[AUG_COLS], double solutions[COLS], FILE *file){
    fprintf(file, "____________________________\n");
    fprintf(file, "|\t\t             \t\t|\n");
    fprintf(file, "|\t\tCRAMER'S RULE\t\t|\n");
    fprintf(file, "|___________________________|\n");


    fprintf(file, "\nAw:\t\t\t\tdet(Aw):\t\t\tw:\n");
    for(int i = 0 ; i < ROWS ; i++){                                                                                         
        fprintf(file, "\t");                                                                                                 
        for (int j = 0 ; j < COLS ; j++ ){                                                                                   
            fprintf(file, "%.0lf ", aw[i][j]);                                                                               
        }                                                                                                                    
        if (i==0){                                                                                                           
            fprintf(file, "\t\t\t\t%.0lf\t\t\t\t%.0lf", dets[1], solutions[0]);                                              
        }                                                                                                                    
                                                                                                                             
        fprintf(file, "\n");                                                                                                 
    }  

    fprintf(file, "\nAx:\t\t\t\tdet(Ax):\t\t\tx:\n");
    for(int i = 0 ; i < ROWS ; i++){
        fprintf(file, "\t");
        for (int j = 0 ; j < COLS ; j++ ){ 
            fprintf(file, "%.0lf ", ax[i][j]);
        }
        if (i==0){        
            fprintf(file, "\t\t\t\t%.0lf\t\t\t\t%.0lf", dets[2], solutions[1]);
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
            fprintf(file, "\t\t\t\t%.0lf\t\t\t\t%.0lf", dets[3], solutions[2]); 
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
            fprintf(file, "\t\t\t\t%.0lf\t\t\t\t%.0lf", dets[4], solutions[3]); 
        }
    
        fprintf(file, "\n");
    }
}


/*
 * gaussianOutput
 *
 * Writes a formatted display to results.txt containing the solution of the linear system with upper triangular form.
 *
 * Parameters:
 *      matrix[][] - double containing the original unaltered matrix [ A | b ]
 *      solutions[] - double containing the solved variables w, x, y, and z
 *      *file - FILE containing the open output file results.txt to be written to
 *
 * Returns:
 *      Nothing
 */
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

    fprintf(file, "\nw = %.0lf = (1/%0.lf)[%.0lf - (%.0lf)z - (%.0lf)y - (%.0lf)x]\n", solutions[0],  matrix[0][0], matrix[0][4], matrix[0][3], matrix[0][2], matrix[0][1]);
    fprintf(file, "x = %.0lf = (1/%.0lf)[%.0lf - (%.0lf)z - (%.0lf)y]\n", solutions[1], matrix[1][1], matrix[1][4], matrix[1][3], matrix[1][2]);
    fprintf(file, "y = %.0lf = (1/%.0lf)[%.0lf - (%.0lf)z]\n", solutions[2], matrix[2][2], matrix[2][4], matrix[2][3]); 
    fprintf(file, "z = %.0lf\n\n\n", solutions[3]); 
}


/*
 * gaussJordanOutput
 *
 * Writes a formatted display containing a full gauss jordan solution to reults.txt where once in upper triangular form,
 * the entries above the pivots are eliminated as well.
 *
 * Parameters:
 *      matrix[][] - double containing the original unaltered augmented matrix [ A | b ]
 *      *file - FILE containing the open output file results.txt to be written to
 *
 * Returns:
 *      Nothing
 */
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
    fprintf(file, "\nw = %.0lf\nx = %.0lf\ny = %.0lf\nz = %.0lf", matrix[0][COLS], matrix[1][COLS], matrix[2][COLS], matrix[3][COLS]);
}


