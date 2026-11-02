/*
 * Name:            Jon Lieder
 * Course:          ENEE 150
 * Project:         Project 4
 * Assignment:      Mastermind game
 * Date:            October 27 2026
 *
 *
 * This program generates a secret string of 4 randomly generated characters for the user to guess as standard input.
 * User input is handled to only accept the letters within "RBGYOP", quits with provided "Q" input, quits when provided
 * input that would result in overflow, and rejects all other input. Once inputted, the program compares each letter to 
 * detect exact matches or out-of-position (misaligned) matches. The user's guess as well as the exact and misaligned
 * values per guess are stored in a dynamically allocated array. 
 *
 * This program was extended to implement the 96 byte systems engineering limit. Once 96 bytes are reached, the program 
 * appends to a history text file to store all guesses, and realloc new memory starting at initial capacity. When the user
 * quits or correctly guesses the key, the remaining guesses are appended to the same file.
 *
 * This program was further extended to read the same history text file, store all user guesses inside of a calloc() 
 * dyanamic memory allocation array, and counts the occurrence of each character inputted by the user. Furthermore,
 * the total amount of guesses and total size of the history file in bytes are calculated and displayed in a formatted
 * history file summer with standard output.
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

/* The colors corresponding to their index value for readability */
#define RED 0
#define GREEN 1
#define BLUE 2
#define YELLOW 3
#define ORANGE 4
#define PURPLE 5

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
bool validGuess(const char guess[]);
void scoreGuess(const char secret[], const char guess[],
                int *exact, int *misplaced);
void saveHistory(const char history[], int *count, FILE *output);
void updateCapacity(int *current_capacity, char (**history)[CODE_LENGTH + 3],
                     int *guesses, FILE *output);
void averageOccurrences(FILE *input, int occurrence_of[], 
                        char data[], int *total_guesses);
void showStatistics(int occurrence_of[], int total_guesses);


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


/*
 * validGuess
 *
 * Validates the string inputted by the user through two checks:
 *      1. Checks that the inputted string is exactly 4 characters in length
 *      2. Checks that all 4 inputted characters are contained in the string of valid colors defined 
 *         at the preprocessor level
 *
 * Parameters:
 *      guess[] - a string containing the user inputted guess
 *
 * Returns:
 *      Nothing
 */
bool validGuess(const char guess[]){
    return strlen( guess ) == 4 && strspn( guess, valid_colors) == 4;
}


/*
 * scoreGuess
 *
 * Compares the user's inputted string with the randomly generated secret string with two for loops (explained below). 
 * The results of each loop are then stored in two integer values: exact and misaligned where exact stores how many times
 * a letter at an index from the user's guess match the same letter at the same index in the secret string. Misaligned does
 * a similar comparison, but is indepedent of index. It only counts if a letter from the user's guess is held within the
 * secret. Conditions are given to prevent reusing any index for guesses like RBGG.
 *
 * Parameters:
 *      secret[] - A string containing the randomly generated secret to guess
 *      guess[] - A string containing the user's inputted string to score
 *      *exact - int pointer containing the value of how many letters at the same index match 
 *      *misaligned - int pointer containing the value of how many letters from guess are within the secret string
 *
 * Returns:
 *      Nothing
 */
void scoreGuess(const char secret[], const char guess[], int *exact, int *misaligned){
    bool guessUsed[CODE_LENGTH] = {false};
    bool secretUsed[CODE_LENGTH] = {false};

    /* PASS 1 - Checks for character matches
     *          When a character matches, the index is recorded to avoid the reusing indecies when scoring.
     *          
     *          Example:
     *                  Secret: BYOP
     *                  Guess: BYPP
     *                  Exact: 3
     *                  Misplaced: 1
     */
    for(int i = 0 ; i < CODE_LENGTH ; i++){
        if(*(guess + i) == *(secret + i)){
            (*exact)++;
            guessUsed[i] = true;
            secretUsed[i] = true;
        }
    }

    /* PASS 2 - Checks for misplaced letters*/
    for(int i = 0 ; i < CODE_LENGTH ; i++){
        if(guessUsed[i]){continue;}         // skips a previously counted letter

        for(int j = 0 ; j < CODE_LENGTH ; j++){
            if(!secretUsed[j] && *(guess + i) == *(secret + j)){
                (*misaligned)++;
            }
        }
    }
    
    printf("\nNumber of characters that match exactly:\t\t%d\n", *exact);
    printf("Number of mathing characters that are out of place:\t%d\n", *misaligned);
}


