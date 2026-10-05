/*
 * Name:            Jon Lieder
 * Course:          ENEE 150
 * Project:         Project 3
 * Assignment:      Rectangular and Polar Coordinate Conversion using Pointers
 * Date:            October 4, 2026
 *
 * Description:
 * This program prompts the use using a menu to swap from rectangular coordinates to polar, from polar coordinates
 * to rectangular, provide a text file containing a list of which conversion they are intending for a given coordinate
 * pair, or exit the program.  
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define PI 3.14159265358979323



int getMenuChoice(void);
void clearInput(void);
int getRect(double *xPty, double *yPty);
int getPolar(double *rPtr, double *thetaPtr);

void rectToPolar(double x, double y, 
                 double *rptr, double *thetaPtr);
void polarToRect(double r, double theta,
                 double *xPtr, double *yPtr);

void displayRect(double x, double y);
void displayPolar(double r, double theta);

int processTestFile(const char *inputName,
                    const char *outputName);




int main(void){
    char input_file[12] = "testing.txt";
    char output_file[20] = "testing_results.txt";
    bool user_input_stream = true;    
    int choice = 1, input_check;    
    double x, y, r, theta;


    while(user_input_stream){
        
        choice = getMenuChoice();        
        
        switch(choice){
            // RECT TO POLAR
            case 1:
                input_check = getRect(&x, &y);
                if(input_check!=2){
                    printf("Invalid Data!\n");
                    clearInput();
                    continue;
                }
                else{
                    rectToPolar(x, y, &r, &theta);
                    displayPolar(r, theta);
                    break;
}
            // POLAR TO RECT
            case 2:
                input_check = getPolar(&r, &theta);
                if(input_check!=2 || r < 0){
                    printf("Invalid Data!\n");
                    clearInput();
                    break;  
                }
                else{
                    polarToRect(r, theta, &x, &y);
                    displayRect(x, y);
                    break;
                }
            // EXIT
            case 3:
                return 1;
            // FILE I/O
            case 4:
                processTestFile(input_file, output_file);

        }
    }    
}


/*
 * getMenuChoice 
 *
 * Displays a formatted menu display to the user and takes in an initial menu choice from the user.
 *
 * Paramters:
 *      None
 *
 * Returns:
 *      None
 */
int getMenuChoice(){
    int choice;
    bool input_stream = true;

    printf("\n\n________________________________________________\n");
    printf("|                                               |\n");
    printf("|  RECTANGULAR AND POLAR CONVERSION CALCULATOR  |\n");
    printf("|                                               |\n");
    printf("|   (1) Rectangular to Polar                    |\n");
    printf("|   (2) Polar to Rectangular                    |\n");
    printf("|   (3) Exit                                    | \n");
    printf("|   (4) Provide input data file                 | \n");
    printf("|_______________________________________________|\n\n\n");

    while(input_stream){
        // Ensures input is an integer between 1 and 4
        if (scanf("%d", &choice)!=1 || (choice < 1 || choice > 4)){
            printf("Invalid input!\n");
            clearInput();
        }
        else{
            input_stream = false;
        }
    }

    // Handles user entering more than one value (Ex: 2 90. Removes the 90).
    clearInput();

    return choice;
}


/*
 * clearInput
 *
 * Clears the input buffer to "undo" incorrectly entered values from the user.
 *
 * Parameters:
 *      None
 *
 * Returns:
 *      Nothing
 */ 
void clearInput(){
    int choice;

    // Clears the input buffer
    while ((choice = getchar()) != '\n' && choice != EOF){}

    if (choice == EOF){
        clearerr(stdin);
    }
}


/*
 * processTestFile
 *
 * This function takes in an input and output file name, opens the file, and does the conversion method stated within the
 * file on its corresponding coordinate pair. The results are written inside of the output file. 
 *
 * TO MAKE BETTER:
 *      Don't assume 2 coordinates are passed. Display INVALID for test entries with 1 coordinate passed.
 *
 * Parameters:
 *      *inputName - Input file name
 *      *outputName - Output file name
 *
 *  Returns:
 *      0 - if files opened succesfully
 *      1 - if files failed to open
 */
