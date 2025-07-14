#include "FMS1.h"
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>


Adresses load_FMS() {

    Adresses save; //create variable vor saving the pointers to delete them later

    Airport *aPort = malloc(7 * sizeof(Airport)); //load Airport
    if (aPort == NULL) { //check if memory was allocated when not terminate program with a fault
        printf("ERROR_can´t allocate Memory for aPort");
        exit(1);
    }
    save.pAirport = aPort; // save pointers to  the structure Adresses  and give them back  to delete the allocated memory later when not needed anymore


    //fill Arrays for Airport with data after the defined Data structure
    aPort[0] = (Airport) {0, "EDDH", "HAM", {53, 37, 49, 0}, {9, 59, 18, 0}, 11}; //Hamburg
    aPort[1] = (Airport) {1, "EDDB", "BER", {52, 21, 44, 0}, {13, 30, 2, 0}, 47.5}; //Berlin
    aPort[2] = (Airport) {2, "EDDL", "DUS", {51, 16, 51, 0}, {6, 45, 26, 0}, 36};//Düsseldorf
    aPort[3] = (Airport) {3, "EDDK", "CGN", {50, 51, 57, 0}, {7, 8, 34, 0}, 77};//Köln
    aPort[4] = (Airport) {4, "EDDF", "FRA", {50, 2, 0, 0}, {8, 34, 14, 0}, 111};//Frankfurt
    aPort[5] = (Airport) {5, "EDDS", "STR", {48, 41, 24, 0}, {9, 13, 19, 0}, 389};//Stuttgart
    aPort[6] = (Airport) {6, "EDDM", "MUC", {48, 21, 14, 0}, {11, 47, 10, 0}, 448};//München

    for (int i = 0; i < 7; ++i) //calculate deimaldegree for every airport latitude/longtitude and insert it in array
    {
        aPort[i].latiude.decimal = decimalDegree(aPort[i].latiude.degree, aPort[i].latiude.minute,aPort[i].latiude.second);
        aPort[i].longtiude.decimal = decimalDegree(aPort[i].longtiude.degree, aPort[i].longtiude.minute,aPort[i].longtiude.second);
    }

    Flightpath *pflightpath = malloc(15 * sizeof(Flightpath)); //create dynamic array for the Flightpaths
    if (pflightpath == NULL) {
        printf("ERROR_can´t allocate Memory for Flightpath");
        exit(1);
    }

    save.pFlightpath = pflightpath;

    pflightpath[0] = (Flightpath) {"LH 2147", &aPort[6], &aPort[0], {11, 30},{14, 30}}; //Fill Array and link the path to the airport after the given flight path
    pflightpath[1] = (Flightpath) {"LH 2147", &aPort[0], &aPort[4], {15, 30}, {16, 30}};
    pflightpath[2] = (Flightpath) {"LH 2147", &aPort[4], &aPort[6], {18, 30}, {20, 30}};
    pflightpath[3] = (Flightpath) {"LH 2147", &aPort[6], &aPort[0], {20, 45}, {22, 00}};
    pflightpath[4] = (Flightpath) {"LH 2147", &aPort[0], &aPort[6], {22, 30}, {23, 30}};
    pflightpath[5] = (Flightpath) {"EW 5953", &aPort[6], &aPort[2], {03, 00}, {04, 15}};
    pflightpath[6] = (Flightpath) {"EW 5953", &aPort[2], &aPort[1], {8, 00}, {10, 00}};
    pflightpath[7] = (Flightpath) {"EW 5953", &aPort[1], &aPort[3], {10, 12}, {13, 15}};
    pflightpath[8] = (Flightpath) {"EW 5953", &aPort[3], &aPort[6], {18, 00}, {20, 30}};
    pflightpath[9] = (Flightpath) {"EW 5953", &aPort[6], &aPort[2], {21, 45}, {23, 30}};
    pflightpath[10] = (Flightpath) {"X3 2174", &aPort[0], &aPort[5], {8, 00}, {10, 00}};
    pflightpath[11] = (Flightpath) {"X3 2174", &aPort[5], &aPort[1], {10, 15}, {13, 00}};
    pflightpath[12] = (Flightpath) {"X3 2174", &aPort[1], &aPort[4], {13, 10}, {15, 00}};
    pflightpath[13] = (Flightpath) {"X3 2174", &aPort[4], &aPort[0], {15, 12}, {17, 00}};
    pflightpath[14] = (Flightpath) {"X3 2174", &aPort[0], &aPort[4], {22, 00}, {24, 00}};

    Airplane *aPlane = malloc(3 * sizeof(Airplane)); //create Array for the Airplanes and link the flightpath to them with the pointer ont the flightpath

    if (aPlane == NULL) {
        printf("ERROR_can´t allocate Memory for aPlane");
        exit(1);
    }

    save.pAirplane = aPlane;

    aPlane[0] = (Airplane) {"A380", "D-AIMA", {pflightpath, pflightpath + 1, pflightpath + 2, pflightpath + 3, pflightpath + 4}};
    aPlane[1] = (Airplane) {"A320", "D-AIAB", {pflightpath + 5, pflightpath + 6, pflightpath + 7, pflightpath + 8, pflightpath + 9}};
    aPlane[2] = (Airplane) {"B747", "D-ABCD", {pflightpath + 10, pflightpath + 11, pflightpath + 12, pflightpath + 13, pflightpath + 14}};

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
    pfms->pAirline = aLine;//point to aLine
    save.pfms = pfms; //save pointer of pfms

    return save;
}

void Free_FMS(Adresses save) //free created data which is carried in adresses
{
    free(save.pAirport);
    free(save.pFlightpath);
    free(save.pAirplane);
    free(save.pAirline);
    free(save.pfms);
}