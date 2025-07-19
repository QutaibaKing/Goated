#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "island.h"
#include "node.h"

int main(void)
{
    Island island[5];
    char input[10];
    int tourNum = 0;

    initializeIslands(island);  // Fill island array with data

    // Ask user to select a tour or multiple to select or exit
    printf("Please enter a tour number (1-4) or enter the number 0 for exit the program: ");
    fgets(input, sizeof(input), stdin);

    
    // Exit if input is only "0"
    if (input[0] == '0' && (input[1] == '\n' || input[1] == '\0')) 
    {
        return EXIT_SUCCESS;
    }

    // Tokenize (split the string in smaller parts) and handle each number
    char *token = strtok(input, " \n"); // first token (split at space)

    while (token != NULL)
    {
        tourNum = atoi(token); // Convert token (string) into int
        if (tourNum >= 1 && tourNum <= 4) 
        {
            Node *begin = createTour(tourNum, island); // Create the selected tour
            printTour(begin, tourNum); // Print the tour(s)
        } else 
        {
            printf("Invalid tour number: %d\n", tourNum);
        }

        token = strtok(NULL, " \n"); // Get next token
    }

    printf("End\n");

    return EXIT_SUCCESS;
}
