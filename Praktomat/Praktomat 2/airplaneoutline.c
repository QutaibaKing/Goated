#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gnuplot.h" 


float y_Value(float x);
void plot_airplane();

int main() 
{
    plot_airplane(); 

    return EXIT_SUCCESS;
}

// Function that calculates the y-Vaule based on the x-Value
float y_Value(float x) 
{
    if (x >= 0 && x < 10) 
        return 1 - expf(-x);
    else if (x >= 10 && x < 18) 
        return 20 - ((x - 14) * (x - 14));
    else if (x >= 18 && x < 23) 
        return 1 - expf(-(30 - x));
    else if (x >= 23 && x < 25) 
        return (2 * x) - 45;
    else if (x >= 25 && x < 27) 
        return 5;
    else if (x >= 27 && x < 28) 
        return (-4.2 * x) + 118.4;
    else if (x >= 28 && x < 30) 
        return 1 - expf(-(30 - x));

    return 0;

}

// Function to plot the airplane outline
void plot_airplane() 
{
    GnuPlotOpen("Airplane Outline", "airplane_function"); 

    // Transformation of x and y Values to GnuPlot and generation of the outline with a 0.1 step size as well as mirroring the function on the x-axis
    for (float x = 0; x < 30; x += 0.1) 
    {
        float y = y_Value(x);
        float y_mirrored = - y_Value(x);
        
        GnuPlotValue(x, y); 
        GnuPlotValue(x, y_mirrored);
    }

    GnuPlotClose();
}
