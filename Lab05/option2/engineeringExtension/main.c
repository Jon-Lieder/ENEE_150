/*  i
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
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 50
#define ELEMENTS 2

int getFiles(const char *input_file_name, FILE **input, int argc, int current_file);
int getKeyword(FILE *input, const char *name_to_match, char *line, char *summary);
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

int getFiles(const char *input_file_name, FILE **input, int argc, int current_file){
    *input = fopen(input_file_name, "r");

    if (*input == NULL && current_file + 1 == argc){
        printf("All files opened successfully.\n");
        return 1;
    }
    else if(*input == NULL){
        printf("Failed to open %s. Terminating program.\n", input_file_name);
        //exit(1);
        return 1;
    }
    
    return 0;
}

void openOutputFile(const char *output_file_name, FILE *output){
    output = fopen(output_file_name, "w");
    
    if (output == NULL){
        printf("Failed to open %s to write. Terminating program\n", output_file_name);
        exit(1);
    }
}

/*
 * getKeyword
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

int getKeyword(FILE *input, const char *name_to_match, char *line, char *summary){
    int length;

    rewind(input);

    while(fgets(line, MAX_CHAR, input) != NULL){

        char *start = strstr(line, name_to_match);
        
        if (start == NULL){
            continue;
        }

        start += strlen(name_to_match);

        while (*start == ' ' || *start == ':'){
            start++;
        }

        length = strcspn(start, " \n");

        if (length >= MAX_CHAR){
            length = MAX_CHAR - 1;
        }

        strncpy(summary, start, length);
        summary[length] = '\0';
        printf("Start:\t\t%s", start);
        printf("Length:\t\t%d\n", length);
        printf("Summary:\t%s\n", summary);
        return 1; // Found keyword
    }

    return 0; // Keyword not found in file
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

void mergeStrings(const char *summary, 
                     const char *name_to_match, 
                     char *full_list){

                                        // Example:
    strcpy(full_list, name_to_match);       // "\0" -> "Jon\0"
    strcat(full_list, ": ");             // "Jon\0" -> "Jon \0"
    strcat(full_list, summary);       // "Jon \0" -> "Jon LIeder\0"
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
void writeOutput(FILE *output,
                 const char *full_list){
//    printf("\n%s + %s -> %s\n", first_name, last_name, full_name);
    fprintf(output, "%s\n", full_list);
}


int main(int argc, char *argv[]){
    FILE *input, *output;
    char summary[MAX_CHAR], line[MAX_CHAR], full_list[MAX_CHAR];
    char names_to_match[ELEMENTS][MAX_CHAR] = {"Equipment", "Sampling Rate"};
    int file_success, is_found;        

    openOutputFile("results.txt", output);
 
    for (int i = 1 ; i < argc ; i++){
        if(getFiles(argv[i], &input, argc, i) == 1){
            continue;
        }

        for (int j = 0 ; j < ELEMENTS ; j++){
            if (getKeyword(input, names_to_match[j], line, summary)){
                //mergeStrings(summary, names_to_match[j], full_list);
                //writeOutput(output, full_list);
            }
            //printf("%s\n", names_to_match[j]);
        }

        //fclose(input);
    }
    
    fclose(output);
    //getName(first_name, last_name);
    //fullNameBuilder(first_name, last_name, full_name);
    //displayName(first_name, last_name, full_name);

    
    return 0;
}
