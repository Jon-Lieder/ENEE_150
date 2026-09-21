// Check whether MATRIXINPUT_H has already been defined
#ifndef MATRIXINPUT_H
// Define MATRIXINPUT_H so this header file is only included once
#define MATRIXINPUT_H
// NEW: Include stdio.h because this header now uses FILE *
#include <stdio.h>
// Include the common matrix definitions, including SIZE
#include "matrixCommon.h"
// CHANGED: read_matrix now returns an int instead of void
// 1 means the matrix was read successfully
// 0 means a value could not be read
//
// CHANGED: The function now receives FILE *in
// so it can read from a file stream instead of only the keyboard
int read_matrix(
FILE *in,
double a[SIZE][SIZE]);
// End the MATRIXINPUT_H include guard
#endif
