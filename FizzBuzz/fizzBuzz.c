#include <stdio.h>

/**
 * printFizzBuzz - Prints "Fizz", "Buzz", "FizzBuzz", or the number.
 * @n: The number to be checked and printed.
 */
void printFizzBuzz(int n)
{
    if ((n % 3) == 0 && (n % 5) == 0)
    {
        printf("FizzBuzz");
    }
    else if ((n % 3) == 0)
    {
        printf("Fizz");
    }
    else if ((n % 5) == 0)
    {
        printf("Buzz");
    }
    else
    {
        printf("%d", n);
    }
}

/**
 * main - Calls printFizzBuzz for numbers from 1 to 100.
 * Return: Always 0.
 */
int main(void)
{
    for (int i = 1; i <= 100; i++)
    {
        printFizzBuzz(i);
        if (i < 100)  // Print a space between numbers but not after the last one
        {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}

