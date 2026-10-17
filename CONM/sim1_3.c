#include <stdio.h>
#include <math.h>  // For exp() function

// Function to compute f(x) = e^x
double f(double x) {
    return exp(x);
}

// Function to calculate the Simpson's 1/3rd Rule approximation
double simpsons_one_third(double a, double b, int n) 
{
	int i;
	double h, sum,x;
	h = (b - a) / n;  
    //h=1−0​/6 1/6 ​=0.1667
	sum = f(a) + f(b);  // Start with the first and last terms
    //f(0) = e^0 = 1 
    //f(1) = e^1 = 2.7183
    //sum = 1 + 2.7183 = 3.7183
    // Loop to apply Simpson's rule
    for (i = 1; i < n; i++)  //i=1 1<6 2<6  3<6 4<6 
    {
	    x = a + i * h;
        //i=1 0+1*0.1667  =0.1667   y1
        //i=2 0+2*0.1667 =0.3333    y2
        //i=3 0+3*0.1667 =0.5001    y3
        //i=4 0+4*0.1667 = 0.6667   y4
        //i=5 0+5*0.1667 = 0.8333   y5
	if (i % 2 == 0) {
	    sum += 2 * f(x); // Even index 
        //i=2 f(x) = e^0.3333 = 1.3956
        //i even → add 2f(x) = 2.7912
        //sum = 8.4439 + 2.7912 = 11.2351 

       //i=4 f(x) = e^0.6667 = 1.9477
       //i even → add 2f(x) = 3.8954
       //sum = 17.8299 + 3.8954 = 21.7253

	} else {
	    sum += 4 * f(x);  // Odd index 
        //i=1 f(x) = e^0.1667 = 1.1814
        //i odd → add 4*f(x) = 4.7256
        //sum = 3.7183 + 4.7256 = 8.4439

        //i=3 f(x) = e^0.5 = 1.6487
        //i odd → add 4f(x) = 6.5948
        //sum = 11.2351 + 6.5948 = 17.8299

        //i=5 f(x) = e^0.8333 = 2.3009
        //i odd → add 4f(x) = 9.2036
        //sum = 21.7253 + 9.2036 = 30.9289
	}
    }

    return (h / 3.0) * sum;  // Final calculation
    //h / 3 = 0.1667 / 3 = 0.05556
    //integral = 0.05556 * 30.9289 = 1.7183
}

void main() {
    double a, b, result;
    int n,i;
    clrscr();

    // Get user input
    printf("Enter lower limit a: ");
    scanf("%lf", &a);  //0

    printf("Enter upper limit b: ");
    scanf("%lf", &b);  //1

    printf("Enter number of sub-intervals n : ");
    scanf("%d", &n);   //6

  

    //displaying result
    result = simpsons_one_third(a, b, n);
    printf("Approximate value of the integral: %lf\n", result);


    getch();
}
//x 0  0.1667 0.3333 0.5001 0.6667 0.8333   1                                         
//y 1  1.1814 1.3956 1.6487 1.9477 2.3009 2.7183
//  y0   y1    y2      y3     y4    y5     yn(y6)