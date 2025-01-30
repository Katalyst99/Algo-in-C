#include <stdio.h>

/**
 * calcAverageSalary - Function to return the average salary
 * @salary: The array containing the salaries of employees
 * @size: The size
 * Return: The average salary
 */

double calcAverageSalary(int salary[], int size) 
{
    int minSalary = salary[0], maxSalary = salary[0];
    int total = 0;

    if (size <= 2) return 0.0;

    for (int i = 0; i < size; i++) 
    {
        if (salary[i] < minSalary) minSalary = salary[i];
        if (salary[i] > maxSalary) maxSalary = salary[i];
        total += salary[i];
    }

    total -= (minSalary + maxSalary);
    int count = size - 2;

    return (double)total / count;
}

int main() 
{
    int salary[] = {4000, 3000, 1000, 2000};
    int size = sizeof(salary) / sizeof(salary[0]);

    printf("%.5f\n", calcAverageSalary(salary, size));
    return 0;
}
