#include <stdio.h>

/* Define the fraction structure */
struct fraction {
    int numerator;
    int denominator;
};

/*
 * hcf - highest common factor using Euclidean Algorithm
 * @a: The first number
 * @b: The second number
 *
 * Return: The HCF of a and b.
 */
int hcf(int a, int b)
{
    while (b != 0)
    {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

/*
 * reduce_fraction - Reduces a fraction to its lowest terms
 * @f: The fraction to reduce
 *
 * Return: The reduced fraction.
 */
struct fraction reduce_fraction(struct fraction f)
{
    int divisor = hcf(f.numerator, f.denominator);
    f.numerator /= divisor;     // Divide both numerator and denominator
    f.denominator /= divisor;   // by the HCF to reduce the fraction
    return f;
}

int main(void)
{
    struct fraction f;

    // Get user input for the fraction
    printf("Enter numerator and denominator of the fraction (space-separated):\n");
    scanf("%d %d", &f.numerator, &f.denominator);

    // Check if the denominator is zero
    if (f.denominator == 0)
    {
        printf("Error: Denominator cannot be zero.\n");
        return 1;
    }

    // Reduce the fraction
    struct fraction reduced = reduce_fraction(f);

    // Output the reduced fraction
    printf("The reduced fraction is: %d/%d\n", reduced.numerator, reduced.denominator);

    return 0;
}

