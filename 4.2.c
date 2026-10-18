#include <stdio.h>
int main()
{
    int qqq(int x);
}
int qqq(int x)
{
    int g,s;
    g=x%10;
    s=(x%100-g)/10;
    printf("%d\n%d\n",g,s);
}