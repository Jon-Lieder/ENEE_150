#ifndef MATRIXOUTPUT_H
#define MATRIXOUTPUT_H

#include "config.h"

void inputDisplay(FILE *file, double matrix[ROWS][AUG_COLS]);

void cramerOutput(double ax[ROWS][COLS], double ay[ROWS][COLS], double az[ROWS][COLS], double dets[AUG_COLS], double solutions[COLS], FILE *file);

void gaussianOutput(double matrix[ROWS][AUG_COLS], double solutions[ROWS], FILE *file);

void gaussJordanOutput(double matrix[ROWS][AUG_COLS], FILE *file);

#endif
