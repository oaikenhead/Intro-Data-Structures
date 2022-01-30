/**
 * Olliver Aikenhead
 *
 * project 1
 * problem 1: circles
 */

#include <stdio.h>

/* macro init */
#define PI 3.14f
#define DOUBLE 2 //it is double bc there are two circles inscribed in the rectangle

/* program execution */
int main() {
  int r, area, diameter, perimeter;
  float circumference, circle_area, total_difference;

  // user input
  printf("This program computes values related to circles inscribed in a rectangle.\n");
  printf("Enter the value of the radii of the two circles: ");
  scanf("%d", &r);

  perimeter = (r*r) + (r*r);
  area = ((r * DOUBLE) + (r * DOUBLE)) * (r * DOUBLE);
  diameter = 2 * r;
  circumference = 2 * PI * r;
  circle_area = PI * (r * r);
  total_difference = (float)area - (circle_area * DOUBLE);

  // displaying results
  printf("The perimeter of the rectangle is: %d\n", perimeter);
  printf("The area of the rectangle is: %d\n", area);
  printf("The diameter of a circle is: %d\n", diameter);
  printf("The circumference of a circle is: %.3f\n", circumference);
  printf("The total area of the circles is: %.3f\n", circle_area);
  printf("The difference between the area of the rectangle and the total area of the circles is: %.3f\n", total_difference);

  return 0;
}
