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
            printf("Treffer in Zeile %d: %s", lineNum, line);
            found = 1;
        }
        lineNum++;
    }

    if (!found)
    {
        printf("Suchwort nicht gefunden");
    }
}

int main(void)
{
    char fileName[50];
    char search[100]; // war vorher char *search[100]; → falsch

    FILE *file;

    printf("Please enter a Jukebox file name: ");
    fgets(fileName, sizeof(fileName), stdin);
    fileName[strcspn(fileName, "\n")] = 0; // Zeilenumbruch entfernen

    printf("Please enter search word: ");
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = 0; // Zeilenumbruch entfernen

    file = fopen(fileName, "r");

    if (file == NULL) // war = statt ==
    {
        printf("Fehler: Datei konnte nicht geöffnet werden\n");
        return EXIT_FAILURE; // vorher war: return;
    }

    Track_Search(file, search);
    fclose(file);

    return EXIT_SUCCESS;
}
