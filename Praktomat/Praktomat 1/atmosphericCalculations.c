#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
double calculateTotaleTemperature(double T, double H);
double calculateTotaleDensity(double p, double T0);
double calculateActualDensity(double rho0, double H, double T0);
double calculateDensityAltitude(double rho);
int validateCoordinates(double latitude, double longitude);
int altitudeCoordintas(double latitude, double longitude);
double convertTemperature(double temperature);
double convertPressure(double pressure);

// constants
#define g 9.81      // Gravitational constant (m/s^2)
#define R 287.0     // Gas constant for air (J/kg*K)
#define n 1.235     // Polytropic exponent
#define Tn 288.15   // Standard troposphere temperature (K)
#define rhon 1.225  // Standard troposphere density (kg/m^3)

int main (void)
{
    double latitude, longitude, temperature, pressure;
    double T0, rho0, rho, H, T, p, altitude;

    // Input
    printf("Please enter latitude, longitude, temperature and pressure for the airport: \n");
    scanf("%lf %lf %lf %lf", &latitude, &longitude, &temperature, &pressure);

    // Output
    if (!validateCoordinates(latitude, longitude)) 
    {
        printf("Wrong coordinates entered!\n");
    } 
    else 
    {
        // Calculations
        T = convertTemperature(temperature); 
        p = convertPressure(pressure);
        altitude = altitudeCoordintas(latitude, longitude);
        T0 = calculateTotaleTemperature(T, altitude);
        rho0 = calculateTotaleDensity(p, T0);
        rho = calculateActualDensity(rho0, altitude, T0);
        H = calculateDensityAltitude(rho);

        printf("T_0 = %.3fK, rho_0 = %.3fkg/m³, rho = %.3fkg/m³, H = %.3fm\n", T0, rho0, rho, H);
    }

    return EXIT_SUCCESS;
}

// Function to convert temperature to Kelvin
double convertTemperature(double temperature)
{
    return temperature + 273.15; 
}

// Function to convert pressure to Pascal
double convertPressure(double pressure)
{
    return pressure * 100;
}

// Function to calculate the totale temperature T0
double calculateTotaleTemperature(double T, double H)
{
    return T + ((n - 1) / n) * (g / R) * H;
}

// Function to calculate totale density rho0
double calculateTotaleDensity(double p, double T0) 
{
    return p / (R * T0);
}

// Function to calculate actual density rho
double calculateActualDensity(double rho0, double H, double T0)
{
    return rho0 * pow(1 - ((n - 1) / n) * (g / (R * T0)) * H, 1.0 / (n - 1));
}

// Function to calculate density altitude H
double calculateDensityAltitude(double rho) 
{
    return ((pow(rho / rhon, n - 1) - 1.0) * (-n / (n - 1)) * ((R * Tn) / g));
}

// Function to validate coordinates
int validateCoordinates(double latitude, double longitude) {
    return (latitude == 48 && longitude == 9) || 
           (latitude == 52 && longitude == 13) || 
           (latitude == 50 && longitude == 8) || 
           (latitude == 48 && longitude == 11);
}

// Function to assign corresponding altitude
int altitudeCoordintas(double latitude, double longitude)
{
    double altitude;

    if (latitude == 48 && longitude == 9)
    {
        altitude = 388;
    }else if (latitude == 52 && longitude == 13)
    {
        altitude = 37;
    }else if (latitude == 48 && longitude == 11)
    {
        altitude = 453;
    }else if (latitude == 50 && longitude == 8)
    {
        altitude = 110;
    }

    return altitude;
}

