#include <stdio.h>

/**
 * grayCode - Function to encode and decode a number in Gray code
 * @encode: If 1, encodes the number; if 0, decodes it.
 * @num: The number to encode or decode.
 *
 * Return: Gray code representation of number or decoded number
 */

int grayCode(int encode, int num)
{
	int mask;

	if (encode)
	{
		return (num ^ (num >> 1));
	}
	else
	{
		mask = num >> 1;
		while (mask != 0)
		{
			num = num ^ mask;
			mask = mask >> 1;
		}
		return num;
	}
}

int main(void)
{
	int num, encode;
	int result = 0;

	printf("Enter the number: ");
	scanf("%d", &num);

	printf("Enter 1 to encode or 0 to decode: ");
	scanf("%d", &encode);

	result = grayCode(encode, num);
	printf("Result: %d\n", result);
	return 0;
}
