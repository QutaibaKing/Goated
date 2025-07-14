#include <stdio.h>
#include <stdlib.h>

// Function protoytype
unsigned long long factorize(unsigned long long number);

int main (void)
{
    unsigned long long number;

    printf("Please enter the number which should be factorized: ");
    scanf("%lld", &number);

     if (number < 4) // any number below 4 can't be factorized using only prime numbers
    {
        printf("The entered number is invalid!\n");
    }else
    {
        printf("Highest prime factor of %lld is %lld\n", number, factorize(number));
    }
    return EXIT_SUCCESS;
}

unsigned long long factorize(unsigned long long number)
{
    unsigned long long max_prime_factor = -1;

    // Handle smallest prime factor (2) first
    while (number % 2 == 0) 
    {
        max_prime_factor = 2;
        number /= 2; // Remove all factors of 2
    }

    // Check for odd factors starting from 3
    for (unsigned long long  i = 3; i * i <= number; i += 2) 
    {
        while (number%i == 0) // Remove all factors of i
        {
            max_prime_factor = i;
            number /= i;
        }
        
    }   

    if (number > 2)
    {
        max_prime_factor = number;
    }

    return max_prime_factor;

}


