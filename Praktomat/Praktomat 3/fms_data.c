#include "fms.h"
#include <stdio.h>
#include <stdlib.h>

Adresses load_FMS() // oder leer lassen 
{
    Adresses save; // variable to save the pointers to delete them later

    Airport *airport = malloc(7 * sizeof(Airport)); //load Airport
    if (airport == NULL) { //check if memory was allocated when not terminate program with a fault
        printf("ERROR_can´t allocate Memory for airport");
        exit (1);
    }

    save.pAirport = airport; // save pointers to  the structure Adresses and give them back to delete the allocated memory later when not needed anymore

    //fill Arrays for Airport with data after the defined Data structure
    airport[0] = (Airport) {"EDDH", "HAM", {53, 37, 49}, {9, 59, 18}, 16}; //Hamburg
    airport[1] = (Airport) {"EDDB", "BER", {52, 21, 44}, {13, 30, 2}, 37}; //Berlin
    airport[2] = (Airport) {"EDDL", "DUS", {51, 16, 51}, {6, 45, 26}, 44};//Düsseldorf
    airport[3] = (Airport) {"EDDK", "CGN", {50, 51, 57}, {7, 8, 34}, 92};//Köln
    airport[4] = (Airport) {"EDDF", "FRA", {50, 1, 59}, {8, 34, 14}, 110};//Frankfurt
    airport[5] = (Airport) {"EDDS", "STR", {48, 41, 24}, {9, 13, 19}, 388};//Stuttgart
    airport[6] = (Airport) {"EDDM", "MUC", {48, 21, 14}, {11, 47, 10}, 453};//München

    FlightPath *pfPath = malloc(15 * sizeof(FlightPath)); //create dynamic array for the FlightPaths
    if (pfPath == NULL) {
        printf("ERROR_can´t allocate Memory for FlightPath");
        exit(1);
    }

    save.pFlightPath = pfPath;

    pfPath[0] = (FlightPath) {"LH 2147", &airport[6], &airport[0], {11, 30},{14, 30}}; //Fill Array and link the path to the airport after the given flight path
    pfPath[1] = (FlightPath) {"LH 2147", &airport[0], &airport[4], {15, 30}, {16, 30}};
    pfPath[2] = (FlightPath) {"LH 2147", &airport[4], &airport[6], {18, 30}, {20, 30}};
    pfPath[3] = (FlightPath) {"LH 2147", &airport[6], &airport[0], {20, 45}, {22, 00}};
    pfPath[4] = (FlightPath) {"LH 2147", &airport[0], &airport[6], {22, 30}, {23, 30}};
    pfPath[5] = (FlightPath) {"EW 5953", &airport[6], &airport[2], {03, 00}, {04, 15}};
    pfPath[6] = (FlightPath) {"EW 5953", &airport[2], &airport[1], {8, 00}, {10, 00}};
    pfPath[7] = (FlightPath) {"EW 5953", &airport[1], &airport[3], {10, 12}, {13, 15}};
    pfPath[8] = (FlightPath) {"EW 5953", &airport[3], &airport[6], {18, 00}, {20, 30}};
    pfPath[9] = (FlightPath) {"EW 5953", &airport[6], &airport[2], {21, 45}, {23, 30}};
    pfPath[10] = (FlightPath) {"X3 2174", &airport[0], &airport[5], {8, 00}, {10, 00}};
    pfPath[11] = (FlightPath) {"X3 2174", &airport[5], &airport[1], {10, 15}, {13, 00}};
    pfPath[12] = (FlightPath) {"X3 2174", &airport[1], &airport[4], {13, 10}, {15, 00}};
    pfPath[13] = (FlightPath) {"X3 2174", &airport[4], &airport[0], {15, 12}, {17, 00}};
    pfPath[14] = (FlightPath) {"X3 2174", &airport[0], &airport[4], {22, 00}, {24, 00}};

    Airplane *aPlane = malloc(3 * sizeof(Airplane)); //create Array for the Airplanes and link the FlightPath to them with the pointer ont the FlightPath

    if (aPlane == NULL) {
        printf("ERROR_can´t allocate Memory for aPlane");
        exit(1);
    }

    save.pAirplane = aPlane;
   
        aPlane[0] = (Airplane) {"A380", {pfPath, pfPath + 1, pfPath + 2, pfPath + 3, pfPath + 4}, "D-AIMA", 5};
        aPlane[1] = (Airplane) {"A320", {pfPath + 5, pfPath + 6, pfPath + 7, pfPath + 8, pfPath + 9}, "D-AIAB", 5};
        aPlane[2] = (Airplane) {"B747", {pfPath + 10, pfPath + 11, pfPath + 12, pfPath + 13, pfPath + 14}, "D-ABCD", 5};
   
    //load Airline
    Airline *aLine = malloc(3 * sizeof(Airline)); //create Array for the 3 Airlines
    if (aLine == NULL) {
        printf("ERROR_can´t allocate Memory for aLine");
        exit(1);
    }

    save.pAirline = aLine; //save pointer of aLine

    aLine[0] = (Airline) {"Lufthansa", aPlane};
    aLine[1] = (Airline) {"EuroWings", aPlane + 1},
    aLine[2] = (Airline) {"TUIFly", aPlane + 2};

    //load fms data
    FMS *pfms = malloc(1 * sizeof(FMS)); //create array for saving the pfms data
    if (pfms == NULL) {
        printf("ERROR_can´t allocate Memory for pfms");
        exit(1);
    }
    save.pfms = pfms; //save pointer of pfms

    pfms[0] = (FMS) {aLine, 3};

    return save;
}

void Free_FMS(Adresses save) //free created data which is carried in adresses
{
    free(save.pAirport);
    free(save.pFlightPath);
    free(save.pAirplane);
    free(save.pAirline);
    free(save.pfms);
}


