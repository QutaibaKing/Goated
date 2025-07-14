#ifndef fms_h
#define fms_h

#define M_PI 3.14159265358979323846
#define earthRadius 6378.388

typedef struct coordinate
{
    double degree;
    double minute;
    double second;
}
Coordinate;

typedef struct time
{
    unsigned char hour;
    unsigned char minute;
}
Time;

typedef struct airport
{
    char icao[4];
    char iata[3];
    Coordinate latitude;
    Coordinate longitude;
    float heightAMSL;
}
Airport;

typedef struct flightpath
{
    char flightPathName[10];
    Airport *pDepartureAirport;
    Airport *pArrivalAirport;
    Time departure;
    Time arrival;
}
FlightPath;

typedef struct airplane
{
    char airplaneName[4];
    FlightPath *pFlightPath;
    char airVehicleRegistration[6];
    unsigned int cntFlightPath;
}
Airplane;

typedef struct airline
{
    char airlineName[20];
    Airplane *pAirplane;
    unsigned int cntAirplane;
}
Airline;

typedef struct fms
{
    Airline *pAirline;
    unsigned int cntAirline;
}
FMS;

typedef struct adresses 
{
    FMS *pfms;
    Airline *pAirline;
    Airplane *pAirplane;
    FlightPath *pFlightpath;
    Airport *pAirport;
}
Adresses;

// funtctions for the time tables
void Generate_Time_Table(FMS * pFMS);
void Generate_Distance_Table(FMS * pFMS);
void Generate_Duration_Table(FMS * pFMS);

// functions for calculations
double calculateDegree(Coordinate coord);
double sinDeg(double degree);
double cosDeg(double degree);
double calculateDistance(Airport *departure, Airport *arrival);
Time calculateDuration(Time departure, Time arrival);



#endif