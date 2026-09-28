/*
 * Name:            Jon Lieder
 * Course:          ENEE 150
 * Project:         Lab 04
 * Assignment:      Fraction Calculations Project
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
    int choice;
    int status;
    int extra;
    int validInput;

    /* First fraction: n1/d1 */
    int n1;
    int d1;

    /* Second fraction: n2/d2 */
    int n2;
    int d2;

    /* Result fraction: n3/d3 */
    int n3;
    int d3;


    /*
     * Repeat until the user selects option 4.
     *
     * Notice that no break or continue statements are needed.
     * The loop condition controls when the program ends.
     */
    do
    {
        printf("\n");
        printf("Fraction Calculator\n");
        printf("-------------------\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Exit\n");
        printf("Enter choice: ");


        /**********************************************************
         * READ THE MENU OPTION
         *
         * scanf() returns the number of variables that it
         * successfully fills.
         *
         * We are trying to read ONE integer.
         *
         * Therefore:
         *
         *      status == 1   successful integer input
         *      status != 1   invalid input
         **********************************************************/

        status = scanf("%d", &choice);


        /*
         * Remove anything else remaining on the input line.
         *
         * clearInput() returns 1 if unexpected non-whitespace
         * characters were found.
         *
         * Therefore:
         *
         *      2
         *
         * is valid, while:
         *
         *      2abc
         *
         * is invalid.
         */
        extra = clearInput();


        /*
         * If the menu input is invalid, set choice to 0.
         *
         * This keeps the loop running but prevents any fraction
         * calculations from being performed.
         */
        if (status != 1 || extra)
        {
            printf("Invalid option. Please enter 1, 2, 3, or 4.\n");

            choice = 0;
        }


        /*
         * Option 4 ends the program through the loop condition.
         */
        else if (choice == 4)
        {
            printf("Goodbye.\n");
        }


        /*
         * Reject integers outside the valid menu range.
         */
        else if (choice < 1 || choice > 4)
        {
            printf("Invalid option. Please enter 1, 2, 3, or 4.\n");
        }


        /*
         * If we reach this point, choice must be 1, 2, or 3.
         */
        else
        {
            /******************************************************
             * READ FIRST FRACTION
             ******************************************************/

            printf("Enter first fraction (N/D): ");

            /*
             * n1 and d1 are ordinary int variables in main().
             *
             * getfraction() must CHANGE them, so their addresses
             * are passed:
             *
             *      &n1
             *      &d1
             *
             * getfraction() returns:
             *
             *      1 for valid input
             *      0 for invalid input
             */
            validInput = getInput(&n1, &d1);


            /******************************************************
             * READ SECOND FRACTION
             *
             * Only ask for the second fraction if the first
             * fraction was valid.
             ******************************************************/

            if (validInput)
            {
                printf("Enter second fraction (N/D): ");

                validInput = getInput(&n2, &d2);
            }


            /******************************************************
             * PERFORM THE CALCULATION
             *
             * Only continue if BOTH fractions were valid.
             ******************************************************/

            if (validInput)
            {
                if (choice == 1)
                {
                    /*
                     * n1, d1, n2, and d2 are input values.
                     *
                     * n3 and d3 are output variables.
                     *
                     * The addresses of n3 and d3 are passed so
                     * add() can store TWO results.
                     */
                    add(n1, d1,
                        n2, d2,
                        &n3, &d3);
                }

                else if (choice == 2)
                {
                    subtract(n1, d1,
                             n2, d2,
                             &n3, &d3);
                }

                else
                {
                    multiply(n1, d1,
                             n2, d2,
                             &n3, &d3);
                }


                /**************************************************
                 * REDUCE THE RESULT
                 **************************************************/

                /*
                 * reduce() must change both n3 and d3.
                 *
                 * Therefore, their addresses are passed.
                 */
                reduce(&n3, &d3);


                /**************************************************
                 * DISPLAY THE RESULT
                 **************************************************/

                printf("Result: ");

                /*
                 * display() only needs to READ n3 and d3.
                 *
                 * Therefore, ordinary values are passed.
                 */
                display(n3, d3);
            }
        }

    } while (choice != 4);


    return 0;
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
}

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
