#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "island.h"
#include "node.h"

// function to initialize the islands
void initializeIslands(Island *island)
{
    // island 1
    strcpy(island[0].islandName, "Amity");
    strcpy(island[0].openingTime, "09:00");
    strcpy(island[0].closingTime, "17:00");

    //island 2
    strcpy(island[1].islandName, "Craggy Island");
    strcpy(island[1].openingTime, "09:00");
    strcpy(island[1].closingTime, "16:00");

    //...
    strcpy(island[2].islandName, "Isla Nubar");
    strcpy(island[2].openingTime, "07:00");
    strcpy(island[2].closingTime, "12:00");

    strcpy(island[3].islandName, "Shutter Island");
    strcpy(island[3].openingTime, "08:00");
    strcpy(island[3].closingTime, "20:00");

    strcpy(island[4].islandName, "Skull Island");
    strcpy(island[4].openingTime, "08:00");
    strcpy(island[4].closingTime, "17:30");

}

Node *initializeTours(int *tour, int numIslands, Island *island)
{
    Node *begin, *newNode, *theNode = NULL;

    for (int i = 0; i < numIslands; i++)
    {
        if (theNode == NULL)
        {
            theNode = Node_New();
            theNode->island = &island[tour[i]];
            begin = theNode;
        } else 
        {
            Node_Insert(theNode);
            newNode = theNode->next;
            newNode->island = &island[tour[i]];
            theNode = newNode;
        }
    }

    return begin;
}

Node *createTour(int tourNum, Island *island)
{
    switch (tourNum)
    {
        case 1: 
        {
            int tour1[] = {0, 1, 2, 0};
            return initializeTours(tour1, sizeof(tour1) / sizeof(int), island);
        }
        case 2: 
        {
            int tour2[] = {4, 1, 2, 4};
            return initializeTours(tour2, sizeof(tour2) / sizeof(int), island);
        }
        case 3: 
        {
            int tour3[] = {3, 4, 3};
            return initializeTours(tour3, sizeof(tour3) / sizeof(int), island);
        }
        case 4: 
        {
            int tour4[] = {2, 4, 3, 0, 2};
            return initializeTours(tour4, sizeof(tour4) / sizeof(int), island);
        }
        default:
            return NULL;
    }
}


void printTour(Node *begin)
{
    if (begin == NULL) {
        return;
    }

    printf("---------------------------------------------------\n");
    printf("---------------- Tour -----------------------------\n");
    printf("---------------------------------------------------\n");
    printf("---------------------------------------------------\n");

    Node *theNode = begin;
    while (theNode != NULL) {
        printf("Island : %s\n", theNode->island->islandName);
        printf("Opening hours: %s - %s\n", theNode->island->openingTime, theNode->island->closingTime);
        printf("---------------------------------------------------\n");
        theNode = theNode->next;
    }

    printf("End\n");
}