int processTestFile(const char *inputName, const char *outputName){
    FILE *input = fopen(inputName, "r");
    FILE *output = fopen(outputName, "w");
    double input1, input2, x, y, r, theta;
    int choice, count = 1;
    


    if (input == NULL){
        printf("Could not open testing.txt. Terminating program.\n");
        return 1;
    }
    
    if (output == NULL ){
        printf("Could not open testing_results.txt. Terminating program.\n");
        return 1;
    }

    // FILE PROCESSING
    while( fscanf(input, "%d %lf %lf", &choice, &input1, &input2) == 3 ){
        switch(choice){
            case 1:
                x = input1;
                y = input2;
                rectToPolar(x, y, &r, &theta);
                fprintf(output, "Test %d: Rectangular (%.3lf, %.3lf) -> Polar (%.3lf, %.3lf)\n", count, x, y, r, theta);
                break;
            case 2:
                r = input1;
                theta = input2;
                polarToRect(r, theta, &x, &y);
                // Checks for negative radius value
                if(r > 0){
                    fprintf(output, "Test %d: Polar (%.3lf , %.3lf) -> Rectangular (%.3lf, %.3lf)\n", count, r, theta, x, y);
                }
                else{
                    fprintf(output, "Test %d: Polar (%.3lf , %.3lf) -> INVALID. Radius value was negative.\n", count, r, theta);
                }
                break;
        }
        
        count++;
        
    } 
    return 0;
}


/*
 * getRect
 *
 * Obtains the (x, y) rectangular  coordinate pair from the user
 *
 * Parameters:
 *      x (double) -  the x axis coordinate value
 *      y (double) - the y axis coordinate vlaue
 *
 * Returns:
 *      The number of entries obtained from the user
 */
int getRect(double *xPtr, double *yPtr){
    printf("Enter in the x and y coordinates\n");
    printf("Example formatting:\n\tx y\n\t5 -2\n");
    return scanf("%lf %lf", xPtr, yPtr);
}


/*
 * getPolar
 *
 * Obtains the (r, theta) polar coordinate pair from the user
 *
 * Parameters: 
 *      r (double) - the magnitude of the x+y vector
 *      theta (double) - the angle the x+y vector makes with the x unit vector
 *
 * Returns:
 *      The number of entries obtained rfmo the user
 */
int getPolar(double *rPtr, double *thetaPtr){
    printf("Enter in the radius and angle in degrees\n");
    printf("Example formatting:\n\tr theta\n\t2 90\n");
    return scanf("%lf %lf", rPtr, thetaPtr);
}


/*
 * rectToPolar
 *
 * Performs the rectangular to polar coordinate conversion calculations. Basic error handling is done to check for
 * when arctangent causes an instance of divide by zero or undefined. 
 *
 * Parameters:
 *      x (double) - the x-axis coordinate value
 *      y (double) - they y-axis coordinate value
 *      *rPtr (*double) - pointer to the value stored in r (radius)
 *      *thetaPtr (*double) - pointer to the value stored in theta
 *
 *  Returns:
 *      Nothing
 */
void rectToPolar(double x, double y, double *rPtr, double *thetaPtr){
    
    *rPtr = sqrt( x * x + y * y );

    if (x > 0){
        *thetaPtr = atan( y / x ) * 180 / PI;
    }

    else if (x < 0 && y >= 0 ){
        *thetaPtr = ( atan( y / x ) + PI ) * 180 / PI;
    }

    else if (x < 0 && y < 0 ){
        *thetaPtr = ( atan( y / x ) - PI ) * 180 / PI;
    }

    else if (x == 0 && y > 0){
        *thetaPtr = 90;
    }
    
    else if ( x == 0 && y < 0 ){
        *thetaPtr = -90;
    }
    
    else{
        *thetaPtr = 0;
    }
}


/*
 * polarToRect
 *
 * Performs the polar to rectangular coordinate conversion calculations. 
 *
 * Parameters:
 *      r (double) - the magnitude of the x+y vector
 *      theta (double) - the angle between the x+y vector and the x unit vector
 *      *xPtr (*double) - pointer to the value stored in x
 *      *yPtr (*double) - pointer to the value stored in y
 *
 * Returns:
 *      Nothing
 */
void polarToRect(double r, double theta, double *xPtr, double *yPtr){
    *xPtr = r * cos( theta * PI / 180 );
    *yPtr = r * sin( theta * PI / 180 );
}


/*
 * displayRect
 *
 * Displays the result of the polar to rectangular coordinate conversion.
 *
 * Parameters:
 *      x (double) - the x coordinate value
 *      y (double) - the y coordinate value
 *
 * Returns:
 *      Nothing
 */
void displayRect(double x, double y){
    printf("Rectangular coordinate pair:\t(%.3lf, %.3lf)\n", x, y);
}


/*
 * displayPolar
 *
 * Displays the result of the rectangular to polar coordinate conversion.
 *
 * Parameters:
 *      r (double) - the magnitude of the x+y vector
 *      theta (double) - the angle between the x+y vector and the x unit vector
 *
 * Returns:
 *      Nothing
 */
void displayPolar(double r, double theta){
    printf("Polar coordinate pair:\t(%.3lf, %.3lf)\n", r, theta);
}
