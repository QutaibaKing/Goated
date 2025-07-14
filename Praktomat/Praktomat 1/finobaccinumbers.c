#include <stdio.h>
#include <stdlib.h>

// Function prototype
void fibonacciSequence(int maxNumber);

int main(void)
{
    int maxNumber;

    printf("Please enter the max value for calculating the even- and uneven sum of fibonacci-numbers: ");
    scanf("%d", &maxNumber);

    fibonacciSequence(maxNumber); 

    return EXIT_SUCCESS;  
}

void fibonacciSequence(int maxNumber) 
{
    int f1 = 1;
    int f2 = 2;
    int fn;
    int evenSum = 0;
    int oddSum = 0;

    while (f1 <= maxNumber)  // loop that claculates next Finobacci number while counting the sum, until Fibonacci number exceeds maxNumber
    {
        if (f1 % 2 == 0) // checks if even or odd and adds odd numbers with odd numbers and acts correspondly with even numbers
        {
            evenSum += f1;
        }else
        {
            oddSum += f1;
        }

        fn = f1 + f2;       
        f1 = f2;           
        f2 = fn;    
           
    }
    printf("The sum of all Fibonacci-numbers not exceeding the entered max of %d is %d (even) and %d (odd)", maxNumber, evenSum, oddSum);
}


