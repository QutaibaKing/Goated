#include <stdio.h>
#include <stdlib.h>

#include "fms.h"

Airport airport[] = // array for the airports
{
    {"EDDH", "HAM", {53,37,49}, {9,59,18},   16},       // 0, Hamburg     
    {"EDDB", "BER", {52,21,44}, {13,30,2},   37},       // 1, Berlin and so on         
    {"EDDL", "DUS", {51,16,51}, {6,45,26},   44},                 
    {"EDDK", "CGN", {50,51,57}, {7,8,34},    92},
    {"EDDF", "FRA", {50,1,59},  {8,34,14},  110},
    {"EDDS", "STR", {48,41,24}, {9,13,19},  388},
    {"EDDM", "MUC", {48,21,14}, {11,47,10}, 453},
};

FlightPath fp_lufthansa[] = // array for the flightpaths of Lufthansa
{                              
    {"LH 2147", &airport[6], &airport[0], {11,30}, {14,30}},      
    {"LH 2147", &airport[0], &airport[4], {15,30}, {16,30}},
    {"LH 2147", &airport[4], &airport[6], {18,30}, {20,30}},
    {"LH 2147", &airport[6], &airport[0], {20,45}, {22, 0}},
    {"LH 2147", &airport[0], &airport[6], {22,30}, {23,30}},    
};

FlightPath fp_eurowings[] = // array for the flightpaths of Eurowings
{                            
    {"EW 5953", &airport[6], &airport[2], { 3, 0}, { 4,15}},
    {"EW 5953", &airport[2], &airport[1], { 8, 0}, {10, 0}},
    {"EW 5953", &airport[1], &airport[3], {10,12}, {13,15}}, 
    {"EW 5953", &airport[3], &airport[6], {18, 0}, {20,30}},
    {"EW 5953", &airport[6], &airport[2], {21,45}, {23,30}},
};

FlightPath fp_TUIFly[] = // array for the flightpaths of TUIFly
{
    {"X3 2174", &airport[0], &airport[5], { 8, 0}, {10, 0}},
    {"X3 2174", &airport[5], &airport[1], {10,15}, {13, 0}},
    {"X3 2174", &airport[1], &airport[4], {13,10}, {15, 0}}, 
    {"X3 2174", &airport[4], &airport[0], {15,12}, {17, 0}},
    {"X3 2174", &airport[0], &airport[4], {22, 0}, {24, 0}},

};

Airplane airplane[] = // array for the airplanes
{
    {"A380", fp_lufthansa, "D-AIMA", 5},
    {"A320", fp_eurowings, "D-AIAB", 5},
    {"B747", fp_TUIFly, "D-ABCD", 5},
};

Airline airline[] = // array for the airlines
{
    {"Lufthansa", &airplane[0], 1},
    {"EuroWings", &airplane[1], 1},
    {"TUIFly", &airplane[2], 1}, 
};

FMS fms = {airline, 3};

FMS *pfms = &fms;