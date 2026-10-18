#include <stdio.h>
int main()
{
    int count=0;
    for(int n=1;n<=100;n++)
    {
        if(n%10==9)
            count++;
        if((n-n%10)/10==9)
            count++;
    }
    printf("%d\n",count);
}