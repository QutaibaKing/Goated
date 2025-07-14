#ifndef FMS1_H
#define FMS1_H

#define string_lenght 32

typedef struct coordinate {
    double degree;
    double minute;
    double second;
    double decimal;
} Coordinate;

typedef struct time {
    unsigned char hour;
    unsigned char minute;
} Time;

typedef struct airport {
    int id;
    char icao[4];
    char iata[4];
    Coordinate latiude;
    Coordinate longtiude;
    float heigtAMSL;
} Airport;

typedef struct flightpath {
    char flightPathName[string_lenght];
    Airport *pDepatureAirport;
    Airport *pArrivalAirport;
    Time depature;
    Time arrival;
} Flightpath;

typedef struct airplane {
    char airplaneName[string_lenght];
    char airVehicleRegestriation[string_lenght];
    Flightpath *pFlightpath[5]; //create array for better handling of the flightpaths
    unsigned int cntFlightPath;
} Airplane;

typedef struct airline {
    char airlineName[string_lenght];
    Airplane *pAirplane;
    unsigned int cntAirplane;
} Airline;

typedef struct fms {
    Airline *pAirline;
    unsigned int cntAirline;
} FMS;

typedef struct adresses {
    FMS *pfms;
    Airline *pAirline;
    Airplane *pAirplane;
    Flightpath *pFlightpath;
    Airport *pAirport;
} Adresses;

#endif