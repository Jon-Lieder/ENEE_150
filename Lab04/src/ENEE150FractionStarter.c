/*
 * fraction.c
 * ENEE 150 - Fraction Calculations Project
 *
 * PURPOSE
 * -------
 * This program implements a menu-driven fraction calculator.
 * The user may:
 *
 *      1. Add two fractions
 *      2. Subtract two fractions
 *      3. Multiply two fractions
 *      4. Exit
 *
 * Fractions are entered in N/D form, such as:
 *
 *      3/4
 *      -2/5
 *      10/3
 *
 * Each calculated result is reduced to lowest terms before
 * it is displayed. If the reduced result is a whole number,
 * the program displays the whole number instead of N/D.
 *
 *
 * POINTER CONCEPTS DEMONSTRATED
 * -----------------------------
 * 1. Passing the address of a variable to a function:
 *
 *        getInput(&n1, &d1);
 *
 * 2. Receiving addresses through pointer parameters:
 *
 *        int getInput(int *numPtr, int *denPtr)
 *
 * 3. Dereferencing a pointer to change a caller's variable:
 *
 *        *numPtr
 *
 * 4. Returning two results through pointer parameters:
 *
 *        add(n1, d1, n2, d2, &n3, &d3);
 *
 * 5. Modifying two existing variables in place:
 *
 *        reduce(&n3, &d3);
 *
 *
 * PROGRAM DESIGN
 * --------------
 * main() owns all fraction variables.
 *
 * No global variables are used.
 *
 * Functions that only need to READ values receive ordinary
 * parameters.
 *
 * Functions that need to CHANGE variables in main() receive
 * their addresses through pointer parameters.
 *
 */

#include <stdio.h>


/**************************************************************
 * FUNCTION PROTOTYPES
 **************************************************************/

int getInput(int *numPtr, int *denPtr);

void display(int num, int den);

void reduce(int *numPtr, int *denPtr);

void add(int n1, int d1,
         int n2, int d2,
         int *n3Ptr, int *d3Ptr);

void subtract(int n1, int d1,
              int n2, int d2,
              int *n3Ptr, int *d3Ptr);

void multiply(int n1, int d1,
              int n2, int d2,
              int *n3Ptr, int *d3Ptr);

int gcd(int x, int y);

int clearInput(void);


/**************************************************************
 * main
 **************************************************************/

int main(void)
{
    int numPtr, denPtr;

    getInput(&numPtr, &denPtr);

    switch(choice){
        case 1:
            add();
        case 2:
            subtract();
        case 3:
            multiply();
        case 4:
            return 1;

    }
    /*
     * TODO:
     * Calculate the result numerator for n1/d1 * n2/d2
     * and store it through n3Ptr.
     */

    /*
     * TODO:
     * Calculate the result denominator and store it through d3Ptr.
     */
}


/**************************************************************
 * getInput
 *
 * Reads one fraction in N/D form.
 *
 * Examples:
 *
 *      3/4
 *      -2/5
 *      10/3
 *
 * numPtr and denPtr already contain the addresses of variables
 * in main().
 *
 * Therefore:
 *
 *      scanf("%d/%d", numPtr, denPtr);
 *
 * is correct.
 *
 * Do NOT use:
 *
 *      &numPtr
 *      &denPtr
 *
 * because that would give scanf() the addresses of the pointer
 * variables rather than the addresses of the integers in main().
 *
 * Returns:
 *
 *      1 for valid input
 *      0 for invalid input
 **************************************************************/

int getInput(int *numPtr, int *denPtr)
{
    int status;
    int extra;
    int valid;


    /*
     * Assume the input is valid until a problem is found.
     */
    valid = 1;


    /*
     * scanf() should successfully fill TWO integer variables:
     *
     *      numerator
     *      denominator
     *
     * Therefore, valid fraction input should make scanf()
     * return 2.
     */
    status = scanf("%d/%d", numPtr, denPtr);


    /*
     * Remove anything remaining on the input line.
     *
     * This allows us to detect input such as:
     *
     *      1/2abc
     */
    extra = clearInput();


    /*
     * VALIDATION 1
     *
     * Two integer values must have been successfully read.
     */

     // TODO
     if (status != 2){
        printf("(V1) Error: fraction must be in num/det form (ex: 3/4)\n");
        valid = 0;
    }


    /*
     * VALIDATION 2
     *
     * Reject unexpected characters after the fraction.
     *
     * Only perform this check if scanf() successfully read
     * the two integers.
     */

     // TODO
    else if (extra){
        printf("(V2) Error: fraction must be in num/det form (ex: 3/4)\n");  
        valid = 0;
    }


    /*
     * VALIDATION 3
     *
     * The denominator cannot be zero.
     *
     * denPtr contains an ADDRESS.
     *
     * *denPtr is the integer VALUE stored at that address.
     */

     //TODO
    else if (*denPtr == 0){
        printf("Error: Attempted to divide by 0. Execution commencing.\n");
        valid = 0;
    }
    /*
     * Return the status to main().
     */
    return valid;
}


