#include <stdio.h>
#include "gnuplot.h"

FILE * gnu;

void GnuPlotOpen(char * title, char * filename)
{
    gnu = popen("gnuplot -persistent","w");

    if (filename != NULL)
    {
        fprintf(gnu,"set title \"%s\"; set terminal png; set output \"%s.png\"; plot '-' \n",title,filename);
    }else
    {
        fprintf(gnu,"plot '-' \n");
    }
}

void GnuPlotClose(void)
{
    pclose(gnu);
}

void GnuPlotValue(float v1, float v2)
{
    fprintf(gnu,"%0.2f %0.2f \n",v1,v2);
}


