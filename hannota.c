#include <stdio.h>
int main()
{
    int han(int n);
    int n=6;
    printf("%d",han(n));
}
int han(int n)
{
    if(n==1)
    {
        return 1;
    }
    else
    {
        int x=2*han(n-1)+1;
        return x;
    }
}