#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * countAndSay - Takes a positive int as input and recursively computes the nth term
 * @n: The positive integer
 * Return: The nth term of the count-and-say sequence
 */

char* countAndSay(int n) {
    if (n == 1) return strdup("1");
    
    char* prev = countAndSay(n - 1);
    int length = strlen(prev);
    char* output = (char*)malloc(2 * length + 1);
    int index = 0, i = 0;

    while (i < length) 
    {
        int count = 1;

        while (i + 1 < length && prev[i] == prev[i + 1]) 
	{
            count++;
            i++;
        }

        output[index++] = count + '0';
        output[index++] = prev[i];
        i++;
    }
    
    output[index] = '\0';
    free(prev);
    return output;
}

int main() 
{
    int n = 5;
    char* output = countAndSay(n);
    printf("countAndSay(%i) = %s\n", n, output);
    free(output);
    return 0;
}

