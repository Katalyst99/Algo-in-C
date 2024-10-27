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

/*
 * gcd_of_three - Computes the GCD of three numbers
 * @u: The first number
 * @v: The second number
 * @w: The third number
 *
 * Return: The GCD of u, v and w.
 *
 */
int gcd_of_three(int u, int v, int w)
{
	int uv_gcd = 0;

	uv_gcd = hcf(u, v);
	return hcf(uv_gcd, w);
}

int main(void)
{
	int u, v, w;

	printf("Enter three integers (space-separated): ");
	scanf("%d %d %d", &u, &v, &w);

	printf("The GCD of %d, %d, and %d is: %d\n", u, v, w, gcd_of_three(u, v, w));
	return 0;
}
