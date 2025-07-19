
#include <stdio.h>
#include "shuttle.h"

int main(void) {
    Shuttle* list = readShuttleFile("shuttle_data.txt");

    if (list == NULL) {
        printf("Liste leer oder Datei konnte nicht gelesen werden.\n");
        return 1;
    }

    printf("Sortierte Shuttle-Liste (absteigend nach Missionsnamen):\n");
    printShuttleList(list);
    freeShuttleList(list);

    return 0;
}
