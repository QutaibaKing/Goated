#include <stdio.h>
#include <math.h>
#include "FMS1.h"
#include "functions.h"

double Sin_Deg(double x) {
    return sin((x) * M_PI / 180);
}

double Cos_Deg(double x) {
    return cos((x) * M_PI / 180);
}

double distance(Airport *Depature, Airport *Arrival) //calculate distance between two points with given Coordinates in degree , which are saved in the Airport structure
{
    double distance = 6378.388 * acos(Sin_Deg(Depature->latiude.decimal) * Sin_Deg(Arrival->latiude.decimal) +Cos_Deg(Depature->latiude.decimal) * Cos_Deg(Arrival->latiude.decimal) *Cos_Deg(Arrival->longtiude.decimal - Depature->longtiude.decimal));
    return distance;
}

double decimalDegree(double Degree, double minutes, double seconds) //convert Coordinates in Degree Decimal
{
    return ((((seconds / 60) + minutes) / 60) + Degree);
}

Time calc_Duration(Time Depature, Time Arrival) //calculate duration
{

    int DepatureMIN = Depature.minute + Depature.hour * 60;//convert hour in minute and add minute from Depatur and Arrival
    int ArrivalMIN = Arrival.minute + Arrival.hour * 60;

    int Duration = ArrivalMIN - DepatureMIN; //calc needed flight time with subtracting

    Time dur;
    dur.hour = Duration / 60; //calculate needed flight time in hour:minute format and write it in a Time structure to give it back
    dur.minute = Duration % 60;

    return dur;
}

void Generate_Time_Table(FMS *pFMS) {
    printf("   Airline|Flight No.|from|  to|Departure| Arrival|Airplane\n");
    printf("----------|----------|----|----|---------|--------|--------\n");


    for (int i = 0; i < 3; i++) //go throug data structure 3 Airlines
    {
        for (int j = 0; j < 5; ++j) //iterate thorug every flight path from the Plane and print it
        {
            printf("%10s|%10s|%4s|%4s|    %02d:%02d|   %02d:%02d|%8s\n",
                   pFMS->pAirline[i].airlineName,
                   pFMS->pAirline[i].pAirplane->pFlightpath[j]->flightPathName,
                   pFMS->pAirline[i].pAirplane->pFlightpath[j]->pDepatureAirport->iata,
                   pFMS->pAirline[i].pAirplane->pFlightpath[j]->pArrivalAirport->iata,
                   pFMS->pAirline[i].pAirplane->pFlightpath[j]->depature.hour,
                   pFMS->pAirline[i].pAirplane->pFlightpath[j]->depature.minute,
                   pFMS->pAirline[i].pAirplane->pFlightpath[j]->arrival.hour,
                   pFMS->pAirline[i].pAirplane->pFlightpath[j]->arrival.minute,
                   pFMS->pAirline[i].pAirplane->airVehicleRegestriation);
        }
    }

    // free(pFMS);

}


void Generate_Duration_Table(FMS *pFMS) {
    Time Duration, Duration_result;


    printf("\n");

    for (int x = 0; x < 3; x++) {
        Duration_result.hour = 0;//reset memory for new iteration
        Duration_result.minute = 0;

        printf("   Airline|Flight No.|from|  to|Duration\n");
        printf("----------|----------|----|----|--------\n");

        for (int y = 0; y <= 4; y++) {
            Duration = calc_Duration(
                    pFMS->pAirline[x].pAirplane->pFlightpath[y]->depature, //get flight duration for every iteration
                    pFMS->pAirline[x].pAirplane->pFlightpath[y]->arrival);

            Duration_result.hour =
                    Duration_result.hour + Duration.hour;//calculate final flight time for the Airline like a Sum
            Duration_result.minute = Duration_result.minute + Duration.minute;
            if (Duration_result.minute >= 60) //correct time if minute is >= 60 minute
            {
                Duration_result.hour = Duration_result.hour + 1;
                Duration_result.minute = Duration_result.minute - 60;
            }

            printf("%10s|%10s|%4s|%4s|  %02d:%02d\n",
                   pFMS->pAirline[x].airlineName,
                   pFMS->pAirline[x].pAirplane->pFlightpath[y]->flightPathName,
                   pFMS->pAirline[x].pAirplane->pFlightpath[y]->pDepatureAirport->iata,
                   pFMS->pAirline[x].pAirplane->pFlightpath[y]->pArrivalAirport->iata,
                   Duration.hour,
                   Duration.minute);

        }
        printf("\nTotal flight Time for %s %s is %02d:%02d\n\n", //print final flight time after the palne is throug the second for loop
               pFMS->pAirline[x].airlineName,
               pFMS->pAirline[x].pAirplane->airplaneName,
               Duration_result.hour, Duration_result.minute);
    }
}

void Generate_Distance_Table(FMS *pFMS) {


    for (int x = 0; x < 3; x++) {
        double dist_result = 0; //"reset" memory for new iteration


        printf("   Airline|Flight No.|from|  to|Distance\n");
        printf("----------|----------|----|----|--------\n");

        for (int y = 0; y < 5; y++) {

            double dist = distance(pFMS->pAirline[x].pAirplane->pFlightpath[y]->pDepatureAirport,
                                   pFMS->pAirline[x].pAirplane->pFlightpath[y]->pArrivalAirport);

            dist_result = dist_result + dist; //calculate final distance like a sum
            printf("%10s|%10s|%4s|%4s| %.2f\n",
                   pFMS->pAirline[x].airlineName,
                   pFMS->pAirline[x].pAirplane->pFlightpath[y]->flightPathName,
                   pFMS->pAirline[x].pAirplane->pFlightpath[y]->pDepatureAirport->iata,
                   pFMS->pAirline[x].pAirplane->pFlightpath[y]->pArrivalAirport->iata,
                   dist);
        }
        printf("\nTotal flight distance for %s %s is %.2lf\n\n", //print final distance after the for loop
               pFMS->pAirline[x].airlineName,
               pFMS->pAirline[x].pAirplane->airplaneName,
               dist_result);
    }
}