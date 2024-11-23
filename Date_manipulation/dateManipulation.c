#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * add12Hours - Adds 12 hours to a given date string in EST.
 * @date_str: Input date string in the format "YYYY-MM-DD HH:MM:SS EST".
 * 
 * Return: A string with 12 hours added, maintaining the timezone.
 */
char *add12Hours(const char *date_str) 
{
    struct tm tm;
    time_t timestamp;
    static char output[30];

    memset(&tm, 0, sizeof(struct tm));
    if (strptime(date_str, "%Y-%m-%d %H:%M:%S EST", &tm) == NULL) 
    {
        fprintf(stderr, "Invalid date format\n");
        return NULL;
    }

    timestamp = mktime(&tm);
    if (timestamp == -1) 
    {
        fprintf(stderr, "Error converting time\n");
        return NULL;
    }

    // Add 12 hours (12 * 60 * 60 seconds)
    timestamp += 12 * 3600;

    localtime_r(&timestamp, &tm);

    if (strftime(output, sizeof(output), "%Y-%m-%d %H:%M:%S EST", &tm) == 0) 
    {
        fprintf(stderr, "Error formatting date\n");
        return NULL;
    }

    return output;
}

int main() 
{
    const char *input_date = "2024-11-23 08:30:00 EST";
    char *result = add12Hours(input_date);

    if (result != NULL) {
        printf("Updated date: %s\n", result);
    }

    return 0;
}
