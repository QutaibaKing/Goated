#include <stdio.h>
#include <stdlib.h>

#include "shuttle.h"

int main (void)
{
    Shuttle *begin = readShuttleFile("shuttle_data.txt");

    printShuttleList(begin);
    freeShuttleList(begin);

    return EXIT_SUCCESS;
}