#include <stdio.h>
#include <stdlib.h>

// Function prototype
unsigned long long calculateDigits(int limit);

int main (void)
{
    int limit;

    //Input
    printf("Please enter the highest value, which will be selected: ");
    scanf("%d", &limit);

    //Output
    printf("The last digits of the series are %lld", calculateDigits(limit));

    return EXIT_SUCCESS;
}

// Function to calculate the last 8 digits of the sum of k^k
unsigned long long calculateDigits(int limit)
{
    unsigned long long sum = 0;
    unsigned long long mod = 100000000; // To get the last 8 digits

    // Loop to calculate and sum k^k % mod
    for (int k = 1; k <= limit; k++) 
    {
        unsigned long long term = 1;

        // Calculate k^k % mod
        for (int i = 0; i < k; i++) 
        {
            term = (term * k) % mod; // Calculate k^k
        }

        sum = (sum + term) % mod;
    }

    return sum;
}


