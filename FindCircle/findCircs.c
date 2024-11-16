#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * distance - Calculates the Euclidean distance between two points.
 * @x1: x-coordinate of the first point.
 * @y1: y-coordinate of the first point.
 * @x2: x-coordinate of the second point.
 * @y2: y-coordinate of the second point.
 * 
 * Return: The distance as a double.
 */
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

/**
 * findCircleCenters - Finds the centers of the circles passing through
 *                     two points with a given radius.
 * @x1: x-coordinate of the first point.
 * @y1: y-coordinate of the first point.
 * @x2: x-coordinate of the second point.
 * @y2: y-coordinate of the second point.
 * @r: The radius of the circle.
 * 
 * Return: void (prints the result or an error message).
 */
void findCircleCenters(double x1, double y1, double x2, double y2, double r) 
{
    double d = distance(x1, y1, x2, y2);
    
    if (d == 0) {
        if (r == 0) {
            printf("Radius Zero\n");
        } else {
            printf("Coincident point. Infinite solutions\n");
        }
        return;
    }

    if (d > 2 * r) {
        printf("No intersection. Points further apart than circle diameter\n");
        return;
    }

    // Calculate the midpoint between the two points
    double mx = (x1 + x2) / 2;
    double my = (y1 + y2) / 2;

    // Calculate the distance from the midpoint to the circle center
    double h = sqrt(r * r - (d / 2) * (d / 2));

    // Normalize the direction vector from point1 to point2
    double dx = (x2 - x1) / d;
    double dy = (y2 - y1) / d;

    // Calculate the two possible circle centers
    double cx1 = mx + h * (-dy);
    double cy1 = my + h * dx;
    double cx2 = mx - h * (-dy);
    double cy2 = my - h * dx;

    printf("Circle Center 1: (%.4f, %.4f)\n", cx1, cy1);
    printf("Circle Center 2: (%.4f, %.4f)\n", cx2, cy2);
}

/**
 * main - Entry point to test the findCircleCenters function.
 * 
 * Return: Always 0.
 */
int main() 
{
    double x1 = 1.0, y1 = 1.0;
    double x2 = 4.0, y2 = 5.0;
    double r = 3.0;

    findCircleCenters(x1, y1, x2, y2, r);

    return 0;
}

