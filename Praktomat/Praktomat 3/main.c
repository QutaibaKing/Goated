#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "fms.h"

extern FMS *pfms; // a global variable but the same method was used "Tutorium 12"

int main(void)
{
    Generate_Time_Table(pfms);
    Generate_Duration_Table(pfms);
    Generate_Distance_Table(pfms);

    return EXIT_SUCCESS;
}