/*
 * saveHistory 
 *
 * Once the System Engineer's limit is met, this function appends the contents of the user's guess history to the output
 * file "mastermind_history.txt". 
 *
 * Parameters:
 *      history[] - 6 char array containing 4 guess letters and 2 char converted ints of exact and misaligned scores for
 *                  that guess.
 *      *count - int pointer containg how many guesses are within that history file
 *      *output - FILE ptr containing the output file to append to
 *
 * Returns:
 *      Nothing - file error handling performed in main.
 */
void saveHistory(const char history[], int *count, FILE *output){

    for (int i = 0 ; i < *count ; i++){
        fprintf(output, "%s\n", history + i * (CODE_LENGTH + 3));
    }
    *count = 0;

    return;
}


/*
 * updateCapacity
 * 
 * The capacity for this history array is:
 *      1. not increased if the current amount of guesses in history are less than the current capacity
 *      2. saved, freed, and reinitialized if the current capacity is equal to the imposed memory limit
 *      3. increased if the amount of guesses stored in history is equal to the capacity and less than the history limit
 *
 * Parameters:
 *      *current_capacity - a pointer to the current value of the current_capacity 
 *      (**history)[CODE_LENGTH + 3] - the history array containing all of the user's guesses within 96 entries
 *      *guesses - a pointer to the amount of guesses contained in the history array
 *      *output - pointer to the output file to be appended to if condition 2 is met
 *
 * Returns:
 *      Nothing
 */
void updateCapacity(int *current_capacity, char (**history)[CODE_LENGTH + 3], int *guesses, FILE *output){
    if (*guesses < *current_capacity){ return; } /* No memory allocation needed  */

    else if (*current_capacity == HISTORY_LIMIT){
        saveHistory((*history[0]), guesses, output);
        free(*history);
        (*history) = malloc(INITIAL_CAPACITY * sizeof(*history));
        if ( history == NULL ){ exit(1); }

        *current_capacity = INITIAL_CAPACITY;
        *guesses = 0;
    }

    else{
        *current_capacity += INITIAL_CAPACITY;
        char (*temp)[CODE_LENGTH + 3] = realloc(*history, *current_capacity * sizeof(**history));
        if (temp == NULL){exit(1);}
        else{*history = temp;}
    }
}


/*
 * averageOccurrence
 *
 * Reports game statistics as standard command line output to the user. The statistics display how often each number 
 * came up in the user's guesses, the total number of guesses, and the total size of the history file in bytes. Since
 * each guess is 6 bytes, then the bytes are the number of guesses * 6.
 *
 * Parameters:
 *      *input - poitner to the input file to be read. 
 *      occurence_of[] - an array of integers containing how many times each color shows up in the history file in 
 *                       the order of "RGBYOP" (B is index 2)
 *      data[] - an array containing a line of the input file to be analyzed and looped through to account for all
 *               lines in the file
 *      *total_guesses - pointer to the total number of guesses contained in the history file
 *
 * Returns:
 *      Nothing
 */
void averageOccurrences(FILE *input, int occurrence_of[], char data[], int *total_guesses){
    
    rewind(input);
    
    while(fscanf(input, "%6s", data ) == 1){
        for (int i = 0 ; i < CODE_LENGTH ; i++){
            if(data[i] == 'R'){occurrence_of[RED]++;}
            else if(data[i] == 'G'){ occurrence_of[GREEN]++; }
            else if(data[i] == 'B'){ occurrence_of[BLUE]++; }
            else if(data[i] == 'Y'){ occurrence_of[YELLOW]++; }
            else if(data[i] == 'O'){ occurrence_of[ORANGE]++; }
            else if(data[i] == 'P'){ occurrence_of[PURPLE]++; }
            else{ continue; }
        }
        (*total_guesses)++;
    }

    return;
}


