#include <stdio.h>
#include <stdlib.h>

// Function prototype
void printNumberAsWords(int number);

int main() 
{
    int number;

    printf("Please enter a number between 0 and 999: ");
    scanf("%d", &number);

    printNumberAsWords(number);

    return EXIT_SUCCESS;
}

void printNumberAsWords(int number) 
{
    int digits[3];  // Array to store the digits in reverse order
    int i = 0;
    
    if (number == 0) 
    {
        printf("ZERO\n");
        return;
    }

    // extracts the digits in reverse order
    while (number > 0) 
    {
        digits[i++] = number % 10;
        number /= 10;
    }

    // prints the digits in  the correct order
    for (int j = i - 1; j >= 0; j--) {
        switch (digits[j]) {
            case 0: printf("ZERO"); break;
            case 1: printf("ONE"); break;
            case 2: printf("TWO"); break;
            case 3: printf("THREE"); break;
            case 4: printf("FOUR"); break;
            case 5: printf("FIVE"); break;
            case 6: printf("SIX"); break;
            case 7: printf("SEVEN"); break;
            case 8: printf("EIGHT"); break;
            case 9: printf("NINE"); break;
        }
        if (j > 0) printf(" ");
    }
    printf("\n");
}


