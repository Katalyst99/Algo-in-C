#include <stdio.h>

/*
 * hcf - highest common factor using Euclidean Algorithm
 * @a: The first number
 * @b: The second number
 *
 * Return: The HCF of a and b.
 *
 */

int hcf(int a, int b)
{
	int remainder = 0;

	if (b == 0)
	{
		return (a);
	}

	while (b != 0)
	{
		remainder = a % b;
		a = b;
		b = remainder;
	}
	return (a);
}

int main(void)
{
	int x, y;

	printf("Enter two positive integers (space-separated):\n");
	while (scanf("%d %i", &x, &y) != EOF)
	{
		if (x > 0 && y > 0)
		{
			printf("HCF of %d and %d is %i\n", x, y, hcf(x, y));
		}
		else
		{
			printf("Please enter positive integers.\n");
		}
	}
	return (0);
}
