#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <time.h>

void scramble(char *word) {
    int length = strlen(word);
    // Seed the random number generator
    srand(time(NULL));

    // Scramble the letters using Fisher-Yates shuffle algorithm
    for (int i = length - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
}

char* generateword(char* ptrword)
{
    int count = 0;
    char *words[50];

    char *token = strtok(ptrword, "\n");
    while (token != NULL && count < 50)
    {
        words[count] = strdup(token); // Store a copy of the token in the array
        count++;
        token = strtok(NULL, "\n");
    }
    //random word picker pick from array words[50]
   srand(time(NULL));
    int random_number = rand() % count; // Use count instead of fixed value 50
    char *selected_word = strdup(words[random_number]);
    for (int i = 0; i < count; i++)
    {
        free(words[i]); // Free memory allocated for each word
    }
    return selected_word;
}

int main(void)
{
    //greet player
    printf("*******************************************************************************\n");
    printf("*                                                                             *\n");
    printf("*                                                                             *\n");
    printf("*                   Welcome to the WORD GUESSING mini game!                   *\n");
    printf("*                                                                             *\n");
    printf("*                                                                             *\n");
    printf("*******************************************************************************\n\n");

    //Display intructions
    printf("INTRUCTIONS\n");
    printf("=====================================================================================================================================\n");

    printf("1. You are granted with 3 lives to guess the scrambled word given\n");
    printf("2. Every CORRECT guesses you make, you will obtain extra 1 extra life and 1 point! Keep in mind, life will be capped at 20 seconds!\n");
    printf("3. For every WRONG guesses you make, 1 life will be deducted from your remaining lives!\n");
    printf("4. If you reach 30 points before your lives runs out, you win!\n");
    printf("5. Have fun!\n");

    printf("=====================================================================================================================================\n");
    //ask player if they are ready
    int points;
    char user_ready [50];
    char* ptrword = (char*)malloc(50*sizeof(word));
    char* scrambled_word = (char*)malloc(20*sizeof(char));
    char* original_word = (char*)malloc(20*sizeof(char));
    FILE* file = fopen("listofwords.txt", "r");
    bool ready = false;
    printf("Type ""READY"" when you are ready to take on this challenge!\n");
    printf("Status: ");

    fgets(user_ready, sizeof(user_ready), stdin);

    if (strcasecmp(user_ready, "READY\n") == 0)
    {
        if (file == NULL)
        {
            printf("Error! File could not be loaded!\n");
            return 1;
        }
        int lives = 3;
        ready = true;
        while (ready == true)
        {
            printf("Challenge has started!\n");
            //read contents from file
            fseek(file, 0, SEEK_END);
            long file_size = ftell(file);
            rewind(file);
            fread(ptrword, sizeof(char), sizeof(file_size), file);
            while (lives > 0)
            {
                char[50] answer;
                original_word = generateword(ptrword);
                strcpy(scrambled_word, original_word);
                printf("Your scrambled word is %s\n", scramble(scrambled_word));
                printf("Your guess: ");
                fgets(answer, sizeof(answer), stdin);
                answer[strcspn(answer, "\n")] = '\0';
                if (strcasecmp(answer,original_word + ))
                {
                    lives ++
                    points ++
                    if (lives > 3)
                    {
                        lives = 3;
                    }
                }
                else:
                {
                    lives --;
                }
                if (lives == 0)
                {
                    break
                }
            }

         printf("You ran out of lives!\n");
         ready == false;
        }
    }
    fclose(file); // Close the file handle
    free(ptrword); // Free allocated memory
    free(scrambled_word);
    free(original_word);
    return 0;
}
