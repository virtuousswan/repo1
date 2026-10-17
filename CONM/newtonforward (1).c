#include <stdio.h>
#include<conio.h>
void main() {
    int n, i, j;
    float x[10], y[10][10], xi, h, u, result,term=1;
    clrscr();
    printf("Enter number of data points: ");
    scanf("%d", &n);
    //4
    printf("Enter x values:\n");
    for(i = 0; i < n; i++) //i=0,1,2,3 
     {
        scanf("%f", &x[i]);
    } 
    //x[0]=10
    //x[1]=15
    //x[2]=20
    //x[3]=25

    printf("Enter y values:\n");
    for(i = 0; i < n; i++) //i=0,1,2,3 
    {
        scanf("%f", &y[i][0]); //  column 0=original y(value)
    }
    //y[0][0]=100
    //y[1][0]=225
    //y[2][0]=400
    //y[3][0]=625

    // Make Forward Difference Table
    for(j = 1; j < n; j++)   
    //col-1 j=1 1<4
    //col-2 j=2 2<4
    //col-3 j=3 3<4
    {
        for(i = 0; i < n - j; i++) 
        //i=0 0<4-1 0<3,  i=1 1<3 ,  i=2 2<3 ,  i=3 3<3 exit
        //i=0 0<4-2 0<2,  i=1 1<2 ,i=2 2<2 exit
        //i=0 0<4-3 0<1,  i=1 1<1 exit
        
        {
            y[i][j] = y[i+1][j-1] - y[i][j-1];
            //col-1 j=1
            //i=0 y[0][1]=y[0+1][1-1]-y[0][1-1]   =y[1][0]-y[0][0]=225-100 =125
            //i=1 y[1][1]=y[1+1][1-1]-y[1][1-1]   =y[2][0]-y[1][0]=400-225 =175
            //i=2 y[2][1]=y[2+1][1-1]-y[2][1-1]   =y[3][0]-y[2][0]=625-400 =225 exit
            
            //col-2 j=2
            //i=0 y[0][2]=y[0+1][2-1]-y[0][2-1]   =y[1][1]-y[0][1]=175-125 =50
            //i=1 y[1][2]=y[1+1][2-1]-y[1][2-1]   =y[2][1]-y[1][1]=225-175=50 exit

            //col-3 j=3
            //i=0 y[0][3]=y[0+1][3-1]-y[0][3-1]   =y[1][2]-y[0][2]=50-50=0 exit
        }
    }
    printf("Enter value of x to interpolate: ");
    scanf("%f", &xi); //12

    h = x[1] - x[0];
  //  h=15-10=5
    u = (xi - x[0]) / h;
  //u=(12-10)/5 =2/5 =0.4
    result = y[0][0]; // result=100

    // Newton forward formula
    for(i = 1; i < n; i++)  //i=1 1<4,
    {
        term = term * (u - (i - 1)) / i;
        //i=1 term=1*(0.4-(1-1))/1      =1*(0.4-0)/1     =1*(0.4)/1      =0.4/1   =0.4  =u
        
        //i=2 term=0.4*(0.4-(2-1))/2    =0.4*(0.4-1)/2   =0.4*(-0.6)/2   =-0.24/2 =-0.12 =u*u-1/2
        
        //i=3 term=-0.12*(0.4-(3-1))/3  =-0.12*(0.4-2)/3 =-0.12*(-1.6)/3 =0.192/3 =0.064 =u(u-1)*u-2/3
        
        result = result + term * y[0][i];
        //result=100+0.4*y[0][1]     =100+0.4*125  =100+50=150   
        //result=150+(-0.12)*y[0][2] =150-0.12*50  =150-6 =144   
        //result=144+0.064*y[0][3]   =144+0.064*0 =144+0  =144   
        

    }

    printf("Interpolated value at %.2f = %.4f\n", xi, result);
    getch();
}
