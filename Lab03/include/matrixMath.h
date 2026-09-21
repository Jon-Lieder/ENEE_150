// Check whether MATRIXMATH_H has already been defined
#ifndef MATRIXMATH_H
// Define MATRIXMATH_H so this header file is only included once
#define MATRIXMATH_H
// Include the common matrix definitions, including SIZE
#include "matrixCommon.h"
// Declare the function used to transpose a matrix
void transpose_matrix(
const double a[SIZE][SIZE],
double result[SIZE][SIZE]);
// Declare the function used to calculate a matrix determinant
double determinant(
const double a[SIZE][SIZE]);
// Declare the function used to multiply two matrices
void multiply_matrix(
const double a[SIZE][SIZE],
const double b[SIZE][SIZE],
double result[SIZE][SIZE]);
// End the MATRIXMATH_H include guard
#endif
