#include <stdio.h>
#include <string.h>

int main(void){
    char city[20] = "Rockville MD 20850";
    char *one, *two, *three, *ptr;

    printf("PART ONE\n");
    printf("sizeof(city) = %ld\n", strlen(city));
    printf("city[0] = %c\n", city[0]);
    printf("city[9] = %c\n", city[9]);
    printf("terminating char index = %ld\n", strrchr(city, '\0') - city);
    printf("city + 10 = %s\n", city + 10);

    one = strtok(city, " ");
    two = strtok(NULL, " ");
    three = strtok(NULL, " ");

    printf("PART TWO\n");
    printf("One two three: %s\n%s\n%s\n", one, two, three);
    
    ptr = strchr(one, 'l');

    printf("puts(ptr) = ");
    puts(ptr);

    printf("PART THREE\n");
    char *four, *fptr;
    char city2[20] = "Rockville MD 20850";
    int cnt = 0;

    four = strtok(city2, " ");
    puts(four);
    fptr = four;

    while ((fptr = strchr(fptr, 'l')) != NULL){
        puts(fptr);
        cnt++;
        fptr++;
    }
    
    printf("cnt = %d\n", cnt);

    printf("PART FOUR\n");
    char first[20] = "Hello";
    char second[20] = "World";
    char combined[50];

    strcpy(combined, first);
    strcat(combined, " ");
    strcat(combined, second);

    printf("Combined string = %s\n", combined);
    printf("strcmp(first,\"Hello\") = %d\n", strcmp(first, "Hello"));
    printf("strcmp(second, \"Wor\", 3) = %d\n", strncmp(second, "Wor", 3));

    char text[100];

    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';    

    printf("PART FIVE\n");
    char *found, text2[100];

    printf("Enter a line of text...\n");
    fgets(text2, sizeof(text2), stdin);
    text2[strcspn(text2, "\n")] = '\0';
    printf("strlen(text2) = %zu\n", strlen(text2));
    found = strchr(text2, 'e');

    if(found != NULL){
        printf("String after first e = ");
        puts(found);
    }
    else{
        printf("No lower case e found\n");
    }

    return 0;
}
