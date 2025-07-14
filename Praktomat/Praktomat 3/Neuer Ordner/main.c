#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "FMS1.h"
#include "functions.h"




void Generate_Table(Adresses A)
{
    Generate_Time_Table(A.pfms);
    Generate_Duration_Table(A.pfms);
    Generate_Distance_Table(A.pfms) ;

    Free_FMS(A); //delete Data in Heap
}


int main(void)
{
    Generate_Table(load_FMS());

    return 0;
}



