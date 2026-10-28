#include <stdio.h>
#include <stdlib.h>

double mysqrt(double y)
{
    double x = 0, start = 0, end = y;
    while (abs(x*x-y) > 0.001)
    {
        x = (end + start)/2;
        if (x*x > y)
            end = x;
        else
            start = x;
    }
    return x;
}

int main()
{
    printf("%f", mysqrt(3.1415));
}
