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
#define ELEMENTS 2

int getInputFile(const char *input_file_name, FILE **input);
void getEquipmentName(FILE *input, const char *name_to_match, char *line, char *summary);
//void fullNameBuilder(const char *first_name, const char *last_name, char *full_name);
//void displayName(const char *first_name, const char *last_name, const char *full_name);


/*
 * getInputFile
 *
 * Opens the current data text files in read mode. 
 *
 * Parameters:
 *      *input_file_name - pointer to the input file to read data from
 *
 * Returns:
 *      None
 */

int getInputFile(const char *input_file_name, FILE **input){
    *input = fopen(input_file_name, "r");

    if (*input == NULL){
        return 1;
    }
    return 0;
}


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

void getEquipmentName(FILE *input, const char *name_to_match, char *line, char *summary){
    int length;
    printf("Here\n");
    fscanf(input, "%s", line);
    printf("No, Here\n");
    char *start = strstr(line, name_to_match);
    //printf("%s\n", summary);
    printf("HERE");    
    start += strlen(name_to_match);
    while (*start == ' '){
        start++;
    }

    length = strcspn(start, " \n");
    if (length >= MAX_CHAR){
        length = MAX_CHAR - 1;
    }
    printf("Here\n");
    strncpy(summary, start, length);
    summary[length] = '\0';

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
/*
void fullNameBuilder(const char *summary, 
                     const char *name_to_match, 
                     char *full_name){

                                        // Example:
    strcpy(full_name, first_name);       // "\0" -> "Jon\0"
    strcat(full_name, "_");             // "Jon\0" -> "Jon \0"
    strcat(full_name, last_name);       // "Jon \0" -> "Jon LIeder\0"
}
*/

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


int main(int argc, char *argv[]){
    FILE *input;
    char equipment_name[MAX_CHAR], channel_number[MAX_CHAR], 
         date[MAX_CHAR], sample_rate[MAX_CHAR], summary[ELEMENTS * MAX_CHAR], line[ELEMENTS * MAX_CHAR];
    char names_to_match[ELEMENTS][MAX_CHAR] = {"Equipment:", "Sampling Rate:"};
    int file_success;        

    for (int i = 0 ; i < argc ; i++){
        file_success = getInputFile(argv[i+1], &input);

        if (file_success == 1 && i+1 == argc){
            printf("End of input files reached. Terminating program.\n");
            break;
        }
        else if (file_success == 1){
            printf("File failed to open. Continuing on to next file.\n");
            continue;
        }
        
        for (int j = 0 ; j < ELEMENTS ; j++){
            getEquipmentName(input, names_to_match[j], line, summary);
            printf("%s\n", names_to_match[j]);
        }
        //fclose(input);
    }
    //getName(first_name, last_name);
    //fullNameBuilder(first_name, last_name, full_name);
    //displayName(first_name, last_name, full_name);

    
    return 0;
}
