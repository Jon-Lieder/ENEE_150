/*
 * ENEE 150 - Programming Project 4
 * Mastermind: The Memory Challenge
 *
 * STARTER FILE - THIS IS NOT A COMPLETE GAME
 *
 * Provided for you:
 *   - Required header files and constants
 *   - Suggested function prototypes
 *   - A complete function for generating the secret color code
 *   - A small main() shell for reading guesses
 *
 * You must write the guess validation, scoring, dynamic memory,
 * archiving, and statistics code. See the project handout.
 *
 * No structs are needed for this project.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

/* Game settings */
#define CODE_LENGTH 4
#define NUM_COLORS 6
#define INITIAL_CAPACITY 3
#define CAPACITY_STEP 3

/* Each history record has four color letters and two result bytes */
#define BYTES_PER_GUESS 6

/* The systems engineers' limit applies to the history array only */
#define HISTORY_LIMIT 96
#define HISTORY_FILE "mastermind_history.txt"

/* The valid characters are used to compare a user's guess entry */
#define valid_colors "RGBYOP"


/*--------------------------------------------------------------
  Function prototypes

  generateSecret() is already written for you below.
  The remaining functions are suggestions for organizing your
  program. YOU must write their function definitions.

  A prototype tells C what a function will look like. You can
  compile this starter before writing the other functions,
  because main() does not call them yet.
--------------------------------------------------------------*/
void generateSecret(char secret[5]);
int validGuess(const char guess[]);
void scoreGuess(const char secret[], const char guess[],
                int *exact, int *misplaced);
int saveHistory(const unsigned char history[], int count);
void showStatistics(int archives, int maximumBytes);


/*--------------------------------------------------------------
  PROVIDED FUNCTION - do not change this function

  Chooses four DIFFERENT colors at random from:
    R = Red      G = Green      B = Blue
    Y = Yellow   O = Orange     P = Purple

  secret must have space for five characters:
  four color letters plus the terminating '\0'.
--------------------------------------------------------------*/
void generateSecret(char secret[5])
{
    const char choices[] = "RGBYOP";
    int used[6] = {0};
    int i, index;

    srand((unsigned int)time(NULL));
    for (i = 0; i < 4; i++) {
        do {
            index = rand() % 6;
        } while (used[index]);
        used[index] = 1;
        secret[i] = choices[index];
    }
    secret[4] = '\0';
}


void scoreGuess(const char secret[], const char guess[], int *exact, int *misplaced){
    bool guessUsed[CODE_LENGTH] = {false};
    bool secretUsed[CODE_LENGTH] = {false};


    printf("SECRET = %s, GUESS = %s\n", secret, guess);
    /* PASS 1 - Checks for character matches
     *          When a character matches, the index is recorded to avoid the reusing indecies when scoring.
     *          
     *          Example:
     *                  Secret: BYOP
     *                  Guess: BYPP
     *                  Exact: 3
     *                  Misplaced: 1
     */
    for(int i = 0 ; i < 4 ; i++){
        if(*(guess + i) == *(secret + i)){
            printf("Chars Match: secret %d = %c, guess %d = %c\n", i, *(secret + i), i, *(guess + i));
            (*exact)++;
            guessUsed[i] = true;
            secretUsed[i] = true;
        }
    }

    /* PASS 2 - Checks for misplaced letters*/
    for(int i = 0 ; i < CODE_LENGTH ; i++){
        if(guessUsed[i]){continue;}

        for(int j = 0 ; j < CODE_LENGTH ; j++){
            if(!secretUsed[j] && *(guess + i) == *(secret + j)){
                (*misplaced)++;
            }
        }
    }
    
    printf("EXACT = %d\n", *exact);
    printf("MISPLACED = %d\n", *misplaced);
}


int saveHistory(const unsigned char history[], int count){

    FILE *output = fopen("history.txt", "a");
    char *temp = realloc(history, INITIAL_CAPACITY * sizeof(temp));
    
    if(output == NULL){return 1;}

    for (int i = 0 ; i < count ; i++){
        fprintf(output, "%s\n", *history[i]);
    }
//    writeToExternal();
    history = temp;
    
    return 0;
}

