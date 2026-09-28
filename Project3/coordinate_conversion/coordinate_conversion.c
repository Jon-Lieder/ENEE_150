/*
 * Name:            Jon Lieder
 * Course:          ENEE 150
 * Project:         Project 3
 * Assignment:      Rectangular and Polar Coordinate Conversion using Pointers
 * Date:            October 4, 2026
 *
 * Description:
 * This program...
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define PI 3.14159


int getMenuChoice(void);
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
    FILE *input;
    FILE *output;

    char *input_file[100];
    char *output_file[100];

    bool user_input_stream = true;    
    
    int choice;
    
    double x, y, r, theta;

/*
    if ( argc !=3 ){
        printf("( 1 ) Error: Improper Usage. Terminating Program\n\t./coordinate_conversion.exe testing.txt testing_results.txt\n");
        return 1;
    }
*/

    // USER HAS TO ENTER FILE AS MENU OPTION 1. DONT DO LIMITING CASE ABOVE.

    processTestFil(argv[1]. argv[2]);

    while(user_input_stream){
        choice = getMenuChoice();
        
        return 1;
        switch(choice){
            // RECT TO POLAR
            case 1:
                getRect(&x, &y);
                rectToPolar(x, y, &r, &theta);
                break;
            // POLAR TO RECT
            case 2:
                getPolar(&r, &theta);
                polarToRect(x, y, &r, &theta);
                break;
            // EXIT
            case 3:
                return 1;
            // FILE I/O
            case 4:
                scanf("%c" , input_file);
                scanf("%c" , output_file);
                processTestFile(input_file, output_file);

        }
    }    
}


int getMenuChoice(){
    int choice;

    printf("___________");
    printf("||\n");
    printf("|RECTANGULAR AND POLAR CONVERSION CALCULATOR|\n");
    printf("||\n");
    printf("| (1) Rectangular to Polar |\n");
    printf("| (2) Polar to Rectangular |\n");
    printf("| (3) Exit | \n");
    printf("| (4) Provide input data file | \n");
    printf("|_|\n");

    scanf("%d", &choice);

    return choice;
}


int processTestFile(const char *inputName, const char *outputName){
    FILE *input = fopen(inputName, "r");
    FILE *output = fopen(outputName, "w");

    if (input == NULL){
        printf("Could not open testing.txt. Terminating program.\n");i
        return 1;
    }
    
    if (output == NULL ){
        printf("Could not open testing_results.txt. Terminating program.\n");
        return 1;
    }
}


int getRect(double *xPtr, double *yPtr){
    scanf("%lf %lf", xPtr, yPtr);
}

int getPolar(double *rPtr, double *thetaPtr){
    scanf("%lf %lf", rPtr, thetaPtr);
}

void rectToPolar(double x, double y, double *rPtr, double *thetaPtr){
    *rPtr = sqrt( x * x + y * y );
    if ( x == 0 && y > 0 ){
        *thetaPtr = 90;
    }
    
    else if ( x == 0 && y < 0 ){
        *thetaPtr = -90;
    }
    else{
        *thetaPtr = atan( y / x ) * 360 / PI;
    }
}

void polarToRect(double r, double theta, double *xPtr, double *yPtr){
    *xPtr = r * cos( theta * PI / 360 );
    *yPtr = r * sin( theta * PI / 360 );
}

void displayRect(double x, double y){}

void displayPolar(double r, double theta){}
