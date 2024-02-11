#include <stdio.h>

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
	return b:
}
