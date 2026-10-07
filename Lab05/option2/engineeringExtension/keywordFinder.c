/*  
 *  NAME:           Jon Lieder
 *  COURSE:         ENEE 150
 *  PROJECT:        Lab 5
 *  ASSIGNMENT:     Option 2 Engineering Extension - Electronics Hardware Keyword Finder
 *  DATE:           October 5, 20206
 *
 *  This program takes in ALL hardware output .txt files on the command line opened one by one in a loop. 
 *  The program then scans each file individually for a known list of keywords configurable in main. Note that if
 *  the list of keywords change, ELEMENTS below must be changed to match the size of the keywords array. 
 *
 *  RIGOL technologies' oscilloscope output files were used as they were the easiest I found to work with but the program
 *  could easily be extended/changed to work with any company's products but an array of delimiters might be needed.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 50
#define ELEMENTS 6

int getFiles(const char *input_file_name, FILE **input, int argc, int current_file);
void openOutputFile(const char *output_file_name, FILE **output);
int getKeyword(FILE *input, const char *name_to_match, char *line, char *summary);
void mergeStrings(const char *summary, const char *name_to_match, char *full_list);
void writeOutput(FILE *output, const char *full_list);
void newFileHeader(FILE *output, const char *input_file_name);

/*
 * getFiles
 *
 * Opens the current data text files in read mode. 
 *
 * Parameters:
 *      *input_file_name - pointer to the input file to read data from
 *      **input - pointer TO the pointer for the file. Allows manipulation of the pointer in different functions
 *      argc - int for how many arguments were passed on the command line
 *      current_file - int for which number file is current being opened
 *
 * Returns:
 *      0 - file opened succesfully
 *      1 - file did not open successfully
 */

int getFiles(const char *input_file_name, FILE **input, int argc, int current_file){
    *input = fopen(input_file_name, "r");

    if(*input == NULL){
        printf("Failed to open %s. Terminating program.\n", input_file_name);
        return 1;
    }
    
    return 0;
}


/*
 * openOutputFile
 *
 * Opens the output file in write mode.
 *
 * Parameters:
 *      *output_file_name - pointer to the output file name to be written to
 *      **output - pointer TO the pointer for the output file to allow changes to be made
 *
 * Returns:
 *      Nothing
 */
void openOutputFile(const char *output_file_name, FILE **output){
    *output = fopen(output_file_name, "w");
    
    if (*output == NULL){
        printf("Failed to open %s to write. Terminating program\n", output_file_name);
        exit(1);
    }
}


/*
 * getKeyword
 *
 * Using the known/configured array of keywords, this function loops through all lines of the current file, 
 * detects the first instance of the keyword, and obtains the string from the .txt file starting after the colon
 * and any amount of spaces. The string after the keyword is the stored within summary.
 *
 * Parameters:  
 *      *input - the input file currently being looped through and scanned
 *      *name_to_match - pointer to the element of the keywords array names_to_match[ELEMENTS] with the current keyword
 *      *line - pointer to the empty string to be filled with a line of the current file
 *      *summary - pointer to the empty string to be filled with the value AFTER the keyword
 *
 * Returns:
 *      1 - Keyword was found
 *      0 - Keyword was NOT found
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

        length = strcspn(start, "\n");

        if (length >= MAX_CHAR){
            length = MAX_CHAR - 1;
        }

        strncpy(summary, start, length);
        summary[length] = '\0';
        
        return 1; // Found keyword
    }

    return 0; // Keyword not found in file
}


/*
 * mergeStrings
 *
 * First copies the keyword into the target string full_list. ": " is that concatenated to the full list.
 * Lastly, the value of that keyword is concatenated to the full list
 *
 *                          EXAMPLE 1 -- Channel: 3
 *                          EXAMPLE 2 -- Voltage Scale: 0.200000 V/div
 *
 * Parameters:
 *      *summary - pointer to the string containing the target value of the current keyword
 *      *name_to_match - pointer to the string containing the current keyword 
 *      *full_list - pointer to the empty string to be added to
 *
 * Returns:
 *      Nothing
 */

void mergeStrings(const char *summary, 
                     const char *name_to_match, 
                     char *full_list){

                                            // Example:
    strcpy(full_list, name_to_match);       // "\0" -> "Model\0"
    strcat(full_list, ": ");                // "Model\0" -> "Model: \0"
    strcat(full_list, summary);             // "Model: \0" -> "Model: DS1054Z\0"
}


/*
 * writeOutput
 *
 * Writes each keyword: value pair to the output file results.txt with one keyword and value pair per line.
 * EX: 
 *      Manufacturer: RIGOL Technologies
 *      Model: DS1054Z
 *      Channel: 1
 *      Voltage Scale: 1.000000 V/div
 *      Time Scale: 0.000500 s/div
 *
 *  Parameters:
 *      *output - the output file to be written to
 *      *full_list - pointer to the string containing the keyword: value pair 
 *
 * Returns:
 *      Nothing
 */
void writeOutput(FILE *output,
                 const char *full_list){
    fprintf(output, "%s\n", full_list);
}


/*
 * newFileHeader
 *
 * Helper function -- Makes the formatted output more organized and readable by separating the data between files.
 * Becomes more and more useful as more input files are added.
 *
 * Parameters:
 *      *output - output file to be written to
 *      *input_file_name - the name of the current input file being looped through to include in the header
 *
 * Returns:
 *      Nothing
 */
void newFileHeader(FILE *output, const char *input_file_name){
    fprintf(output, "__________________________________________\n");
    fprintf(output, "\n%s\n", input_file_name);
    fprintf(output, "__________________________________________\n\n");
}



int main(int argc, char *argv[]){
    FILE *input, *output;
    char summary[MAX_CHAR], line[MAX_CHAR], full_list[MAX_CHAR];
    char names_to_match[ELEMENTS][MAX_CHAR] = {"Manufacturer", "Model", "Firmware Ver.", 
                                               "Channel", "Voltage Scale", "Time Scale"};

    if (argc == 1){
        printf("Error - improper call.\n\tRun program with:\n\t\t./keywordFinder.exe inputfiles/*\n");
    }

    openOutputFile("results.txt", &output);
 
    for (int i = 1 ; i < argc ; i++){
        if(getFiles(argv[i], &input, argc, i) == 1){
            continue;
        }

        newFileHeader(output, argv[i]);

        for (int j = 0 ; j < ELEMENTS ; j++){
            if (getKeyword(input, names_to_match[j], line, summary)){
                mergeStrings(summary, names_to_match[j], full_list);
                writeOutput(output, full_list);
            }
        }
        
        fprintf(output, "\n");

        fclose(input);
    }
    
    fclose(output);
    
    return 0;
}
