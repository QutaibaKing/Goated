#include <stdio.h>
#include <stdlib.h>

int getHighestPalindrome(int low_limit, int high_limit, int *factor1, int *factor2);
int isPalindrome(int product);

int main (void)
{
    int low_limit, high_limit;

    printf("Please enter the range of numbers - multiplied with each other - to get the highest palindrome: ");

    // Checks if the input is correct or makes sense
    if (scanf("%d %d", &low_limit, &high_limit) != 2 || low_limit < 100 || high_limit < 100 || low_limit > 999 || high_limit > 999 || low_limit > high_limit) 
    {
        printf("Wrong input!\n");
    }

    int factor1 = 0;
    int factor2 = 0;

    int highest_palindrome = getHighestPalindrome(low_limit, high_limit, &factor1, &factor2);

    // Checks if there is a palindrome in the range
    if (highest_palindrome != -1) {
        printf("The highest palindrome as a product of %d and %d is %d\n", factor1, factor2, highest_palindrome);
    } else {
        printf("No palindrome found!\n");
    }

    return EXIT_SUCCESS;
}

// Function that checks if the product of two numbers within the given range is a palindrome
int isPalindrome (int product)
{
    int original = product;
    int reversed = 0;
    int remainder;

    // A for Loop that reverses the number
    for (int i = product; i != 0; i /= 10) 
    {
        remainder = i % 10;
        reversed = reversed * 10 + remainder;
    }

    // Checks if the reversed number equals the original number - if so then the number is a palindrome
    if (original == reversed)
    {
        return 1;
    }else
    {
        return 0;
    }

}


// Function that calculates the highest possible palindrome wihtin the given range
int getHighestPalindrome(int low_limit, int high_limit, int *factor1, int *factor2)
{
    int highest_palindrome = -1;

    // A for loop that goes through every possible multiplication within the given range 
    for (int i = high_limit; i >= low_limit; i--)
    {
        for (int j = i; j >= low_limit; j--)
        { 
            int product = i * j;

            // Checks wether product is a palindrome - if so - the previous product gets overwritten until reaching highest possible product
            if (isPalindrome(product) && product > highest_palindrome)
            {
                highest_palindrome = product;

                // Used factors to reach the highest possible palindrome within the range
                *factor1 = j;
                *factor2 = i;
            }
        }
    }
    
    return highest_palindrome;
}

