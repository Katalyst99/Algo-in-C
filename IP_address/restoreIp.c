#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_IPS 100
#define MAX_LENGTH 16
//Recursive backtracking function
void backtrack(char *s, int start, int part, char *current, char output[MAX_IPS][MAX_LENGTH], int *count) 
{
    if (part == 4 && start == strlen(s)) 
    {
        strcpy(output[*count], current);
        (*count)++;
        return;
    }

    if (part >= 4) return;

    int len = strlen(s);
    char seg[4];

    for (int i = 1; i <= 3; i++) 
    {
        if (start + i > len) break;

        strncpy(seg, s + start, i);
        seg[i] = '\0';

        int num = atoi(seg);

        if ((num > 255) || (seg[0] == '0' && i > 1)) continue;

        char newIP[MAX_LENGTH];
        if (part == 0)
            sprintf(newIP, "%s", seg);
        else
            sprintf(newIP, "%s.%s", current, seg);

        backtrack(s, start + i, part + 1, newIP, output, count);
    }
}

// Wrapper function
char** restoreIpAddresses(char *s, int *returnSize) 
{
    static char output[MAX_IPS][MAX_LENGTH];
    static char *outputPnts[MAX_IPS];
    *returnSize = 0;

    if (strlen(s) < 4 || strlen(s) > 12) return NULL;

    char current[MAX_LENGTH] = "";
    backtrack(s, 0, 0, current, output, returnSize);

    for (int i = 0; i < *returnSize; i++) 
    {
        outputPnts[i] = (char *)malloc(strlen(output[i]) + 1);
        strcpy(outputPnts[i], output[i]);
    }
    return outputPnts;
}

int main(void) 
{
    char s[] = "25525511135";
    int returnSize;
    char **output = restoreIpAddresses(s, &returnSize);

    printf("Valid IP Addresses:\n");
    for (int i = 0; i < returnSize; i++) 
    {
        printf("%s\n", output[i]);
        free(output[i]);
    }
    return 0;
}