void updateCapacity(int *current_capacity){
    *current_capacity += INITIAL_CAPACITY;
}
/*--------------------------------------------------------------
  main() - program shell

  Complete the TODO sections as you work through the project.
--------------------------------------------------------------*/
int main(void)
{
    char secret[CODE_LENGTH + 1];
    char guess[20];
    int gameOver = 0;   /* 0 = keep playing; 1 = stop */

    /* Create a NEW random secret each time the game runs */
    generateSecret(secret);

    /* TESTING ONLY: uncomment to see this game's random secret.
       Remove or comment out again before submitting. */
    /* printf("TEST ONLY - secret: %s\n", secret); */

    puts("COLOR MASTERMIND");
    puts("Colors: R G B Y O P");
    puts("Enter four DIFFERENT color letters, or Q to quit.");

    /* 70% TODO:
       x Allocate an unsigned char history array for THREE guesses
         using malloc()
       x Track how many guesses are stored and the array capacity
       - Implement validGuess() and scoreGuess()
       x Expand capacity by THREE using realloc() when necessary
       x Store EACH valid guess in SIX bytes:
           bytes 0-3 = color letters
           byte 4    = numeric exact count (0 through 4)
           byte 5    = numeric misplaced count (0 through 4)
       x Stop when the player scores four exact matches
       x Release the allocated array using free()
    */
    char (*history)[CODE_LENGTH + 3] = malloc(INITIAL_CAPACITY * sizeof(*history));
    int guesses = 0;
    int exact;
    int misplaced;
    int current_capacity = INITIAL_CAPACITY;
    /* The loop runs until gameOver becomes 1.
       The user can quit with Q, or the game can end after a win.
       End-of-input also stops the program. */
    while (gameOver == 0) {
        printf("\nEnter guess: ");

        if (scanf("%19s", guess) != 1) {
            gameOver = 1;                 /* Input ended */
        }
        else if (strcmp(guess, "Q") == 0) {
            gameOver = 1;                 /* Player chose to quit */
        }
        else {
            /* TODO: Validate this guess before counting/storing it */
            if(strlen( guess ) == 4 && strspn( guess, valid_colors) == 4){
                printf("Successful read\n");
                strcpy(history[guesses], guess);
                guesses++;
                exact = 0;
                misplaced = 0;
                printf("Guesses = %d\n", guesses);
            }

            /* TODO: Calculate and display exact / misplaced matches */

            /* TODO: Expand history if needed, then store this guess */

            /* TODO: When exact == 4, set gameOver = 1 */

            puts("TODO: Add your game logic here.");
        }
        
        if(current_capacity == HISTORY_LIMIT ){
            saveHistory(history, guesses);  // NEED TO MAKE: append "a" file.
            //createNew();    // NEED TO MAKE: new malloc array
        }

        if(guesses == current_capacity){
        //if(current_capacity == HISTORY_LIMIT){
            updateCapacity(&current_capacity);
            printf("Current Capacity = %d\n", current_capacity);
        }

        else{
            //writeToExternalMemory();
            //reset();
        }
        
        scoreGuess(secret, guess, &exact, &misplaced);
        guess[4] = (char)(exact + '0');
        guess[5] = (char)(misplaced + '0');

        if(exact == 4){break;}
    }

    /* 85% TODO:
       - Never allocate over HISTORY_LIMIT bytes for history
       - Before the first guess, create a fresh HISTORY_FILE
       - Before an expansion that would exceed the limit, read
         existing archive lines, then APPEND active records
       - Free the old array and malloc() a new three-guess array
       - At the end, append any remaining guesses exactly once
    */

    /* 100% TODO:
       - Use calloc() to allocate six zero-initialized counters
       - Read the COMPLETE history file for game statistics
       - Count all guesses and each color's appearances
       - Display the archive count and maximum history bytes
       - Free the counters and all remaining allocated memory
    */
    free(history);

    return 0;
}
