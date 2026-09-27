#ifndef MATRIXINPUT_H
#define MATRIXINPUT_H

#include "config.h"

void inputMatrix(FILE *file, double ab[ROWS][AUG_COLS], double a[ROWS][COLS], double b[ROWS]);

void buildAx(FILE *file, double a[ROWS][COLS], double b[ROWS], double ax[ROWS][COLS]);

void buildAy(FILE *file, double a[ROWS][COLS], double b[ROWS], double ay[ROWS][COLS]);

void buildAz(FILE *file, double a[ROWS][COLS], double b[ROWS], double az[ROWS][COLS]);
#endif
