/*  
 *  NAME:           Jon Lieder
 *  COURSE:         ENEE 150
 *  PROJECT:        Lab 5
 *  ASSIGNMENT:     Option 6 - Full Name Builder
 *  DATE:           October 5, 20206
 *
 *  This program takes in a first name and a last name from the user on the command line, copies
 *  the first name and last name into a name separated by a concatenated space to form and display
 *  the inputted full name.
 */

#include <stdio.h>
#include <string.h>

#define MAX_CHAR 50

void getName(char *first_name, char *last_name);
void fullNameBuilder(const char *first_name, const char *last_name, char *full_name);
void displayName(const char *first_name, const char *last_name, const char *full_name);

/*
 * getName
 *
 * Obtains the first name and the last name into two separate arrays.
 *
 * Parameters:  
 *      *first_name - pointer to the first_name char array
 *      *last_name - pointer to the last_name char array
 *
 * Returns:
 *      Nothing
 */
void getName(char *first_name, char *last_name){
    printf("Enter your first name:\t");
    scanf("%s", first_name);
    printf("Enter your last name:\t");
    scanf("%s", last_name);
}


/*
 * fullNameBuilder
 *
 * Copies the first and last name into the full_name array separated by a space.
 *
 * Parameters:
 *      *first_name - pointer to the first_name char array
 *      *last_name - pointer to the last_name char array
 *      *full_name - pointer to the full_name char array 
 *
 * Returns:
 *      Nothing
 */
void fullNameBuilder(const char *first_name, 
                     const char *last_name, 
                     char *full_name){

                                        // Example:
    strcpy(full_name, first_name);       // "\0" -> "Jon\0"
    strcat(full_name, "_");             // "Jon\0" -> "Jon \0"
    strcat(full_name, last_name);       // "Jon \0" -> "Jon LIeder\0"
}


/*
 * displayName
 *
 * Displays the inputted names and the final concatenated result to the command line.
 * EX: 
 *      Jon + Lieder -> Jon Lieder
 *
 *  Parameters:
 *      *first_name - pointer to the first_name char array
 *      *last_name - pointer to the last_name char array
 *      *full_name - pointer to the full_name char array
 *
 * Returns:
 *      Nothing
 */
void displayName(const char *first_name,
                 const char *last_name,
                 const char *full_name){
    printf("\n%s + %s -> %s\n", first_name, last_name, full_name);
}


int main(){
    char first_name[MAX_CHAR], last_name[MAX_CHAR], full_name[2 * MAX_CHAR];
    
    getName(first_name, last_name);
    fullNameBuilder(first_name, last_name, full_name);
    displayName(first_name, last_name, full_name);

    return 0;
}
