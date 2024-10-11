#include <stdio.h>

/*
 * hcf - highest common factor
 * @a: The first number
 * @b: The second number
 *
 * Return: The HCF of a and b.
 */

int hcf(int a, int b)
{
    int tmp;

    while (a > 0)
    {
        if (a < b)
        {
            tmp = a;
            a = b;
            b = tmp;
        }
        a = a - b;
    }
    return b;
}

int main()
{
    int x, y;

    printf("Enter two positive integers (space-separated):\n");

    while (scanf("%d %d", &x, &y) != EOF)
    {
        if (x > 0 && y > 0)
        {
            printf("HCF of %d and %d is %d\n", x, y, hcf(x, y));
        }
        else
        {
            printf("Please enter positive integers.\n");
        }
    }
    return (0);
}

