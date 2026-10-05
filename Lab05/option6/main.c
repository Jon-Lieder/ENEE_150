#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 50

int main(int argc, char *argv[]){
    FILE *input;
    char input_file[]="results.tar.gz";

    bool command_match = false;
    char commands[3][SIZE] = {"SAVE", "DELETE", "TOUCH"};
    char extensions[SIZE];
    char command[SIZE];
    //char ext;

    if (argc < 3 && argc %2 == 0){
        printf("Improper executable call. Use:\n./command_extension_checker.exe SAVE results.txt\n");
    }

    input = fopen(input_file, "r");

    if(input == NULL){
        printf("Error: Could not open file. Please call the executable as:\n./command_extension_checker.exe SAVE results.txt\n");
    }

    for (int i = 1 ; i < argc ; i++){
        if(strncmp(argv[i], commands[0], SIZE) == 0){
            command_match = true;
            strcpy(command, argv[i]);
            break;
        }
    }
 
    const char *extension = strchr(argv[2], '.') + 1;
    printf("%s\n", extension);
    printf("%s\n", command);
}
