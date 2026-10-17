#include <stdio.h>
#include<conio.h>
void main() {
    float x0, y0, x1, y1, x, y;

    printf("Enter first point (x0 y0): ");
    scanf("%f %f", &x0, &y0);
    //2 4

    printf("Enter second point (x1 y1): ");
    scanf("%f %f", &x1, &y1);
    //6 8
    printf("Enter x to find y: ");
    scanf("%f", &x);
    //4
    y = y0 + (x - x0)*(y1 - y0)/(x1 - x0);
    //y = y0 + (4-2)*(8-4)/(6-2)
    //y = y0 + (2*4)/4 
    //y = y0 + 8/4
    //y= 4+2
    //y=6
    printf("Interpolated value: y = %.2f\n", y);
    getch();
}
