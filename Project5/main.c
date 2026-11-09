/*  NAME:               Jon Lieder
 *  COURSE:             ENEE 150
 *  ASSIGNMENT:         Fraction calculator using struct
 *  PROJECT:            Project 5
 *  DATE:               November 8 2026
 *
 *  This program has an interactive and automatic mode. Interactive mode takes in standard input from the user for the
 *  operand, numerator 1, denominator 1, numerator 2, and denomiator 2. 
 *
 *  This can be performed in one input 
 *                  EXAMPLE: + 1 5 2 5
 *  or separately 
 *                  EXAMPLE: +
 *                           1
 *                           5
 *                           2
 *                           5 
 *
 *  Automatic mode takes in an input file and an output file. The input is file containing fraction operations and the values
 *  for each numerator and denominator, then writes the result to the provided output file.
 *
 *  QUESTION: 
 *      In a professional setting when writing a program with the functionality of an interactive and automatic mode or just
 *      multiple modes in general, is main() treated as just the mode selection? 
 *
 *      main() ---- interactiveMode()
 *              |
 *              --- fileMode() 
 */ 


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "fraction.h"

#define VALID_OPERANDS "+-*/$"


int main(int argc, char *argv[]){ 
    bool take_input = true;
    char operand, line[100];
    int count;
    FILE *in = stdin;
    FILE *out = stdout;
    Fraction a = {0}, b = {0}, f = {0};


    if ( argc == 3 ){
        /*    Input file handling    */
        in = fopen( argv[1], "r" );
            if ( in == NULL ){ 
                printf( "ERROR: Could not open %s", argv[1] );
                return 1; 
            }

        /*    Output file handling    */
        out = fopen( argv[2], "w" );
            if ( out == NULL ){ 
                printf( "ERROR: Could not open %s", argv[2] );
                fclose(in);
                return 1; 
            }
    }
   
    /*    Improper runtime executable call    */ 
    else if ( argc != 1 ){ 
        printf("Incorrect useage. Please use one of the two calls:\n");
        printf("\t(1) ./fraction.exe - Interactive mode\n");
        printf("\t(2) ./fraction.exe fraction_input.txt fraction_results.txt - Automatic / File mode\n\n");

        return 1;
    }

    while ( take_input ){
        
        if ( argc != 3){ printf("Operation (+, -, *, /, $): "); }

        /* Input failed, quit program */
        if ( fgets(line, sizeof(line), in) == NULL ){ break; }

        /* Decides 70% tier vs. 80% tier logic */
        count = sscanf(line, " %c %d %d %d %d", &operand, &a.numerator, &a.denominator, &b.numerator, &b.denominator); 

        /* Accidental enter input */
        if ( count == EOF ){ continue; }

        /* Manually quit program */
        if ( count >= 1 && operand == '$'){ take_input = false; continue; }

        /* No input or invalid operand not in given string of valid operands */
        if ( count < 1 || strchr(VALID_OPERANDS, operand) == NULL){
            fprintf( out, "Invalid operation.\n" );
        }

        /*  70% TIER INPUT  */
        if ( count == 1 ){
            if ( !readInt( "Numerator 1: " , &a.numerator )     ||
                 !readInt( "Denominator 1: " , &a.denominator ) ||
                 !readInt( "Numerator 2: " , &b.numerator )     ||
                 !readInt( "Denominator 2: " , &b.denominator ) ){
                printf("Invalid operation.\n");
                continue; 
            }
        }

        /*  Incomplete line. EX: + 1 5 4  */
        else if ( count != 5){
            fprintf( out, "Invalid input\n" );
            continue;
        }

        /*  Division by 0  */
        if ( a.denominator == 0 || b.denominator == 0 ){ 
            fprintf( out, "ERROR: cannot divide by 0\n" );
            continue; 
        }

        /*  Division by 0  */
        if ( b.numerator == 0 && operand == '/' ){ 
            fprintf( out, "ERROR: cannot divide by 0\n" );
            continue; 
        }


        /*  Operand processing block  */
        if ( operand == '+' ){ f = addFraction(a, b); }
        
        else if ( operand == '-' ){ f = subFraction(a, b); }
        
        else if ( operand == '*' ){ f = multiplyFraction(a, b); }

        else if ( operand == '/' ){ f = divideFraction(a, b); }

        else if ( operand == '$' ){ take_input = false; break; }

        else{ continue; }

        simplifyFraction(&f); 
        displayFraction(f, out);
        
        
    }

    if ( argc == 3 ){
        fclose( out );
        fclose( in );
    }

}
