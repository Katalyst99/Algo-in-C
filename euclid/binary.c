#include <stdio.h>

/*
 * binary - Prints out the binary representation of a number
 * @x: The number
 *
 * Return always 0
 */

void binary(int x)
{
	char b_rep[32];
	int i = 0;
	int j = 0;

	if (x == 0)
	{
		printf("0");
		return;
	}

	while (x > 0)
	{
		b_rep[i++] = (x & 1) ? '1' : '0';
		x >>= 1;
	}

	for (j = i - 1; j >= 0; j--)
	{
		putchar(b_rep[j]);
	}
	putchar('\n');
}

int main()
{
	int number;

	printf("Enter an integer: ");
	scanf("%d", &number);

	printf("Binary equivalent: ");
	binary(number);
	return 0;
}
