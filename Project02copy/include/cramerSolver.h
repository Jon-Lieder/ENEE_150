#ifndef CRAMERSOLVER_H
#define CRAMERSOLVER_H

#include "config.h"

double cramerSolver(double ab[ROWS][AUG_COLS], double solutions[ROWS], double dets[AUG_COLS], FILE *file);

#endif