/*
 * showStatistics
 *
 * Displays a formatted standard output of the game statistics calculated in averageOccurrences. The roder of the summer is:
 *      1. Header
 *      2. Occurrences of each letter
 *      3. Total guesses
 *      4. Total size of the history file
 *
 * Parameters:
 *      occurrence_of[] - an array containing an integer of how many times each letter occurs in the history file 
 *      total_guesses - the total number of guesses contained within the history file (which directly gives the size
 *                      of the history file as well since each guess is known to be a constant 6 bytes so size = guesses * 6
 *
 * Returns:
 *      Nothing
 */
void showStatistics(int occurrence_of[], int total_guesses){    
    int total_bytes = total_guesses * BYTES_PER_GUESS;

    printf("\n\n");
    printf("_________________________________________\n");
    printf("|                                       |\n");
    printf("|          HISTORY FILE SUMMARY         |\n");    
    printf("|_______________________________________|\n\n\n");

    printf("OCCURRENCES OF:\n");
    printf("\tRed:\t%d instances\n", occurrence_of[RED]);
    printf("\tGreen:\t%d instances\n", occurrence_of[GREEN]);
    printf("\tBlue:\t%d instances\n", occurrence_of[BLUE]);
    printf("\tYellow:\t%d instances\n", occurrence_of[YELLOW]);
    printf("\tOrange:\t%d instances\n", occurrence_of[ORANGE]);
    printf("\tPurple:\t%d instances\n", occurrence_of[PURPLE]); 
    printf("\n\n");
    printf("TOTAL GUESSES:\n\t%d guesses", total_guesses);
    printf("\n\n");
    printf("TOTAL SIZE OF HISTORY FILE:\n\t%d bytes\n\n", total_bytes);

    return;
} 


/*--------------------------------------------------------------
  main() - program shell
--------------------------------------------------------------*/
int main(void)
{
    char secret[CODE_LENGTH + 1];
    char guess[20];
    int gameOver = 0;   /* 0 = keep playing; 1 = stop */

    FILE *output = fopen(HISTORY_FILE, "a+");
    
    if (output == NULL){ return 1; }

    /* Create a NEW random secret each time the game runs */
    generateSecret(secret);

    puts("COLOR MASTERMIND");
    puts("Colors: R G B Y O P");
    puts("Enter four DIFFERENT color letters, or Q to quit.");

    char (*history)[CODE_LENGTH + 3] = malloc(INITIAL_CAPACITY * sizeof(*history));
    char *data = calloc(BYTES_PER_GUESS, sizeof(data));
    int *occurrence_of = calloc(BYTES_PER_GUESS, sizeof(occurrence_of));
    int guesses = 0;
    int exact;
    int misplaced;
    int current_capacity = INITIAL_CAPACITY;
    int total_guesses = 0; // 100% tier 

    /* The loop runs until gameOver becomes 1.
       The user can quit with Q, or the game can end after a win.
       End-of-input also stops the program. */
    while (gameOver == 0) {
        printf("\nEnter guess: ");

        /*            Input ended     ||    Player chose to quit        */
        if (scanf("%19s", guess) != 1 || strcmp(guess, "Q") == 0) {
            gameOver = 1;
            continue;
        }

        else if (!validGuess(guess)){
            printf("Invalid Guess\n");
            continue;
        }

        else {
            strcpy(history[guesses], guess);
            guesses++;
            exact = 0;
            misplaced = 0;
        }
        
        scoreGuess(secret, guess, &exact, &misplaced);
        history[guesses - 1][4] = (char)exact + '0';
        history[guesses - 1][5] = (char)misplaced + '0';
        history[guesses - 1][6] = '\0';
        updateCapacity(&current_capacity, &history, &guesses, output);


        if(exact == 4){break;}
    }

    saveHistory(history[0], &guesses, output);
    free(history);
    averageOccurrences(output, occurrence_of, data, &total_guesses);
    showStatistics(occurrence_of, total_guesses);
    free(occurrence_of);
    free(data);

    return 0;
}
