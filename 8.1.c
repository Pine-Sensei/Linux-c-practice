#include <stdio.h>
int main()
{
    int x=114514;
    int a[x],b[x];
    for(int i=0;i<x;i++)
    {
        a[i]=i;
        b[i]=a[i];
        printf("a[%d]=%d\nb[%d]=%d\n",i,a[i],i,b[i]);
    }
}