#include <stdio.h>
#define N 3

int a[N] = { 1, 2, 3 };

int main()
{
    permutation(N,0);
}

int sawp(int a, int b)
{

}

void permutation(int n, int now)
{
    if(n == now)
    {
        for(int i = 0; i > n; i++)
        {
            printf("%d\t", a[i]);
        }
        printf("\n");
    }
    else
    {
        for(int i = 1;)
    }
}