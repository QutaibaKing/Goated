#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shuttle.h"

// Creates and initializes a new Shuttle node
Shuttle *createShuttleNode(int missionNum, char *date, char *missionName, char *orbitor, char *launch_pad)
{
    Shuttle *node = (Shuttle*)malloc(sizeof(Shuttle));

    if (node == NULL)
    {
        printf("Memory Allocation Failed\n");
        return NULL;
    }

    node->missionNum = missionNum;
    strncpy(node->date, date, sizeof(node->date));
    strncpy(node->missionName, missionName, sizeof(node->missionName));
    strncpy(node->orbiter, orbitor, sizeof(node->orbiter));
    strncpy(node->launch_pad, launch_pad, sizeof(node->launch_pad));

    node->next = NULL;
    node->prev = NULL;

    return node;
}

// Removes leading and trailing whitespace characters
void trim(char* str) 
{
    if (str == NULL)
    {
        return;
    } 

    // Remove leading spaces
    while (*str == ' ') 
    {
        memmove(str, str + 1, strlen(str));
    }

    int len = strlen(str);

    // Remove trailing spaces, newlines and return carriages
    while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\n' || str[len - 1] == '\r')) 
    {
        str[len - 1] = '\0';
        len--;
    }
}

// Parses a line from the file into a Shuttle node
Shuttle *parseLineToShuttle(char* line) 
{
    int missionNum;
    char date[15], missionName[20], orbiter[20], launch_pad[20];

    // Tokenize (split the string in smaller parts) and handle each part
    char* token = strtok(line, "|");                                // First token (split at '|')
    if (token == NULL) return NULL;                                 // Ignore if token is missing
    missionNum = atoi(token);                                       // Convert to int

    token = strtok(NULL, "|");                                      // Next token ...
    if (token == NULL) return NULL;
    strncpy(date, token, sizeof(date));
    trim(date);                                                     // Remove whitespace

    token = strtok(NULL, "|");
    if (token == NULL) return NULL;
    strncpy(missionName, token, sizeof(missionName));
    trim(missionName);

    token = strtok(NULL, "|");
    if (token == NULL) return NULL;
    strncpy(orbiter, token, sizeof(orbiter));
    trim(orbiter);

    token = strtok(NULL, "|");
    if (token == NULL) return NULL;
    strncpy(launch_pad, token, sizeof(launch_pad));
    trim(launch_pad);

    return createShuttleNode(missionNum, date, missionName, orbiter, launch_pad);
}


// Reads the file and builds a sorted linked list of Shuttle nodes
Shuttle *readShuttleFile(const char* filename)
{
    Shuttle *begin = NULL;

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("File could not be found!\n");
        return NULL;
    }

    char line[200];

    fgets(line, sizeof(line), file); // Skip Header-Line

    while (fgets(line, sizeof(line), file))
    {
        trim(line);  // Remove possible \n, \r or spaces at the end

        if (strlen(line) == 0 || line[0] == '-' || line[0] == '\n') 
        {
            continue;  // Skip empty lines after trimming
        }

        Shuttle* newNode = parseLineToShuttle(line);

        // If conversion was successful, insert the node into the sorted list
        if (newNode != NULL) 
        {
            if (begin == NULL) 
            {
                // First valid node becomes the start of the list
                begin = newNode;
            } 
            else 
            {
                // Insert node into the list, keeping it sorted by mission name
                begin = Insertion_Sort(begin, newNode);
            }
        }
    }

    fclose(file);
    return begin;
}

// Inserts a node into the linked list sorted by mission name (descending)
Shuttle* Insertion_Sort(Shuttle* begin, Shuttle* newNode)
{
    if (begin == NULL)
    {
        return newNode;
    }

    // New node comes before the first node (alphabetically descending)
    if (strcmp(newNode->missionName, begin->missionName) < 0)
    {
        newNode->next = begin;
        begin->prev = newNode;
        return newNode;
    }

    Shuttle* current = begin;

    // Find the correct insertion point
    while (current->next != NULL && strcmp(newNode->missionName, current->next->missionName) >= 0)
    {
        current = current->next;
    }

    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != NULL)
    {
        current->next->prev = newNode;
    }

    current->next = newNode;

    return begin;
}

// Prints the list in a formatted table
void printShuttleList(Shuttle* begin) 
{
    if (begin == NULL)
    {
        return;
    } 

    printf("Missions-Nr. | Start-Datum | Missionsbezeichnung |  Orbiter   | Startrampe\n");
    printf("-------------------------------------------------------------------------\n");

    while (begin != NULL) 
    {
        printf("%-12d | %-11s | %-19s | %-11s| %-6s\n",
               begin->missionNum,
               begin->date,
               begin->missionName,
               begin->orbiter,
               begin->launch_pad);

        begin = begin->next;
    }
}

// Frees all allocated memory of the shuttle list
void freeShuttleList(Shuttle* begin) 
{
    while (begin != NULL) 
    {
        Shuttle* temp = begin;
        begin = begin->next;
        free(temp);
    }
}
