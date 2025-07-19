
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shuttle.h"

void trim(char* str) {
    if (!str) return;
    char* end = str + strlen(str) - 1;
    while (end >= str && (*end == '\n' || *end == '\r' || *end == ' '))
        *end-- = '\0';
}

Shuttle* create_shuttle_node(int missionNum, char *date, char *missionName, char *orbiter, char *launch_pad) {
    Shuttle* node = malloc(sizeof(Shuttle));
    if (!node) return NULL;

    node->missionNum = missionNum;
    strncpy(node->date, date, sizeof(node->date));
    strncpy(node->missionName, missionName, sizeof(node->missionName));
    strncpy(node->orbiter, orbiter, sizeof(node->orbiter));
    strncpy(node->launch_pad, launch_pad, sizeof(node->launch_pad));
    node->next = NULL;
    node->prev = NULL;
    return node;
}

Shuttle* parseLineToShuttle(char* line) {
    if (!line) return NULL;
    trim(line);
    char* token = strtok(line, "|");
    if (!token) return NULL;
    int number = atoi(token);

    token = strtok(NULL, "|");
    if (!token) return NULL;
    char date[15]; strncpy(date, token, sizeof(date));

    token = strtok(NULL, "|");
    if (!token) return NULL;
    char name[20]; strncpy(name, token, sizeof(name));

    token = strtok(NULL, "|");
    if (!token) return NULL;
    char orbiter[20]; strncpy(orbiter, token, sizeof(orbiter));

    token = strtok(NULL, "|");
    if (!token) return NULL;
    char pad[20]; strncpy(pad, token, sizeof(pad));

    return create_shuttle_node(number, date, name, orbiter, pad);
}

Shuttle* Insertion_Sort(Shuttle* begin, Shuttle* newNode) {
    if (!newNode) return begin;
    if (!begin) return newNode;

    if (strcmp(newNode->missionName, begin->missionName) > 0) {
        newNode->next = begin;
        begin->prev = newNode;
        return newNode;
    }

    Shuttle* current = begin;
    while (current->next != NULL &&
           strcmp(newNode->missionName, current->next->missionName) <= 0) {
        current = current->next;
    }

    newNode->next = current->next;
    newNode->prev = current;
    if (current->next)
        current->next->prev = newNode;
    current->next = newNode;
    return begin;
}

Shuttle* readShuttleFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Datei konnte nicht geöffnet werden.\n");
        return NULL;
    }

    Shuttle* begin = NULL;
    char line[200];

    fgets(line, sizeof(line), file); // Header
    fgets(line, sizeof(line), file); // Trennzeile

    while (fgets(line, sizeof(line), file)) {
        Shuttle* newNode = parseLineToShuttle(line);
        if (newNode == NULL) {
            printf("⚠️ Fehler beim Parsen: %s", line);
            continue;
        }
        begin = Insertion_Sort(begin, newNode);
    }

    fclose(file);
    return begin;
}

void printShuttleList(Shuttle *begin) 
{
    Shuttle *current = begin;
    printf("Sortierte Shuttle-Liste (absteigend nach Missionsnamen):\n");
    while (current != NULL) {
        printf("%3d |  %-12s|  %-10s|  %-11s|  %-8s\n", //stimmt nicht muss überbearbeitet werden
               current->missionNum,
               current->date,
               current->missionName,
               current->orbiter,
               current->launch_pad);
        current = current->next;
    }
}

void freeShuttleList(Shuttle* begin) {
    while (begin) {
        Shuttle* temp = begin;
        begin = begin->next;
        free(temp);
    }
}
