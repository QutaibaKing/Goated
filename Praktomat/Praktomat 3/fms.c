#include <stdio.h>
#include <math.h>

#include "fms.h"

// converts to decimal degrees 
double calculateDegree(Coordinate coord)
{
    return coord.degree + coord.minute / 60 + coord.second / 3600;
}

// sine of angle in degrees
double sinDeg (double degree)
{
    return sin(degree * M_PI / 180);
}

// cosine of angle in degrees
double cosDeg (double degree)
{
    return cos(degree * M_PI / 180);
}

// calculates flight distance based on the provided coordinates
double calculateDistance(Airport *departure, Airport *arrival)
{
    double deplat = calculateDegree(departure->latitude);
    double arrlat = calculateDegree(arrival->latitude);
    double deplon = calculateDegree(departure->longitude);
    double arrlon = calculateDegree(arrival->longitude);

    return earthRadius * acos(sinDeg(deplat) * sinDeg(arrlat) + cosDeg(deplat) * cosDeg(arrlat) * cosDeg(arrlon - deplon));
}

// calculates the duration of a flight
Time calculateDuration(Time departure, Time arrival)
{
    // converts time to minutes
    int minutesDeparture = departure.minute + departure.hour * 60;
    int minutesArrival = arrival.minute + arrival.hour * 60;

    // calculates flight time in minutes
    int durationeMinutes = minutesArrival - minutesDeparture;

    // converts flight time to hour:minute format
    Time duration;
    duration.hour = durationeMinutes / 60;
    duration.minute = durationeMinutes % 60;

    return duration;
}

// function that generates the time table
void Generate_Time_Table(FMS *pFMS)
{
    unsigned int cntAirline = pFMS->cntAirline;
    unsigned int cntAirplane = pFMS->pAirline->cntAirplane;
    unsigned int cntFlightPath = pFMS->pAirline->pAirplane->cntFlightPath;

    printf("   Airline|Flight No.|from|  to|Departure| Arrival|Airplane\n");
    printf("----------|----------|----|----|---------|--------|--------\n");

    for (int i = 0; i < cntAirline; i++) // goes through the every airline
    {
        Airline *airline = &pFMS->pAirline[i];

        for (int j = 0; j < cntAirplane; j++) // goes through every airplane
        {
            Airplane *airplane = &airline->pAirplane[j];

            for (int k = 0; k < cntFlightPath; k++) // goes through every flight path
            {
                FlightPath *flightpath = &airplane->pFlightPath[k];

                printf("%10s|%10s|%4s|%4s|    %02d:%02d|   %02d:%02d|%8s\n",
                    airline->airlineName,
                    flightpath->flightPathName,
                    flightpath->pDepartureAirport->iata,
                    flightpath->pArrivalAirport->iata,
                    flightpath->departure.hour,
                    flightpath->departure.minute,
                    flightpath->arrival.hour,
                    flightpath->arrival.minute,
                    airplane->airVehicleRegistration);
            }
        }
    }
}

// function that generates duration table
void Generate_Duration_Table(FMS * pFMS)
{
    Time duration, totaleDuration;
    printf("\n");

    unsigned int cntAirline = pFMS->cntAirline;
    unsigned int cntAirplane = pFMS->pAirline->cntAirplane;
    unsigned int cntFlightPath = pFMS->pAirline->pAirplane->cntFlightPath;

    for (int i = 0; i < cntAirline; i++) // goes through every airline
    {
        Airline *airline = &pFMS->pAirline[i];

        printf("   Airline|Flight No.|from|  to|Duration\n");
        printf("----------|----------|----|----|--------\n");

        for (int j = 0; j < cntAirplane; j++) // goes through every airplane
        {
            Airplane *airplane = &airline->pAirplane[j];

            // resets totale flight time for a new iteration
            totaleDuration.hour = 0;
            totaleDuration.minute = 0;

            for (int k = 0; k < cntFlightPath; k++) // goes through every flight path
            {
                FlightPath *flightpath = &airplane->pFlightPath[k];

                duration = calculateDuration(flightpath->departure, flightpath->arrival);

                totaleDuration.hour = totaleDuration.hour + duration.hour;
                totaleDuration.minute = totaleDuration.minute + duration.minute;

                // if the minutes exceed 60 correct the time to hour:minute format
                if (totaleDuration.minute >= 60)
                {
                    totaleDuration.hour = totaleDuration.hour + 1;
                    totaleDuration.minute = totaleDuration.minute - 60;
                }

                printf("%10s|%10s|%4s|%4s|  %02d:%02d\n",
                        airline->airlineName,
                        flightpath->flightPathName,
                        flightpath->pDepartureAirport->iata,
                        flightpath->pArrivalAirport->iata,
                        duration.hour, duration.minute);   
            }

            printf("\nTotal flight Time for %s %s is %02d:%02d\n\n",
                    airline->airlineName,
                    airplane->airplaneName,
                    totaleDuration.hour, totaleDuration.minute);
        } 
    }
}

// function that generates the distance table
void Generate_Distance_Table(FMS * pFMS)
{   
    unsigned int cntAirline = pFMS->cntAirline;
    unsigned int cntAirplane = pFMS->pAirline->cntAirplane;
    unsigned int cntFlightPath = pFMS->pAirline->pAirplane->cntFlightPath;
    
    for (int i = 0; i < cntAirline; i++) // goes through every airline
    {
        Airline *airline = &pFMS->pAirline[i];

        printf("   Airline|Flight No.|from|  to|Distance\n");
        printf("----------|----------|----|----|--------\n");

        for (int j = 0; j < cntAirplane; j++) // goes through every airplane
        {
            Airplane *airplane = &airline->pAirplane[j];

            double totaleFlightDistance = 0; // resets totale flight distance for a new iteration

            for (int k = 0; k < cntFlightPath; k++) // goes through every flight path
            {
                FlightPath *flightpath = &airplane->pFlightPath[k];

                // calculates the distance for each iteration
                double distance = calculateDistance(flightpath->pDepartureAirport, flightpath->pArrivalAirport);
            
                totaleFlightDistance += distance;

                printf("%10s|%10s|%4s|%4s| %.2f\n",
                        airline->airlineName,
                        flightpath->flightPathName,
                        flightpath->pDepartureAirport->iata,
                        flightpath->pArrivalAirport->iata,
                        distance);
            }

            printf("\nTotal flight distance for %s %s is %.2lf\n\n",
                    airline->airlineName,
                    airplane->airplaneName,
                    totaleFlightDistance);
        }   
    }
}



