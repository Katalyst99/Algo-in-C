#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * addBinary - Returns the sum of 2 binary strings as a binary string
 * @a: The first string
 * @b: The second string
 * Return: The sum as a binary string.
 */

char* addBinary(char* a, char* b) 
{
    int lenA = strlen(a), lenB = strlen(b);
    int maxLen = (lenA > lenB ? lenA : lenB) + 1;
    char* output = (char*)malloc((maxLen + 1) * sizeof(char));
    output[maxLen] = '\0';

    int i = lenA - 1, j = lenB - 1, k = maxLen - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) 
    {
        int bitA = (i >= 0) ? a[i] - '0' : 0;
        int bitB = (j >= 0) ? b[j] - '0' : 0;
        int sum = bitA + bitB + carry;

        output[k] = (sum % 2) + '0';
        carry = sum / 2;

        i--; j--; k--;
    }

    if (output[0] == '0') 
    {
        return output + 1;
    }
    return output;
}

int main() 
{
    char a[] = "101";
    char b[] = "11";
    
    char* sum = addBinary(a, b);
    printf("Sum: %s\n", sum);

    if (sum[-1] == '0') 
    {
        free(sum - 1);
    } else 
    {
        free(sum);
    }

    return 0;
}
