/* Name:            Jon Lieder
 * Course:          ENEE 150
 * Project:         Lab 03
 * Assignment:      File I/O and Command Line Arguments with the Matrix Program
 * Date:            September 20, 2026
 *
 * Description:
 * This program takes in two file names on the commandline "./Matrix.exe {INPUT FILE} {OUTPUT FILE}",
 * takes in two matrices A and B, then calculates and writes the transpose of A, determinant of A, 
 * and the matrix product AxB to the specified output file. This is achieved through the implementation
 * of provided custom header files to limit code blocks within main().
 *
 * NOTE FOR PROFESSOR: 
 * I sent a last minute email with a question about the content of this lab. From what I remember hearing
 * in class, students were instructed to copy and pste code and just get this working since we have yet
 * to go over pointer and pointer implementation and this code is a direct copy of the slides. Please
 * let me know if I am mistaken in my understanding of this.
 */


// Include the standard input/output library for printf
#include <stdio.h>
// Inlucde string.h to concatenate in/out files with known directories
#include <string.h>
// Include the header file for matrix input functions
#include "matrixInput.h"
// Include the header file for matrix output functions
#include "matrixOutput.h"
// Include the header file for matrix math functions
#include "matrixMath.h"
// Begin the main program
int main(int argc, char *argv[])
{
    // CHANGED: main now receives command line arguments
    // argc stores the number of command line arguments
    // argv stores the command line arguments as strings
    // NEW: Declare pointers for the input and output files
    FILE *in, *out;
    // Declare Matrix A
    double A[SIZE][SIZE];
    // Declare Matrix B
    double B[SIZE][SIZE];
    // Declare a matrix used to store calculation results
    double result[SIZE][SIZE];

    char in_directory[] = "tests/";
    char out_directory[] = "outputFiles/";
    // NEW: Check that the user entered two filenames
    // argc should equal 3 because argv[0] is the program name
    // argv[1] is the input filename
    // argv[2] is the output filename
    if (argc != 3) {
        // NEW: Display the correct command format using stderr
        fprintf(stderr,
                "Usage: ./matrix.exe inputfile outputfile\n");
        // End the program with an error status
        return 1;
    }
    // NEW: Open the input file for reading
    // argv[1] contains the input filename
    strcat(in_directory, argv[1]);
    in = fopen(in_directory, "r");    
    // NEW: Check whether the input file opened successfully
    if (in == NULL) {
        // Display an error message using stderr
        fprintf(stderr,
                "Cannot open input file: %s\n",
                argv[1]);
        // End the program with an error status
        return 1;
    }
    // NEW: Open the output file for writing
    // argv[2] contains the output filename
    strcat(out_directory, argv[2]);
    out = fopen(out_directory, "w");

    // NEW: Check whether the output file opened successfully
    if (out == NULL) {
        // Display an error message using stderr
        fprintf(stderr,
                "Cannot open output file: %s\n",
                argv[2]);
        // Close the input file before ending the program
        fclose(in);
        // End the program with an error status
        return 1;
    }

    // CHANGED: Read Matrix A and Matrix B from the input file
    // read_matrix returns 1 for success and 0 for failure
    //
    // The ! operator changes 0 to true
    // so this condition is true if either read fails
    if (!read_matrix(in, A) ||
        !read_matrix(in, B)) {
        // Display an error if two complete matrices
        // cannot be read from the input file
        fprintf(stderr,
                "Input file does not contain two complete 3x3 matrices.\n");
        // Close both files before ending the program
        fclose(in);
        fclose(out);
        // End the program with an error status
        return 1;
    }

    // CHANGED: Write the Matrix A heading to the output file
    fprintf(out, "Matrix A:\n");
    // CHANGED: Write Matrix A to the output file
    print_matrix(out, A);
    // CHANGED: Write the transpose heading to the output file
    fprintf(out, "\nTranspose of A:\n");
    // Calculate the transpose of Matrix A
    transpose_matrix(A, result);
    // CHANGED: Write the transpose to the output file
    print_matrix(out, result);
    // CHANGED: Calculate and write the determinant
    // to the output file
    fprintf(out,
            "\nDeterminant of A = %.2f\n",
            determinant(A));

    // CHANGED: Write the multiplication heading
    // to the output file
    fprintf(out, "\nA x B:\n");
    // Multiply Matrix A by Matrix B
    multiply_matrix(A, B, result);
    // CHANGED: Write the multiplication result
    // to the output file
    print_matrix(out, result);
    // NEW: Close the input file
    fclose(in);
    // NEW: Close the output file
    fclose(out);
    // End the program successfully

    return 0;
}
