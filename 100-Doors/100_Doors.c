#include <stdio.h>
#include <stdbool.h>

/**
 * toggleDoors - Determines the state of the doors after 100 passes.
 * 
 * Return: Prints the door numbers that are open after the last pass.
 */
void toggleDoors() 
{
    bool doors[100] = {false};
    int i, j;

    for (i = 1; i <= 100; i++) 
    {
        for (j = i - 1; j < 100; j += i) 
	{
            doors[j] = !doors[j];
        }
    }

    printf("Open doors: ");
    for (int i = 0; i < 100; i++) 
    {
        if (doors[i]) 
	{
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}

int main() 
{
    toggleDoors();
    return 0;
}

