// Check whether MATRIXOUTPUT_H has already been defined
#ifndef MATRIXOUTPUT_H
// Define MATRIXOUTPUT_H so this header file is only included once
#define MATRIXOUTPUT_H
// NEW: Include stdio.h because this header now uses FILE *
#include <stdio.h>
// Include the common matrix definitions, including SIZE
#include "matrixCommon.h"
// CHANGED: print_matrix now receives FILE *out
// so the function can write to a file stream instead of only the screen
// The function still returns void because it does not need
// to return a calculated value
//
// const still indicates that the matrix values will not be changed
void print_matrix(
FILE *out,
const double a[SIZE][SIZE]);
// End the MATRIXOUTPUT_H include guard
#endif
