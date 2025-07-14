#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void Track_Search(FILE *file, const char *search)
{
    char line[200];
    signed int lineNum = 1;
    signed char found = 0;

    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, search))
        {
            printf("Track %d: %s", lineNum, line);
            found = 1;
        }
        lineNum++;
    }

    if (!found)
    {
        printf("Search word not found!");
    }
}

int main(void)
{
    char fileName[50];
    char search[100]; 

    FILE *file;

    printf("Please enter a Jukebox file name: ");
    fgets(fileName, sizeof(fileName), stdin);
    fileName[strcspn(fileName, "\n")] = 0; 

    printf("Please enter search word: ");
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = 0; 

    file = fopen(fileName, "r");

    if (file == NULL) 
    {
        printf("ERROR: File could not be found!\n");
    }

    Track_Search(file, search);
    fclose(file);

    return EXIT_SUCCESS;
}
