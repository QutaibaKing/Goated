#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M_PI 3.14159265358979323846
#define earthRadius 6378.388

// Functions prototypes
double calculateDegree(double degree, double minutes, double seconds);
double sinDeg(double degree);
double cosDeg(double degree);
double calculateDistance(double deplat, double deplon, double arrlat, double arrlon);

int main (void)
{
    int dep_deg_lat, dep_min_lat, dep_sec_lat, dep_deg_lon, dep_min_lon, dep_sec_lon; // departure latitude & longtitude in degrees, miniutes & seconds
    int arr_deg_lat, arr_min_lat, arr_sec_lat, arr_deg_lon, arr_min_lon, arr_sec_lon; // arrival latitude & longtitude in degrees, miniutes & seconds
    double deplat, deplon, arrlat, arrlon, distance;

    // Coordinates input
    printf("Please enter latitude in ° ' '' and longitude in ° ' '' for departure and arrival:\n");
    scanf("%d° %d' %d'' %d° %d' %d'' %d° %d' %d'' %d° %d' %d''",
        &dep_deg_lat, &dep_min_lat, &dep_sec_lat,
        &dep_deg_lon, &dep_min_lon, &dep_sec_lon,
        &arr_deg_lat, &arr_min_lat, &arr_sec_lat,
        &arr_deg_lon, &arr_min_lon, &arr_sec_lon);
    
    // Convert to decimal degrees
    deplat = calculateDegree(dep_deg_lat, dep_min_lat, dep_sec_lat);
    deplon = calculateDegree(dep_deg_lon, dep_min_lon, dep_sec_lon);
    arrlat = calculateDegree(arr_deg_lat, arr_min_lat, arr_sec_lat);
    arrlon = calculateDegree(arr_deg_lon, arr_min_lon, arr_sec_lon);

    // Calculate distance
    distance = calculateDistance(deplat, deplon, arrlat, arrlon);

    // Output
    printf("Flight Distance in km is %.2f\n", distance);

    return EXIT_SUCCESS;
}

// Converts to decimal degrees 
double calculateDegree(double degree, double minutes, double seconds)
{
    return degree + minutes / 60 + seconds / 3600;
}

// Sine of angle in degrees
double sinDeg (double degree)
{
    return sin(degree * M_PI / 180);
}

// Cosine of angle in degrees
double cosDeg (double degree)
{
    return cos(degree * M_PI / 180);
}

// Calculates flight distance based on the provided coordinates
double calculateDistance(double deplat, double deplon, double arrlat, double arrlon)
{
    return earthRadius * acos(sinDeg(arrlat) * sinDeg(deplat) + cosDeg(deplat) * cosDeg(arrlat) * cosDeg(arrlon -deplon));
}

