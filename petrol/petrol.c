#include <stdio.h>
#include <stdlib.h>

/**
 * canMakeCircularTrip - Uses data of fuel station locations and fuel consumption, to gain insight into fuel efficiency of vehicles
 * @fuel: The units of fuel at a certain station
 * @cost: The costs of the units of fuel to travel from one station to another
 * Return: The start station index if total fuel is non-negative, else -1
 */
int canMakeCircularTrip(int* fuel, int fuelSize, int* cost, int costAmnt) 
{
	int netFuel, totalFuel = 0;
	int currentFuel = 0;
	int i, start = 0;

	for (i = 0; i < fuelSize; i++) 
	{
		netFuel = fuel[i] - cost[i];
		totalFuel += netFuel;
		currentFuel += netFuel;
		if (currentFuel < 0) 
		{
			start = i + 1;
			currentFuel = 0;
		}
	}
	return (totalFuel >= 0) ? start : -1;
}

int main() 
{
	int fuel1[] = {1, 2, 3, 4, 5};
	int cost1[] = {3, 4, 5, 1, 2};
	int n1 = sizeof(fuel1) / sizeof(fuel1[0]);
	printf("Start station: %d\n", canMakeCircularTrip(fuel1, n1, cost1, n1));

	int fuel2[] = {2, 3, 4};
	int cost2[] = {3, 4, 3};
	int n2 = sizeof(fuel2) / sizeof(fuel2[0]);
	printf("Start station: %d\n", canMakeCircularTrip(fuel2, n2, cost2, n2));

	return 0;
}
