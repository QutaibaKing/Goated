#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// function to search for a word within a file
void Track_Search(FILE *file, const char *search)
{
    char line[200];
    signed int lineNum = 1;
    signed char found = 0;  // 0 if nothing is found and 1 if something was found

    // goes through every line of the file
    while (fgets(line, sizeof(line), file))
    {
        // if the search word was found the corresponding output will be printed
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
    char searchWord[100]; 

    FILE *file;

    printf("Please enter a Jukebox file name: ");
    scanf("%s", fileName);

    printf("Please enter search word: ");
    scanf("%s", searchWord);

    // read file if found
    file = fopen(fileName, "r");

    if (file == NULL) 
    {
        printf("ERROR: File could not be found!\n");
    }

    Track_Search(file, searchWord);
    fclose(file);

    return EXIT_SUCCESS;
}
