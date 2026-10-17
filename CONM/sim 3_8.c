#include <stdio.h>
#include <math.h>

// Function f(x) = √x
double f(double x) {
    return sqrt(x);
}

// Simpson’s 3/8 Rule Function
double simpsons_three_eighth(double a, double b, int n) {
    double h, sum;
    int i;
    h = (b - a) / n;  // size 4.5-0/9 = 0.5

    sum = f(a) + f(b);  // First and last terms
    //f(0)=0
    //f(4.5)=2.1213 
    //f(0) + f(4.5) = 0 + 2.1213 = 2.1213

    //i = 1 to n-1 (i=1 to 8)

    for (i = 1; i < n; i++) 
    {
        double x = a + i * h;
        //i=1: x = 0 + 1*0.5 = 0.5
        //i=2: x = 0 + 2*0.5 = 1.0
        //i=3: x = 0 + 3*0.5 = 1.5
        //i=4: x = 0 + 4*0.5 = 2.0
        //i=5: x = 0 + 5*0.5 = 2.5
        //i=6: x = 0 + 6*0.5 = 3.0
        //i=7: x = 0 + 7*0.5 = 3.5
        // i=8: x = 0 + 8*0.5 = 4.0

        if (i % 3 == 0)
            sum += 2 * f(x);  // Every 3rd term has coefficient 2
    //  i=3        f(x) = √1.5 = 1.2247
    //  2 * 1.2247 = 2.4494
    //  sum = 7.2426 + 2.4494 = 9.6920

   //i=6 f(x) = √3.0 = 1.7321
   //  2 * 1.7321 = 3.4642
   //  sum = 18.6779 + 3.4642 = 22.1421

        else
            sum += 3 * f(x);  // Others have coefficient 3
    // i=1 f(x) = √0.5 = 0.7071
    // 3 * 0.7071 = 2.1213
    // sum = 2.1213 + 2.1213 = 4.2426

   // i=2 f(x) = √1.0 = 1.0000
   // 3 * 1.0 = 3.0000
   // sum = 4.2426 + 3.0000 = 7.2426


   //  i=4 f(x) = √2.0 = 1.4142
   // 3 * 1.4142 = 4.2426
   // sum = 9.6920 + 4.2426 = 13.9346

   //  i=5   f(x) = √2.5 = 1.5811
   //  3 * 1.5811 = 4.7433
   //  sum = 13.9346 + 4.7433 = 18.6779

   // i=7   f(x) = √3.5 = 1.8708
   //  3 * 1.8708 = 5.6124
   //  sum = 22.1421 + 5.6124 = 27.7545

   // i=8  f(x) = √4.0 = 2.0000
   //  3 * 2.0000 = 6.0000
   //  sum = 27.7545 + 6.0000 = 33.7545
    }

    return (3 * h / 8) * sum;  // Final formula
    //3h/8 = 3*0.5/8 = 0.1875

// Integral ≈ 0.1875 * 33.7545 ≈ 6.328

}

void main() {
    double a, b, result;
    int n;
    clrscr();

    // Given values
    printf("Enter lower limit a: ");
    scanf("%lf", &a);  //0

    printf("Enter upper limit b: ");
    scanf("%lf", &b);  //4.5

    printf("Enter number of sub-intervals n (must be multiple of 3): ");
    scanf("%d", &n); //9

    

    // Calculate and display result
    result = simpsons_three_eighth(a, b, n);
    printf("\nApproximate value of the integral = %lf\n", result);

    getch();
}


// x 0   0.5    1   1.5     2      2.5     3      3.5    4   4.5
// y 0  0.7071  1  1.2247 1.4142  1.5811 1.7320  1.8708  2  2.1213
//   y0   y1    y2    y3     y4     y5     y6      y7    y8  y9(yn)