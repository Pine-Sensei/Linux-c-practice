#include <stdio.h>
int main()
{
    int gcd(int a,int b);
    int a=50,b=110;
    printf("%d",gcd(a,b));
}
int gcd(int a,int b)
{
    while(1)
    {
        if(a%b==0)
        {
            return b;
        }
        else
        {
            int x=a,y=b;
            a=y;
            b=x%y;
        }
    }
}