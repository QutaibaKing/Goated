#ifndef SHUTTLE_H_
#define SHUTTLE_H_

typedef struct Shuttle
{
    unsigned char missionNum;
    char date[15];
    char missionName[20];
    char orbiter[20];
    char launch_pad[20];
    struct Shuttle* next;
    struct Shuttle* prev;
}Shuttle;

Shuttle *create_shuttle_node(int missionNum, char *date, char *missionName, char *orbitor, char *launch_pad);
void trim(char* str);
Shuttle *parseLineToShuttle(char* line);
Shuttle *readShuttleFile(const char* filename);
Shuttle* Insertion_Sort(Shuttle* begin, Shuttle* newNode);
void printShuttleList(Shuttle* begin); 
void freeShuttleList(Shuttle* begin);


#endif



