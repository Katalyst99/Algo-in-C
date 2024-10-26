#include <stdio.h>

/**
 * converter - Reads a decimal number one character at a time.
 *
 * Return: The value of the number
 */
int converter()
{
	int digit = 0;
	int num = 0;
	char ch;

	while ((ch = getchar()) != ' ')
	{
		if (ch >= '0' && ch <= '9')
		{
			digit = ch - '0';
			num  = num * 10 + digit;
		}
		else
		{
			printf("Invalid input. Please enter digits only.\n");
			return -1;
		}
	}
	return num;
}

int main(void)
{
	printf("Enter a decimal number followed by a space: ");
	int result = converter();
	if (result != -1)
	{
		printf("The converted number is: %d\n", result);
	}
	return 0;
}