/**************************************************************
 * display
 *
 * Displays a reduced fraction.
 *
 * This function does not modify num or den, so ordinary
 * parameters are used.
 **************************************************************/

void display(int num, int den)
{
    /*
     * If the numerator divides evenly by the denominator,
     * display a whole number.
     *
     * Example:
     *
     *      6/3
     *
     * displays:
     *
     *      2
     */


     // TODO
    if (!num % den){
        printf("%d\n", num / den);
    }
    /*
     * Otherwise display the result in N/D form.
     */

     //TODO
    else{
        printf("%d / %d\n", num, den);
    }
}


/**************************************************************
 * reduce
 *
 * Reduces a fraction to lowest terms.
 *
 * Example:
 *
 *      6/8
 *
 * becomes:
 *
 *      3/4
 *
 * Because this function changes BOTH the numerator and
 * denominator in main(), pointer parameters are used.
 **************************************************************/

void reduce(int *numPtr, int *denPtr)
{
    int divisor;


    /*
     * Keep a negative sign in the numerator rather than the
     * denominator.
     *
     * Example:
     *
     *      1/-2
     *
     * becomes:
     *
     *      -1/2
     */
    if (*denPtr < 0)
    {
        *numPtr = -*numPtr;

        *denPtr = -*denPtr;
    }


    /*
     * Find the greatest common divisor.
     *
     * Notice that gcd() receives ordinary integer VALUES.
     */
    divisor = gcd(*numPtr, *denPtr);


    /*
     * Divide both values by the GCD.
     *
     * Because these assignments dereference numPtr and denPtr,
     * they change n3 and d3 back in main().
     */
    *numPtr = *numPtr / divisor;

    *denPtr = *denPtr / divisor;
}


/**************************************************************
 * gcd
 *
 * Calculates the greatest common divisor using Euclid's
 * algorithm.
 *
 * Examples:
 *
 *      gcd(6, 8)    returns 2
 *      gcd(12, 18)  returns 6
 **************************************************************/

int gcd(int x, int y)
{
    int remainder;


    /*
     * Work with positive magnitudes.
     */
    if (x < 0)
    {
        x = -x;
    }

    if (y < 0)
    {
        y = -y;
    }


    /*
     * Euclid's algorithm.
     */
    while (y != 0)
    {
        remainder = x % y;

        x = y;

        y = remainder;
    }


    return x;
}


/**************************************************************
 * add
 *
 * Adds:
 *
 *      n1     n2
 *      --  +  --
 *      d1     d2
 *
 * Formula:
 *
 *      result numerator   = n1*d2 + n2*d1
 *      result denominator = d1*d2
 *
 * n3Ptr and d3Ptr are OUTPUT pointer parameters.
 **************************************************************/

void add(int n1, int d1,
         int n2, int d2,
         int *n3Ptr, int *d3Ptr)
{
    /*
     * Dereferencing the pointers stores the results in
     * n3 and d3 in main().
     */

     // TODO!!
    *n3Ptr = n1 * d2 + n2 * d1;
    *d3Ptr = d1 * d2;


/**************************************************************
 * subtract
 *
 * Subtracts:
 *
 *      n1     n2
 *      --  -  --
 *      d1     d2
 *
 * Formula:
 *
 *      result numerator   = n1*d2 - n2*d1
 *      result denominator = d1*d2
 **************************************************************/

void subtract(int n1, int d1,
              int n2, int d2,
              int *n3Ptr, int *d3Ptr)
{
        // TODO
    *n3Ptr = n1 * d2 - n2 * d1;
    *d3Ptr = d1 * d2;
}


/**************************************************************
 * multiply
 *
 * Multiplies:
 *
 *      n1     n2
 *      --  *  --
 *      d1     d2
 *
 * Formula:
 *
 *      result numerator   = n1*n2
 *      result denominator = d1*d2
 **************************************************************/

void multiply(int n1, int d1,
              int n2, int d2,
              int *n3Ptr, int *d3Ptr)
{

    // TODO
    *n3Ptr = n1 * n2;
    *d3Ptr = d1 * d2;
}


/**************************************************************
 * clearInput
 *
 * Removes the characters remaining on the current input line.
 *
 * This prevents bad input from interfering with the next
 * scanf() call.
 *
 * It also reports whether unexpected non-whitespace characters
 * were found.
 *
 * Returns:
 *
 *      0   only whitespace remained
 *
 *      1   at least one non-whitespace character remained
 *
 * NOTE:
 * This is an input-validation helper function. It is not one
 * of the important pointer concepts being assessed.
 **************************************************************/

int clearInput(void)
{
    int ch;
    int extra;


    extra = 0;


    /*
     * Read characters until the newline ending the current
     * input line is reached.
     */
    ch = getchar();

    while (ch != '\n')
    {
        /*
         * Spaces and tabs are harmless.
         *
         * Anything else counts as unexpected trailing input.
         */
        if (ch != ' ' &&
            ch != '\t' &&
            ch != '\r')
        {
            extra = 1;
        }


        /*
         * Read the next character.
         */
        ch = getchar();
    }


    return extra;
}
