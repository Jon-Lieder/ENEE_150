#include <stdio.h>
#include <stdlib.h>
#include "fraction.h"



/* addFraction
 *
 * Performs addition of fractions through:
 *      
 *      n1   n2    n1 * d2 + n2 * d1
 *      __   __    __________________
 *         +    =
 *      d1   d2         d1 * d2
 *
 * Parameters:
 *      a - the first Fraction containing numerator 1 and denominator 1
 *      b - the second Fraction containing numerator 2 and denominator 2
 *
 * Returns:
 *      f - the resulting fraction containing numerator 3 and denominator 3
 */
Fraction addFraction( Fraction a, Fraction b ){
    Fraction f = {0};

    f.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    f.denominator = a.denominator * b.denominator;
 
    return f;
}



/* subFraction
 *
 * Performs subtraction of fractions through:
 *      
 *      n1   n2    n1 * d2 - n2 * d1
 *      __   __    __________________
 *         -    =
 *      d1   d2         d1 * d2
 *
 * Parameters:
 *      a - the first Fraction containing numerator 1 and denominator 1
 *      b - the second Fraction containing numerator 2 and denominator 2
 *
 * Returns:
 *      f - the resulting fraction containing numerator 3 and denominator 3
 */
Fraction subFraction( Fraction a, Fraction b ){
    Fraction f = {0};

    f.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    f.denominator = a.denominator * b.denominator;

    return f;
}


/* multiplyFraction
 *
 * Performs multiplication of fractions through:
 *      
 *      n1   n2     n1 * n2
 *      __   __    _________
 *         +    =
 *      d1   d2     d1 * d2
 *
 * Parameters:
 *      a - the first Fraction containing numerator 1 and denominator 1
 *      b - the second Fraction containing numerator 2 and denominator 2
 *
 * Returns:
 *      f - the resulting fraction containing numerator 3 and denominator 3
 */

Fraction multiplyFraction( Fraction a, Fraction b ){
    Fraction f = {0};

    f.numerator = a.numerator * b.numerator;
    f.denominator = a.denominator * b.denominator;

    return f;
}


/* divideFraction
 *
 * Performs division of fractions through:
 *      
 *      n1   n2     n1 * d2
 *      __   __    _________
 *         +    =
 *      d1   d2     d1 * n2
 *
 * Parameters:
 *      a - the first Fraction containing numerator 1 and denominator 1
 *      b - the second Fraction containing numerator 2 and denominator 2
 *
 * Returns:
 *      f - the resulting fraction containing numerator 3 and denominator 3
 */

Fraction divideFraction( Fraction a, Fraction b ){
    Fraction f = {0};

    f.numerator = a.numerator * b.denominator;
    f.denominator = b.numerator * a.denominator;

    return f;
}



/* simplifyFraction
 *
 * Through nested loops, the fraction f is placed into standard form (full simplification).
 *
 * The for loop raises a counter (gcd) from 2 to the lowest of the two numbers:
 *          f->numerator = 3, f->denominator = 7, loop goes to gcd = 3
 *          f->numerator = 8, f->denominator = 2, loop only performs the first loop at gcd = 2
 *          f->numerator = 4, f->denominator = 4, loop goes to gcd = 4
 *
 * The while loop checks if both the numerator and denominator can be divided by the same number. When both can be 
 * divided by the current value of gcd, both numerator and denominator are scaled by 1 / gcd.
 *
 * If the denominator is 0, the fraction's numerator is given its negative counter part and the denominator is turned
 * positive. 
 *
 * Parameters: 
 *      *f - Fraction pointer containing the numerator and denominator to be simplified
 *
 * Returns:
 *      Nothing
 */ 
void simplifyFraction( Fraction *f ){
    for(int gcd = 2 ; gcd <= abs(f->numerator) && gcd <= abs(f->denominator) ; gcd++){
        while (f->numerator % gcd == 0 && f->denominator % gcd == 0){
            f->numerator /= gcd;
            f->denominator /= gcd;
        }
    }

    if ( f->denominator < 0 ){
        f->numerator = -f->numerator;
        f->denominator = -f->denominator;
    }

    return;
}



/* displayFraction
 *
 * Displays / writes the simplified fraction to either the command line / file respectively. If no files were provided
 * at runtime, out is standard output. If the fraction can be further simplified to a whole number, a separate output
 * is called to only use the numerator. 
 *
 * Parameters:
 *      f - Fraction containing the numerator and denominator values to print out
 *      out ---- stdout - no files privded and displayed to command line
 *           | 
 *           --- fraction_results.txt - output file to be written to
 *
 * Returns:
 *      Nothing
 */
void displayFraction( Fraction f, FILE *out ){

    if ( f.denominator == 1 ){
        fprintf( out, "Result: %d\n", f.numerator );
    }
    
    else if ( f.numerator == 0 ){
        fprintf( out, "Result: %d\n", f.numerator );
    }
    
    else{
        fprintf( out, "Result: %d / %d\n", f.numerator, f.denominator );
    }

    return;
}


/* OPTIONAL HELPER FUNCTIONS */


/* readInt
 *
 * Provides a stdout prompt to the user asking for a numerator 1, denominator 1, numerator 2, and denominator 2 in that order.
 * Takes in a line from the user and returns 0 if input fails to be read OR if sscanf DOES NOT return 1. Returns 1 if scanf 
 * returns 1.
 *
 * Parameters:
 *      prompt - string containing the stdout text (numerator 1, denominator 1, numerator 2, or denominator 2)
 *      value - integer corresponding to the current fraction member to be stored
 *
 * Returns:
 *      0 - failed input | sscanf does not return 1
 *      1 - successfully read 1 integer value 
 */
int readInt(const char *prompt, int *value){
    char line[100];

    printf("%s", prompt);
    if(fgets(line, sizeof(line), stdin) == NULL){ return 0; }
    return sscanf(line, "%d", value) == 1;
}
