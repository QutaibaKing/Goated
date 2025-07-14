#include <stdio.h>
#include <stdlib.h>

#include "island.h"
#include "node.h"

int main(void)
{
    Island island[5];
    int tourNum;

    initializeIslands(island);

    printf("Please enter a tour number (1-4) or enter the number 0 for exit the program: ");
    scanf("%d", &tourNum);

    Node *begin = createTour(tourNum, island);

    if(tourNum == 0)
    {
        return EXIT_FAILURE;
    }

    if (begin == NULL) {
        printf("Invalid tour number.\n");
        return 1;
    }

    printTour(begin);

    return 0;
}