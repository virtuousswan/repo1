#include <stdio.h>
#include <math.h>

// Function f(x) = 1 / (1 + x*x)
float f(float x) {
    return 1.0 / (1 + x * x);
}

void main() {
    float a, b, h, sum = 0.0, integral;
    int n, i;
    clrscr();
    // Step 1: Input
    printf("Enter lower limit (a): ");
    scanf("%f", &a);//0
    printf("Enter upper limit (b): ");
    scanf("%f", &b);//1
    printf("Enter number of sub-intervals (n): ");
    scanf("%d", &n);//4

    // Step 2: Calculate step size h
    h = (b - a) / n;
    //1-0/4 =0.25
    // Step 3: Apply trapezoidal rule
    sum = f(a) + f(b); // first + last terms

// a = 0
// b = 1
// f(a) = f(0) = 1 / (1 + 0*0) = 1
// f(b) = f(1) = 1 / (1 + 1*1) = 1/2 = 0.5
// sum = 1 + 0.5 = 1.5
    for (i = 1; i < n; i++)//i=1,2,3
    {
        float x = a + i * h;
        //x=0+1*0.25=0.25
        sum += 2 * f(x); // middle terms multiplied by 2
        //f(0.25)=1/(1+0.25*0.25)=1/1.0625 =0.941176
        //2*f(x)=1.882352
        //sum=1.5+1.882352
        //sum=3.382352

        //i=2
        //x=0+2*0.25=0.5
        //f(0.5)=1/(1+0.5*0.5)=1/1.25=0.8
        //2*f(x)=2*0.8=1.6
        //sum=3.382352+1.6
        //sum=4.982352

        //i=3
        //x=0+3*0.25=0.75
        //f(0.75)=1/(1+0.75*0.75)=1/1+0.5625=1/1.5625=0.64
        //2*f(x)=2*0.64=1.28
        //sum=4.982352+1.28=6.262352
    }


    // Step 4: Final formula
    integral = (h / 2) * sum;
    //0.25/2=0.125*6.262352=0.782794
    
    // Step 5: Output
    printf("Value of integral = %f\n", integral);

    getch();
}



