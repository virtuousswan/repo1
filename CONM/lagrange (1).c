#include <stdio.h>
#include<conio.h>
void main() {
    int n, i, j;
    float x[10], y[10], xp, yp = 0, p;

    // Step 1: Input number of points
    \printf("Enter number of data points: ");
    scanf("%d", &n); //3

    // Step 2: Input x and y values
    printf("Enter data points (x y):\n");
    for (i = 0; i < n; i++) //i=0,1,2,3<3 false
    {
        scanf("%f %f", &x[i], &y[i]); 
        //x[0]=1     y[0]=1 
        //x[1]=2     y[1]=4
        //x[2]=3     y[2]=9
    }

    // Step 3: Input the value of x for interpolation
    printf("Enter value of x to find y: ");
    scanf("%f", &xp); //2.5

    // Step 4: Apply Lagrange Interpolation Formula
    for (i = 0; i < n; i++)  //i=0 0<3    //i=1 1<3  //i=2 2<3
    {
        p = 1;                //p=1
        for (j = 0; j < n; j++) 
        //i=0   j=0 0<3 ,j=1 1<3 ,j=2 2<3 ,j=3 3<3 exit
        //i=1   j=0 0<3 ,j=1 1<3 ,j=2 2<3 ,j=3 3<3 exit
        //i=2   j=0 0<3 ,j=1 1<3 ,j=2 2<3 ,j=3 3<3 exit
        {
            if (j != i)  
            //i=0 0==0 false , 1!=0 ,2!=0
            //i=1 0!=1  ,1==1 false , 2!=1
            //i=2 0!=2  ,1!=2 , 2==2 false
    //    x0 x1 x2            
    // x  1 2 3
    // y  1 4 9
            {
               p = p * (xp - x[j]) / (x[i] - x[j]);
            //i=0      j=0 skip
            //j=1 = 1 * (2.5-x[1])  / x[0]-x[1]
            //    = 1 * (2.5 - 2) / (1 - 2) = 1 * 0.5 / -1 = -0.5
            //j=2 = -0.5 * (2.5-x[2])  / x[0]-x[2]
            //    = -0.5 * (2.5 - 3) / (1 - 3) = -0.5 * (-0.5) / -2 = -0.5 * 0.25 = -0.125 j exit

            //i=1
            //j=0 = 1 * (2.5 - x[0]) / x[1] -x[0]
            //    = 1 * (2.5 - 1) / (2 - 1) = 1 * 1.5 / 1 = 1.5
            //j=1: skip
            //j=2 = 1 * (2.5 - x[2]) / x[1] - x[2]
            //    = 1.5 * (2.5 - 3) / (2 - 3) = 1.5 * (-0.5) / -1 = 1.5 * 0.5 = 0.75

            //i=2
            //j=0 = 1 * (2.5 - x[0]) / x[2] - x[0]
            //    = 1 * (2.5 - 1) / (3 - 1) = 1 * 1.5 / 2 = 0.75
            //j=1 = 1 * (2.5 - x[1]) / x[2] - x[1]
            //    = 0.75 * (2.5 - 2) / (3 - 2) = 0.75 * 0.5 / 1 = 0.375
            //j = 2: skip

            }
        }
        yp = yp + p * y[i];
        // =0+(-0.125)*y[0]
        // =0+(-0.125)*1
        // =-0.125

        // =-0.125 + (0.75)*y[1]
        // =-0.125 + (0.75)*4
        // =-0.125 + 3
        // =2.875

        // =2.875 + 0.375 * y[2]
        // =2.875 + 0.375 * 9
        // =2.875 + 3.375
        // =6.25 


    }

    // Step 5: Print result
    printf("Interpolated value at x = %.2f is y = %.4f\n", xp, yp);

    getch();
}


