#include <stdio.h>
#include <math.h>

#define LIMIT 10000

/**
 * sumOfDivisors - Computes the sum of proper divisors of a number
 * @n: The number
 * Return: The sum of proper divisors
 */
int sumOfDivisors(int n) 
{
    if (n < 2) return 0;

    int sum = 1;
    int sqrt_n = sqrt(n);

    for (int i = 2; i <= sqrt_n; i++) 
    {
        if (n % i == 0) 
	{
            sum += i;
            if (i != n / i)
                sum += n / i;
        }
    }
    return sum;
}

/**
 * findAmicablePairs - Finds and prints amicable pairs up to a given limit
 * @limit: The given limit
 */
void findAmicablePairs(int limit) 
{
    int divisorSums[limit];

    for (int i = 2; i < limit; i++) 
    {
        divisorSums[i] = sumOfDivisors(i);
    }

    for (int x = 2; x < limit; x++) 
    {
        int y = divisorSums[x];

        if (y > x && y < limit && divisorSums[y] == x) 
	{
            printf("Amicable Pair: (%i, %d)\n", x, y);
        }
    }
}

int main() 
{
    printf("Finding Amicable Pairs up to %i:\n", LIMIT);
    findAmicablePairs(LIMIT);
    return 0;
}
