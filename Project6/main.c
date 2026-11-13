#include <stdio.h>
#include <stdbool.h>

#include "studentList.h"

#define INSERT 1
#define DELETE 2
#define DISPLAY 3
#define EXIT 4

int main(){
    int user_choice;
    char line[100];
    bool continue_input = true; 

    while ( continue_input ){
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        fgets( line, sizeof( line ), stdin );

        if ( sscanf( line, "%d", &user_choice ) == 1 && (
             user_choice == INSERT  ||
             user_choice == DELETE  ||
             user_choice == DISPLAY ||
             user_choice == EXIT   )){
            
            switch( user_choice ){
                case INSERT:
                    // createNode();
                    printf("( DEBUG ) INSERTED\n");                
                    break;

                case DELETE:
                    // deleteValue();
                    printf("( DEBUG ) DELETED\n");
                    break;

                case DISPLAY:
                    // printList();
                    printf("( DEBUG ) DISPLAYED\n");
                    break;

                case EXIT:
                    printf("( DEBUG ) EXITED\n");
                    continue_input = false;
                    break;
            }
        }
    }
    
    // clearList();

    return 0;
}
