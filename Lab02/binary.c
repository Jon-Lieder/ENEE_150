/* Name:            Jon Lieder
 * Course:          ENEE 150
 * Project:         Lab 01
 * Assignment:      Problem 11 -- 8-Bit Binary Input Validator
 * Date:            September 3, 2026
 *
 * Description: 
 * This program takes input from a user and determines whether or not it is a 
 * valid 8-bit binary value.
 */



#include <stdio.h>
#include <string.h>
#include <stdbool.h>



void binaryValidation(){
    char buffer[100];
    bool input_stream = true;
    bool valid_input = false;

    while(input_stream){
        printf("Enter an 8-bit binary value:\t");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL ){
            printf("Error reading input\n");
            continue;
        }
        
        buffer[strcspn(buffer, "\n")] = '\0';
        
        if (strlen(buffer) != 8){
            printf("You have entered %lu digits\n", strlen(buffer));
            continue;
        }

        for (int i = 0; i < 8; i++){
            if (buffer[i] != '0' && buffer[i] != '1'){
                printf("Binary values can only contain numeric values of 0 or 1. \n");
                valid_input = false;
                input_stream = true;
                break;
            }
            else{
                input_stream = false;
                valid_input = true;
            }
        }
    }
    
    if(valid_input){
        printf("%s is a valid 8-bit binary value.\n", buffer);  
    }
}



int main(){

    binaryValidation();
    
    return 0;
}


