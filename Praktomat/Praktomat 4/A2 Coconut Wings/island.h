#ifndef Island_H_
#define Island_H_

typedef struct island
{
    char islandName[30];
    char openingTime[6];
    char closingTime[6];
}Island;

void initializeIslands(Island *island);
Node *initializeTours(int *tour, int numIslands, Island *island);
Node *createTour(int tourNum, Island *island);
void printTour(Node *begin);

#endif