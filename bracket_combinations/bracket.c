#include <stdio.h>

/**
 * countCombinations - Recursive function to count valid bracket combinations
 * @open: The number of open parentheses
 * @close: The number of close parentheses
 * @count: The total of both open and close parentheses
 */
void countCombinations(int open, int close, int *count) 
{
    if (open == 0 && close == 0) 
    {
        (*count)++;
        return;
    }

    if (open > 0) 
    {
        countCombinations(open - 1, close, count);
    }

    if (close > open) 
    {
        countCombinations(open, close - 1, count);
    }
}

// Wrapper function to count bracket combinations
int bracketCombinations(int num) 
{
    int count = 0;
    countCombinations(num, num, &count);
    return count;
}

int main() 
{
    int num = 3;
    printf("Number of valid bracket combinations for %i pairs: %i\n", num, bracketCombinations(num));
    return 0;
}
