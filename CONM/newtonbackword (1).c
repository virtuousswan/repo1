#include <stdio.h>
#include<conio.h>
void main() 
{
    int n, i, j;
    float X[10], Y[10][10], xi, h, u, result, term=1;

    printf("Enter number of data points:  ");
    scanf("%d", &n);
    //3

    printf("Enter x values:\n");
    for(i = 0; i < n; i++) {
        scanf("%f", &X[i]);
    }
    //x[0]=10
    //x[1]=15
    //x[2]=20

    printf("Enter y values:\n");
    for(i = 0; i < n; i++) {
        scanf("%f", &Y[i][0]);
    }
    //y[0][0]=100
    //y[1][0]=225
    //y[2][0]=400

    //  Construct Backward Difference Table
    for(j = 1; j < n; j++)   //j=1 1<3    //j=2 2<3
    {
        for(i = n-1; i >= j; i--) 
        //i=3-1=2  2>=1 1>=1 
        //i=3-1=2  2>=2 
        {
            Y[i][j] = Y[i][j-1] - Y[i-1][j-1];
            // i=2: Y[2][1] = Y[2][0] - Y[1][0] = 400 - 225 = 175
            // i=1: Y[1][1] = Y[1][0] - Y[0][0] = 225 - 100 = 125


            //i=2: Y[2][2] = Y[2][1] - Y[1][1] = 175 - 125 = 50

        }
    }
// Now backward difference table last row values are:
// Y[2][0] = 400
// Y[2][1] = 175
// Y[2][2] = 50

    // Input xi to interpolate
    printf("Enter value of x to interpolate: ");
    scanf("%f", &xi); //18

    h = X[1] - X[0];
    // h = 15 - 10 = 5
    u = (xi - X[n-1]) / h; 
    //x[n-1]=x[2]=20
    //u = (18 - 20)/5 = -2/5 = -0.4
    // Newton Backward formula
    result = Y[n-1][0];  // last y result= Y[2][0] = 400
    for(i = 1; i < n; i++) //i=1 1<3 //i=2 2<3
    {
        term = term * (u + (i - 1)) / i;
        //term = 1 * (-0.4 + (1-1)) / 1  = 1 * (-0.4+0)/1 =1*-0.4/1  =-0.4
        //term = (-0.4) * (-0.4+1) / 2     = (-0.4)*(0.6)/2 = (-0.24)/2 = -0.12

        result = result + term * Y[n-1][i];
        //result = 400 + (-0.4)*Y[2][1] = 400 + (-0.4)*175 = 400 - 70 = 330
        //result = 330 + (-0.12)*Y[2][2] = 330 + (-0.12)*50 = 330 - 6 = 324

    }
    printf("Interpolated value at %.2f = %.4f\n", xi, result);

    getch();
}
