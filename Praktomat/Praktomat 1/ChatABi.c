#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constants
#define g 9.81      // Gravitational constant (m/s^2)
#define R 287.0     // Gas constant for air (J/kg*K)
#define n 1.235     // Polytropic exponent
#define Tn 288.15   // Standard troposphere temperature (K)
#define rhon 1.225  // Standard troposphere density (kg/m^3)

// Function declarations
double calculateTotaleTemperature(double T);
double calculateTotaleDensity(double p, double T0);
double calculateActualDensity(double rho0, double H, double T0);
double calculateDensityAltitude(double rho);
int validateCoordinates(double latitude, double longitude);

// Function to calculate the total temperature T0
double calculateTotaleTemperature(double T) {
    return T + ((n - 1) / n) * (g / R) * 0.0; // H = 0 for T0 calculation
}

// Function to calculate total density rho0
double calculateTotaleDensity(double p, double T0) {
    return p / (R * T0);
}

// Function to calculate actual density rho
double calculateActualDensity(double rho0, double H, double T0) {
    return rho0 * pow(1 - ((n - 1) / n) * (g / (R * T0)) * H, 1.0 / (n - 1));
}

// Function to calculate density altitude H
double calculateDensityAltitude(double rho) {
    return ((pow(rho / rhon, n - 1) - 1.0) * (-n / (n - 1)) * ((R * Tn) / g));
}

// Function to validate coordinates
int validateCoordinates(double latitude, double longitude) {
    return (latitude == 48 && longitude == 9) || 
           (latitude == 52 && longitude == 13) || 
           (latitude == 50 && longitude == 8) || 
           (latitude == 48 && longitude == 11);
}

// Main function
int main(void) {
    double latitude, longitude, temperature, pressure;
    double T0, rho0, rho, H;

    // Input
    printf("Please enter latitude, longitude, temperature and pressure for the airport: \n");
    scanf("%lf %lf %lf %lf", &latitude, &longitude, &temperature, &pressure);

    // Output
    if (!validateCoordinates(latitude, longitude)) {
        printf("Wrong coordinates entered!\n");
    } else {
        // Convert input values
        double T = temperature + 273.15;    // Converts to Kelvin
        double p = pressure * 100;          // Converts to Pascal
        double altitude = 0.0;              // Initial altitude 

        // Perform calculations
        T0 = calculateTotaleTemperature(T);
        rho0 = calculateTotaleDensity(p, T0);
        rho = calculateActualDensity(rho0, altitude, T0);
        H = calculateDensityAltitude(rho);

        printf("T0 = %.3fK, rho0 = %.3fkg/m^3, rho = %.3fkg/m^3, H = %.2fm\n", T0, rho0, rho, H);
    }

    return EXIT_SUCCESS;
}