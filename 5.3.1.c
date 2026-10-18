#include <stdio.h>
#include <stdlib.h>
int main()
{
    int Euclid(int x,int y);
    int z=Euclid(-12,18);
    printf("%d",z);
}
int Euclid(int x,int y)
{
    int m,a=abs(x),b=abs(y);
    if(a%b==0)
    {
        m=b;
    }
    else
    {
        m=Euclid(b,a%b);
    }
    return m;
}