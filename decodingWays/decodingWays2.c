#include <stdio.h>
#include <string.h>

/**
 * numDecodings - Calculates the number of ways to decode the string
 * @s: The string
 * Return: The number of ways to decode string
 */
int numDecodings(char *s) {
    int n = strlen(s);
    if (n == 0 || s[0] == '0') 
    {
        return 0;
    }
    
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++) 
    {
        dp[i] = 0;
        
        int oneDigit = s[i - 1] - '0';
        if (oneDigit >= 1 && oneDigit <= 9) 
	{
            dp[i] += dp[i - 1];
        }
        
        int twoDigits = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        if (twoDigits >= 10 && twoDigits <= 26) 
	{
            dp[i] += dp[i - 2];
        }
    }
    return dp[n];
}

int main() 
{
    char s[] = "1106";
    int output = numDecodings(s);
    printf("Number of ways to decode '%s': %i\n", s, output);
    return 0;
}
