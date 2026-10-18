#include <stdio.h>
int main()
{
    int Fib(int a);
    int x=Fib(8);
    printf("%d",x);
}
int Fib(int a)
{
    if(a<0)
    {
        printf(">0\nplese");
        return -1;
    }
    switch (a)
    {
    case 0:
        return 1;
        break;
    case 1:
        return 1;
        break;
    default:
        int x;
        x=Fib(a-1)+Fib(a-2);
        return x;
        break;
    }
}